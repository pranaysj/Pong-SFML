#pragma once
#include <chrono>

namespace Utility {
	class TimeService {
	private :
		std::chrono::steady_clock::time_point previousTime;
		float deltaTime;

		void CalculateDeltaTime();
		void UpdateDeltaTime();
		void UpdatePreviousTime();

	public:
		void Initialize();
		void Update();
		void GetDeltaTime();
	};
}