#ifndef __ENEMY_BASE_H__
#define __ENEMY_BASE_H__

#include "cocos2d.h"

USING_NS_CC;

/*
敌机类 同样继承自Sprite
	拥有的属性
		初始化
		爆炸动画
		敌机移动
*/
class EnemyBase : public Sprite
{
public:
	EnemyBase(void);
	~EnemyBase(void);
public:
	bool init();
	CREATE_FUNC(EnemyBase);
public:
	//初始化敌机，里边传入需要使用的纹理名字，提供默认参数
	void initEnemy(std::string name = "AirplaneResource\\ui\\shoot\\enemy1", int count = 4);

	//爆炸动画
	void blowUp();
	
	void onEnterTransitionDidFinish();
	
	//敌机移动
	void move(float tm);
	
	void setHp(int hp);
	int getHp();

	void hit();
private:
	
	//获得start-end范围内的一个随机数
	int getRandomNumber(int start, int end);
	
	//敌机的偏移量
	enum { OFFSET = 5 };
	
	//初始化敌机用到的纹理名称
	std::string m_frameName;
	
	//爆炸效果的纹理数量
	int m_count;

	//敌机的血量值
	int m_hp;
};

#endif