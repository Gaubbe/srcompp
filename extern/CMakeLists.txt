###########
# JSONCPP #
###########

if(${SRCOMPP_BUILD_STATIC})
	set(BUILD_SHARED_LIBS OFF)
	set(BUILD_STATIC_LIBS ON)
else()
	set(BUILD_SHARED_LIBS ON)
	set(BUILD_STATIC_LIBS OFF)
endif()

set(JSONCPP_WITH_TESTS OFF)
set(BUILD_OBJECT_LIBS OFF)
add_subdirectory(jsoncpp)

###########
# OpenSSL #
###########