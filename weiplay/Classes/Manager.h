#ifndef __MANAGER_H__
#define __MANAGER_H__


#include "cocos2d.h"
#include "Bullet.h"

USING_NS_CC;

/*
�Ե���ģʽʵ��Manager
	�������������ӵ��������
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
	// �ӵ��Ĺ�������
	Vector<Bullet *> m_bulletVector;
	Vector<Bullet *> & getBulletVector(){ return m_bulletVector; };

};

#endif //