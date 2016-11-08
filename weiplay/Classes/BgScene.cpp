#include "BgScene.h"

USING_NS_CC;

Scene* Bg::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Bg::create();

	// add layer as a child to scene
	scene->addChild(layer);

	return scene;
}

bool Bg::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	/*auto sp = Sprite::create("CloseNormal.png");
	sp->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(sp,1);*/

	initBG();

	this->scheduleUpdate(); // 更新

	return true;
}

void Bg::initBG()
{
	m_bgSprite1 = Sprite::create("bg1.png");
	m_bgSprite1->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(m_bgSprite1, 0);

	m_bgSprite2 = Sprite::create("bg2.png");
	m_bgSprite2->setPosition(Point(visibleSize.width / 2, visibleSize.height + visibleSize.height / 2));
	this->addChild(m_bgSprite2, 0);

}

void Bg::update(float delta)
{
	int posY1 = m_bgSprite1->getPositionY();	//背景地图1的Y坐标
	int posY2 = m_bgSprite2->getPositionY();	//背景地图2的Y坐标

	int iSpeed = 1;	//地图滚动速度

	/* 两张地图向左滚动（两张地图是相邻的，所以要一起滚动，否则会出现空隙） */
	posY1 -= iSpeed;
	posY2 -= iSpeed;

	/* 图大小 */
	Size bgSize = m_bgSprite1->getContentSize();

	/* 当第1个地图完全离开屏幕时，第2个地图刚好完全出现在屏幕上，这时候就让第1个地图紧贴在
	 第2个地图后面 */
	if (posY1 <= -bgSize.height / 2) {
		posY1 = bgSize.height + bgSize.height / 2;
	}
	/* 同理，当第2个地图完全离开屏幕时，第1个地图刚好完全出现在屏幕上，这时候就让第2
	 个地图紧贴在第1个地图后面 */
	if (posY2 <= -bgSize.height / 2) {
		posY2 = bgSize.height + bgSize.height / 2;
	}

	m_bgSprite1->setPositionY(posY1);
	m_bgSprite2->setPositionY(posY2);
}