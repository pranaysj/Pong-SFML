#include "../../Header/Core/GameLoop.h"

using namespace Events;

namespace Core {
	void GameLoop::Initialize()
	{
		gameWindowManager = new GameWindowManager();
		eventManger = new EventManager();

		gameWindowManager->Initialize();
	}

	bool GameLoop::IsGameRunning()
	{
		return gameWindowManager->IsGameRunning();
	}

	void GameLoop::PollEvent()
	{
		eventManger->PollEvent(gameWindowManager->GetGameWindow());
	}

	void GameLoop::Update()
	{
	}

	void GameLoop::Render()
	{
		gameWindowManager->ClearGameWindow();
		//Draw
		gameWindowManager->DisplayGameWindow();
	}
}

