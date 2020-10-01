#include "pch.h"
#include "GameBase.h"
#include <iostream>
#include <time.h>
namespace Graficos1 {

	GameBase::GameBase() {
		_window = new Window();
		_renderer = new Renderer();
	}
	GameBase::~GameBase() {
		if (_window != NULL)
			delete _window;
		if (_renderer != NULL)
			delete _renderer;
		if (_shape != NULL)
			delete _shape;
	}
	int GameBase::Play(int width, int height, const char* windowName, GLFWmonitor* fullScreen) {
		//Iniciar GLFW
		if (!glfwInit()) {
			std::cout << "GLFW Initialization failed" << std::endl;
			glfwTerminate(); //Si no puede iniciar, entra aca y termina con glfw
			return 1;
		}

		//Seteamos propiedades de la ventana de windows con glfw
		//OpenGL version
		//GLFWWINDOWHINT Setea la version de glfw (3.3)
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		//Core profile = No tiene compatibilidad con versiones anteriores de GL
		//glfwWindowHint(GLFW_OPENGL_PROFILE, glfw_complement_p);
		//Esto setea que haya compatibilidad con versiones mas recientes de GL
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		
		if (_window != NULL)
			_window->MakeWindow(width, height, windowName, fullScreen);
		
		int bufferWidth;
		int bufferHeight;
		//Esta funcion setea los pixeles del frame buffer de la ventana en las variables que le pasemos
		//par: GLFWwindow* creada, donde almacenar el largo en pixeles, donde almacenar el alto en pixeles
		//Hay que pasar la referencia en memoria de los buffers
		glfwGetFramebufferSize(_window->GetWindow(), &bufferWidth, &bufferHeight);

		if (_window != NULL)
			_window->InitWindow();

		if (_renderer != NULL)
			if (!_renderer->InitGlew()) {
				glfwTerminate();
				return -1;
			}
		
		if (_renderer != NULL)
			_renderer->InitShaders();

		_shape = new Shape(_renderer, nullptr);
		if (_shape != NULL) {
			_shape->InitShape(GL_TRIANGLES);
			_shape->CreateShape();
		}

		double oldTimer = clock();
		float posX = 0;
		float posY = 0;
		float posZ = 0;
		
		float rotX = 0;
		float rotY = 0;
		float rotZ = 0;

		float scaleX = 1;
		float scaleY = 1;
		float scaleZ = 1;

		float speed = 1000;

		if (_window != NULL) {
			while (_window->CheckIfWindowIsOpen()) {
				//Limpia los buffers a sus valores base
				//Par: gl_color_buffer_bit - indica los buffers que actualmente estan activados para el dibujado
				glClear(GL_COLOR_BUFFER_BIT);

				//Limpia la pantalla y setea un color - No hace lo que hace glClear
				//par: r,g,b,a
				glClearColor(0.33f,0.33f,0.33f, 1.0f);

				double timer = clock();
				float dt = (float)((timer - oldTimer) / 1000.0f);
				oldTimer = timer;

				if (glfwGetKey(_window->GetWindow(), GLFW_KEY_W) == GLFW_PRESS) 
					posY += speed * dt;
				else if (glfwGetKey(_window->GetWindow(), GLFW_KEY_S) == GLFW_PRESS) 
					posY -= speed * dt;

				if (glfwGetKey(_window->GetWindow(), GLFW_KEY_A) == GLFW_PRESS) 
					posX -= speed * dt;
				else if (glfwGetKey(_window->GetWindow(), GLFW_KEY_D) == GLFW_PRESS)
					posX += speed * dt;

				if (glfwGetKey(_window->GetWindow(), GLFW_KEY_1) == GLFW_PRESS)
					rotZ -= speed * dt;
				else if (glfwGetKey(_window->GetWindow(), GLFW_KEY_2) == GLFW_PRESS)
					rotZ += speed * dt;

				if (glfwGetKey(_window->GetWindow(), GLFW_KEY_3) == GLFW_PRESS)
					rotX += speed * dt;
				else if (glfwGetKey(_window->GetWindow(), GLFW_KEY_4) == GLFW_PRESS)
					rotX -= speed * dt;

				if (glfwGetKey(_window->GetWindow(), GLFW_KEY_5) == GLFW_PRESS)
					rotY -= speed * dt; 
				else if (glfwGetKey(_window->GetWindow(), GLFW_KEY_6) == GLFW_PRESS)
					rotY += speed * dt;

				if (glfwGetKey(_window->GetWindow(), GLFW_KEY_Q) == GLFW_PRESS)
					scaleX -= 5 * dt;
				else if (glfwGetKey(_window->GetWindow(), GLFW_KEY_E) == GLFW_PRESS)
					scaleX += 5 * dt;

				if (glfwGetKey(_window->GetWindow(), GLFW_KEY_Z) == GLFW_PRESS)
					scaleY -= 5 * dt;
				else if (glfwGetKey(_window->GetWindow(), GLFW_KEY_X) == GLFW_PRESS)
					scaleY += 5 * dt;

				if (_shape != NULL) {
					_shape->SetPos((posX / 960.0f), (posY / 540.0f), posZ);
					_shape->SetRotX((rotX/180.0f));
					_shape->SetRotY((rotY/180.0f));
					_shape->SetRotZ((rotZ/180.0f));
					_shape->SetScale(scaleX, scaleY, scaleZ);
				}
				if (_shape != NULL)
					_shape->DrawShape();
		
				if (_window != NULL)
					_window->SwapBuffers();

				glfwPollEvents();
			}
		}
		if (_window != NULL)
			_window->DestroyWindow();
		glfwTerminate();
		return 0;
	}
	void GameBase::Stop() {

	}

}