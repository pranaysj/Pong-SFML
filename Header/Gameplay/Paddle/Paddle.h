#pragma once
#include <SFML/Graphics.hpp>

namespace GamePlay {
	class Paddle {
	private :
		sf::RectangleShape paddleSprite;
		const float paddleWidth = 20.0f;
		const float paddleHeight = 140.0f;

	public :
		Paddle(float positionX, float positionY);
		void Update();
		void Render(sf::RenderWindow* gameWindow);
	};
}