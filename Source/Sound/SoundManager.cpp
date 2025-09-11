#include <../../Header/Sound/SoundManager.h>
#include <iostream>

namespace Sounds {
	
	sf::Sound SoundManager::soundEffect;
	sf::SoundBuffer SoundManager::ballBounce;
	sf::Music SoundManager::backgroundMusic;

	const std::string SoundManager::ballBouncePath = "Assets/Sounds/Ball_Bounce.wav";
	const std::string SoundManager::bgmPath = "Assets/Sounds/Pong_BGM.mp3";

	float SoundManager::backgroundMusicVolume = 30.0f;

	SoundManager::SoundManager()
	{
		Initialize();
	}

	SoundManager::~SoundManager()
	{
	}

	void SoundManager::Initialize()
	{
		LoadSoundFromFile();
	}

	void SoundManager::LoadSoundFromFile()
	{
		if (!ballBounce.loadFromFile(ballBouncePath)) {
			std::cerr << "Error loading sound file: " << ballBouncePath << std::endl;
		}
		if (!backgroundMusic.openFromFile(bgmPath))
		{
			std::cerr << "Error loading background music file: " << bgmPath << std::endl;
		}

	}

	void SoundManager::PlaySoundEffect(SoundType soundType)
	{
		switch (soundType)
		{
		case Sounds::SoundType::BALL_BOUNCE:
			soundEffect.setBuffer(ballBounce);
			break;
		default:
			std::cerr << "Invalid sound type" << std::endl;
			break;
		}

		soundEffect.play();
	}

	void SoundManager::PlayBackgroundMusic()
	{
		backgroundMusic.setVolume(backgroundMusicVolume);
		backgroundMusic.setLoop(true);
		backgroundMusic.play();
	}
}

