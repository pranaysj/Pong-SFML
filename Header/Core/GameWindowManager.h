#pragma once
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

namespace Core {
	class GameWindowManager {

	private:
		int gameWidth = 150;
		int gameHeight = 150;
		std::string gameTitle = "PONG SFML";

		RenderWindow* gameWindow;

		void CreateGameWindow();

	public:
		void Initialize();
		RenderWindow* GetGameWindow();
		bool IsGameRunning();
		void Render();
	};
}