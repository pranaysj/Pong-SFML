#pragma once
#include <SFML/Audio.hpp>

namespace Sounds {
	enum class SoundType {
		BALL_BOUNCE
	};

	class SoundManager {
	private:

		static sf::Sound soundEffect;
		static sf::SoundBuffer ballBounce;
		static sf::Music backgroundMusic;

		static const std::string ballBouncePath;
		static const std::string bgmPath;
		static float backgroundMusicVolume;

		void Initialize();
		static void LoadSoundFromFile();

	public:
		SoundManager();
		~SoundManager();

		static void PlaySoundEffect(SoundType soundType);
		static void PlayBackgroundMusic();
	};
}