set(HEADER_FILES
	include/Egg.h
	EggApp.h
	Utilities.h
	GameWindow.h
	WindowImplementation.h
	GLFWCode/GLFWImplementation.h
)

set(SOURCE_FILES
	GameWindow.cpp
	GLFWCode/GLFWImplementation.cpp
)

add_definitions(-DEGG_DEBUG=2)
add_definitions(-DEGG_LIB)

include_directories(../Egg)
include_directories(../glfw/include)

add_library(Egg SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Egg PRIVATE pch.h)

target_link_libraries(Egg glfw)