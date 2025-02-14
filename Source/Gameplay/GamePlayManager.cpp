#include<../../Header/Gameplay/GamePlayManager.h>

namespace GamePlay {
	
	GameplayManager::GameplayManager(Events::EventManager* eventManager) {

		this->eventManager = eventManager;
		Initialize();
	}

	void GameplayManager::Initialize()
	{
		timeService = new Utility::TimeService();
		timeService->Initialize();
		uiService = new UI::UIService();

		ball = new Ball();
		paddle1 = new Paddle(paddle1PositionX, paddle1PositionY);
		paddle2 = new Paddle(paddle2PostionX, paddle2PostionY);
		boundary = new Gameplay::Boundary(); //WHY?
		
	}

	void GameplayManager::Update()
	{
		timeService->Update();

		ball->Update(paddle1, paddle2, timeService);
		paddle1->Update(eventManager->IsKeyPressed(Keyboard::W), eventManager->IsKeyPressed(Keyboard::S), timeService);
		paddle2->Update(eventManager->IsKeyPressed(Keyboard::Up), eventManager->IsKeyPressed(Keyboard::Down), timeService);
	}

	void GameplayManager::Render(sf::RenderWindow* gameWindow)
	{
		boundary->Render(gameWindow);
		ball->Render(gameWindow);
		paddle1->Render(gameWindow);
		paddle2->Render(gameWindow);
		uiService->Render(gameWindow);
	}
}