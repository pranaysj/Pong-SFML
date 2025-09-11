#include <../../Header/Core/GameWindowManager.h>
#include <../../Header/Event/EventManager.h>

int main()
{
	Core::GameWindowManager gameWindowManager;
	Events::EventManager eventManager;

    gameWindowManager.Initialize();

	while (gameWindowManager.IsGameRunning())
	{
		eventManager.PollEvent(gameWindowManager.GetGameWindow());
		gameWindowManager.Render();
	}

	return 0;
}