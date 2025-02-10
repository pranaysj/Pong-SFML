#include <../../Header/Core/GameWindowManager.h>

int main()
{
	Core::GameWindowManager gameWindowManager;

    gameWindowManager.Initialize();

	while (gameWindowManager.IsGameRunning())
	{
		gameWindowManager.Render();
	}

	return 0;
}