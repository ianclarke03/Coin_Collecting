set(HEADER_FILES
	include/Egg.h
	EggApp.h
	Utilities.h
)

set(SOURCE_FILES
	placeholder.cpp
)

add_definitions(-DEGG_DEBUG=2)
add_definitions(-DEGG_LIB)

if(WIN32)
	add_definitions(-DEGG_MSCPP)
elseif(LINUX)
	add_definitions(-DEGG_LINUX)
elseif(APPLE)
	add_definitions(-DEGG_APPLE)
endif()

add_library(Egg SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Egg PRIVATE pch.h)