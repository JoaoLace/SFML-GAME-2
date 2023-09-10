#include "Game.h"


void Game::initWindow()
{
	videoMode = sf::VideoMode(800,600);
	window = new sf::RenderWindow(videoMode, "Game 2",sf::Style::Close | sf::Style::Titlebar);
}

void Game::initVariables()
{
	endGame = false;
}

// Construtores e destrutores
Game::Game()
{
	initVariables();
	initWindow();
}
Game::~Game()
{
	delete window;
}
// Funcs
void Game::update()
{
	pollEvents();

}
void Game::render()
{
	window->clear();
	
	// Render (drawing)
	player.render(window);

	window->display();
}
const bool Game::running() const
{
	return window->isOpen();
}
void Game::pollEvents()
{
	while (window->pollEvent(sfmlEvent))
	{
		switch (sfmlEvent.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			if (sfmlEvent.key.code == sf::Keyboard::Escape)
				window->close();
			break;
		}
	}
}