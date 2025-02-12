#pragma once
#include <SFML/Graphics.hpp>

namespace GamePlay {
	class Ball {
	private:
		sf::CircleShape ballSprite;
		const float radius = 10.0f;
		const float positonX = 615.0f;
		const float positionY = 335.0f;

	public:
		Ball();
		void Update();
		void Render(sf::RenderWindow* gameWindow);
	};
}