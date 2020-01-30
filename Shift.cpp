#include "Shift.hpp"
#include "Format.hpp"
#include <Arduino.h>
#include <stdint.h>

namespace DivergenceMeter
{
	namespace Shift
	{
		void initialize(const Pins& pins)
		{
			pinMode(pins.serial, OUTPUT);
			pinMode(pins.clock, OUTPUT);
			pinMode(pins.latch, OUTPUT);

			digitalWrite(pins.latch, LOW);
		}

		void pulse_latch(const uint_fast8_t& pin)
		{
			digitalWrite(pin, HIGH);
			delayMicroseconds(1);
			digitalWrite(pin, LOW);
		}

		void pulse_latch(const Pins& pins)
		{
			pulse_latch(pins.latch);
		}

		void digits(const Pins& pins, const Format::EightDigits& number)
		{
			const uint8_t* bytes = (const uint8_t*)(&number);

			for (size_t i = 0; i < 4; i++)
			{
				shiftOut(pins.serial, pins.clock, MSBFIRST, bytes[i]);
			}
		
			pulse_latch(pins);
		}

		void display_number(const Pins& pins, const uint_fast32_t& number)
		{
			Shift::digits(pins, Format::number(number));
		}

		void display_time(const Pins& pins, const DivergenceMeter::Time& time)
		{
			Shift::digits(pins, Format::time(time));
		}
	}
}
