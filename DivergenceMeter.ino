#include <stdint.h>
#include "Time.hpp"
#include "Shift.hpp"

constexpr DivergenceMeter::Shift::Pins pins = {
	.serial = 3,
	.clock = 4,
	.latch = 5
};

void setup()
{
	pinMode(pins.serial, OUTPUT);
	pinMode(pins.clock, OUTPUT);
	pinMode(pins.latch, OUTPUT);

	digitalWrite(pins.latch, LOW);
}

DivergenceMeter::Time time(12, 34, 56);

void loop()
{
	DivergenceMeter::Shift::display_time(pins, time);
	time.add_1s();
	delay(1000);
}

