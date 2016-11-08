#ifndef __MANAGER_H__
#define __MANAGER_H__


#include "cocos2d.h"
#include "Bullet.h"
#include "Enemy.h"

USING_NS_CC;

/*
以单例模式实现Manager
	用来管理类似子弹，怪物等
*/
class  Manager
{
public:
    
	static Manager * getInstance();
	static void Manager::freeInstance(void);

public:
	static Manager * m_manager;
	Manager();
	bool init();

public:
	// 子弹的管理容器
	Vector<Bullet *> m_bulletVector;
	Vector<Bullet *> & getBulletVector(){ return m_bulletVector; };

	// 敌机管理器
	Vector<EnemyBase *> m_enemyVector;
	Vector<EnemyBase *> & getEnemyVector(){ return m_enemyVector; };
};

#endif //