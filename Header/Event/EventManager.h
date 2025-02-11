#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

namespace Events {
	class EventManager {
	public :
		void PollEvent(RenderWindow* gameWindow);
		bool IsKeyPressed(Keyboard::Key key);
	};
}