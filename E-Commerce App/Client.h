#pragma once
#include "Base.h"
#include <iostream>

class App::Client : public Base
{

private:
	std::string full_name;
	char create_time[26];

public:
	static unsigned int client_id;

	App::Client(const std::string& full_name)
	{
		Set_full_name(full_name);
		Set_create_time(this->create_time);
		Increment_id();
	}

	void Set_full_name(const std::string& full_name)
	{
		if (full_name.empty())
			throw InvalidArgumentException("Full Name is Empty!", 30, "Client.h");

		this->full_name = full_name;

	}

	std::string Get_full_name() const
	{
		return full_name;
	}

	void Increment_id()
	{
		this->id = ++client_id;
	}

	static unsigned int Get_current_id()
	{
		return client_id;
	}

	const char* Get_create_time() const
	{
		return create_time;
	}

	void Show() const
	{
		std::cout << "Client ID: " << Get_id() << '\n';
		std::cout << "Client Full Name: " << Get_full_name() << '\n';
		std::cout << "Client Create Time: " << Get_create_time() << "\n\n";
	}

};