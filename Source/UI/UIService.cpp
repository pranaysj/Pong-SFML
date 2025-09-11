#include <../../Header/UI/UIService.h>

namespace UI {
	UIService::UIService()
	{
		LoadFontTexture();
		CreateLeftScoreText();
		CreateRightScoreText();
	}

	void UIService::LoadFontTexture()
	{
		font.loadFromFile(texturePath);
	}

	void UIService::CreateLeftScoreText()
	{
		leftScoreText.setFont(font);
		leftScoreText.setString(initialValue);
		leftScoreText.setCharacterSize(fontSize);
		leftScoreText.setFillColor(fontColour);
		leftScoreText.setPosition(leftScorePositionX, leftScorePositionY);
	}
	void UIService::CreateRightScoreText()
	{
		rightScoreText.setFont(font);
		rightScoreText.setString(initialValue);
		rightScoreText.setCharacterSize(fontSize);
		rightScoreText.setFillColor(fontColour);
		rightScoreText.setPosition(rightScorePositionX, rightScorePositionY);
	}

	void UIService::IncrementPlayer1Score()
	{
		player1Score++;
	}

	void UIService::IncrementPlayer2Score()
	{
		player2Score++;
	}


	std::string UIService::FromatScore(int score)
	{
		return (score < 10 ? "0" : "") + std::to_string(score);
	}

	void UIService::Update()
	{
		leftScoreText.setString(FromatScore(player1Score));
		rightScoreText.setString(FromatScore(player2Score));
	}

	void UIService::Render(sf::RenderWindow* gameWindow)
	{
		gameWindow->draw(leftScoreText);
		gameWindow->draw(rightScoreText);
	}

}

