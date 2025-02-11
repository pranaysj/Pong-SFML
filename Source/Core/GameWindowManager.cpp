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
		gameWindow->create(VideoMode::getDesktopMode(), gameTitle, Style::Fullscreen);
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
		gameWindow->clear(Color(0,0,0,255));

		//Draw

		gameWindow->display();
	}
}

