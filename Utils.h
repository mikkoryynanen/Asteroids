#pragma once

#include <SDL.h>

namespace Utils
{
	inline float HireTimeInSeconds()
	{
		float t = SDL_GetTicks();
		t *= 0.001f;
		return t;
	}
}

