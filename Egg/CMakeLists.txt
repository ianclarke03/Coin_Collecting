set(HEADER_FILES
	include/Egg.h
	EggApp.h
	Events.h
	GameWindow.h
	WindowImplementation.h
	GLFWCode/GLFWImplementation.h
	GLFWCode/OpenGLPicture.h
	GLFWCode/OpenGLRenderer.h
	GLFWCode/OpenGLShader.h
	Picture.h
	PictureImplementation.h
	Renderer.h
	RendererImplementation.h
	Shader.h
	ShaderImplementation.h
	Unit.h
	Utilities.h
	WindowImplementation.h
)

set(SOURCE_FILES
	Events.cpp
	GameWindow.cpp
	GLFWCode/GLFWImplementation.cpp
	GLFWCode/OpenGLPicture.cpp
	GLFWCode/OpenGLRenderer.cpp
	GLFWCode/OpenGLShader.cpp
	Picture.cpp
	Renderer.cpp
	Shader.cpp
	Unit.cpp
)

add_definitions(-DEGG_DEBUG=2)
add_definitions(-DEGG_LIB)

include_directories(../Egg)
include_directories(../glfw/include)
include_directories(../glad/include)
include_directories(../stbi)

add_library(Egg SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Egg PRIVATE pch.h)

target_link_libraries(Egg glfw)
target_link_libraries(Egg glad)
target_link_libraries(Egg stbi)