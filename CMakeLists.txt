cmake_minimum_required(VERSION 3.8)
project(srcompp)

if(WIN32)
	add_compile_definitions(SRCOMPP_WIN)
endif()

set(${PROJECT_NAME}_PUBLIC_HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

################
# HEADER FILES #
################
set(${PROJECT_NAME}_PUBLIC_HEADERS
	${${PROJECT_NAME}_PUBLIC_HEADERS_DIR}/srcompp/TestClass.h
)

################
# SOURCE FILES #
################
set(${PROJECT_NAME}_SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/src/TestClass.cpp
)

##################
# SHARED LIBRARY #
##################
add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${${PROJECT_NAME}_PUBLIC_HEADERS_DIR})
target_compile_definitions(${PROJECT_NAME} PUBLIC SRCOMPP_SHARED PRIVATE SRCOMPP_EXPORT)

##################
# STATIC LIBRARY #
##################
add_library(${PROJECT_NAME}_static ${${PROJECT_NAME}_SOURCE_FILES})
target_include_directories(${PROJECT_NAME}_static PUBLIC ${${PROJECT_NAME}_PUBLIC_HEADERS_DIR})