#include "Help.h"
#include "StartGame.h"

USING_NS_CC;

#include "ui\CocosGUI.h"
#include "editor-support\cocostudio\CCSGUIReader.h"

using namespace cocos2d::ui;
using namespace cocostudio;

Scene* Help::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Help::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Help::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

	auto ui = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("Help\\Help_1.ExportJson"); 
	ui->setPosition(Point(0, 0));
	this->addChild(ui);

	Button* btnBack = (Button*)Helper::seekWidgetByName(ui, "btn_back");

	btnBack->addTouchEventListener(this, toucheventselector(Help::back));
    return true;
}


void Help::back(Ref* pSender, cocos2d::ui::TouchEventType type)
{
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN: // 单机时间开始时触发（按下的时候）
		break;
	case TouchEventType::TOUCH_EVENT_MOVED: // 按下之后，进行移动操作时触发
		break;
	case TouchEventType::TOUCH_EVENT_ENDED: // 按下之后，然后松开触发
	{
		auto scene = StartGame::createScene();
		Director::getInstance()->replaceScene(scene);
	}
		break;
	case TouchEventType::TOUCH_EVENT_CANCELED: // 中断触发
		break;
	default:
		break;
	}
}
