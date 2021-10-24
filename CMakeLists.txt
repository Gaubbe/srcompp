cmake_minimum_required(VERSION 3.8)
project(srcompp)

if(WIN32)
	add_compile_definitions(SRCOMPP_WIN)
endif()

###########
# OPTIONS #
###########
option(srcompp_BUILD_SHARED "Builds as shared library" ON)
option(srcompp_BUILD_STATIC "Builds as static library" ON)

############################
# NON-MODIFYABLE VARIABLES #
############################
set(srcompp_PUBLIC_HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(srcompp_FINAL_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR}/srcompp)
set(srcompp_FINAL_BIN_DIR ${srcompp_FINAL_BUILD_DIR}/bin)
set(srcompp_FINAL_INCLUDE_DIR ${srcompp_FINAL_BUILD_DIR}/include)
set(srcompp_FINAL_LIB_DIR ${srcompp_FINAL_BUILD_DIR}/lib)

################
# HEADER FILES #
################
set(srcompp_PUBLIC_HEADERS
	${srcompp_PUBLIC_HEADERS_DIR}/srcompp/TestClass.h
)

################
# SOURCE FILES #
################
set(srcompp_SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/src/TestClass.cpp
)

##################
# SHARED LIBRARY #
##################
if(${srcompp_BUILD_SHARED})
	add_library(srcompp SHARED ${srcompp_SOURCE_FILES})
	target_include_directories(srcompp PUBLIC ${srcompp_PUBLIC_HEADERS_DIR})
	target_compile_definitions(srcompp PUBLIC SRCOMPP_SHARED PRIVATE SRCOMPP_EXPORT)

	set_target_properties(
		srcompp PROPERTIES 
		RUNTIME_OUTPUT_DIRECTORY ${srcompp_FINAL_BIN_DIR}
		RUNTIME_OUTPUT_DIRECTORY_DEBUG ${srcompp_FINAL_BIN_DIR}
		RUNTIME_OUTPUT_DIRECTORY_RELEASE ${srcompp_FINAL_BIN_DIR}
		ARCHIVE_OUTPUT_DIRECTORY ${srcompp_FINAL_LIB_DIR}
		ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${srcompp_FINAL_LIB_DIR}
		ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${srcompp_FINAL_LIB_DIR}
	)

	add_custom_command(TARGET srcompp POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${srcompp_PUBLIC_HEADERS_DIR} ${srcompp_FINAL_INCLUDE_DIR})
endif()

##################
# STATIC LIBRARY #
##################
if(${srcompp_BUILD_STATIC})
	add_library(srcompp_static ${srcompp_SOURCE_FILES})
	target_include_directories(srcompp_static PUBLIC ${srcompp_PUBLIC_HEADERS_DIR})

	set_target_properties(
		srcompp_static PROPERTIES 
		ARCHIVE_OUTPUT_DIRECTORY ${srcompp_FINAL_LIB_DIR}
		ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${srcompp_FINAL_LIB_DIR}
		ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${srcompp_FINAL_LIB_DIR}
	)

	add_custom_command(TARGET srcompp_static POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${srcompp_PUBLIC_HEADERS_DIR} ${srcompp_FINAL_INCLUDE_DIR})
endif()