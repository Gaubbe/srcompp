cmake_minimum_required(VERSION 3.8)
project(srcompp)

option(${PROJECT_NAME}_BUILD_SHARED off)

if(${${PROJECT_NAME}_BUILD_SHARED})
	add_compile_definitions(SRCOMPP_EXPORT)
	add_compile_definitions(SRCOMPP_SHARED)
endif()

if(WIN32)
	add_compile_definitions(SRCOMPP_WIN)
endif()

set(${PROJECT_NAME}_PUBLIC_HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(${PROJECT_NAME}_PUBLIC_HEADERS
	${${PROJECT_NAME}_PUBLIC_HEADERS_DIR}/srcompp/TestClass.h
)

set(${PROJECT_NAME}_SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/src/TestClass.cpp
)

if(${SRCOMPP_BUILD_SHARED})
	add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_SOURCE_FILES})
	target_include_directories(${PROJECT_NAME} PUBLIC ${${PROJECT_NAME}_PUBLIC_HEADERS_DIR})
else()
	add_library(${PROJECT_NAME}_static ${${PROJECT_NAME}_SOURCE_FILES})
	target_include_directories(${PROJECT_NAME}_static PUBLIC ${${PROJECT_NAME}_PUBLIC_HEADERS_DIR})
endif()