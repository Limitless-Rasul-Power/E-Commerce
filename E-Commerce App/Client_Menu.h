#pragma once
#include "DataBase.h"
namespace Client = ECommerce::Client;

//void Client::Menu(App::DataBase* const& database)
//{
//	std::string full_name;
//	std::cout << "Full Name: ";
//	getline(std::cin, full_name);
//
//	bool is_client_exist = false;
//
//	for (int i = 0; i < database->notes->Get_item_count(); i++)
//	{
//		if (full_name == database->notes->At(i)->Get_guest_name())
//		{
//			is_client_exist = true;
//			break;
//		}
//
//	}
//
//	App::Notification* note{};
//	App::Client* client{};
//
//
//	if (is_client_exist)
//	{
//		note = new App::Notification("Database Client Visit!", full_name);
//	}
//	else
//	{
//		client = new App::Client(full_name);
//		note = new App::Notification("New Client Visit", client->Get_full_name());
//		database->clients()->Add(client);
//	}
//	database->notes->Add(note);
//
//
//	short choice{};
//
//	int index = -1;
//
//	while (true)
//	{
//		for (int i = 0; i < database->products->Get_item_count(); i++)
//		{
//			std::cout << "\n\n" << '#' << i + 1 << ", Product Short Information\n\n";
//			std::cout << "Product ID: " << database->products->At(i)->Get_product()->Get_id() << '\n';
//			std::cout << "Product Name: " << database->products->At(i)->Get_product()->Get_name() << "\n\n";
//		}
//		std::cout << "\n\n1)Buy with ID\n2)Show More Information with ID\nEnter: ";
//		std::cin >> choice;
//
//		if (choice == 1)
//		{
//			std::cout << "DataBase has this IDs\n\n";
//
//			for (unsigned int i = 0U; i < database->products->Get_item_count(); i++)
//			{
//				std::cout << "ID = " << database->products->At(i)->Get_product()->Get_id() << '\n';
//			}
//
//			std::cout << "\nEnter Product id which you want to buy: ";
//			std::cin >> choice;		
//
//			for (unsigned int i = 0U; i < database->products->Get_item_count(); i++)
//			{
//				if (choice == database->products->At(i)->Get_product()->Get_id())
//				{
//					index = i;
//					break;
//				}
//			}
//
//			if (index == -1)
//				throw InvalidArgumentException("Wrong ID entered!", 77, "Client_Menu.h");
//
//			if (is_client_exist)
//				note = new App::Notification("Client wants to buy product!", full_name);
//			else
//				note = new App::Notification("New Client wants to buy product!", client->Get_full_name());
//
//			database->notes->Add(note);
//			break;
//		}
//		else if (choice == 2)
//		{
//			std::cout << "DataBase has this IDs\n\n";
//
//			for (int i = 0; i < database->products->Get_item_count(); i++)
//			{
//				std::cout << "ID = " << database->products->At(i)->Get_product()->Get_id() << '\n';
//			}
//
//			std::cout << "\nEnter ID: ";
//			std::cin >> choice;
//
//			bool is_id_exist = false;
//
//
//			for (int i = 0; i < database->products->Get_item_count(); i++)
//			{
//				if (choice == database->products->At(i)->Get_product()->Get_id())
//				{
//					is_id_exist = true;
//					index = i;
//					break;
//				}
//			}
//
//
//			if (is_id_exist)
//			{
//				database->products->At(index)->Show();
//				if (is_client_exist)
//					note = new App::Notification("Database Client wants to show more information!", full_name);
//				else
//					note = new App::Notification("New Client wants to show more information!", client->Get_full_name());
//
//				database->notes->Add(note);
//				std::cout << '\n';
//				system("pause");
//			}
//			else
//				std::cout << "Wrong ID!\n";
//
//
//
//		}
//		else
//		{
//			if (is_client_exist)
//				note = new App::Notification("Database client didn't buy anything and press exit button!", full_name);
//			else
//				note = new App::Notification("New Client didn't buy anything and press exit button!", client->Get_full_name());
//
//			database->notes->Add(note);
//			return;
//
//		}
//	}
//
//	int amount{};
//	std::cout << "\n\nWe have " << database->products->At(index)->Get_amount() << " amounts\n";
//	std::cout << "How many amount do you want to buy: ";
//	std::cin >> amount;
//
//	while (amount <= 0 || amount > database->products->At(index)->Get_amount())
//	{
//		std::cout << "\nInvalid Amount entered please enter again: ";
//		std::cin >> amount;
//	}
//
//
//	int option{};
//	std::cout << "\n\nDo you want to buy " << amount << " amounts of " << database->products->At(index)->Get_product()->Get_name() \
//		<< " ?\n1)Yes(press Y)\n2)No(press N)\nEnter: ";
//	std::cin >> option;
//
//	while (option < 0 || option > 2)
//	{
//		std::cout << "\n\nDo you want to buy " << amount << " amounts of " << database->products->At(index)->Get_product()->Get_name() \
//			<< " ?\n1)Yes(press Y)\n2)No(press N)\nEnter: ";
//		std::cin >> option;
//	}
//
//	if (option == 1)
//	{
//		std::cout << "\n\nSuccessfully bought, thank you for choosing us\n";
//		if (amount == database->products->At(index)->Get_amount())
//		{
//			if (is_client_exist)
//				note = new App::Notification("Database client buy last product!", full_name);
//			else
//				note = new App::Notification("New client buy last product!", client->Get_full_name());
//
//
//			database->products->Delete_by_id(database->products->At(index)->Get_product()->Get_id());
//		}
//		else
//		{
//			if (!is_client_exist)
//				note = new App::Notification("Database client buys X amount(s) of product!", full_name);
//			else
//				note = new App::Notification("New client buys X amount(s) of product!", client->Get_full_name());
//
//			database->products->At(index)->Set_amount(database->products->At(index)->Get_amount() - amount);
//		}
//	}
//	else
//	{
//		if (is_client_exist)
//			note = new App::Notification("Database client comes to last operation and didn't buy!", full_name);
//		else
//			note = new App::Notification("New client comes to last operation and didn't buy!", client->Get_full_name());
//
//		std::cout << "\n\nProduct didn't buy, Thank you for visiting!\n";
//	}
//
//
//	database->notes->Add(note);
//}


void Client::Menu(App::DataBase* const& database)
{
	std::string full_name;
	std::cout << "Full Name: ";
	getline(std::cin, full_name);

	bool is_client_exist = false;

	for (int i = 0; i < database->Get_database_notes()->Get_item_count(); i++)
	{
		if (full_name == database->Get_database_notes()->At(i)->Get_guest_name())
		{
			is_client_exist = true;
			break;
		}

	}

	App::Notification* note{};
	App::Client* client{};


	if (is_client_exist)
	{
		note = new App::Notification("Database Client Visit!", full_name);
	}
	else
	{
		client = new App::Client(full_name);
		note = new App::Notification("New Client Visit", client->Get_full_name());
		database->Get_database_clients()->Add(client);
	}
	database->Get_database_notes()->Add(note);


	short choice{};

	int index = -1;

	while (true)
	{
		for (int i = 0; i < database->Get_database_products()->Get_item_count(); i++)
		{
			std::cout << "\n\n" << '#' << i + 1 << ", Product Short Information\n\n";
			std::cout << "Product ID: " << database->Get_database_products()->At(i)->Get_product()->Get_id() << '\n';
			std::cout << "Product Name: " << database->Get_database_products()->At(i)->Get_product()->Get_name() << "\n\n";
		}
		std::cout << "\n\n1)Buy with ID\n2)Show More Information with ID\nEnter: ";
		std::cin >> choice;

		if (choice == 1)
		{
			std::cout << "DataBase has this IDs\n\n";

			for (unsigned int i = 0U; i < database->Get_database_products()->Get_item_count(); i++)
			{
				std::cout << "ID = " << database->Get_database_products()->At(i)->Get_product()->Get_id() << '\n';
			}

			std::cout << "\nEnter Product id which you want to buy: ";
			std::cin >> choice;

			for (unsigned int i = 0U; i < database->Get_database_products()->Get_item_count(); i++)
			{
				if (choice == database->Get_database_products()->At(i)->Get_product()->Get_id())
				{
					index = i;
					break;
				}
			}

			if (index == -1)
				throw InvalidArgumentException("Wrong ID entered!", 77, "Client_Menu.h");

			if (is_client_exist)
				note = new App::Notification("DataBase Client wants to buy product!", full_name);
			else
				note = new App::Notification("New Client wants to buy product!", client->Get_full_name());

			database->Get_database_notes()->Add(note);
			break;
		}
		else if (choice == 2)
		{
			std::cout << "DataBase has this IDs\n\n";

			for (int i = 0; i < database->Get_database_products()->Get_item_count(); i++)
			{
				std::cout << "ID = " << database->Get_database_products()->At(i)->Get_product()->Get_id() << '\n';
			}

			std::cout << "\nEnter ID: ";
			std::cin >> choice;

			bool is_id_exist = false;


			for (int i = 0; i < database->Get_database_products()->Get_item_count(); i++)
			{
				if (choice == database->Get_database_products()->At(i)->Get_product()->Get_id())
				{
					is_id_exist = true;
					index = i;
					break;
				}
			}


			if (is_id_exist)
			{
				database->Get_database_products()->At(index)->Show();
				if (is_client_exist)
					note = new App::Notification("Database Client wants to show more information!", full_name);
				else
					note = new App::Notification("New Client wants to show more information!", client->Get_full_name());

				database->Get_database_notes()->Add(note);
				std::cout << '\n';
				system("pause");
			}
			else
				std::cout << "Wrong ID!\n";



		}
		else
		{
			if (is_client_exist)
				note = new App::Notification("Database client didn't buy anything and press exit button!", full_name);
			else
				note = new App::Notification("New Client didn't buy anything and press exit button!", client->Get_full_name());

			database->Get_database_notes()->Add(note);
			return;

		}
	}

	int amount{};
	std::cout << "\n\nWe have " << database->Get_database_products()->At(index)->Get_amount() << " amounts\n";
	std::cout << "How many amount do you want to buy: ";
	std::cin >> amount;

	while (amount <= 0 || amount > database->Get_database_products()->At(index)->Get_amount())
	{
		std::cout << "\nInvalid Amount entered please enter again: ";
		std::cin >> amount;
	}


	int option{};
	std::cout << "\n\nDo you want to buy " << amount << " amounts of " << database->Get_database_products()->At(index)->Get_product()->Get_name() \
		<< " ?\n1)Yes(press Y)\n2)No(press N)\nEnter: ";
	std::cin >> option;

	while (option < 0 || option > 2)
	{
		std::cout << "\n\nDo you want to buy " << amount << " amounts of " << database->Get_database_products()->At(index)->Get_product()->Get_name() \
			<< " ?\n1)Yes(press Y)\n2)No(press N)\nEnter: ";
		std::cin >> option;
	}

	if (option == 1)
	{
		std::cout << "\n\nSuccessfully bought, thank you for choosing us\n";
		if (amount == database->Get_database_products()->At(index)->Get_amount())
		{
			if (is_client_exist)
				note = new App::Notification("Database client buy last product!", full_name);
			else
				note = new App::Notification("New client buy last product!", client->Get_full_name());


			database->Get_database_products()->Delete_by_id(database->Get_database_products()->At(index)->Get_product()->Get_id());
		}
		else
		{
			if (!is_client_exist)
				note = new App::Notification("Database client buys X amount(s) of product!", full_name);
			else
				note = new App::Notification("New client buys X amount(s) of product!", client->Get_full_name());

			database->Get_database_products()->At(index)->Set_amount(database->Get_database_products()->At(index)->Get_amount() - amount);
		}
	}
	else
	{
		if (is_client_exist)
			note = new App::Notification("Database client comes to last operation and didn't buy!", full_name);
		else
			note = new App::Notification("New client comes to last operation and didn't buy!", client->Get_full_name());

		std::cout << "\n\nProduct didn't buy, Thank you for visiting!\n";
	}


	database->Get_database_notes()->Add(note);
}
