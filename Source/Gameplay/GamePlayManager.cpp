#include<../../Header/Gameplay/GamePlayManager.h>

namespace GamePlay {
	GamePlayManager::GamePlayManager() {
		ball = new Ball();
		paddle1 = new Paddle(paddle1PositionX, paddle1PositionY);
		paddle2 = new Paddle(paddle2PostionX, paddle2PostionY);
	}

	void GamePlayManager::Update()
	{
		ball->Update();
		paddle1->Update();
		paddle2->Update();
	}

	void GamePlayManager::Render(sf::RenderWindow* gameWindow)
	{
		ball->Render(gameWindow);
		paddle1->Render(gameWindow);
		paddle2->Render(gameWindow);
	}
}