#include "Player.h"

USING_NS_CC;

PlaneLayer* PlaneLayer::sharedPlane = NULL; //静态变量要在cpp外初始化  

PlaneLayer* PlaneLayer::create()
{
	PlaneLayer *pRet = new PlaneLayer();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		sharedPlane = pRet;//获得静态指针sharedPlane的值  
		return pRet;
	}
	else
	{
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}

bool PlaneLayer::init()
{

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//创建飞机精灵
	plane = Sprite::create("AirplaneResource/ui/shoot/hero1.png");
	plane->setPosition(Point(visibleSize.width / 2, plane->getContentSize().height / 2)); //飞机放置在底部中央  
	this->addChild(plane, 0, 100);//添加精灵，AIRPLANE是tag  

	// 根据图片帧制作动画
	Vector<SpriteFrame*> spriteFrameVec;
	auto spriteFrameCache = SpriteFrameCache::getInstance();

	char path[256] = { 0 };
	for (int i = 1; i <= 2; ++i)
	{
		sprintf(path, "AirplaneResource/ui/shoot/hero%d.png", i);

		// 150*105是图片的大小，貌似这样直接设定是不好的；但是还必须提供这个参数
		// 应该给这个Rect参数提供一个默认参数，默认加载整个图片
		SpriteFrame *pSpriteFrame = SpriteFrame::create(path, Rect(0, 0, 102, 126));

		// 加入SpriteFrameCache中
		spriteFrameCache->addSpriteFrame(pSpriteFrame, path);
		spriteFrameVec.pushBack(pSpriteFrame);
	}
	auto animation = Animation::createWithSpriteFrames(spriteFrameVec, 0.1);
	AnimationCache::getInstance()->addAnimation(animation, "animation");
	auto animate = Animate::create(AnimationCache::getInstance()->getAnimation("animation"));

	Blink *blink = Blink::create(5.0f, 10);//闪烁动画
	plane->runAction(blink);//执行闪烁动画

	auto repeat = Repeat::create(animate, 5); // 执行精灵帧自身动画
	plane->runAction(repeat);

	return true;
}

void PlaneLayer::moveLeftOrRight(char c)
{
	int OFFSET = 5;
	float nx; 
	if (c == 'A')
		nx = plane->getPositionX() - OFFSET;
	if (c == 'D')
		nx = plane->getPositionX() + OFFSET;
	float ny = plane->getPositionY();
	if (nx < 0)
		nx = 0;
	if (nx >  Director::getInstance()->getVisibleSize().width)
		nx = Director::getInstance()->getVisibleSize().width;
	//MoveTo* moveTo = MoveTo::create(0.8f, Point(nx, ny));
	// 精灵执行动作
	//plane->runAction(moveTo);
	plane->setPosition(Point(nx, ny));
}

#if 0
void PlaneLayer::blow()
{
	// 根据图片帧制作动画,飞机自生的爆炸
	Vector<SpriteFrame*> spriteFrameVec;
	auto spriteFrameCache = SpriteFrameCache::getInstance();

	char path[256] = { 0 };
	for (int i = 1; i <= 4; ++i)
	{
		sprintf_s(path, "AirplaneResource/ui/shoot/hero_blowup_n%d.png", i);

		// 150*105是图片的大小，貌似这样直接设定是不好的；但是还必须提供这个参数
		// 应该给这个Rect参数提供一个默认参数，默认加载整个图片
		SpriteFrame *pSpriteFrame = SpriteFrame::create(path, Rect(0, 0, 102, 126));

		// 加入SpriteFrameCache中
		spriteFrameCache->addSpriteFrame(pSpriteFrame, path);
		spriteFrameVec.pushBack(pSpriteFrame);
	}

	//auto animation = Animation::createWithSpriteFrames(spriteFrameVec, 0.1);
	//AnimationCache::getInstance()->addAnimation(animation, "animation");
	//auto animate = Animate::create(AnimationCache::getInstance()->getAnimation("animation"));

	//auto repeat = Repeat::create(animate, 5); // 执行精灵帧自身动画
	//plane->runAction(repeat);
	
	Animation* animation = Animation::createWithSpriteFrames(spriteFrameVec);
	animation->setLoops(1);
	animation->setRestoreOriginalFrame(false); // 设置是否在动画播放结束后恢复到第一帧
	// should last 2.0 seconds. And there are 4 frames.
	animation->setDelayPerUnit(1.3f / 4.0f);
	Animate* peeAnimate = Animate::create(animation);
	plane->runAction(peeAnimate);
}
#endif