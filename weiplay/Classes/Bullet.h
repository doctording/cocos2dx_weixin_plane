#ifndef __BULLET_H__
#define __BULLET_H__

#include "cocos2d.h"

USING_NS_CC;

/*
子弹 继承精灵类
	有自己的属性
		初始化
		自己移动
	子弹有生命周期，可以专门建立一个管理器，管理子弹
*/
class  Bullet : public Sprite 
{
public:
	Bullet(void){}
	~Bullet(void){}

public:

	virtual bool init();
	CREATE_FUNC(Bullet);
	virtual void onEnterTransitionDidFinish();

public:
	//初始化子弹
	void initBullet(std::string name);

	//子弹移动
	void move(float tm);
};

#endif