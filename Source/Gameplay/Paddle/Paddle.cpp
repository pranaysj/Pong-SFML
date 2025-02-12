#include <../../Header/Gameplay/Paddle/Paddle.h>

namespace GamePlay
{
	Paddle::Paddle(float positionX, float positionY)
	{
		paddleSprite.setPosition(positionX, positionY);
		paddleSprite.setSize(sf::Vector2f(paddleWidth, paddleHeight));
	}

	void Paddle::MovePaddle(bool moveUpKeyPressed, bool moveDownKeyPressed)
	{
		if (moveUpKeyPressed) {
			paddleSprite.move(0, -paddleSpeed);
		}
		else if (moveDownKeyPressed) {
			paddleSprite.move(0, paddleSpeed);
		}
	}

	void Paddle::Update(bool moveUpKeyPressed, bool moveDownKeyPressed)
	{
		MovePaddle(moveUpKeyPressed, moveDownKeyPressed);
	}

	void Paddle::Render(sf::RenderWindow* gameWindow)
	{
		gameWindow->draw(paddleSprite);
	}
}
