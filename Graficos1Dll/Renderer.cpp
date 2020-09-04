#include "pch.h"
#include "Renderer.h"
#include <glew.h>
#include <glfw3.h>

namespace Graficos1 {
	Renderer::Renderer() {

	}
	Renderer::~Renderer(){
	
	}
	void Renderer::Draw(){
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.0f, 1.0f, 0.0f, 1.0f);

		glBegin(GL_TRIANGLES);

		glVertex2f(0.0f, 0.5f);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);

		glEnd();
	}
}