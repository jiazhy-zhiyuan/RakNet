cmake_minimum_required(VERSION 2.6)
project(RakNet)

set(CMAKE_MACOSX_RPATH 1)

if (NOT APPLE)
    # Check if 64-bit
    if (CMAKE_SIZEOF_VOID_P MATCHES "4")
        set(HAVE_64_BIT 0)
    else (CMAKE_SIZEOF_VOID_P MATCHES "4")
        set(HAVE_64_BIT 1)
    endif (CMAKE_SIZEOF_VOID_P MATCHES "4")
endif (NOT APPLE)

IF (WIN32 AND NOT UNIX)
    set(PROGRAMFILESX86 $ENV{PROGRAMFILES})
    string(REPLACE "\\" "/" PROGRAMFILESX86 ${PROGRAMFILESX86})
ENDIF (WIN32 AND NOT UNIX)

IF (WIN32 AND NOT UNIX)
    set(RAKNET_LIBRARY_LIBS ws2_32.lib)
ELSE (WIN32 AND NOT UNIX)
    set(RAKNET_LIBRARY_LIBS pthread)
ENDIF (WIN32 AND NOT UNIX)

# LibDLL ------------------------------------------------------------------------------------------------------
FILE(GLOB ALL_HEADER_SRCS ${RakNet_SOURCE_DIR}/include/*.h)
FILE(GLOB ALL_CPP_SRCS ${RakNet_SOURCE_DIR}/src/*.cc)

include_directories(${RakNet_SOURCE_DIR}/include)

add_library(RakNetShared SHARED ${ALL_CPP_SRCS} ${ALL_HEADER_SRCS})

IF(WIN32 AND NOT UNIX)
	SET( CMAKE_CXX_FLAGS "/D WIN32 /D _RAKNET_DLL /D _CRT_NONSTDC_NO_DEPRECATE /D _CRT_SECURE_NO_DEPRECATE /GS- /GR- ")
ENDIF(WIN32 AND NOT UNIX)

IF(WIN32 AND NOT UNIX)
	target_link_libraries (RakNetShared ${RAKNET_LIBRARY_LIBS})
ELSE(WIN32 AND NOT UNIX)
	target_link_libraries (RakNetShared ${RAKNET_LIBRARY_LIBS})
	# INSTALL(TARGETS RakNetDLL DESTINATION ${RakNet_SOURCE_DIR}/Lib/DLL)
ENDIF(WIN32 AND NOT UNIX)
# LibDLL ------------------------------------------------------------------------------------------------------

# LibStatic ---------------------------------------------------------------------------------------------------
FILE(GLOB ALL_HEADER_SRCS ${RakNet_SOURCE_DIR}/include/*.h)
FILE(GLOB ALL_CPP_SRCS ${RakNet_SOURCE_DIR}/src/*.cc)

include_directories(${RakNet_SOURCE_DIR}/include)

add_library(RakNetStatic STATIC ${ALL_CPP_SRCS} ${ALL_HEADER_SRCS})

IF(WIN32 AND NOT UNIX)
	SET(CMAKE_CXX_FLAGS "/D WIN32 /D _RAKNET_LIB /D _CRT_NONSTDC_NO_DEPRECATE /D _CRT_SECURE_NO_DEPRECATE /GS- /GR- ")
ENDIF(WIN32 AND NOT UNIX)

IF(WIN32 AND NOT UNIX)
	target_link_libraries (RakNetStatic ${RAKNET_LIBRARY_LIBS})

	IF(NOT ${CMAKE_GENERATOR} STREQUAL "MSYS Makefiles")

		IF(MSVC10 OR MSVC11 OR MSVC12)
			set_target_properties(RakNetStatic PROPERTIES STATIC_LIBRARY_FLAGS "/NODEFAULTLIB:\"LIBCD.lib LIBCMTD.lib MSVCRT.lib\"" )
		ELSE()
			set_target_properties(RakNetStatic PROPERTIES STATIC_LIBRARY_FLAGS "/NODEFAULTLIB:&quot;LIBCD.lib LIBCMTD.lib MSVCRT.lib&quot;" )
		ENDIF()

	ENDIF(NOT ${CMAKE_GENERATOR} STREQUAL "MSYS Makefiles")

ELSE(WIN32 AND NOT UNIX)
	target_link_libraries (RakNetStatic ${RAKNET_LIBRARY_LIBS})
	# INSTALL(TARGETS RakNetLibStatic DESTINATION ${RakNet_SOURCE_DIR}/Lib/RakNetLibStatic)
	# INSTALL(FILES ${ALL_HEADER_SRCS} DESTINATION ${RakNet_SOURCE_DIR}/include/raknet)
ENDIF(WIN32 AND NOT UNIX)
# LibStatic ---------------------------------------------------------------------------------------------------
