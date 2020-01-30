#include "Format.hpp"
#include "Math.hpp"
#include "Time.hpp"
#include <stdint.h>
#include <stdlib.h> // malloc, free

namespace DivergenceMeter
{
	namespace Format
	{
		uint8_t* splitNum(uint64_t num, uint8_t desiredLength)
		{
			uint8_t length = Math::baseTenLength(num);
		
			if (length > desiredLength)
			{
				return nullptr;
			}
		
			uint8_t* arr = (uint8_t*)malloc(desiredLength);
		
			uint8_t i = 0;
		
			for ( ; i < (desiredLength - length); i++)
			{
				arr[i] = 0;
			}
		
			for ( ; i < desiredLength; i++)
			{
				uint64_t significance = Math::powerOfTen(desiredLength - i - 1);
		
				uint8_t place = num / significance;
		
				num -= place * significance;
		
				arr[i] = place;
			}
		
			return arr;
		}
		
		uint8_t nixiePair(uint8_t l, uint8_t r)
		{
			if (l > 9 || r > 9) return 0;
		
			return (l << 4) | r;
		}
		
		uint8_t* number(uint32_t num)
		{
			uint8_t* arr = splitNum(num, 8);
		
			if (arr == nullptr) return nullptr;
		
			uint8_t* format = (uint8_t*)malloc(4);
		
			format[0] = Format::nixiePair(arr[0], arr[1]);
			format[1] = Format::nixiePair(arr[2], arr[3]);
			format[2] = Format::nixiePair(arr[4], arr[5]);
			format[3] = Format::nixiePair(arr[6], arr[7]);
	
			free(arr);
		
			return format;
		}

		uint8_t* time(DivergenceMeter::Time time)
		{
			uint8_t* hours = splitNum(time.get_hours(), 2);
			uint8_t* minutes = splitNum(time.get_minutes(), 2);
			uint8_t* seconds = splitNum(time.get_seconds(), 2);

			uint8_t* format = (uint8_t*)malloc(4);

			format[0] = 0x00;
			format[1] = Format::nixiePair(hours[0], hours[1]);
			format[2] = Format::nixiePair(minutes[0], minutes[1]);
			format[3] = Format::nixiePair(seconds[0], seconds[1]);

			free(hours);
			free(minutes);
			free(seconds);

			return format;
		}
	}
}
