#pragma once
#include "Player.h"
#include <iostream>
#include <ctime>


class Game
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event sfmlEvent;
	bool endGame;

	Player player;

	void initWindow();
	void initVariables();
public:
	// Construtures e destrutores
	Game();
	~Game();

	// Accessors

	// Modifiers

	// Funcs
	const bool running() const;

	void pollEvents();
	void update();
	void render();
};

