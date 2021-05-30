#ifndef MODELIMPORTER_H
#define MODELIMPORTER_H

#include "../Exports/Exports.h"

#include <vector>
#include <string>

#include "ASSIMP_N/include/assimp/Importer.hpp"
#include "ASSIMP_N/include/assimp/scene.h"
#include "ASSIMP_N/include/assimp/postprocess.h"

#include "../TextureImporter/TextureImporter.h"

namespace Coco {

	class GraficosEngine_API ModelImporter {

		Assimp::Importer _importer;

	public:
		ModelImporter();
		~ModelImporter();
	};

}

#endif