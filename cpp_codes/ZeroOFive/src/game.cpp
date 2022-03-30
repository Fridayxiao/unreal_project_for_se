#include "..\\include\\game.h"
GAME::GAME()//游戏初始化
{
	_player = new Player;



	detect_savefile();
	/*
	按照我在日志写的大概的思路，有个“新游戏”和“继续游戏”的按钮，当然你也可以自己发挥
	游戏初始化的时候先判断有没有存档文件在，如果没有存档文件在的话“继续游戏”的按键就灰掉或者直接不存在
	如果有存档文件的时候就可以把“继续游戏”这个界面整出来
	以下部分你来发挥
	*/

//	newgame();
	loadgame();
}

GAME::~GAME()
{
	delete player;
}

int GAME::to_int(const char *temp)
{
	int num = 0;
	int len = strlen(temp);
	for (int i = 0; i < len; i++)
	{
		num = num * 10 + int(temp[i]) - 48;
	}
	return num;
}

void GAME::newgame()//创建新游戏
{
	_player->newplayer();//新建角色
	//创建xml存档
	savegame();
}

void GAME::loadgame()
{
	f_error = fopen_s(&fp, "data\\save.xml", "r");
	if (f_error)
	{
		throw "读取存档出现错误";
	}
	//读xml文档
	xml = mxmlLoadFile(NULL, fp, MXML_OPAQUE_CALLBACK);
	data = mxmlGetFirstChild(xml);
	player = mxmlGetFirstChild(data);
	status = mxmlGetFirstChild(player);
	d = mxmlGetFirstChild(status);
	setting = mxmlGetNextSibling(data);
	//读player信息
	_player->_name = mxmlGetOpaque(d);//名字
	d = mxmlGetNextSibling(d);
	_player->_class = to_int(mxmlGetOpaque(d));//职业
	d = mxmlGetNextSibling(d);
	_player->_level = to_int(mxmlGetOpaque(d));//等级
	d = mxmlGetNextSibling(d);
	_player->_exp = to_int(mxmlGetOpaque(d));//经验
	d = mxmlGetNextSibling(d);
	_player->_lv_exp = to_int(mxmlGetOpaque(d));//升级经验
	d = mxmlGetNextSibling(d);
	_player->_hp = to_int(mxmlGetOpaque(d));//当前血量
	d = mxmlGetNextSibling(d);
	_player->_maxhp = to_int(mxmlGetOpaque(d));//最大血量
	d = mxmlGetNextSibling(d);
	_player->_atk = to_int(mxmlGetOpaque(d));//攻击
	d = mxmlGetNextSibling(d);
	_player->_def = to_int(mxmlGetOpaque(d));//防御

	fclose(fp);
	_player->loadplayer();//登陆角色

}

void GAME::savegame()
{
	detect_savefile();
	if (!_saveexist)//如果存档不存在
	{//创建个新存档
		//这里思路改正一下，先整个存档文件创建完，再存数据
		xml = mxmlNewXML("1.0");
		data = mxmlNewElement(xml, "data");
		player = mxmlNewElement(data, "player1");
		status = mxmlNewElement(player, "status");
		d = mxmlNewElement(status, "name");//名字
		d = mxmlNewElement(status, "class");//职业
		d = mxmlNewElement(status, "level");//等级
		d = mxmlNewElement(status, "exp");//经验
		d = mxmlNewElement(status, "lv_exp");//升级要的经验
		d = mxmlNewElement(status, "hp");//血量
		d = mxmlNewElement(status, "maxhp");//最大血量
		d = mxmlNewElement(status, "atk");//攻击
		d = mxmlNewElement(status, "def");//防御
		//人物数据创建完毕，背包以后再想怎么操作
		//背包部分
		//推图进度
		//其他玩意
		//成就？
		//系统设置
		//应该没啥别了？

		//开始往xml写东西
		d = mxmlGetFirstChild(status);
		mxmlNewText(d, 0, _player->_name.c_str());//名字
		d = mxmlGetNextSibling(d);
		mxmlNewInteger(d, _player->_class);//职业
		d = mxmlGetNextSibling(d);
		mxmlNewInteger(d, _player->_level);//等级
		d = mxmlGetNextSibling(d);
		mxmlNewInteger(d, _player->_exp);//经验
		d = mxmlGetNextSibling(d);
		mxmlNewInteger(d, _player->_lv_exp);//升级需要经验
		d = mxmlGetNextSibling(d);
		mxmlNewInteger(d, _player->_hp);//当前血量
		d = mxmlGetNextSibling(d);
		mxmlNewInteger(d, _player->_maxhp);//血量上限
		d = mxmlGetNextSibling(d);
		mxmlNewInteger(d, _player->_atk);//攻击
		d = mxmlGetNextSibling(d);
		mxmlNewInteger(d, _player->_def);//防御
	}
	//以下为存档
	f_error = fopen_s(&fp, "data\\save.xml", "w");
	if (f_error)
	{
		throw "存档的时候出现问题了";
	}
	mxmlSaveFile(xml, fp, MXML_NO_CALLBACK);//存xml
	fclose(fp);
	_saveexist = true;//更新为能检测到存档
}

void GAME::detect_savefile()//检测存档文件
{//暂时不考虑存档出错的问题，默认不会崩档
	f_error = fopen_s(&fp, "data/save.xml", "r");
	if (f_error)//没存档
	{
		_saveexist = false;
	}
	else//有存档
	{
		_saveexist = true;
		fclose(fp);
	}
}