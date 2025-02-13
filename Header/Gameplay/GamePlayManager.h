#pragma once
#include<../../Header/Gameplay/Ball/Ball.h>
#include<../../Header/Gameplay/Paddle/Paddle.h>
#include<../../Header/Gameplay/Boundary/Boundary.h>
#include <../../Header/Event/EventManager.h>
#include <../../Header//Utility/TimeService.h>

namespace GamePlay {
	class GameplayManager {
	private :

		Events::EventManager* eventManager;
		Utility::TimeService* timeService;

		float paddle1PositionX = 40.0f;
		float paddle1PositionY = 300.0f;

		float paddle2PostionX = 1210.0f;
		float paddle2PostionY = 300.0f;

		Ball* ball;
		Paddle* paddle1;
		Paddle* paddle2;
		Gameplay::Boundary* boundary;

		void Initialize();

	public :
		GameplayManager(Events::EventManager* eventManager);
		void Update();
		void Render(sf::RenderWindow* gameWindow);
	};
}