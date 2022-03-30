#pragma once
#include <vector>
#include "weapon.h"
#include "items.h"
using std::vector;
struct Status;
class Character
{
	public:
	Character();
	Status get_status();//返回当前角色状态给战斗场景用
	virtual void init();//针对一些static变量进行的一次性初始化
	virtual int attack();//进行攻击
	virtual void takedamage(const int &);//受伤 

	protected:
	static const string _classname[3];
	string _name;//角色名字
	int _class;//职业编号
	int _level;//等级
	int _exp;//经验
	int _lv_exp;//升级所需经验
	int _hp;//血量
	int _maxhp;//血量上限
	int _atk;//攻击
	int _def;//防御
	
	friend class GAME;
};

struct Status
{
	int _hp;//血量
	int _maxhp;//血量上限
	int _atk;//攻击
	int _def;//防御
};

class Player: public Character
{
	public:
	Player();
	void init() override;//都是继承上方
	int attack() override;
	void takedamage(const int &) override;

	void newplayer();//新建角色
	void loadplayer();//登陆角色
	/*
	此处有个问题，因为loadgame()的时候可以直接去做loadplayer的工作
	所以此处loadplayer()功能改为用于登陆提示之类的？
	*/
	void changeweapon(const int &);//换武器

	//你操作这些
	string getName();
	char getUserOperation();//获得用户的选择并返回参数

	//你操作这些
	
	private:
};

class Enemy: public Character
{
	public:
	Enemy();
	void init() override;
	int attack() override;
	void takedamage(const int &) override;

	private:
};