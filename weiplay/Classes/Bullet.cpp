#include "Bullet.h"
#include "Manager.h"

USING_NS_CC;

bool Bullet::init()
{
	if (!Sprite::init())
        return false;

    return true;
}

void Bullet::onEnterTransitionDidFinish()
{
	Sprite::onEnterTransitionDidFinish();
	//每隔一定时间移动子弹
	this->schedule(SEL_SCHEDULE(&Bullet::move), 0.08f);
}

//根据传入的纹理名称来初始化子弹类
void Bullet::initBullet(std::string name)
{
	//this->initWithSpriteFrameName(name);
	this->initWithFile(name);
}

/*
子弹移动 从发射位置往上 出了屏幕就应该被销毁
*/
void Bullet::move(float tm)
{
	int OFFSET = 35;
	this->setPositionY(this->getPositionY() + OFFSET);
	//子弹移动出了屏幕
	if (this->getPositionY() > Director::getInstance()->getWinSize().height) // 出了屏幕
	{
		this->removeFromParentAndCleanup(true); // 先从场景中移除出去
		// 还需要销毁这个对象
		//从管理器中移除出去
		auto & bulletVector = Manager::getInstance()->getBulletVector();
		bulletVector.eraseObject(this);
		// 使用 log
		//CCLOG("bulletSize=%d", (int)bulletVector.size());
	}
}