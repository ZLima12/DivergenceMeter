#pragma once

#include "Time.hpp"
#include <stdint.h>

namespace DivergenceMeter
{
	namespace Format
	{
		typedef uint32_t EightDigits;

		uint8_t* splitNum(uint64_t num, uint8_t desiredLength);
		uint8_t nixiePair(uint8_t l, uint8_t r);
		EightDigits number(uint32_t num);
		EightDigits time(DivergenceMeter::Time time);
	}
}

