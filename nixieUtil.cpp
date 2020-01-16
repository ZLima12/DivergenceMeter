#include "nixieUtil.hpp"
#include <stdlib.h> // malloc, free

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

uint8_t* splitNum(uint64_t num, uint8_t desiredLength)
{
	uint8_t length = baseTenLength(num);

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
		uint64_t significance = powerOfTen(desiredLength - i - 1);

		uint8_t place = num / significance;

		num -= place * significance;

		arr[i] = place;
	}

	return arr;
}

uint8_t nixiePairFormat(uint8_t l, uint8_t r)
{
	if (l > 9 || r > 9) return 0;

	return (l << 4) | r;
}

uint8_t* meterFormat(uint32_t num)
{
	uint8_t* arr = splitNum(num, 8);

	if (arr == nullptr) return nullptr;

	uint8_t* format = (uint8_t*)malloc(4);

	format[0] = nixiePairFormat(arr[0], arr[1]);
	format[1] = nixiePairFormat(arr[2], arr[3]);
	format[2] = nixiePairFormat(arr[4], arr[5]);
	format[3] = nixiePairFormat(arr[6], arr[7]);

	free(arr);

	return format;
}

