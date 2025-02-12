#include<../../Header/Gameplay/GamePlayManager.h>

namespace GamePlay {
	
	GameplayManager::GameplayManager(Events::EventManager* eventManager) {

		this->eventManager = eventManager;
		Initialize();
	}

	void GameplayManager::Initialize()
	{
		ball = new Ball();
		paddle1 = new Paddle(paddle1PositionX, paddle1PositionY);
		paddle2 = new Paddle(paddle2PostionX, paddle2PostionY);
		boundary = new Gameplay::Boundary(); //WHY?
		
	}

	void GameplayManager::Update()
	{
		ball->Update();
		paddle1->Update(eventManager->IsKeyPressed(Keyboard::W), eventManager->IsKeyPressed(Keyboard::S));
		paddle2->Update(eventManager->IsKeyPressed(Keyboard::Up), eventManager->IsKeyPressed(Keyboard::Down));
	}

	void GameplayManager::Render(sf::RenderWindow* gameWindow)
	{
		boundary->Render(gameWindow);
		ball->Render(gameWindow);
		paddle1->Render(gameWindow);
		paddle2->Render(gameWindow);
	}
}