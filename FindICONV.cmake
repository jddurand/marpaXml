# taken from:
# https://code.google.com/p/tinygettext/source/browse/trunk/FindICONV.cmake?spec=svn185&r=185

#
#  Copyright (c) 2006, Peter Kümmel, <syntheticpp@gmx.net>
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
#  
#  1. Redistributions of source code must retain the copyright
#     notice, this list of conditions and the following disclaimer.
#  2. Redistributions in binary form must reproduce the copyright
#     notice, this list of conditions and the following disclaimer in the
#     documentation and/or other materials provided with the distribution.
#  3. The name of the author may not be used to endorse or promote products 
#     derived from this software without specific prior written permission.
#  
#  THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
#  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
#  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
#  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
#  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
#  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
#  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
#  THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#  

set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS true)
include(CheckFunctionExists)
if (ICONV_INCLUDE_DIR)
  # Already in cache, be silent
  set(ICONV_FIND_QUIETLY TRUE)
endif()

find_path(ICONV_INCLUDE_DIR iconv.h
 /usr/include
 /usr/local/include)

set(POTENTIAL_ICONV_LIBS iconv libiconv libiconv2)

find_library(ICONV_LIBRARY NAMES ${POTENTIAL_ICONV_LIBS}
	PATHS /usr/lib /usr/local/lib)

if(WIN32)
	set(ICONV_DLL_NAMES iconv.dll  libiconv.dll libiconv2.dll)
	find_file(ICONV_DLL   
					NAMES ${ICONV_DLL_NAMES}
					PATHS ENV PATH
					NO_DEFAULT_PATH)
	find_file(ICONV_DLL_HELP   
					NAMES ${ICONV_DLL_NAMES}
					PATHS ENV PATH
					${ICONV_INCLUDE_DIR}/../bin)
	if(ICONV_FIND_REQUIRED)
		if(NOT ICONV_DLL AND NOT ICONV_DLL_HELP)
			message(FATAL_ERROR "Could not find iconv.dll, please add correct your PATH environment variable")
		endif()
		if(NOT ICONV_DLL AND ICONV_DLL_HELP)
			get_filename_component(ICONV_DLL_HELP ${ICONV_DLL_HELP} PATH)
			message(STATUS)
			message(STATUS "Could not find iconv.dll in standard search path, please add ")
			message(STATUS "${ICONV_DLL_HELP}")
			message(STATUS "to your PATH environment variable.")
			message(STATUS)
			message(FATAL_ERROR "exit cmake")
		endif()
	endif()
	if(ICONV_INCLUDE_DIR AND ICONV_LIBRARY AND ICONV_DLL)
   		set(_ICONV_FOUND TRUE)
	endif()
else()
	check_function_exists(iconv HAVE_ICONV_IN_LIBC)
	if(ICONV_INCLUDE_DIR AND HAVE_ICONV_IN_LIBC)
   		set(_ICONV_FOUND TRUE)
		set(ICONV_LIBRARY CACHE TYPE STRING FORCE)
	endif()
	if(ICONV_INCLUDE_DIR AND ICONV_LIBRARY)
   		set(_ICONV_FOUND TRUE)
	endif()
endif()



if(_ICONV_FOUND)
  IF(ICONV_INCLUDE_DIR)
    SET(_INCLUDE_DIR ICONV_INCLUDE_DIR)
  ELSE()
    SET(_INCLUDE_DIR ".")
  ENDIF()
  TRY_COMPILE(ICONV_SECOND_ARGUMENT_IS_CONST ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/iconv.c
    COMPILE_DEFINITIONS "-I\"${_INCLUDE_DIR}\" -DICONV_SECOND_ARGUMENT_IS_CONST"
    OUTPUT_VARIABLE detectWarnings)
  string (REGEX MATCH "const" ICONV_CONST ${detectWarnings})
  IF((NOT ICONV_SECOND_ARGUMENT_IS_CONST) OR (ICONV_CONST MATCHES "const"))
    set(ICONV_SECOND_ARGUMENT_IS_CONST FALSE)
    # Make sure it compiles anyway
    TRY_COMPILE(ICONV_SECOND_ARGUMENT_IS_NOT_CONST ${CMAKE_CURRENT_BINARY_DIR}
      ${CMAKE_CURRENT_SOURCE_DIR}/cmake/iconv.c
      COMPILE_DEFINITIONS "-UICONV_SECOND_ARGUMENT_IS_CONST")
    IF(NOT ICONV_SECOND_ARGUMENT_IS_NOT_CONST)
      message(FATAL_ERROR "Could not check if iconv second argument is const or not")
      set(_ICONV_FOUND FALSE)
    endif()
  endif()
endif(_ICONV_FOUND)

if(_ICONV_FOUND)
   if(WIN32)
      message(STATUS "Found iconv dll      : ${ICONV_DLL}")
   else()
      if(HAVE_ICONV_IN_LIBC)
         message(STATUS "Found iconv library      : [in libc]")
      else()
         message(STATUS "Found iconv library      : ${ICONV_LIBRARY}")
      endif()
   endif()
   if(ICONV_SECOND_ARGUMENT_IS_CONST)
      message(STATUS "Check iconv library      : Second argument in iconv is a const")
   else()
      message(STATUS "Check iconv library      : Second argument in iconv is not a const")
   endif()
else()
   if(ICONV_FIND_REQUIRED)
      message(STATUS "Looked for iconv library named ${POTENTIAL_ICONV_LIBS}.")
      message(STATUS "Found no acceptable iconv library. This is fatal.")
      message(STATUS "iconv header: ${ICONV_INCLUDE_DIR}")
      message(STATUS "iconv lib   : ${ICONV_LIBRARY}")
      message(FATAL_ERROR "Could NOT find iconv library")
   endif()
endif()

IF(_ICONV_FOUND)
  TRY_COMPILE(HAS_ICONV_OPEN ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/iconv_open.c
    COMPILE_DEFINITIONS "-I\"${_INCLUDE_DIR}\"")
  IF(NOT HAS_ICONV_OPEN)
    MESSAGE(STATUS "Check iconv library      : iconv_open() found.")
  ELSE()
    MESSAGE(STATUS "Check iconv library      : iconv_open() not found.")
    SET (ICONV_FOUND FALSE)
  ENDIF()
ENDIF()

IF(_ICONV_FOUND)
  TRY_COMPILE(HAS_ICONV_CLOSE ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/iconv_close.c
    COMPILE_DEFINITIONS "-I\"${_INCLUDE_DIR}\"")
  IF(NOT HAS_ICONV_CLOSE)
    MESSAGE(STATUS "Check iconv library      : iconv_close() found.")
  ELSE()
    MESSAGE(STATUS "Check iconv library      : iconv_close() not found.")
    SET (ICONV_FOUND FALSE)
  ENDIF()
ENDIF()

IF(_ICONV_FOUND)
  SET (ICONV_FOUND 1 CACHE STRING "ICONV is found")
ENDIF()

mark_as_advanced(ICONV_LIBRARY ICONV_INCLUDE_DIR ICONV_SECOND_ARGUMENT_IS_CONST)
