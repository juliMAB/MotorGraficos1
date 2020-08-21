#ifndef GAME_H
#define GAME_H
#include "GameBase.h"
using namespace Graficos1;
namespace Graficos1 {
	class Game : GameBase{
		GameBase* gb;
	public:
		Game();
		~Game();
		void Play();
		void Stop();
	};

}
#endif