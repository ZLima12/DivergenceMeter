#include <stdint.h>
#include "Format.hpp"
#include "Time.hpp"

constexpr uint8_t serial = 3;
constexpr uint8_t clock = 4;
constexpr uint8_t latch = 5;

void pulseLatch()
{
	digitalWrite(latch, HIGH);
	delayMicroseconds(1);
	digitalWrite(latch, LOW);
}

void shiftOutFormatted(uint8_t* bytes)
{
	for (size_t i = 0; i < 4; i++)
	{
		shiftOut(serial, clock, MSBFIRST, bytes[i]);
	}

	free(bytes);

	pulseLatch();
}

void meterDisplay(uint32_t num)
{
	uint8_t* bytes = DivergenceMeter::Format::number(num);
	shiftOutFormatted(bytes);
}

void meterDisplay(DivergenceMeter::Time time)
{
	uint8_t* bytes = DivergenceMeter::Format::time(time);
	shiftOutFormatted(bytes);
}

void setup()
{
	pinMode(serial, OUTPUT);
	pinMode(clock, OUTPUT);
	pinMode(latch, OUTPUT);

	digitalWrite(latch, LOW);
}

DivergenceMeter::Time time(12, 34, 56);

void loop()
{
	meterDisplay(time);
	time.add_1s();
	delay(1000);
}

