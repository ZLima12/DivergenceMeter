#include <stdint.h>
#include "Format.hpp"

constexpr uint8_t serial = 3;
constexpr uint8_t clock = 4;
constexpr uint8_t latch = 5;

void pulseLatch()
{
	digitalWrite(latch, HIGH);
	delayMicroseconds(1);
	digitalWrite(latch, LOW);
}

void meterDisplay(uint32_t num)
{
	uint8_t* bytes = DivergenceMeter::Format::number(num);

	for (size_t i = 0; i < 4; i++)
	{
		shiftOut(serial, clock, MSBFIRST, bytes[i]);
	}

	free(bytes);

	pulseLatch();
}

void setup()
{
	pinMode(serial, OUTPUT);
	pinMode(clock, OUTPUT);
	pinMode(latch, OUTPUT);

	digitalWrite(latch, LOW);
}

uint32_t time = 0;

void loop()
{
	meterDisplay(time);
	time++;
	delay(1000);
}

