#include<../../Header/Gameplay/GamePlayManager.h>

namespace GamePlay {
	
	GameplayManager::GameplayManager(Events::EventManager* eventManager) {

		this->eventManager = eventManager;
		Initialize();
	}

	void GameplayManager::UpdateScore()
	{
		if (ball->IsLeftCollsionOccured()) {
			uiService->IncrementPlayer2Score();
			ball->UpdateLeftCollsionState(false);
			ResetPlayer();
		}

		if (ball->IsRightCollsionOccured()) {
			uiService->IncrementPlayer1Score();
			ball->UpdateRightCollsionState(false);
			ResetPlayer();
		}
	}

	void GameplayManager::ResetPlayer()
	{
		paddle1->Reset(paddle1PositionX, paddle1PositionY);
		paddle2->Reset(paddle2PostionX, paddle2PostionY);
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

		UpdateScore();
		uiService->Update();
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