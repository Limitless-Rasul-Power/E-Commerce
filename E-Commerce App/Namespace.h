#pragma once
namespace ECommerce
{

	namespace DB
	{
		class Base;
		class Client;

		class Notification;

		class Admin;
		class Product;

		class ProductItem;

		template<typename T>
		class DataStructure;

		class DataBase;
	}

	namespace Admin
	{
		void Menu(ECommerce::DB::DataBase* const&);
	}

	namespace Client
	{
		void Menu(ECommerce::DB::DataBase* const&);
	}


	void Start(ECommerce::DB::DataBase* const&);

}
namespace App = ECommerce::DB;
