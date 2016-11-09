#include "SaveData.h"

// 单例设计模式
SaveData * SaveData::m_userData = NULL;

SaveData * SaveData::sharedUserData()
{
	if (m_userData == NULL)
	{
		m_userData = new SaveData();
	}

	return m_userData;
}

void SaveData::freeUserData()
{
	if (m_userData)
	{
		delete m_userData;
		m_userData = NULL;
	}
}

//在UserData的构造函数中为游戏数据初始化
SaveData::SaveData()
{
	bool isExist = false;
	isExist = UserDefault::getInstance()->getBoolForKey("isExist");
	if (!isExist)
	{
		UserDefault::getInstance()->setBoolForKey("isExist", true);
		m_high_score = 0;
		UserDefault::getInstance()->setIntegerForKey("highScore", m_high_score);
	}
}

//返回用户的声音数据
int SaveData::getHighScore()
{
	this->m_high_score = UserDefault::getInstance()->getIntegerForKey("highScore");
	return this->m_high_score;
}

//设置用户的数据，并且保存在文件中，最后使用flush来刷新近XML文件中
void SaveData::setHighScore(int score)
{
	this->m_high_score = score;
	UserDefault::getInstance()->setIntegerForKey("highScore", this->m_high_score);
	//在win32上这个函数的实现是空的
	UserDefault::getInstance()->flush();
}