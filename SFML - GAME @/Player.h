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

	int hp;
	int hpMax;
	float speedMove;
	
	void initVariables();
	void initShape();

public:
	Player(float x = 0, float y = 0);
	virtual ~Player();
	
	// Accessors
	const sf::RectangleShape & getShape() const;
	const int& getHp() const;
	const int& getHpMax() const;

	/*
		Just a quick test
	float xScale;
	float yScale;
	float maxScale;

	void gainPoints();
	*/

	// funcs
	void takeDamage(const int damage);
	void getHealth(const int health);

	void updateInput();
	void updateWindowBounce(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);
	
	void render(sf::RenderTarget* target);
};

