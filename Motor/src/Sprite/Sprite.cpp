#include "Sprite.h"
#include <glew.h>
#include <GLFW/glfw3.h>
#include <glm\gtc\type_ptr.hpp>

namespace Graficos1 {

	Sprite::Sprite(Renderer* rend, Material* mat) : Entity2D(rend, mat) {}
	Sprite::Sprite(Renderer* rend) : Entity2D(rend, NULL) {	}
	Sprite::~Sprite() { 
		glDeleteTextures(1, &_texture); 
	}
	void Sprite::LoadTexture(const char* path, bool transparent) {
		_textureImp.LoadTexture(path, _data, _texture, _width, _height, _channels, transparent);
	}
	void Sprite::UseTexture() {
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, _texture);
	}

	int	 Sprite::GetWidth() {
		return _width;
	}	 
	int	 Sprite::GetHeight() {
		return _height;
	}	 
	int	 Sprite::GetChannels(){
		return _channels;
	}	 
	void Sprite::BlendSprite() {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
}