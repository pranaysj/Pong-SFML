#pragma once
#include <SFML/Graphics.hpp>
#include<../../Header/Gameplay/Paddle/Paddle.h>
#include<../../Header/Sound/SoundManager.h>


namespace GamePlay {
	enum class BallState {
		Idle,
		Moving
	};

	class Ball {
	private:

		sf::Texture ballTexture;
		sf::Sprite ballSprite;

		const std::string ballTexturePath = "Assets/Textures/Ball.png";

		const float scaleX = 0.03f;
		const float scaleY = 0.03f;

		const float positonX = 625.0f;
		const float positionY = 335.0f;

		float ballSpeed = 10.0f;
		sf::Vector2f velocity;
		float speedMultiplier = 40.0f;

		const float topBoundary = 20.0f;
		const float bottomBoundary = 700.0f;
		const float leftBoundary = 20.0f;
		const float rightBoundary = 1260.0f;

		const float centerPositionX = 615.0f;
		const float centerPositionY = 325.0f;

		float delayDuration = 2.0f;
		float elapsedDelayTime = 0.0f;

		bool hadLeftCollison = false;
		bool hadRightCollison = false;

		BallState currentState;

		void UpdateDelayTime(float deltaTime);

		void LoadTexture();
		void InitializeVariable();
		void MoveBall(Utility::TimeService* timeServices);
		void Reset();

	public:
		Ball();

		void HandlePaddleCollision(Paddle* player1, Paddle* player2);
		void HandleBoundaryCollision();
		void HandleOutofBoundCollision();

		bool IsLeftCollsionOccured();
		void UpdateLeftCollsionState(bool value);
		
		bool IsRightCollsionOccured();
		void UpdateRightCollsionState(bool value);

		void OnCollision(Paddle* player1, Paddle* player2);
		void Update(Paddle* player1, Paddle* player2, Utility::TimeService* timeServices);
		void Render(sf::RenderWindow* gameWindow);
	};
}