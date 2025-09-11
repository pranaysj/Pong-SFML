#pragma once
#include<../../Header/Gameplay/Ball/Ball.h>
#include<../../Header/Gameplay/Paddle/Paddle.h>

namespace GamePlay {
	class GamePlayManager {
	private :
		float paddle1PositionX = 40.0f;
		float paddle1PositionY = 300.0f;

		float paddle2PostionX = 1210.0f;
		float paddle2PostionY = 300.0f;

		Ball* ball;
		Paddle* paddle1;
		Paddle* paddle2;


	public :
		GamePlayManager();
		void Update();
		void Render(sf::RenderWindow* gameWindow);
	};
}