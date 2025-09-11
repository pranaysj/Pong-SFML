#include <iostream>
#include<../../Header/Event/EventManager.h>

using namespace sf;

namespace Events {
	void EventManager::PollEvent(RenderWindow* gameWindow)
	{
		sf::Event event;

		while (gameWindow->pollEvent(event)) {

			if (event.type == sf::Event::Closed()) {
				gameWindow->close();
			}

			if (IsKeyPressed(Keyboard::Escape)) {
				gameWindow->close();
			}

			if (IsLeftMouseButtonClicked()) {
				Vector2i position = Mouse::getPosition();
				std::cout << "position " << position.x << " : " << position.y << std::endl;

			}
		}
	}

	bool EventManager::IsKeyPressed(Keyboard::Key key)
	{
		return Keyboard::isKeyPressed(key);
	}

	bool EventManager::IsLeftMouseButtonClicked()
	{
		return Mouse::isButtonPressed(Mouse::Left);
	}
}