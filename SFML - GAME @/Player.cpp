#include "Player.h"

void Player::initVariables()
{
	speedMove = 10.f;
}

void Player::initShape()
{
	shape.setFillColor(sf::Color::Yellow);
	shape.setSize(sf::Vector2f(100.f, 100.f));
}

Player::Player(float x, float y)
{
	shape.setPosition(x, y);

	initVariables();
	initShape();
}

Player::~Player()
{
}

void Player::updateInput()
{
	//window  bounds collision

	// keybord input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		shape.move(-speedMove, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		shape.move(speedMove,0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		shape.move(0.f, -speedMove);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		shape.move(0.f, speedMove);
	}

	
}

void Player::updateWindowBounce(const sf::RenderTarget* target)
{
	sf::FloatRect playerBounds = shape.getGlobalBounds();

	if (playerBounds.left <= 0.f)
		shape.setPosition(0.f, shape.getPosition().y);
	

	else if (playerBounds.left + playerBounds.width>= target->getSize().x)
		shape.setPosition(target->getSize().x - playerBounds.width, playerBounds.top);


	if (playerBounds.top <= 0.f)
		 shape.setPosition(shape.getPosition().x, 0.f);
	
	else if (playerBounds.top + playerBounds.height >= target->getSize().y)
		 shape.setPosition(shape.getPosition().x, target->getSize().y - playerBounds.height);
		

}

void Player::update(const sf::RenderTarget* target)
{	
	updateInput();
	updateWindowBounce(target);
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(shape);
}
