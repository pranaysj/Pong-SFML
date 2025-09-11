#include<../../Header/Utility/TimeService.h>

namespace Utility {
	void TimeService::Initialize()
	{
		previousTime = std::chrono::steady_clock::now();
		deltaTime = 0;
	}

	float TimeService::CalculateDeltaTime()
	{
		int deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - previousTime).count();
		return static_cast<float>(deltaTime) * microsecond;
	}

	void TimeService::UpdateDeltaTime()
	{
		deltaTime = CalculateDeltaTime();
		UpdatePreviousTime();
	}

	void TimeService::UpdatePreviousTime()
	{
		previousTime = std::chrono::steady_clock::now();
	}

	void TimeService::Update()
	{
		UpdateDeltaTime();
	}

	float TimeService::GetDeltaTime()
	{
		return deltaTime;
	}
}