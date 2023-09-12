#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
class Player
{
private:
	sf::RectangleShape shape;

	void initVariables();
	void initShape();
public:

	// in game vars
	float speedMove;
	Player(float x = 0, float y = 0);
	virtual ~Player();
	void updateInput();
	void updateWindowBounce(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};

