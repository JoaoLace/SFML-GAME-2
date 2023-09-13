#include "Balls.h"

void Balls::initShape(const sf::RenderWindow& window)
{
	shape.setRadius(static_cast<float>(rand() % 10 + 10));
	sf::Color color;
	switch (type)
	{
	case DEFAULT:
		color = sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
		break;
	case DAMAGING:
		color = sf::Color::Red;
		shape.setOutlineColor(sf::Color::White);
		shape.setOutlineThickness(2.f);
		break;
	case HEALING:
		color = sf::Color::Green;
		shape.setOutlineColor(sf::Color::White);
		shape.setOutlineThickness(2.f);
		break;
	}


	shape.setFillColor(color);
	shape.setPosition
	(
		sf::Vector2f(static_cast<float>(rand() % window.getSize().x - shape.getGlobalBounds().width),
			         static_cast<float>(rand() % window.getSize().y) - shape.getGlobalBounds().height)
	);
}

const sf::CircleShape Balls::getshape() const
{
	return shape;
}

const int& Balls::getType() const
{
	return type;
}

Balls::Balls(const sf::RenderWindow& window, int type)
	: type(type)
{
	initShape(window);
}

void Balls::update()
{
}

void Balls::render(sf::RenderTarget* target)
{
	target->draw(shape);
}

Balls::~Balls()
{
}
