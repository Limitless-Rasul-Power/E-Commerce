#pragma once
#include "Namespace.h"
#include "Exception.h"

template<typename T>
class App::DataStructure
{
private:
	T** items;
	unsigned int item_count = 0;

public:

	void Set_item_count(const int& item_count)
	{
		this->item_count = item_count;
	}

	unsigned int  Get_item_count() const
	{
		return item_count;
	}

	void Add(T* const& added)
	{
		T** new_items = new T * [Get_item_count() + 1];

		for (int i = 0; i < Get_item_count(); i++)
			new_items[i] = items[i];

		delete[] items;
		new_items[Get_item_count()] = added;

		items = new_items;
		new_items = nullptr;

		Set_item_count(Get_item_count() + 1);
	}

	void Delete_by_id(const int& id)
	{
		if (Get_item(id) == nullptr)
			throw InvalidArgumentException("This ID didn't Exist!", 43, "Data_Structure.h");

		int go{ 0 };

		T** new_items = new T * [Get_item_count() - 1];

		for (int i = 0; i + go < Get_item_count(); i++)
		{
			if (id == items[i]->Get_product()->Get_id())
			{
				delete items[i];
				++go;
			}

			if (i + go < item_count)
				new_items[i] = items[i + go];
		}

		delete[] items;
		items = new_items;
		new_items = nullptr;

		Set_item_count(Get_item_count() - 1);

	}

	T* Get_item(const int& id)
	{
		for (int i = 0; i < Get_item_count(); i++)
		{
			if (items[i]->Get_product()->Get_id() == id)
				return items[i];
		}

		T* not_found = nullptr;
		return not_found;

	}

	T* At(const int& index)
	{
		if (index < 0)
			throw InvalidArgumentException("Index must be more than -1", 85, "Data_Structure.h");

		return items[index];
	}


	~DataStructure()
	{
		for (int i = 0; i < Get_item_count(); i++)
			delete items[i];

		delete[] items;
	}

};