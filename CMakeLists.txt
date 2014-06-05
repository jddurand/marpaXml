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
INCLUDE_DIRECTORIES (${PROJECT_SOURCE_DIR}/include)

# ---------------------------
# General overwrite of CFLAGS
# ---------------------------
SET (CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -D_CRT_SECURE_NO_WARNINGS")
SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_CRT_SECURE_NO_WARNINGS")

# -------------------------------------------------
# General output path for libraries and executables
# -------------------------------------------------
SET (LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/build)
SET (EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/build)

# ---------------------------------------
# Add current path to modules search path
# ---------------------------------------
SET (CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})

# ----------------------------
# General variables used below
# ----------------------------
FIND_PROGRAM (PERL perl)

# -------------
# Marpa library
# -------------
SET (MARPA_VERSION "2.085_006")
SET (MARPA_DIR "${PROJECT_SOURCE_DIR}/Marpa-R2-${MARPA_VERSION}")
IF (NOT EXISTS "${MARPA_DIR}" OR NOT IS_DIRECTORY "${MARPA_DIR}")
  MESSAGE (STATUS "Preparing ${MARPA_DIR}")
  GET_FILENAME_COMPONENT (CC_BASENAME ${CMAKE_C_COMPILER} NAME)
  # CMAKE_C_FLAGS is not really important here, and this is fortunate, since this variable is not easily accessible at this precise time
  EXECUTE_PROCESS (
    COMMAND "${PERL}" tools/prepare_libmarpa.pl "${MARPA_VERSION}" "${CC_BASENAME}" "" "${CMAKE_C_OUTPUT_EXTENSION}"
    )
ENDIF ()
FILE(GLOB marpa_lib_src Marpa-R2-${MARPA_VERSION}/libmarpa_dist/*.c)
ADD_LIBRARY (libmarpa ${marpa_lib_src})

# ------------------------
# libcharsetdetect library
# ------------------------
SET (LIBCHARSETDETECT_SRC ${PROJECT_SOURCE_DIR}/bundle/cChardet/src/ext/libcharsetdetect)
FILE (GLOB charsetdetect_lib_src ${LIBCHARSETDETECT_SRC}/mozilla/extensions/universalchardet/src/base/*.cpp)
SET (charsetdetect_lib_src ${charsetdetect_lib_src} ${LIBCHARSETDETECT_SRC}/charsetdetect.cpp)
ADD_LIBRARY (libcharsetdetect ${charsetdetect_lib_src})
SET_PROPERTY (TARGET libcharsetdetect
  PROPERTY INCLUDE_DIRECTORIES
    ${LIBCHARSETDETECT_SRC}
    ${LIBCHARSETDETECT_SRC}/nspr-emu
    ${LIBCHARSETDETECT_SRC}/mozilla/extensions/universalchardet/src/base)

# ------------------------
# marpaXmlInternal library
# ------------------------
ADD_LIBRARY (marpaXmlInternal
  ${PROJECT_SOURCE_DIR}/src/internal/genericStack.c
  ${PROJECT_SOURCE_DIR}/src/internal/marpaWrapper.c
  ${PROJECT_SOURCE_DIR}/src/internal/messageBuilder.c
  ${PROJECT_SOURCE_DIR}/src/internal/streamIn.c
  ${PROJECT_SOURCE_DIR}/src/internal/grammar/xml_1_0.c
  ${PROJECT_SOURCE_DIR}/src/internal/grammar/xml_1_1.c
  )
SET_PROPERTY (TARGET marpaXmlInternal APPEND PROPERTY INCLUDE_DIRECTORIES ${MARPA_DIR}/libmarpa_dist)
ADD_DEPENDENCIES (marpaXmlInternal libmarpa)

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
  ${MARPA_DIR}
  include/internal/config.h
  )
ADD_CUSTOM_COMMAND (
  DEPENDS clean
  COMMENT "distclean"
  COMMAND "${PERL}"
  ARGS    -MExtUtils::Command -e rm_rf ${DISTCLEANED}
  TARGET  distclean
  )

# --------------
# ICU dependency
# --------------
FIND_PACKAGE (ICU)
SET (HAVE_ICU ICU_FOUND)

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

# ------------------------------------
# Generate marpaXmlInternal's config.h
# ------------------------------------
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/include/internal/config.h.in
               ${CMAKE_CURRENT_BINARY_DIR}/include/internal/config.h)

# -----------
# Executables
# -----------
ADD_EXECUTABLE        (marpaWrapperTest ${PROJECT_SOURCE_DIR}/test/internal/marpaWrapperTest.c)
TARGET_LINK_LIBRARIES (marpaWrapperTest marpaXmlInternal libmarpa)

ADD_EXECUTABLE        (streamInTest ${PROJECT_SOURCE_DIR}/test/internal/streamInTest.c)
SET_PROPERTY          (TARGET streamInTest APPEND PROPERTY INCLUDE_DIRECTORIES ${LIBCHARSETDETECT_SRC})
TARGET_LINK_LIBRARIES (streamInTest marpaXmlInternal libcharsetdetect)

ADD_EXECUTABLE        (ICU4CDetectEncoding ${PROJECT_SOURCE_DIR}/test/internal/ICU4CDetectEncoding.c)
SET_PROPERTY          (TARGET ICU4CDetectEncoding APPEND_STRING PROPERTY COMPILE_FLAGS "${ICU_CPP_FLAGS} ${ICU_C_FLAGS} ")
FOREACH (_icu_link_flag ${ICU_LINK_FLAGS})
  # ICU_LINK_FLAGS is potentially a list, and cmake is painful with stringified versions of lists
  SET_PROPERTY          (TARGET ICU4CDetectEncoding APPEND_STRING PROPERTY LINK_FLAGS "${_icu_link_flag} ")
ENDFOREACH ()

ADD_EXECUTABLE        (xml_1_0 ${PROJECT_SOURCE_DIR}/test/internal/grammar/xml_1_0.c)
TARGET_LINK_LIBRARIES (xml_1_0 marpaXmlInternal libmarpa)

#INSTALL (TARGETS marpaxml DESTINATION install/bin)
#INSTALL (FILES marpaWrapper.h DESTINATION install/include)
