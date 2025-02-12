#pragma once
#include <SFML/Graphics.hpp>

namespace GamePlay {
	class Paddle {
	private :
		sf::RectangleShape paddleSprite;
		const float paddleWidth = 20.0f;
		const float paddleHeight = 140.0f;

		const float paddleSpeed = 0.04f;

		void MovePaddle(bool moveUpKeyPressed, bool moveDownKeyPressed);

	public :

		Paddle(float positionX, float positionY);
		void Update(bool moveUpKeyPressed, bool moveDownKeyPressed);
		void Render(sf::RenderWindow* gameWindow);
	};
}