#include "Enemy.h"
#include "Manager.h"

EnemyBase::EnemyBase(void)
{
}

EnemyBase::~EnemyBase(void)
{
}

bool EnemyBase::init()
{
	if (!Sprite::init())
		return false;

	return true;
}

//这里传入纹理的名称来初始化敌机
void EnemyBase::initEnemy(std::string name, int count)
{
	auto size = Director::getInstance()->getVisibleSize();

	//为成员变量赋值
	m_frameName = name;
	m_count = count;

	//使用精灵图片初始化
	std::string str = name + ".png";
	//this->initWithSpriteFrameName(str);
	this->initWithFile(str);

	//横纵坐标按照以下的方法设置
	auto point = Point(getRandomNumber(this->getContentSize().width / 2, size.width - this->getContentSize().width / 2),
		size.height);
	//auto point = Point(size.width / 2 , size.height / 2);
	this->setPosition(point);
}

//如果要获得a~b之间的一个随机数，则应该是CCRANDOM_0_1*(b-a)+a，传入的参数就是a和b
int EnemyBase::getRandomNumber(int start, int end)
{
	return CCRANDOM_0_1()*(end - start) + start;
}

// 场景切换完调用
void EnemyBase::onEnterTransitionDidFinish()
{
	//先调用父类的
	Sprite::onEnterTransitionDidFinish();
	//调用schedule函数，不断的改变敌机的坐标
	this->schedule(SEL_SCHEDULE(&EnemyBase::move)); 
}

//敌机的移动
void EnemyBase::move(float tm)
{
	auto point = this->getPositionY() - OFFSET;
	this->setPositionY(point);
	//如果移动出了屏幕则从父节点中移除
	if (point < -this->getContentSize().height)
	{
		this->removeFromParentAndCleanup(true);

		//从管理器中移除出去
		auto & enemyVector = Manager::getInstance()->getEnemyVector();
		enemyVector.eraseObject(this);
		//CCLOG("enemySize=%d", (int)enemyVector.size());
	}
}

//敌机爆炸动画，这个类是敌机类的基类，所以敌机的名字和用到的动画帧数是不确定的，需要在参数中传递
void EnemyBase::blowUp()
{
	Vector<SpriteFrame *> vector;
	auto spriteFrameCache = SpriteFrameCache::getInstance();

	for (int i = 0; i<m_count; i++)
	{
		auto frameName = __String::createWithFormat("_down%d.png", i + 1);
		//将传入的字符串和frameName拼接起来，str是最后使用的spriteframe的名字
		std::string str = m_frameName + frameName->getCString();
		//auto spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
		SpriteFrame *pSpriteFrame = SpriteFrame::create(str, Rect(0, 0, 69, 95));
		spriteFrameCache->addSpriteFrame(pSpriteFrame, str);
		vector.pushBack(pSpriteFrame);
	}

	//设置动画帧的间隔，同时动画只执行一次
	/*auto animation = Animation::createWithSpriteFrames(vector, 1.2f, 1);
	auto animate = Animate::create(animation);
	this->runAction(animate);*/
	auto animation = Animation::createWithSpriteFrames(vector, 0.1);
	AnimationCache::getInstance()->addAnimation(animation, "animation");
	auto animate = Animate::create(AnimationCache::getInstance()->getAnimation("animation"));
	
	auto repeat = Repeat::create(animate, 5);
	this->runAction(repeat);
}