#include "Game.h"

void Game::initFont()
{
	font.loadFromFile("Fonts/Gerlick.otf");
}

void Game::initText()
{
	text.setFont(font);
	text.setCharacterSize(24);

	endText.setFont(font);
	endText.setCharacterSize(50);
	endText.setPosition(200.f, 200.f);
	endText.setString("GAME OVER!");

}

void Game::initWindow()
{
	points = 0;

	videoMode = sf::VideoMode(800,600);
	window = new sf::RenderWindow(videoMode, "Game 2",sf::Style::Close | sf::Style::Titlebar);
	window->setFramerateLimit(60);
}

void Game::initVariables()
{
	spawTimerMax = 10.f;
	spawnTimer = spawTimerMax;
	maxBalls = 10;
	endGame = false;
}

// Construtores e destrutores
Game::Game()
{
	initFont();
	initText();
	initVariables();
	initWindow();
}
Game::~Game()
{
	delete window;
}

const bool& Game::getEndGame() const
{
	return endGame;
}

// Funcs
void Game::updateText()
{
	std::stringstream ss;

	ss << "Points: " << points << "\n" << "Health: " << player.getHp() << " / " << player.getHpMax();
	text.setString(ss.str());
}

void Game::update()
{
	pollEvents();

	if (endGame == false)
	{
		spawBalls();
		updatePlayer();
		updateCollision();
		updateText();
	}
}
void Game::renderText(sf::RenderTarget* target)
{
	target->draw(text);
}
void Game::render()
{
	window->clear();
	
	// Render (drawing)
	player.render(window);
	
	for (Balls ball : BallsVector)
	{
		ball.render(window);
	}

	renderText(window);

	if (endGame)
	{
		window->clear();
		window->draw(endText);
	}

	window->display();
}
const bool Game::running() const
{
	return window->isOpen();
}
const int Game::randomizeType() const
{
	int type = BallsTypes::DEFAULT;
	int randValue = rand() % 100 + 1;
	if (randValue > 60 && randValue <= 80)
	{
		type = BallsTypes::DAMAGING;
	}
	else if (randValue > 80 && randValue <= 100)
	{
		type = BallsTypes::HEALING;
	}
	return type;
}
void Game::spawBalls()
{
	if (spawnTimer < spawTimerMax)
	{
		spawnTimer+=1.f;
	}
	else
	{
		if (BallsVector.size() < maxBalls)
		{
			spawnTimer = 0.f;
		
			BallsVector.push_back(Balls(*window, randomizeType()));
		}
	}
}
void Game::updatePlayer()
{
	player.update(window);

	if (player.getHp() <= 0)
		endGame = true;
}
void Game::updateCollision()
{
	// Check collision
	for (size_t i = 0; i < BallsVector.size(); i++)
	{
		if (player.getShape().getGlobalBounds().intersects(BallsVector[i].getshape().getGlobalBounds()))
		{
			switch (BallsVector[i].getType())
			{
			case BallsTypes::DEFAULT:
				points++;
				break;
			case BallsTypes::DAMAGING:
				player.takeDamage(10);
				break;
			case BallsTypes::HEALING:
				player.getHealth(1);
				break;
			}
			
			
			
			BallsVector.erase(BallsVector.begin() + i);
			
			// player.gainPoints();
		}
	}
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