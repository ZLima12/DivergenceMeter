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
	DivergenceMeter::Shift::initialize(pins);
}

DivergenceMeter::Time time(12, 34, 56);

void loop()
{
	DivergenceMeter::Shift::display_time(pins, time);
	time.add_1s();
	delay(1000);
}

