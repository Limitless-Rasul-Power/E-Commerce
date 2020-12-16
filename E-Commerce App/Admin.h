#pragma once
#include "Exception.h"
#include "Namespace.h"
#include <iostream>

class App::Admin
{

private:
	std::string user_name;
	std::string password;

public:

	Admin(const std::string& user_name, const std::string& password)
	{
		Set_user_name(user_name);
		Set_password(password);
	}

	void Set_user_name(const std::string& user_name)
	{
		if (user_name.empty())
			throw InvalidArgumentException("User Name is Empty!", 23, "Admin.h");

		this->user_name = user_name;
	}

	std::string Get_user_name() const
	{
		return user_name;
	}

	void Set_password(const std::string& password)
	{
		if (password.empty())
			throw InvalidArgumentException("Password is Empty!", 36, "Admin.h");

		this->password = password;
	}

	std::string Get_password() const
	{
		return password;
	}

	void Show() const
	{
		std::cout << "Admin User Name: " << Get_user_name() << '\n';
		std::string x(password.length(), '*');
		std::cout << "Admin Password: " << x << "\n\n";
	}

};
