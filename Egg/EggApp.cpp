#include"pch.h"
#include "EggApp.h"
#include "Utilities.h"

#include"../glad/include/glad/glad.h"
#include"../glfw/include/GLFW/glfw3.h"
#include"../stbi/stb_image.h"


#include"Shader.h"

namespace egg
{
	template<typename T>
	EggApp<T>::EggApp()
	{
	}

	template<typename T>
	void EggApp<T>::Init()
	{
		if (sInstance == nullptr)
			sInstance = new T;
	}

	template<typename T>
	void EggApp<T>::RunInterface()
	{
		sInstance->Run();
	}

	template<typename T>
	void EggApp<T>::Run()
	{

		mWindow.Create("Game_IC", 1000, 800);

		/////////// NEW ADDITIONS  ***UNFINISHED***/////////////
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			EGG_ERROR("Failed to initialize GLAD");
			return;
		}

		float vertices[] = {
			-0.5f, -0.5f, 0.0f, 0.0f,
			 0.5f, -0.5f, 1.0f, 0.0f,
			-0.5f,  0.5f, 0.0f, 1.0f,
			 0.5f,  0.5f, 1.0f, 1.0f
		};

		unsigned int indices[] = {
			0, 1, 2,
			1, 2, 3
		};


		unsigned int VAO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		unsigned int VBO;
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		unsigned int EBO;
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2*sizeof(float))); //dk if this coreect
		glEnableVertexAttribArray(1);


		////////////// SHADERS ///////////////
		
		egg::Shader shader{ "../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl" };
		shader.SetUniform2Ints("ScreenSize", 1000, 800);
		
			
			
		////////////// TEXTURES //////////////


		unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		//might be some code missing here
		int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true);
		//modified
		unsigned char* data = stbi_load("../Assets/Pictures/test.png", &width, &height, &nrChannels, 0);
		if (data)
		{
			//modified
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			EGG_ERROR("Failed to load a picture from the file!!!");
		}
		stbi_image_free(data);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		/////////// NEW ADDITIONS MIGHT BE UNFINISHED /////////



		while (mShouldContinue)
		{
			OnUpdate();

			glClearColor(0.3f, 0.2f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			shader.Bind();

			glBindVertexArray(VAO);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}


	}

	template<typename T>
	void EggApp<T>::OnUpdate() //called in main.cpp
	{
	}





}