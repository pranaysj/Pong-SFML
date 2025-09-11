#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

namespace Gameplay
{
	class Boundary {
	private:
		RectangleShape topBoundary;
		RectangleShape bottomBoundary;
		RectangleShape leftBoundary;
		RectangleShape rightBoundary;
		RectangleShape centerLine;

		const float horizontalBoundaryWidth = 1280.0f;
		const float horizontalBoundaryHeight = 20.0f;
	   
		const float topPositionX = 0.0f;
		const float topPositionY = 0.0f;

		const float bottomPositionX = 0.0f;
		const float bottomPositionY = 700.0f;

		const float verticalBoundaryWidth = 20.0f;
		const float verticalBoundaryHeight = 720.0f;

		const float leftPositionX = 0.0f;
		const float leftPositionY = 0.0f;

		const float rightPositionX = 1260.0f;
		const float rightPositionY = 0.0f;

		const float centerLineWidth = 10.0f;
		const float centerLineHeight = 680.0f;

		const float centerLinePositionX = 640.0f;
		const float centerLinePositionY = 20.0f;

		const Color boundaryColor = Color::Blue;
		const Color centerLineColor = Color::White;

		void CreateTopBoundary();
		void CreateBottomBoundary();
		void CreateLeftBoundary();
		void CreateRightBoundary();

		void CreateCenterLine();

	public:
		Boundary();

		void Update();
		void Render(RenderWindow* game_window);
	};
}