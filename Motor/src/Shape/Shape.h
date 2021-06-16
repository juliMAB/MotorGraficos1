#ifndef SHAPE_H
#define SHAPE_H

#include "../src/Exports/Exports.h"
#include "../src/Entity/Entity.h"
#include "../src/Material/Material.h"
#include "../Model/ModelTexture.h"

#define TRIANGLE 0x0004
#define QUAD 0x0007

namespace Coco {

	typedef unsigned int uint;
	class GraficosEngine_API Shape : public Entity {
		float* _vb;
		uint _vbo;
		uint _vao;
		uint _ibo;

		float cubeVerticesCol[64]{
			//front left down
			-1.0, -1.0, 1.0,/**/ -1.0f, -1.0f, /**/	0.0f, 0.0f, 0.0f,

			//front right down
			1.0, -1.0, 1.0,	/**/ -1.0f, 0.0f, /**/	0.0f, 0.0f, 0.0f,

			//front right up
			1.0, 1.0, 1.0,	/**/ 0.0f, 0.0f, /**/	0.0f, 0.0f, 0.0f,

			//front left up
			-1.0, 1.0, 1.0,	/**/ 0.0f, 1.0f, /**/	0.0f, 0.0f, 0.0f,

			//back left down
			-1.0, -1.0, -1.0,/**/1.0f, 1.0f, /**/	0.0f, 0.0f, 0.0f,

			//back right down
			1.0, -1.0, -1.0, /**/1.0f, 0.0f, /**/	0.0f, 0.0f, 0.0f,

			//back right up
			1.0, 1.0, -1.0,	 /**/0.0f, 0.0f, /**/	0.0f, 0.0f, 0.0f,

			//back left up
			-1.0, 1.0, -1.0, /**/0.0f, 1.0f, /**/	0.0f, 0.0f, 0.0f
		};

		uint _textureID;
		int  _width;
		int  _height;
		int  _bitDepth;
		bool _usingTexture;
		ModelTexture* _texture;

		bool _usingOriginalMaterial;
		Material* _material;
	public:
		Shape(Renderer* rend);
		~Shape();
		void InitShape(TypeShape type, TypeShader t);
		void LoadTexture(const char* path, const char* name);
		void DrawShape();
		void SetMaterial(Material* m);
		Material* GetMaterial();
		int GetVerticesArrLenght();
		int GetVerticesTam();
		float* GetVertices();
		float GetVertexIndex(int ind);
		uint GetType();
		int GetIndexTam();
		unsigned int* GetIndexs();
		void CalcAverageNormals(uint * indices, uint indiceCount, float * vertices, uint verticeCount, uint vLength, uint normalOffset);
	};

}

#endif