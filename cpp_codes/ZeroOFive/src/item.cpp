#include "..\\include\\items.h"
Item::Item()
{
}

void Item::event()
{

}

ItemList::ItemList(): vector<Item>(max_itemid), _init(max_itemid)
{
	vector<Item>::iterator it = vector<Item>::begin();
	vector<Init_Item>::iterator iti = _init.begin();
	for (; it != vector<Item>::end(); it++, iti++)
	{
		it->_id = iti->id;
		it->_name = iti->name;
		it->_category = iti->catagory;
		it->_description = iti->description;
	}
}

void ItemList::set_InitList()
{
	_init = {
		{0, "小型生命回复药水", 3, "回复10点hp"},
		{1, },
		{},
		{}
	};
}