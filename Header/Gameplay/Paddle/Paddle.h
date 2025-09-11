#pragma once
#include <SFML/Graphics.hpp>

namespace GamePlay {
	class Paddle {
	private :
		sf::RectangleShape paddleSprite;
		const float paddleWidth = 20.0f;
		const float paddleHeight = 140.0f;

		float paddleSpeed = 0.05f;
		float topBoundary = 20.0f;
		float bottomBoundary = 700.0f;

		void CreatePaddle(float positionX, float positionY);
		void MovePaddle(bool moveUpKeyPressed, bool moveDownKeyPressed);

	public :

		Paddle(float positionX, float positionY);

		sf::RectangleShape GetPaddleSprite();
		void Reset(float positionX, float positionY);

		void Update(bool moveUpKeyPressed, bool moveDownKeyPressed);
		void Render(sf::RenderWindow* gameWindow);
	};
}