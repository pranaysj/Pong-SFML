#include "../../Header/Core/GameWindowManager.h"

using namespace sf;

namespace Core {
	void GameWindowManager::Initialize()
	{
		gameWindow = new RenderWindow();
		CreateGameWindow();
	}

	void GameWindowManager::CreateGameWindow()
	{
		gameWindow->create(VideoMode(gameWidth, gameHeight), gameTitle);
	}

	RenderWindow* GameWindowManager::GetGameWindow()
	{
		return gameWindow;
	}

	bool GameWindowManager::IsGameRunning()
	{
		return gameWindow->isOpen();
	}

	void GameWindowManager::Render()
	{
		//Draw the shap
	}
}

