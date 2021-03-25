#include "Sprite.h"
#include <glew.h>
#include <GLFW/glfw3.h>
#include <glm\gtc\type_ptr.hpp>
#include <iostream>

namespace Graficos1 {

	//static float texVertices[] = {
	//	 1.0f,  1.0f, 0.0f, 1.0f,0.0f,1.0f, 1.0f, 1.0f,   // top right
	//	 1.0f, -1.0f, 0.0f, 1.0f,0.0f,1.0f, 1.0f, 0.0f,   // bottom right
	//	-1.0f, -1.0f, 0.0f, 1.0f,0.0f,1.0f, 0.0f, 0.0f,   // bottom left
	//	-1.0f,  1.0f, 0.0f, 1.0f,0.0f,1.0f, 0.0f, 1.0f    // top left 
	//};

	unsigned int posIndexsTex[] = {
		0, 1, 2,
		2, 3, 0
	};

	typedef unsigned int uint;
	static uint tamVertsTex;

	Sprite::Sprite(Renderer* rend, Material* mat) : Entity2D(rend, mat) {
		tamVertsTex = sizeof(texVertices);
		_vb = texVertices;
		_renderer->SetBuffers(tamVertsTex, _vb, _vbo, _vao);
		_renderer->SetIndexThings(tamVertsTex, posIndexsTex, _ibo);
		_renderer->SetAttribs(model,TypeShader::Texture);
		_animation = NULL;
		_settedAnimsValues = false;
	}
	Sprite::Sprite(Renderer* rend) : Entity2D(rend, NULL) {
		tamVertsTex = sizeof(texVertices);
		_vb = texVertices;
		_animation = NULL;
		_settedAnimsValues = false;
	}
	Sprite::~Sprite() { 
		glDeleteTextures(1, &_texture); 
		glDeleteVertexArrays(1, &_vao);
		glDeleteBuffers(1, &_vbo);

		if (_animation != NULL) {
			delete _animation;
			_animation = NULL;
		}
	}
	void Sprite::LoadTexture(const char* path, bool transparent) {
		_transparent = transparent;
		_textureImp.LoadTexture(path, _data, _texture, _width, _height, _channels, _transparent);
	}
	void Sprite::StartUseAnimation() {
		if (_animation == NULL) {
			_animation = new Animation();
			return;
		}
			
		std::cout << "You can't use again StartUseAnimation in this Sprite" << std::endl;
	}

	void Sprite::SetAnimation(int columns, int rows, float framesPerSeconds) {
		if (_animation == NULL) {
			std::cout << "You can't use this SetAnimation without use StartUseAnimation" << std::endl;
			return;
		}
		_settedAnimsValues = true;
		_animation->SetAnimationValues(columns, rows, framesPerSeconds, _width, _height, texVertices);
	}
	void Sprite::AddFrameToAnimation(int frameX, int frameY, int animation, int frame) {
		if (_animation == NULL) {
			std::cout << "You can't use this AddFrameToAnimation without use StartUseAnimation" << std::endl;
			return;
		}
		else if (!_settedAnimsValues) {
			std::cout << "You can't use this AddFrameToAnimation without use SetAnimationValues" << std::endl;
			return;
		}

		_animation->AddFrame(frameX, frameY, animation, frame);
	}
	void Sprite::DrawTexture() {
		if (_transparent)
			BlendSprite();
		glEnable(GL_TEXTURE_2D);

		_renderer->UpdateModel(model, projection);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, _texture);

		_renderer->Draw(TypeShape::Quad, 6, _vao, _vbo, _ibo, texVertices, tamVertsTex,TypeShader::Texture);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDisable(GL_TEXTURE_2D);

		if (_transparent)
			UnBlendSprite();
	}
	void Sprite::UpdateAnimation() {
		if (_animation == NULL) {
			std::cout << "You can't use this UpdateAnimation without use StartUseAnimation" << std::endl;
			return;
		}
		else if (!_settedAnimsValues) {
			std::cout << "You can't use this UpdateAnimation without use SetAnimationValues" << std::endl;
			return;
		}
		_animation->UpdateAnimation();
	}
	void Sprite::ChangeAnimation(int anim) {
		if (_animation == NULL) {
			std::cout << "You can't use this ChangeAnimation without use StartUseAnimation" << std::endl;
			return;
		}
		else if (!_settedAnimsValues) {
			std::cout << "You can't use this ChangeAnimation without use SetAnimationValues" << std::endl;
			return;
		}
		_animation->ChangeAnimation(anim);
	}
	float* Sprite::GetVerts() {
		return texVertices;
	}
	int	 Sprite::GetChannels(){
		return _channels;
	}	 
	void Sprite::BlendSprite() {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
	void Sprite::UnBlendSprite() {
		glDisable(GL_BLEND);
	}
}