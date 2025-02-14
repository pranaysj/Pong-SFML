#include "../../Header/Core/GameLoop.h"

using namespace Events;
using namespace GamePlay;
using namespace Sounds;

namespace Core {
	void GameLoop::Initialize()
	{
		gameWindowManager = new GameWindowManager();
		eventManger = new EventManager();
		gamePlayManager = new GameplayManager(eventManger);
		soundManager = new SoundManager();

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
		gamePlayManager->Update();
	}

	void GameLoop::Render()
	{
		gameWindowManager->ClearGameWindow();
		gamePlayManager->Render(gameWindowManager->GetGameWindow());
		gameWindowManager->DisplayGameWindow();
	}
}

