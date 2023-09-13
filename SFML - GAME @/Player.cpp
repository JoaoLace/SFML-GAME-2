#include "Player.h"

void Player::initVariables()
{
	// maxScale = 1.5f;
	// yScale = 1.f;
	// xScale = 1.f;
	
	speedMove = 7.f;
	hpMax = 10;
	hp = hpMax;
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

// acessors
const sf::RectangleShape & Player::getShape() const
{
	return shape;
}

const int& Player::getHp() const
{
	return hp;
}

const int& Player::getHpMax() const
{
	return hpMax;
}

/*
	Just a quick test 

void Player::gainPoints()
{
	xScale += 0.1f;
	yScale += 0.1f;
	if (xScale > maxScale)
	{
		xScale = maxScale;
		yScale = maxScale;
	}
	points++;
	shape.setScale( xScale, yScale);
}
*/

void Player::takeDamage(const int damage)
{
	if (hp > 0)
		hp -= damage;
	if (hp < 0)
		hp = 0;
}

void Player::getHealth(const int health)
{
	if (hp < hpMax)
		hp += health;
	if (hp > hpMax)
		hp = hpMax;
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
