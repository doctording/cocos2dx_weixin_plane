#ifndef _SAVE_DATA_H_
#define _SAVE_DATA_H_
#include "cocos2d.h"

USING_NS_CC;

class SaveData
{
public:
	//以下的set和get方法都是用来设置和获取游戏数据的
	int getHighScore();
	void setHighScore(int score);
	static SaveData * sharedUserData();
	//在Appdelegate的析构函数中调用，用来释放m_userData数据成员
	void freeUserData();
private:
	//保存是否播放背景音乐的成员变量
	int m_high_score;
	static SaveData * m_userData;
	//在构造函数中来进行一些初始化的操作
	SaveData();
};

#endif