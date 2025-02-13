#pragma once
#include <chrono>

namespace Utility {
	class TimeService {
	private :
		std::chrono::steady_clock::time_point previousTime;
		float deltaTime;
		float microsecond = 0.000001;

		float CalculateDeltaTime();
		void UpdateDeltaTime();
		void UpdatePreviousTime();

	public:
		void Initialize();
		void Update();
		float GetDeltaTime();
	};
}