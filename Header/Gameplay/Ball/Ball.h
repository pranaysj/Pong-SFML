#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace GamePlay {
	class Ball {
	private:

		sf::Texture ballTexture;
		sf::Sprite ballSprite;

		const std::string ballTexturePath = "Assets/Textures/Ball.png";

		const float scaleX = 0.03f;
		const float scaleY = 0.03f;

		const float positonX = 615.0f;
		const float positionY = 335.0f;

	public:
		Ball();
		void LoadTexture();
		void InitializeVariable();
		void Update();
		void Render(sf::RenderWindow* gameWindow);
	};
}