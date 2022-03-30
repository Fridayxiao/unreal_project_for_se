#pragma once
#include "all_headfiles.h"
#include <string>
class GAME
{
	public:
	GAME();
	~GAME();
	void newgame();//新游戏
	void loadgame();//读取游戏
	void savegame();//存档
	void detect_savefile();//检测存档文件


	private:
	//读xml文件用的，下面数字表示层级
	mxml_node_t *xml;//1，基础
	mxml_node_t *data;//2，数据，上级xml
	mxml_node_t *player;//3，玩家数据，上级data
	mxml_node_t *status;//4，状态属性，上级player
	mxml_node_t *setting;//2，游戏设置，上级xml
	mxml_node_t *d;//拿来填数据
	FILE* fp;//读存档文件
	errno_t f_error;//vs要求用fopen_s，这个是配套的
	int to_int(const char *);//因为callback的问题所以自己写个转int的函数
	Player *_player;
	bool _saveexist;//true有存档, false没有存档
};