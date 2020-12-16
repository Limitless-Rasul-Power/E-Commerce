#pragma once
#include "Base.h"
#include <iostream>

class App::Notification : public Base
{

private:
	std::string text;
	std::string guest_name;
	bool is_read;
	char create_time[26];

public:

	static unsigned int note_id;

	Notification(const std::string& text, const std::string& guest_name)
	{
		Set_text(text);
		Set_guest_name(guest_name);
		Set_create_time(this->create_time);
		Increment_id();
		this->is_read = false;
	}

	void Set_text(const std::string& text)
	{
		if (text.empty())
			throw InvalidArgumentException("Text is Empty!", 23, "Notification.h");

		this->text = text;
	}

	std::string Get_text() const
	{
		return text;
	}

	void Set_guest_name(const std::string& guest_name)
	{
		if (guest_name.empty())
			throw InvalidArgumentException("Guest name is Empty!", 36, "Notification.h");

		this->guest_name = guest_name;
	}

	std::string Get_guest_name() const
	{
		return guest_name;
	}

	void Set_is_read(const bool& is_read)
	{
		this->is_read = is_read;
	}

	bool Is_read() const
	{
		return is_read;
	}

	void Increment_id()
	{
		this->id = ++note_id;
	}

	static unsigned int Get_current_id()
	{
		return note_id;
	}

	const char* Get_create_time() const
	{
		return create_time;
	}

	void Show() const
	{
		std::cout << "Notification Text: " << Get_text() << '\n';
		std::cout << "Guest Name: " << Get_guest_name() << '\n';
		std::cout << "Notification Create Time: " << Get_create_time() << "\n\n";
	}

};