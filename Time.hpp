#pragma once

#include <stdint.h>

namespace DivergenceMeter
{
	class Time
	{
	public:
		Time();
		Time(uint_fast8_t hours, uint_fast8_t minutes, uint_fast8_t seconds);

		bool increment_hours();
		bool increment_minutes();
		bool increment_seconds();

		void add_1s();

		const uint_fast8_t& get_hours() const;
		const uint_fast8_t& get_minutes() const;
		const uint_fast8_t& get_seconds() const;

	private:
		uint_fast8_t hours;
		uint_fast8_t minutes;
		uint_fast8_t seconds;
	};
}
