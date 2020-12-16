#pragma once
#include "Product.h"

class App::ProductItem
{

private:
	Product* product;
	unsigned int amount;

public:

	ProductItem(Product* const& product, const int& amount)
	{
		Set_product(product);
		Set_amount(amount);
	}

	void Set_product(Product* const& product)
	{
		if (product == nullptr)
			throw InvalidArgumentException("Product is nullptr!", 21, "ProductItem.h");

		this->product = product;
	}

	Product* Get_product() const
	{
		return product;
	}


	void Set_amount(const int& amount)
	{
		if (amount <= 0)
			throw InvalidArgumentException("Amount must be more than 0!", 35, "ProductItem.h");

		this->amount = amount;
	}

	unsigned int Get_amount() const
	{
		return amount;
	}

	void Show()
	{
		product->Show();
		std::cout << "Product Amount: " << Get_amount() << "\n\n";
	}

	~ProductItem()
	{
		std::cout << "Product Name: " << Get_product()->Get_name() << '\n';
		delete product;
		std::cout << "Product Name: " << Get_product()->Get_name() << '\n';
	}
};