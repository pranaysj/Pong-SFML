#include <../../Header/Gameplay/Boundary/Boundary.h>

namespace Gameplay {
	Boundary::Boundary()
	{
		CreateTopBoundary();
		CreateLeftBoundary();
		CreateBottomBoundary();
		CreateRightBoundary();
		CreateCenterLine();
	}

	void Boundary::CreateTopBoundary()
	{
		topBoundary.setSize(Vector2f(horizontalBoundaryWidth, horizontalBoundaryHeight));
		topBoundary.setPosition(Vector2f(topPositionX, topPositionY));
		topBoundary.setFillColor(boundaryColor);
	}

	void Boundary::CreateBottomBoundary()
	{
		bottomBoundary.setSize(Vector2f(horizontalBoundaryWidth, horizontalBoundaryHeight));
		bottomBoundary.setPosition(Vector2f(bottomPositionX, bottomPositionY));
		bottomBoundary.setFillColor(boundaryColor);
	}

	void Boundary::CreateLeftBoundary()
	{
		leftBoundary.setSize(Vector2f(verticalBoundaryWidth, verticalBoundaryHeight));
		leftBoundary.setPosition(Vector2f(leftPositionX, leftPositionY));
		leftBoundary.setFillColor(boundaryColor);
	}

	void Boundary::CreateRightBoundary()
	{
		rightBoundary.setSize(Vector2f(verticalBoundaryWidth, verticalBoundaryHeight));
		rightBoundary.setPosition(Vector2f(rightPositionX, rightPositionY));
		rightBoundary.setFillColor(boundaryColor);
	}

	void Boundary::CreateCenterLine()
	{
		centerLine.setSize(Vector2f(centerLineWidth, centerLineHeight));
		centerLine.setPosition(Vector2f(centerLinePositionX, centerLinePositionY));
		centerLine.setFillColor(centerLineColor);
	}


	void Boundary::Update()
	{
	}

	void Boundary::Render(RenderWindow* game_window)
	{
		game_window->draw(topBoundary);
		game_window->draw(leftBoundary);
		game_window->draw(bottomBoundary);
		game_window->draw(rightBoundary);
		game_window->draw(centerLine);
	}

}
