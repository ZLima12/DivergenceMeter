#pragma once

#include "Time.hpp"
#include <stdint.h>

namespace DivergenceMeter
{
	namespace Format
	{
		uint8_t* splitNum(uint64_t num, uint8_t desiredLength);
		uint8_t nixiePair(uint8_t l, uint8_t r);
		uint8_t* number(uint32_t num);
		uint8_t* time(DivergenceMeter::Time time);
	}
}

