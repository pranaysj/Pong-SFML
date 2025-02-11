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
		}
	}

	bool EventManager::IsKeyPressed(Keyboard::Key key)
	{
		return Keyboard::isKeyPressed(key);
	}
}