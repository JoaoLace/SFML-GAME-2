#include "Game.h"
int main()
{
	// Rand
	srand(static_cast<unsigned>(time(0)));

	// Inint game object
	Game game;
	// Loop
	while (game.running())
	{
		game.update();
		game.render();
	}
	// End

	return 0;
}