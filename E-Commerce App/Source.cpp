#include "DataBase.h"
#include "Admin_Menu.h"
#include "Client_Menu.h"

using std::cout; using std::cin; using std::endl; using std::string;

unsigned int App::Notification::note_id{ 0 };
unsigned int App::Product::product_id{ 0 };
unsigned int App::Client::client_id{ 0 };

void ECommerce::Start(App::DataBase* const& database)
{
	short choice{};

	while (true)
	{
		cout << "\n1)Guest Menu\n2)Admin Menu\n3)Exit\nEnter: ";
		cin >> choice;

		while (choice <= 0 || choice > 3)
		{
			cout << "Choose one of this options: ";
			cin >> choice;
		}

		cin.ignore(1, '\n');

		if (choice == 1)
		{
			try
			{
				Client::Menu(database);
			}
			catch (const Exception& ex)
			{
				cout << ex;
			}
		}
		else if (choice == 2)
		{
			try
			{
				Admin::Menu(database);
			}
			catch (const Exception& ex)
			{
				cout << ex;
			}
		}
		else
			break;

	}

}



int main()
{
	App::Client* c_1 = new App::Client("Martin");
	App::Client* c_2 = new App::Client("Luther");
	App::Client* c_3 = new App::Client("King");
	App::Client* c_4 = new App::Client("Jr");

	App::Admin* a_1 = new App::Admin("Rasul", "1234");
	App::Admin* a_2 = new App::Admin("Ms.Agent", "1234");
	App::Admin* a_3 = new App::Admin("Ferhad", "admin");

	App::Product* p_1 = new App::Product("Anthony Robbins", "Awake the Giant Within", 10000, 20, 1);
	App::Product* p_2 = new App::Product("Simon Sinek", "Start With Why", 1000, 20, 1);
	App::Product* p_3 = new App::Product("Joe Dispenza", "Your Subconcious Mind", 2222, 11, 0.2);
	App::Product* p_4 = new App::Product("Stephen R.Covey", "High Effective People's 7 habits", 9876, 14, 30);
	App::Product* p_5 = new App::Product("Napoleon Hill", "Think and Grow Rich", 99999888, 45, 38);

	App::ProductItem* p_i_1 = new App::ProductItem(p_1, 1000);
	App::ProductItem* p_i_2 = new App::ProductItem(p_2, 3000);
	App::ProductItem* p_i_3 = new App::ProductItem(p_3, 40000);
	App::ProductItem* p_i_4 = new App::ProductItem(p_4, 3001);
	App::ProductItem* p_i_5 = new App::ProductItem(p_5, 56);

	App::Notification* n_1 = new App::Notification("Hey", "Aftandil");
	App::Notification* n_2 = new App::Notification("Sen", "Ronald");
	App::Notification* n_3 = new App::Notification("Men", "Reagan");
	App::Notification* n_4 = new App::Notification("O", "Kennedy");
	App::Notification* n_5 = new App::Notification("Senin adin nedir?", "John");
	App::Notification* n_6 = new App::Notification("Niyeni tapmaqda daha mukemmeles", "Templeton");
	App::Notification* n_7 = new App::Notification("Heyatin senin leyhinedi eleyhine deyil!!!", "Tony Robbins");


	App::DataStructure<App::ProductItem>* all_products = new App::DataStructure<App::ProductItem>;
	App::DataStructure<App::Admin>* all_admins = new App::DataStructure<App::Admin>;
	App::DataStructure<App::Client>* all_clients = new App::DataStructure<App::Client>;
	App::DataStructure<App::Notification>* all_notes = new App::DataStructure<App::Notification>;


	App::DataBase* database = new App::DataBase(all_products, all_admins, all_clients, all_notes);



	database->Get_database_products()->Add(p_i_1);
	database->Get_database_products()->Add(p_i_2);
	database->Get_database_products()->Add(p_i_3);
	database->Get_database_products()->Add(p_i_4);
	database->Get_database_products()->Add(p_i_5);

	database->Get_database_admins()->Add(a_1);
	database->Get_database_admins()->Add(a_2);
	database->Get_database_admins()->Add(a_3);

	database->Get_database_clients()->Add(c_1);
	database->Get_database_clients()->Add(c_2);
	database->Get_database_clients()->Add(c_3);
	database->Get_database_clients()->Add(c_4);

	database->Get_database_notes()->Add(n_1);
	database->Get_database_notes()->Add(n_2);
	database->Get_database_notes()->Add(n_3);
	database->Get_database_notes()->Add(n_4);
	database->Get_database_notes()->Add(n_5);
	database->Get_database_notes()->Add(n_6);
	database->Get_database_notes()->Add(n_7);


	ECommerce::Start(database);

	cout << "\n\n\n\n";
	database->Show();

	delete database;

	system("pause");
	return 0;
}