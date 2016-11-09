#include "Pause.h"

Pause::Pause(void)
{
}

Pause::~Pause(void)
{
}

Scene * Pause::createScene()
{
	auto scene = Scene::create();
	auto layer = Pause::create();
	scene->addChild(layer);

	return scene;
}

bool Pause::init()
{

	if (!Layer::init())
		return false;
	auto size = Director::getInstance()->getWinSize();
	//添加恢复游戏的按钮
	auto resume = MenuItemImage::create();
	//
	SpriteFrame *pSpriteFrame = SpriteFrame::create("resume_pressed.png", Rect(0, 0, 60, 45));
	//resume->setNormalSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("resume_button.png"));
	resume->setNormalSpriteFrame(pSpriteFrame);
	auto callback = [](Ref * ref)
	{
		//弹出保存的场景
		Director::getInstance()->popScene();
	};
	resume->setCallback(callback);
	auto menu = Menu::create(resume, NULL);
	//menu->setPosition(Point(size.width*0.95, size.height*0.97));
	menu->setPosition(Point(size.width / 2, size.height / 2));
	this->addChild(menu,1);


	// 键盘事件
	auto listenerKeyPad = EventListenerKeyboard::create();
	listenerKeyPad->onKeyPressed = CC_CALLBACK_2(Pause::onKeyPressed, this);
	listenerKeyPad->onKeyReleased = CC_CALLBACK_2(Pause::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyPad, this);

	return true;
}

Scene* Pause::scene(RenderTexture* sqr, bool isFlip)
{
	Scene *m_scene = Scene::create();

	Sprite *_spr = Sprite::createWithTexture(sqr->getSprite()->getTexture());
	_spr->setPosition(Point(400.0 / 2.0 , 550.0 / 2.0));
	_spr->setFlipY(isFlip);
	_spr->setColor(ccGRAY);
	m_scene->addChild(_spr,0);

	auto layer = Pause::create();
	m_scene->addChild(layer);

	return m_scene;
}

// 按键 按下
void Pause::onKeyPressed(EventKeyboard::KeyCode keycode, cocos2d::Event *event)
{
	switch (keycode)
	{
	
	// I键 返回游戏
	case EventKeyboard::KeyCode::KEY_I:
	{
		Director::getInstance()->popScene();
	}
	break;

	default:
		break;
	}
}

void Pause::onKeyReleased(EventKeyboard::KeyCode keycode, cocos2d::Event *event)
{}