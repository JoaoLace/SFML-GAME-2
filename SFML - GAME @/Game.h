#pragma once
#include "Player.h"
#include "Balls.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>

class Game
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event sfmlEvent;
	bool endGame;

	Player player;

	std::vector <Balls> BallsVector;
	float spawTimerMax;
	float spawnTimer;
	int maxBalls;

	int points;
	sf::Font font;
	sf::Text text;
	sf::Text endText;
	void initFont();
	void initText();

	void initWindow();
	void initVariables();
public:
	// Construtures e destrutores
	Game();
	~Game();

	// Accessors
	const bool& getEndGame() const;
	// Modifiers

	// Funcs
	const bool running() const;

	const int randomizeType() const;
	void spawBalls();
	void updatePlayer();
	void updateCollision();
	
	void pollEvents();

	void updateText();
	void update();

	void renderText(sf::RenderTarget* target);
	void render();
};

