#include "Time.hpp"
#include <stdint.h>

namespace DivergenceMeter
{
	Time::Time()
	{
		this->hours = 0;
		this->minutes = 0;
		this->seconds = 0;
	}

	Time::Time(uint_fast8_t hours, uint_fast8_t minutes, uint_fast8_t seconds)
	{
		this->hours = hours;
		this->minutes = minutes;
		this->seconds = seconds;
	}

	static bool increment_limit(uint_fast8_t& ref, uint_fast8_t limit)
	{
		if (ref + 1 == limit)
		{
			ref = 0;
			return true;
		}

		else
		{
			ref++;
			return false;
		}
	}

	bool Time::increment_hours()
	{
		return increment_limit(this->hours, 24);
	}

	bool Time::increment_minutes()
	{
		return increment_limit(this->minutes, 60);
	}

	bool Time::increment_seconds()
	{
		return increment_limit(this->seconds, 60);
	}

	void Time::add_1s()
	{
		if (this->increment_seconds())
		{
			if (this->increment_minutes())
			{
				this->increment_hours();
			}
		}
	}

	const uint_fast8_t& Time::get_hours() const
	{
		return this->hours;
	}

	const uint_fast8_t& Time::get_minutes() const
	{
		return this->minutes;
	}

	const uint_fast8_t& Time::get_seconds() const
	{
		return this->seconds;
	}
}
