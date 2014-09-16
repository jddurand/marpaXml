#
# Usage: On Windows: cmake -G "NMake Makefiles", then nmake install
#        On UNIX   : cmake -G "UNIX Makefiles", then make install
#
cmake_minimum_required (VERSION 2.8)
#
# As per http://www.cmake.org/pipermail/cmake/2008-September/023808.html
#
#
# If the user specifies -DCMAKE_BUILD_TYPE on the command line, take their definition
# and dump it in the cache along with proper documentation, otherwise set CMAKE_BUILD_TYPE
# to Debug prior to calling PROJECT()
#
IF (DEFINED CMAKE_BUILD_TYPE)
   SET (CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel.")
ELSE ()
   SET (CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel.")
ENDIF ()

PROJECT (marpaXml)

# In any case we include our include directory for all targets
INCLUDE_DIRECTORIES (${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/include/API)

# ---------------------------------------
# Add current path to modules search path
# ---------------------------------------
SET (CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})

# --------------
# ICU dependency
# --------------
FIND_PACKAGE (ICU)
IF (NOT ICU_FOUND)
    MESSAGE (FATAL_ERROR "ICU must be detected")
ENDIF ()

# ----------------
# Check for inline
# ----------------
FIND_PACKAGE (Inline)

# ---------------------------
# General overwrite of CFLAGS
# ---------------------------
# Specific to Windows, does not hurt to set it in any case
ADD_DEFINITIONS("-D_CRT_SECURE_NO_WARNINGS")
ADD_DEFINITIONS("-D_CRT_NONSTDC_NO_DEPRECATE")

SET (CMAKE_C_FLAGS             "${CMAKE_C_FLAGS} $ENV{CFLAGS} ${ICU_CPP_FLAGS} ${ICU_C_FLAGS}")
SET (CMAKE_CXX_FLAGS           "${CMAKE_CXX_FLAGS} $ENV{CXXFLAGS} ${ICU_CPP_FLAGS} ${ICU_CXX_FLAGS}")
SET (CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS_INIT} $ENV{LDFLAGS} ${ICU_LDFLAGS}")
SET (CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS_INIT} $ENV{LDFLAGS} ${ICU_LDFLAGS}")
SET (CMAKE_EXE_LINKER_FLAGS    "${CMAKE_EXE_LINKER_FLAGS_INIT} $ENV{LDFLAGS} ${ICU_LDFLAGS}")

# Specific to GCC like family
IF (CMAKE_COMPILER_IS_GNUCC)
  IF (${CMAKE_C_FLAGS} MATCHES "std=c99")
    #
    # For functions like strdup that are not anymore in ISO C99 namespace
    ADD_DEFINITIONS("-D_GNU_SOURCE")
  ENDIF ()
ENDIF ()

MESSAGE (STATUS "CMAKE_C_FLAGS            : ${CMAKE_C_FLAGS}")
MESSAGE (STATUS "CMAKE_CXX_FLAGS          : ${CMAKE_CXX_FLAGS}")
MESSAGE (STATUS "CMAKE_SHARED_LINKER_FLAGS: ${CMAKE_SHARED_LINKER_FLAGS}")
MESSAGE (STATUS "CMAKE_MODULE_LINKER_FLAGS: ${CMAKE_MODULE_LINKER_FLAGS}")
GET_DIRECTORY_PROPERTY( DirDefs DIRECTORY ${CMAKE_SOURCE_DIR} COMPILE_DEFINITIONS )
FOREACH (d ${DirDefs})
    MESSAGE (STATUS "DEFINITION               : ${d}" )
ENDFOREACH ()
GET_DIRECTORY_PROPERTY( DirDefs DIRECTORY ${CMAKE_SOURCE_DIR} INCLUDE_DIRECTORIES )
FOREACH (d ${DirDefs})
    MESSAGE (STATUS "INCLUDE                  : ${d}" )
ENDFOREACH ()

# -------------------------------------------------
# General output path for libraries and executables
# -------------------------------------------------
SET (LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/build)
SET (EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/build)

# ----------------------------
# General variables used below
# ----------------------------
FIND_PROGRAM (PERL perl)

# -----------------------------------------
# Transliterate DOM Level 3 Core.sql into C
# -----------------------------------------

# -------------
# Marpa library
# -------------
SET (MARPA_VERSION "2.088000")
SET (MARPA_DIR "${PROJECT_SOURCE_DIR}/Marpa-R2-${MARPA_VERSION}")
IF (NOT EXISTS "${MARPA_DIR}" OR NOT IS_DIRECTORY "${MARPA_DIR}")
  MESSAGE (STATUS "Preparing ${MARPA_DIR}")
  GET_FILENAME_COMPONENT (CC_BASENAME ${CMAKE_C_COMPILER} NAME)
  # CMAKE_C_FLAGS is not really important here, and this is fortunate, since this variable is not easily accessible at this precise time
  EXECUTE_PROCESS (
    #
    # Take care:
    # The following will build libmarpa in two ways:
    # - one that is guaranteed to use OUR compiler in libmarpa_dist
    # - one that is compiled with perl's configured compiler and that we will reuse when
    #   generating src/internal/grammar/xml_1_0.c and src/internal/grammar/xml_1_1.c
    #   Note that Marpa::R2 procedure uses libmarpa_build
    #
    COMMAND "${PERL}" tools/prepare_libmarpa.pl "${MARPA_VERSION}" "${CC_BASENAME}" "" "${CMAKE_C_OUTPUT_EXTENSION}"
    )
ENDIF ()
FILE(GLOB marpa_lib_src Marpa-R2-${MARPA_VERSION}/core/read_only/*.c)
ADD_LIBRARY (marpa ${marpa_lib_src})

# -----------
# AVL library
# -----------
SET (AVL_VERSION "2.0.3")
SET (AVL_DIR "${PROJECT_SOURCE_DIR}/avl-${AVL_VERSION}")
IF (NOT EXISTS "${AVL_DIR}" OR NOT IS_DIRECTORY "${AVL_DIR}")
  MESSAGE (STATUS "Preparing ${AVL_DIR}")
  EXECUTE_PROCESS (
    COMMAND "${PERL}" tools/prepare_libavl.pl "${AVL_VERSION}"
    )
ENDIF ()
FILE(GLOB avl_lib_src ${AVL_DIR}/*avl.c)
ADD_LIBRARY (avl ${avl_lib_src})

# --------------
# SQLITE library
# --------------
SET (SQLITE_VERSION "3080600")
SET (SQLITE_DIR "${PROJECT_SOURCE_DIR}/sqlite-amalgamation-${SQLITE_VERSION}")
IF (NOT EXISTS "${SQLITE_DIR}" OR NOT IS_DIRECTORY "${SQLITE_DIR}")
  MESSAGE (STATUS "Preparing ${SQLITE_DIR}")
  EXECUTE_PROCESS (
    COMMAND "${PERL}" tools/prepare_sqlite_amalgamation.pl "${SQLITE_VERSION}"
    )
ENDIF ()
FILE(GLOB sqlite_lib_src ${SQLITE_DIR}/sqlite3.c)
ADD_LIBRARY (sqlite ${sqlite_lib_src})
SET_PROPERTY (TARGET sqlite APPEND_STRING PROPERTY COMPILE_FLAGS " -DSQLITE_DISABLE_LFS")
IF (MINGW)
  CHECK_INCLUDE_FILE("mingw.h" _HAVE_MINGW_H)
  CHECK_INCLUDE_FILE("_mingw.h" _HAVE__MINGW_H)
  IF (_HAVE_MINGW_H)
    SET_PROPERTY (TARGET sqlite APPEND_STRING PROPERTY COMPILE_FLAGS " -D_HAVE_MINGW_H")
  ENDIF()
  IF (_HAVE__MINGW_H)
    SET_PROPERTY (TARGET sqlite APPEND_STRING PROPERTY COMPILE_FLAGS " -D_HAVE__MINGW_H")
  ENDIF()
ENDIF ()
#
# This will affect upper(), lower(), LIKE, and REGEXP, c.f. http://www.sqlite.org/src/finfo?name=ext/icu/README.txt
#
SET_PROPERTY (TARGET sqlite APPEND_STRING PROPERTY COMPILE_FLAGS " -DSQLITE_ENABLE_ICU")
#
# We know what we are doing: disable processing of foreign keys
#
# SET_PROPERTY (TARGET sqlite APPEND_STRING PROPERTY COMPILE_FLAGS " -DSQLITE_OMIT_FOREIGN_KEY")
#
# Our implementation cannot go beyond SQLITE_MAX_LENGTH for length of TEXT
#
SET_PROPERTY (TARGET sqlite APPEND_STRING PROPERTY COMPILE_FLAGS " -DSQLITE_MAX_LENGTH=2147483647")
#
# Likely to never happen but how knows
#
SET_PROPERTY (TARGET sqlite APPEND_STRING PROPERTY COMPILE_FLAGS " -DSQLITE_64BIT_STATS")
#
# Make sure db connection is serialized for multithread concurrent access. This mean
# that SQLite will systematically serialize any access to database connection and
# prepared statement. I.e. there is no need for us to mutex on our database connection.
# We just make sure that there is one and that all statements are prepared using
# marpaXml_DOM_init().
#
SET_PROPERTY (TARGET sqlite APPEND_STRING PROPERTY COMPILE_FLAGS " -DSQLITE_THREADSAFE=1")
#
# No need for extension, triggers, trace, etc... in SQLite
#
# SET_PROPERTY (TARGET sqlite APPEND_STRING PROPERTY COMPILE_FLAGS " -DSQLITE_OMIT_LOAD_EXTENSION -DSQLITE_OMIT_TRACE -DSQLITE_OMIT_AUTHORIZATION -DSQLITE_OMIT_PROGRESS_CALLBACK -DSQLITE_OMIT_CHECK -DSQLITE_OMIT_EXPLAIN")
#
# ------------------------
# marpaXmlInternal library
# ------------------------
ADD_LIBRARY (marpaXml
  src/internal/genericStack.c
  src/internal/marpaWrapper.c
  src/internal/manageBuf.c
  src/internal/messageBuilder.c
  src/internal/dateBuilder.c
  src/internal/streamIn.c
  src/internal/hash.c
  src/internal/grammar/xml_common.c
  src/internal/grammar/xml_1_0.c
  src/internal/grammar/xml_1_1.c
  src/internal/grammar/qname_1_0.c
  src/internal/grammar/qname_1_1.c
  src/API/marpaXml/String.c
  src/API/marpaXml/DOM2.c
  src/API/marpaXml/cplus.c
  src/API/marpaXml/log.c
  xxhash-read-only/xxhash.c
  "db/Dom Level 3 Core.h"
  )
SET_PROPERTY (TARGET marpaXml APPEND PROPERTY INCLUDE_DIRECTORIES "${MARPA_DIR}/core/read_only" "${SQLITE_DIR}" "${PROJECT_SOURCE_DIR}")
ADD_DEPENDENCIES (marpaXml marpa)

# -----------------------
# distclean custom target
# -----------------------
ADD_CUSTOM_TARGET (distclean)
SET(DISTCLEANED
  build
  CMakeFiles
  CMakeCache.txt
  Makefile
  cmake_install.cmake
  "${MARPA_DIR}"
  "${AVL_DIR}"
  "${SQLITE_DIR}"
  include/internal/config.h
  src/internal/grammar/xml_1_0.c
  src/internal/grammar/xml_1_1.c
  src/internal/grammar/qname_1_0.c
  src/internal/grammar/qname_1_1.c
  "db/Dom Level 3 Core.h"
  GLOB *vcxproj*
  GLOB *sln
  )
ADD_CUSTOM_COMMAND (
  DEPENDS clean
  COMMENT "distclean"
  COMMAND "${PERL}"
  ARGS    -MExtUtils::Command -e rm_rf ${DISTCLEANED}
  TARGET  distclean
  )

# ------------------------------
# Generated files custom targets
# ------------------------------
ADD_CUSTOM_COMMAND(
    PRE_BUILD
    COMMENT "Generating xml_1_0.c"
    OUTPUT src/internal/grammar/xml_1_0.c
    COMMAND "${PERL}"
    ARGS tools/generateMarpaWrapperCode.pl --bnf bnf/xml_1_0.bnf --output src/internal/grammar/xml_1_0.c
    DEPENDS tools/generateMarpaWrapperCode.pl bnf/xml_1_0.bnf
)
ADD_CUSTOM_COMMAND(
    PRE_BUILD
    COMMENT "Generating xml_1_1.c"
    OUTPUT src/internal/grammar/xml_1_1.c
    COMMAND "${PERL}"
    ARGS tools/generateMarpaWrapperCode.pl --bnf bnf/xml_1_1.bnf --output src/internal/grammar/xml_1_1.c
    DEPENDS tools/generateMarpaWrapperCode.pl bnf/xml_1_1.bnf
)
ADD_CUSTOM_COMMAND(
    PRE_BUILD
    COMMENT "Generating qname_1_0.c"
    OUTPUT src/internal/grammar/qname_1_0.c
    COMMAND "${PERL}"
    ARGS tools/generateMarpaWrapperCode.pl --bnf bnf/qname_1_0.bnf --output src/internal/grammar/qname_1_0.c
    DEPENDS tools/generateMarpaWrapperCode.pl bnf/qname_1_0.bnf
)
ADD_CUSTOM_COMMAND(
    PRE_BUILD
    COMMENT "Generating qname_1_1.c"
    OUTPUT src/internal/grammar/qname_1_1.c
    COMMAND "${PERL}"
    ARGS tools/generateMarpaWrapperCode.pl --bnf bnf/qname_1_1.bnf --output src/internal/grammar/qname_1_1.c
    DEPENDS tools/generateMarpaWrapperCode.pl bnf/qname_1_1.bnf
)
ADD_CUSTOM_COMMAND(
    PRE_BUILD
    COMMENT "Generating Dom Level 3 Core.h"
    OUTPUT "db/Dom Level 3 Core.h"
    COMMAND "${PERL}"
    ARGS tools/prepare_dom3.pl "db/Dom Level 3 Core.sql" "db/Dom Level 3 Core.h"
    DEPENDS tools/prepare_dom3.pl "db/Dom Level 3 Core.sql"
)
# ----------------------
# va_copy implementation
# ----------------------
INCLUDE(VA_COPY)
VA_COPY()

# -------------------------
# prefer memset() over loop
# -------------------------
INCLUDE(NULL_IS_ZEROES)
NULL_IS_ZEROES()

# -------------
# localtime_r ?
# -------------
INCLUDE(LOCALTIME_R)
LOCALTIME_R()

# -------
# Threads
# -------
FIND_PACKAGE(Threads REQUIRED)

# -------------------------
# Additional include checks
# -------------------------
INCLUDE(CheckIncludeFile)
CHECK_INCLUDE_FILE("inttypes.h" HAVE_INTTYPES_H)
CHECK_INCLUDE_FILE("sys/types.h" HAVE_SYS_TYPES_H)
CHECK_INCLUDE_FILE("stdint.h" HAVE_STDINT_H)
CHECK_INCLUDE_FILE("features.h" HAVE_FEATURES_H)
CHECK_INCLUDE_FILE("unistd.h" HAVE_UNISTD_H)
CHECK_INCLUDE_FILE("io.h" HAVE_IO_H)

# -------------
# 32bits/64bits
# -------------
INCLUDE(CheckTypeSize)
CHECK_TYPE_SIZE ("void*" SIZEOF_VOID_P BUILTIN_TYPES_ONLY)
CHECK_TYPE_SIZE ("unsigned int" SIZEOF_UINT BUILTIN_TYPES_ONLY)
CHECK_TYPE_SIZE ("unsigned long long int" SIZEOF_ULONGLONGINT BUILTIN_TYPES_ONLY)

# ------------------------------------
# Generate marpaXmlInternal's config.h
# ------------------------------------
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/include/internal/config.h.in
               ${CMAKE_CURRENT_BINARY_DIR}/include/internal/config.h)

# -----------
# Executables
# -----------
ADD_EXECUTABLE        (marpaWrapper_test ${PROJECT_SOURCE_DIR}/test/internal/marpaWrapper_test.c)
TARGET_LINK_LIBRARIES (marpaWrapper_test marpaXml marpa)

ADD_EXECUTABLE        (streamIn_test ${PROJECT_SOURCE_DIR}/test/internal/streamIn_test.c)
TARGET_LINK_LIBRARIES (streamIn_test marpaXml)

ADD_EXECUTABLE        (log_test ${PROJECT_SOURCE_DIR}/test/API/log_test.c)
TARGET_LINK_LIBRARIES (log_test marpaXml)

ADD_EXECUTABLE        (DOM_test ${PROJECT_SOURCE_DIR}/test/API/DOM_test.c)
TARGET_LINK_LIBRARIES (DOM_test marpaXml marpa sqlite ${CMAKE_THREAD_LIBS_INIT})

ADD_EXECUTABLE        (String_test ${PROJECT_SOURCE_DIR}/test/API/String_test.c)
TARGET_LINK_LIBRARIES (String_test marpaXml)

ADD_EXECUTABLE        (ICU4CDetectEncoding ${PROJECT_SOURCE_DIR}/test/internal/ICU4CDetectEncoding.c)

ADD_EXECUTABLE        (xml_1_0_test ${PROJECT_SOURCE_DIR}/test/internal/grammar/xml_1_0_test.c)
TARGET_LINK_LIBRARIES (xml_1_0_test marpaXml marpa)

ADD_EXECUTABLE        (xml_1_1_test ${PROJECT_SOURCE_DIR}/test/internal/grammar/xml_1_1_test.c)
TARGET_LINK_LIBRARIES (xml_1_1_test marpaXml marpa)

#INSTALL (TARGETS marpaxml DESTINATION install/bin)
#INSTALL (FILES marpaWrapper.h DESTINATION install/include)
