#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

enum BallsTypes {DEFAULT, DAMAGING, HEALING, NROFTYPES};

class Balls
{
private:
	sf::CircleShape shape;
	int type;

	void initShape(const sf::RenderWindow& window);
public:
	const sf::CircleShape getshape() const;

	const int& getType() const;

	Balls(const sf::RenderWindow& window, int type);
	void update();
	void render(sf::RenderTarget* target);
	virtual ~Balls();
};

