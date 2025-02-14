#pragma once
#include <SFML/Graphics.hpp>
//#include <string.h>

namespace UI {
	class UIService {
	private :
		sf::Font font;
		sf::Text leftScoreText;
		sf::Text rightScoreText;

		std::string texturePath = "Assets/Fonts/Aloevera-OVoWO.ttf";

		int fontSize = 40;
		sf::Color fontColour = sf::Color::White;
		std::string initialValue = "00";

		float leftScorePositionX = 570.0f;
		float leftScorePositionY = 30.0f;

		float rightScorePositionX = 670.0f;
		float rightScorePositionY = 30.0f;

		int player1Score = 0;
		int player2Score = 0;

		void LoadFontTexture();
		void CreateLeftScoreText();
		void CreateRightScoreText();

	public:
		UIService();
		void Update();
		void Render(sf::RenderWindow* gameWindow);
	};
}