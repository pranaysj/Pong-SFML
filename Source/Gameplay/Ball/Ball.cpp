#include <../../Header/Gameplay/Ball/Ball.h>

namespace GamePlay
{
	Ball::Ball()
	{
		ballSprite.setRadius(radius);
		ballSprite.setPosition(positonX, positionY);
	}

	void Ball::Update()
	{

	}

	void Ball::Render(sf::RenderWindow* gameWindow)
	{
		gameWindow->draw(ballSprite);
	}
}
