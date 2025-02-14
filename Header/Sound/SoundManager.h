#pragma once
#include <SFML/Audio.hpp>

namespace Sounds {
	enum class SoundType {
		BALL_BOUNCE
	};

	class SoundManager {
	private:
		static sf::SoundBuffer ballBounce;
		static sf::Sound soundEffect;

		static const std::string ballBouncePath;

		void Initialize();
		static void LoadSoundFromFile();

	public:
		SoundManager();
		~SoundManager();

		static void PlaySoundEffect(SoundType soundType);
	};
}