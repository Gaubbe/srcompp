cmake_minimum_required(VERSION 3.12)
project(srcompp)

if(WIN32)
	add_compile_definitions(SRCOMPP_WIN)
endif()

###########
# OPTIONS #
###########
option(SRCOMPP_BUILD_STATIC "Builds as static library" ON)

######################
# EXTERNAL LIBRARIES #
######################
add_subdirectory(extern)

############################
# NON-MODIFYABLE VARIABLES #
############################
set(SRCOMPP_PUBLIC_HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRCOMPP_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SRCOMPP_PRIVATE_HEADERS_DIR ${SRCOMPP_SRC_DIR})

################
# HEADER FILES #
################
set(SRCOMPP_PUBLIC_HEADERS
	${SRCOMPP_PUBLIC_HEADERS_DIR}/srcompp/TestClass.h
)

################
# SOURCE FILES #
################
add_subdirectory(src)