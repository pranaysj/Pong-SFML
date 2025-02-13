#pragma once
#include <SFML/Graphics.hpp>
#include<../../Header/Utility/TimeService.h>

namespace GamePlay {
	class Paddle {
	private :
		sf::RectangleShape paddleSprite;
		const float paddleWidth = 20.0f;
		const float paddleHeight = 140.0f;

		float paddleSpeed = 10.0f;
		float topBoundary = 20.0f;
		float bottomBoundary = 700.0f;
		float speedMultiplier = 20.0f;

		void CreatePaddle(float positionX, float positionY);
		void MovePaddle(bool moveUpKeyPressed, bool moveDownKeyPressed, Utility::TimeService* timeServices);

	public :

		Paddle(float positionX, float positionY);

		sf::RectangleShape GetPaddleSprite();
		void Reset(float positionX, float positionY);

		void Update(bool moveUpKeyPressed, bool moveDownKeyPressed, Utility::TimeService* timeServices);
		void Render(sf::RenderWindow* gameWindow);
	};
}