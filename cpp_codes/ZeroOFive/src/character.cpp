#include <conio.h>
#include "..\\include\\character.h"
#include <string>
Character::Character()
{
}

Status get_status()
{
	Status a{0, 0, 0, 0};
	return a;
}

void Character::init()
{
}

int Character::attack()
{
	return 0;
}

void Character::takedamage(const int &)
{

}

const string Character::_classname[3] = {"", "战士", "法师"};

//Player
Player::Player()
{

}

void Player::changeweapon(const int &id)
{

}

void Player::init()//
{

}

void Player::newplayer()//新建角色
{
	_name = getName();//给角色起名
	char option = getUserOperation();//选择职业
	_level = 1;
	_exp = 0;
	_lv_exp = 20;
	switch (option)
	{
		case '1'://战士
			_class = 1;
			_maxhp = _hp = 15;
			_atk = 4;
			_def = 6;
			break;
		case '2'://法师
			_class = 2;
			_maxhp = _hp = 10;
			_atk = 6;
			_def = 4;
			break;
		default:
			throw "接受新建角色职业参数的时候出现问题";
			break;
	}
}

void Player::loadplayer()
{

}

int Player::attack()
{
	return 0;
}

void Player::takedamage(const int &hit)
{

}

//你操作这部分
char Player::getUserOperation()//获得用户的操作
{
	return '2';
}

string Player::getName()
{
	return "abaaba";
}
//你操作这部分

//Enemy
Enemy::Enemy()
{
}

void Enemy::init()
{

}

int Enemy::attack()
{
	return 0;
}

void Enemy::takedamage(const int &hit)
{

}