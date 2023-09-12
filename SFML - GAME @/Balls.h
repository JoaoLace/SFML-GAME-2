#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
class Balls
{
private:
	sf::CircleShape shape;

	void initShape();
public:
	Balls();
	void update();
	void render(sf::RenderTarget* target);
	virtual ~Balls();
};

