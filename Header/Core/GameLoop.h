#pragma once
#include<../../Header/Core/GameWindowManager.h>
#include<../../Header/Event/EventManager.h>
#include<../../Header/Gameplay/GamePlayManager.h>
#include<../../Header/Sound/SoundManager.h>

namespace Core {
	class GameLoop {
	private :
		Core::GameWindowManager* gameWindowManager;
		Events::EventManager* eventManger;
		GamePlay::GameplayManager* gamePlayManager;
		Sounds::SoundManager* soundManager;

	public :
		void Initialize();
		bool IsGameRunning();
		void PollEvent();
		void Update();
		void Render();
	};
}