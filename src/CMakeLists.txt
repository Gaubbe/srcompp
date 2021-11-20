file(GLOB SRCOMPP_SOURCE_FILES 
	*.cpp
)

##################
# SHARED LIBRARY #
##################
if(NOT ${SRCOMPP_BUILD_STATIC})
	add_library(srcompp SHARED ${SRCOMPP_SOURCE_FILES})
	target_include_directories(srcompp PUBLIC ${SRCOMPP_PUBLIC_HEADERS_DIR} PRIVATE ${SRCOMPP_PRIVATE_HEADERS_DIR})
	target_link_libraries(srcompp PUBLIC jsoncpp_lib)
	target_compile_definitions(srcompp PUBLIC SRCOMPP_SHARED PRIVATE SRCOMPP_EXPORT)
endif()

##################
# STATIC LIBRARY #
##################
if(${SRCOMPP_BUILD_STATIC})
	add_library(srcompp_static STATIC ${SRCOMPP_SOURCE_FILES})
	target_include_directories(srcompp_static PUBLIC ${SRCOMPP_PUBLIC_HEADERS_DIR} PRIVATE ${SRCOMPP_PRIVATE_HEADERS_DIR})
	target_link_libraries(srcompp_static PUBLIC jsoncpp_static)
endif()