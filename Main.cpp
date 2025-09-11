#include <../../Header/Core/GameLoop.h>

int main()
{
	Core::GameLoop* gameLoop = new Core::GameLoop();

    gameLoop->Initialize();

	while (gameLoop->IsGameRunning())
	{
		gameLoop->PollEvent();
		gameLoop->Update();
		gameLoop->Render();
	}

	return 0;
}