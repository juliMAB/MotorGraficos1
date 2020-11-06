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
		_renderer->SetQuadThings(tamVertsTex, posIndexsTex);
		_renderer->SetAttribs(model,TypeShader::Texture);
	}
	Sprite::Sprite(Renderer* rend) : Entity2D(rend, NULL) {
		tamVertsTex = sizeof(texVertices);
		_vb = texVertices;
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
	void Sprite::SetAnimation(int cantFramesAnim, int cantFramesImg, float timeBetweenFrames, int rows, int actualRow) {
		_animation = new Animation();
		_animation->SetAnimationValues(cantFramesAnim, cantFramesImg, timeBetweenFrames, _width, _height, rows, actualRow,texVertices);
	}
	void Sprite::DrawTexture() {
		if (_transparent)
			BlendSprite();
		glEnable(GL_TEXTURE_2D);

		_renderer->SetBuffers(tamVertsTex, _vb, _vbo, _vao);
		_renderer->SetQuadThings(tamVertsTex, posIndexsTex);
		_renderer->SetAttribs(model,TypeShader::Texture);

		_renderer->UpdateModel(model);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, _texture);
		_renderer->Draw(GL_QUADS, 6, _vao);

		glDisable(GL_TEXTURE_2D);

		if (_transparent)
			UnBlendSprite();
	}
	void Sprite::UpdateAnimation() {
		_animation->UpdateAnimation();
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