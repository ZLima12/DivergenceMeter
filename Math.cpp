#include "Math.hpp"
#include <stdint.h>

namespace DivergenceMeter
{
	namespace Math
	{
		uint64_t powerOfTen(uint8_t power)
		{
			if (power == 0) return 1;
		
			uint64_t num = 1;
		
			for (uint8_t i = 0; i < power; i++)
			{
				num *= 10;
			}
		
			return num;
		}
		
		uint8_t baseTenLength(uint64_t num)
		{
			if (num == 0) return 1;
		
			uint8_t places = 0;
		
			while (num > 0)
			{
				num /= 10;
				places++;
			}

			return places;
		}
	}
}

