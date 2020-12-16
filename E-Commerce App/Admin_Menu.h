#pragma once
#include "DataBase.h"
namespace Admin = ECommerce::Admin;

//void Admin::Menu(App::DataBase* const& database)
//{
//	std::string user_name{};
//	std::string password{};
//	std::cout << "User Name: ";
//	getline(std::cin, user_name);
//	std::cout << "Password: ";
//	getline(std::cin, password);
//
//	bool is_here = false;
//
//	for (int i = 0; i < database->admins->Get_item_count(); i++)
//	{
//		if (database->admins->At(i)->Get_user_name() == user_name && database->admins->At(i)->Get_password() == password)
//		{
//			is_here = true;
//			break;
//		}
//	}
//
//	if (!is_here)
//		throw DatabaseException("User Name or password didn't Exist", 28, "Source.cpp");
//
//	short choice{};
//
//	while (true)
//	{
//		std::cout << "1)Show All Product Info\n2)Add Product\n3)Delete Product\n4)Show Notification\n5)Exit\nEnter: ";
//		std::cin >> choice;
//		is_here = false;
//
//		if (choice < 0 || choice > 5)
//			throw InvalidArgumentException("Choice must be between 0 and 5!", 38, "Admin_Menu.h");
//
//		if (choice == 1)
//		{
//			database->Show_all_product();
//		}
//
//		else if (choice == 2)
//		{
//			std::cin.ignore(1, '\n');
//			std::string name;
//			std::cout << "Name: ";
//			getline(std::cin, name);
//
//			int amount{};
//
//			for (int i = 0; i < database->products->Get_item_count(); i++)
//			{
//				if (database->products->At(i)->Get_product()->Get_name() == name)
//				{
//					is_here = true;
//					std::cout << "Product is in the Database, how many Amounts do you want to add: ";
//					std::cin >> amount;
//					database->products->At(i)->Set_amount(database->products->At(i)->Get_amount() + amount);
//					break;
//				}
//			}
//
//			if (!is_here)
//			{
//				std::string description;
//				std::cout << "Description: ";
//				getline(std::cin, description);
//
//				double price;
//				std::cout << "Price: ";
//				std::cin >> price;
//
//				double discount;
//				std::cout << "Discount: ";
//				std::cin >> discount;
//
//				double tax;
//				std::cout << "Tax: ";
//				std::cin >> tax;
//
//
//				std::cout << "Amount: ";
//				std::cin >> amount;
//
//				App::Product* product = new App::Product(name, description, price, discount, tax);
//				App::ProductItem* product_item = new App::ProductItem(product, amount);
//				database->products->Add(product_item);
//
//			}
//
//
//		}
//		else if (choice == 3)
//		{
//			std::cout << "DataBase has this IDs\n\n";
//
//
//			for (int i = 0; i < database->products->Get_item_count(); i++)
//			{
//				std::cout << "ID = " << database->products->At(i)->Get_product()->Get_id() << '\n';
//			}
//
//			int id{};
//			std::cout << "Enter Product ID which you want to delete: ";
//			std::cin >> id;
//
//			for (int i = 0; i < database->products->Get_item_count(); i++)
//			{
//				if (id == database->products->At(i)->Get_product()->Get_id())
//				{
//					is_here = true;
//					break;
//				}
//			}
//
//			if (is_here)
//				database->products->Delete_by_id(id);
//			else
//				std::cout << "There is no ID " << id << " product in DataBase\n\n";
//
//		}
//		else if (choice == 4)
//			database->Show_all_notification();
//		else
//			return;
//
//	}
//
//
//}



void Admin::Menu(App::DataBase* const& database)
{
	std::string user_name{};
	std::string password{};
	std::cout << "User Name: ";
	getline(std::cin, user_name);
	std::cout << "Password: ";
	getline(std::cin, password);

	bool is_here = false;

	for (int i = 0; i < database->Get_database_admins()->Get_item_count(); i++)
	{
		if (database->Get_database_admins()->At(i)->Get_user_name() == user_name &&
			database->Get_database_admins()->At(i)->Get_password() == password)
		{
			is_here = true;
			break;
		}
	}

	if (!is_here)
		throw DatabaseException("User Name or password didn't Exist", 28, "Source.cpp");

	short choice{};

	while (true)
	{
		std::cout << "1)Show All Product Info\n2)Add Product\n3)Delete Product\n4)Show Notification\n5)Exit\nEnter: ";
		std::cin >> choice;
		is_here = false;

		if (choice < 0 || choice > 5)
			throw InvalidArgumentException("Choice must be between 0 and 5!", 38, "Admin_Menu.h");

		if (choice == 1)
		{
			database->Show_all_product();
		}

		else if (choice == 2)
		{
			std::cin.ignore(1, '\n');
			std::string name;
			std::cout << "Name: ";
			getline(std::cin, name);

			int amount{};

			for (int i = 0; i < database->Get_database_products()->Get_item_count(); i++)
			{
				if (database->Get_database_products()->At(i)->Get_product()->Get_name() == name)
				{
					is_here = true;
					std::cout << "Product is in the Database, how many Amounts do you want to add: ";
					std::cin >> amount;
					database->Get_database_products()->At(i)->Set_amount(database->Get_database_products()->At(i)->Get_amount() + amount);
					break;
				}
			}

			if (!is_here)
			{
				std::string description;
				std::cout << "Description: ";
				getline(std::cin, description);

				double price;
				std::cout << "Price: ";
				std::cin >> price;

				double discount;
				std::cout << "Discount: ";
				std::cin >> discount;

				double tax;
				std::cout << "Tax: ";
				std::cin >> tax;


				std::cout << "Amount: ";
				std::cin >> amount;

				App::Product* product = new App::Product(name, description, price, discount, tax);
				App::ProductItem* product_item = new App::ProductItem(product, amount);
				database->Get_database_products()->Add(product_item);

			}


		}
		else if (choice == 3)
		{
			std::cout << "DataBase has this IDs\n\n";


			for (int i = 0; i < database->Get_database_products()->Get_item_count(); i++)
			{
				std::cout << "ID = " << database->Get_database_products()->At(i)->Get_product()->Get_id() << '\n';
			}

			int id{};
			std::cout << "Enter Product ID which you want to delete: ";
			std::cin >> id;

			for (int i = 0; i < database->Get_database_products()->Get_item_count(); i++)
			{
				if (id == database->Get_database_products()->At(i)->Get_product()->Get_id())
				{
					is_here = true;
					break;
				}
			}

			if (is_here)
				database->Get_database_products()->Delete_by_id(id);
			else
				std::cout << "There is no ID " << id << " product in DataBase\n\n";

		}
		else if (choice == 4)
			database->Show_all_notification();
		else
			return;

	}


}