#pragma once
#include "ProductItem.h"
#include "Admin.h"
#include "Notification.h"
#include "Client.h"
#include "Data_Structure.h"
#include <iostream>
#include <windows.h>

class App::DataBase
{

private:
	DataStructure<ProductItem>* products;
	DataStructure<Admin>* admins;
	DataStructure<Client>* clients;
	DataStructure<Notification>* notes;

public:

	DataBase() :products(nullptr), admins(nullptr), clients(nullptr), notes(nullptr)
	{}

	DataBase(DataStructure<ProductItem>* const& products, DataStructure<Admin>* const& admins,
		DataStructure<Client>* const& clients, DataStructure<Notification>* const& notes)
	{
		Set_database_products(products);
		Set_database_admins(admins);
		Set_database_clients(clients);
		Set_database_notes(notes);
	}

	void Set_database_products(DataStructure<ProductItem>* const& products)
	{
		if (products == nullptr)
			throw InvalidArgumentException("Products is nullptr", 36, "DataBase.h");

		this->products = products;
	}

	DataStructure<ProductItem>* Get_database_products() const
	{
		return products;
	}


	void Set_database_admins(DataStructure<Admin>* const& admins)
	{
		if (admins == nullptr)
			throw InvalidArgumentException("Admins is nullptr", 50, "DataBase.h");

		this->admins = admins;
	}

	DataStructure<Admin>* Get_database_admins() const
	{
		return admins;
	}

	void Set_database_clients(DataStructure<Client>* const& clients)
	{
		if (clients == nullptr)
			throw InvalidArgumentException("Clients is nullptr", 63, "DataBase.h");

		this->clients = clients;
	}

	DataStructure<Client>* Get_database_clients() const
	{
		return clients;
	}


	void Set_database_notes(DataStructure<Notification>* const& notes)
	{
		if (notes == nullptr)
			throw InvalidArgumentException("Notification is nullptr", 77, "DataBase.h");

		this->notes = notes;
	}

	DataStructure<Notification>* Get_database_notes() const
	{
		return notes;
	}


	void Show_all_product() const
	{
		for (int i = 0; i < products->Get_item_count(); i++)
		{
			std::cout << '#' << i + 1 << ", Product Information\n\n";
			products->At(i)->Show();
		}
	}

	void Show_all_admin() const
	{
		for (int i = 0; i < admins->Get_item_count(); i++)
		{
			std::cout << '#' << i + 1 << ", Admin Information\n\n";
			admins->At(i)->Show();
		}
	}

	void Show_all_client() const
	{
		for (int i = 0; i < clients->Get_item_count(); i++)
		{
			std::cout << '#' << i + 1 << ", Client Information\n\n";
			clients->At(i)->Show();
		}
	}

	void Show_all_notification() const
	{
		short choice{};
		std::cout << "Do You want to see notification(s)!\n1)Yes\n2)No\nEnter: ";
		std::cin >> choice;

		while (choice <= 0 || choice > 2)
		{
			std::cout << "Choose first or second choice\nEnter: ";
			std::cin >> choice;
		}

		if (choice == 2)
			return;

		std::cout << "You have " << notes->Get_item_count() << " notifications\n";

		int id{};

		while (true)
		{
			std::cout << "1)Show Unread message(s)\n2)Show all message(s)\n3)Exit\nEnter: ";
			std::cin >> choice;

			while (choice <= 0 || choice > 3)
			{
				std::cout << "Choose first or second or third choice\nEnter: ";
				std::cin >> choice;
			}

			if(choice != 3)
			for (int i = 0; i < notes->Get_item_count(); i++)
				if (notes->At(i)->Is_read() == false)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					std::cout << "Unread Message ID: " << notes->At(i)->Get_id() << "..........\n";
				}


			if (choice == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				std::cout << "\nWhich id do you want to read: ";
				std::cin >> id;

				for (unsigned int i = 0U; i < notes->Get_item_count(); i++)
				{
					if (id == notes->At(i)->Get_id() && notes->At(i)->Is_read() == false)
					{
						notes->At(i)->Set_is_read(true);
						notes->At(i)->Show();
						break;
					}
				}


			}

			else if (choice == 2)
			{
				for (unsigned int i = 0U; i < notes->Get_item_count(); i++)
					if (notes->At(i)->Is_read() == true)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
						std::cout << "Red Message ID: " << notes->At(i)->Get_id() << '\n';
					}

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				std::cout << "\nWhich id do you want to read: ";
				std::cin >> id;

				for (int i = 0; i < notes->Get_item_count(); i++)
				{
					if (id == notes->At(i)->Get_id())
					{
						if (notes->At(i)->Is_read() == false)
							notes->At(i)->Set_is_read(true);

						notes->At(i)->Show();
						break;
					}
				}


			}

			else
				break;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

			system("pause");

		}

	}

	void Show() const
	{
		std::cout << "All Database Information\n\n\n\n";
		Show_all_client();
		Show_all_product();
		Show_all_admin();
		Show_all_notification();
		std::cout << "\n\n";
	}

	~DataBase()
	{
		delete products;
		delete admins;
		delete clients;
		delete notes;
	}

};
