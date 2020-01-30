#pragma once

#include "Format.hpp"
#include "Time.hpp"
#include <stdint.h>

namespace DivergenceMeter
{
	namespace Shift
	{
		typedef struct Pins
		{
			uint_fast8_t serial;
			uint_fast8_t clock;
			uint_fast8_t latch;
		} Pins;

		void pulse_latch(const uint_fast8_t& latchPin);
		void pulse_latch(const Pins& pins);

		void digits(const Pins& pins, const Format::EightDigits& digits);

		void display_number(const Pins& pins, const uint_fast32_t& number);
		void display_time(const Pins& pins, const DivergenceMeter::Time& time);
	}
}
