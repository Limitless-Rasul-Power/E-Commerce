#pragma once
#include "Base.h"
#include <iostream>

class App::Product : public Base
{

private:
	std::string name;
	std::string description;
	double price;
	double discount;
	double tax;

public:

	static unsigned int product_id;

	Product(const std::string& name, const std::string& description, const double& price, const double& discount, const double& tax)
	{
		Set_name(name);
		Set_description(description);
		Set_price(price);;
		Set_discount(discount);
		Set_tax(tax);
		Increment_id();
	}

	void Set_name(const std::string& name)
	{
		if (name.empty())
			throw InvalidArgumentException("Name is Empty!", 25, "Product.h");

		this->name = name;
	}

	std::string Get_name() const
	{
		return name;
	}

	void Set_description(const std::string& description)
	{
		if (description.empty())
			throw InvalidArgumentException("Description is Empty!", 38, "Product.h");

		this->description = description;
	}

	std::string Get_description() const
	{
		return description;
	}

	void Set_price(const double& price)
	{
		if (price <= 0)
			throw InvalidArgumentException("Price must be more than 0!", 51, "Product.h");

		this->price = price;
	}

	double Get_price() const
	{
		return price;
	}

	void Set_discount(const double& discount)
	{
		if (discount <= 0 || discount > 99)
			throw InvalidArgumentException("Discount must be between 0 and 100!", 64, "Product.h");

		this->discount = discount;
	}

	double Get_discount() const
	{
		return discount;
	}

	double Get_price_with_discount() const
	{
		return Get_price() - ((Get_price() * Get_discount()) / 100);
	}

	void Set_tax(const double& tax)
	{
		if (tax <= 0)
			throw InvalidArgumentException("Tax must be more than 0!", 82, "Product.h");

		this->tax = tax;
	}

	double Get_tax() const
	{
		return tax;
	}

	void Increment_id()
	{
		this->id = ++product_id;
	}

	static unsigned int Get_current_id()
	{
		return product_id;
	}

	void Show() const
	{
		std::cout << "Product ID: " << Get_id() << '\n';
		std::cout << "Product Name: " << Get_name() << '\n';
		std::cout << "Product Description: " << Get_description() << '\n';
		std::cout << "Product Price: " << Get_price() << '\n';
		std::cout << "Product Price after " << Get_discount() << " % discount " << Get_price_with_discount() << '\n';
		std::cout << "Product Tax: " << Get_tax() << '\n';
	}

};