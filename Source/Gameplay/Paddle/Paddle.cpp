#include <../../Header/Gameplay/Paddle/Paddle.h>

namespace GamePlay
{
	Paddle::Paddle(float positionX, float positionY)
	{
		paddleSprite.setPosition(positionX, positionY);
		paddleSprite.setSize(sf::Vector2f(paddleWidth, paddleHeight));
	}

	void Paddle::Update()
	{

	}

	void Paddle::Render(sf::RenderWindow* gameWindow)
	{
		gameWindow->draw(paddleSprite);
	}
}
