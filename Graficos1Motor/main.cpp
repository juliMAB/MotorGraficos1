#include "Game.h"
using namespace Graficos1;
int main(void){
	Game* g = new Game();
	if (g)
		g->Play();
	if (g)
		delete g;
}