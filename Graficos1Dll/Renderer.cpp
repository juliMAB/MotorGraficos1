#include "pch.h"
#include "Renderer.h"
#include <iostream>

namespace Graficos1 {

	Renderer::Renderer() {
	
	}
	Renderer::~Renderer() {

	}
	int Renderer::InitGlew() {
		//Permitir extensiones modernas;
		glewExperimental = GL_TRUE;

		if (glewInit() != GLEW_OK) {
		std::cout << "Entra aca";
			std::cout << "Error in Glew Init" << std::endl;
			glfwTerminate();
			return 0;
		}

		return 1;
	}
	void Renderer::Draw(){
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(1, 0, 0, 1);
		glBegin(GL_TRIANGLES);

		glVertex2f(0.0f, 0.5f);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);

		glEnd();
	}
}