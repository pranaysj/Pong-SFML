#include <../../Header/Gameplay/Ball/Ball.h>

namespace GamePlay
{
	
	Ball::Ball()
	{
		LoadTexture();
		InitializeVariable();
	}

	void Ball::LoadTexture()
	{
		if (!ballTexture.loadFromFile(ballTexturePath)) {
			throw std::runtime_error("Failed to load ball texture!");
		}
	}

	void Ball::InitializeVariable()
	{
		ballSprite.setTexture(ballTexture);
		ballSprite.setScale(scaleX, scaleY);
		ballSprite.setPosition(positonX, positionY);
	}

	void Ball::MoveBall()
	{
		ballSprite.move(velocity);
	}

	void Ball::Update()
	{
		MoveBall();
	}

	void Ball::Render(sf::RenderWindow* gameWindow)
	{
		gameWindow->draw(ballSprite);
	}
}
