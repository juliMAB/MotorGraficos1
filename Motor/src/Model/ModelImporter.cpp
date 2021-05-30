#include "ModelImporter.h"

namespace Coco {
	ModelImporter::ModelImporter() {
		_importer = Assimp::Importer();
	}
	ModelImporter::~ModelImporter() {
	}
}