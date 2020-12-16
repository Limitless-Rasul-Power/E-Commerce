#pragma once
#include "Exception.h"
#include "Namespace.h"
#include <ctime>

void Set_create_time(char* const& create_time)
{
	time_t now = time(NULL);
	ctime_s(create_time, 26, &now);
}

class App::Base
{

protected:
	unsigned int id;

public:

	unsigned int Get_id() const
	{
		return id;
	}

	virtual ~Base() = 0
	{

	}
};