#include "Sprite.h"

namespace Graficos1 {
	Sprite::Sprite(Renderer* rend, Material* mat) : Entity2D(rend, mat) {

	}
	Sprite::Sprite(Renderer* rend) : Entity2D(rend, NULL){

	}
	Sprite::~Sprite() {

	}
	void Sprite::LoadTexture(const char* path) {
		_textureImp.LoadTexture(path, _data, _texture, _width, _height, _channels);
	}

}