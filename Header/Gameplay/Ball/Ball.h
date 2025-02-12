#pragma once
#include <SFML/Graphics.hpp>
#include<../../Header/Gameplay/Paddle/Paddle.h>
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

		float ballSpeed = 0.06f;
		sf::Vector2f velocity;

		const float topBoundary = 20.0f;
		const float bottomBoundary = 700.0f;
		const float leftBoundary = 20.0f;
		const float rightBoundary = 1260.0f;

		const float centerPositionX = 615.0f;
		const float centerPositionY = 325.0f;

		void LoadTexture();
		void InitializeVariable();
		void MoveBall();
		void Reset();

	public:
		Ball();

		void HandlePaddleCollision(Paddle* player1, Paddle* player2);
		void HandleBoundaryCollision();
		void HandleOutofBoundCollision();

		void OnCollision(Paddle* player1, Paddle* player2);
		void Update(Paddle* player1, Paddle* player2);
		void Render(sf::RenderWindow* gameWindow);
	};
}