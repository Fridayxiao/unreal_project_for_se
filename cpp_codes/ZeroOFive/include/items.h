#pragma once
#include <iostream>
#include <vector>
using std::string;
using std::vector;

const int max_itemid = 100;

class ItemList;
struct Init_Item;

class Item
{
	public:
	Item();
	virtual void event();

	protected:
	int _id;//物品id
	string _name;//物品名字
	int _category;//物品类别
	string _description;//物品描述

	friend ItemList;

};

class ItemList: public vector<Item>
{
	public:
	ItemList();
	void set_InitList();

	private:
	vector<Init_Item> _init;
};

struct Init_Item
{
	int id;//编号
	string name;//物品名字
	int catagory;//物品类别
	string description;//物品描述
};