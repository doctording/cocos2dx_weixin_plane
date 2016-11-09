#include "StartGame.h"
#include "BgScene.h"
#include "Help.h"
#include "HighScore.h"

StartGame::StartGame(void)
{
}

StartGame::~StartGame(void)
{

}

Scene * StartGame::createScene()
{
	auto scene = Scene::create();
	auto layer = StartGame::create();
	scene->addChild(layer);

	return scene;
}

bool StartGame::init()
{
	if (!Layer::init())
		return false;

	auto size = Director::getInstance()->getWinSize();

	//使用缓存文件创建精灵
	auto background = Sprite::create("AirplaneResource\\ui\\shoot_background\\background.png");
	background->setPosition(Point(size.width / 2, size.height / 2));
	this->addChild(background);

	//设置logo
	auto logo = Sprite::create("AirplaneResource\\ui\\shoot_background\\shoot_copyright.png");
	logo->setPosition(Point(size.width / 2, size.height - logo->getContentSize().height));
	//设置透明度是0
	logo->setOpacity(0);
	this->addChild(logo);

	//设置logo的动作
	auto fade = FadeIn::create(2.0f);
	logo->runAction(fade);

	//从xml文件中读取中文显示出来
	auto dictionary = Dictionary::createWithContentsOfFile("fonts\\text.xml");
	// 1 添加一个游戏开始按钮
	Label* playText = Label::createWithTTF(((__String *)(dictionary->objectForKey("play")))->getCString(),
		"fonts\\DFPShaoNvW5-GB.ttf", 40);
	playText->setColor(Color3B(100, 100, 100));
	auto playMenu = MenuItemLabel::create(playText, CC_CALLBACK_1(StartGame::play, this));
	
	auto menu = Menu::create(playMenu, NULL);
	menu->setPosition(size.width / 2, size.height*0.3);
	this->addChild(menu);
	// 2 游戏帮助按钮
	Label* playText2 = Label::createWithTTF(((__String *)(dictionary->objectForKey("help")))->getCString(),
		"fonts\\DFPShaoNvW5-GB.ttf", 40);
	playText2->setColor(Color3B(100, 100, 100));
	auto playMenu2 = MenuItemLabel::create(playText2, CC_CALLBACK_1(StartGame::help, this));

	auto menu2 = Menu::create(playMenu2, NULL);
	menu2->setPosition(size.width / 2, size.height*0.2);
	this->addChild(menu2);

	// 2 游戏帮助按钮
	Label* playText3 = Label::createWithTTF(((__String *)(dictionary->objectForKey("highScore")))->getCString(),
		"fonts\\DFPShaoNvW5-GB.ttf", 40);
	playText3->setColor(Color3B(100, 100, 100));
	auto playMenu3 = MenuItemLabel::create(playText3, CC_CALLBACK_1(StartGame::highScore, this));

	auto menu3 = Menu::create(playMenu3, NULL);
	menu3->setPosition(size.width / 2, size.height*0.1);
	this->addChild(menu3);

	return true;
}

//开始游戏按钮的响应函数
void StartGame::play(cocos2d::Ref * ref)
{
	//CCLOG("play game!");
	auto scene = Bg::createScene();
	Director::getInstance()->replaceScene(scene);
}

// 帮助界面
void StartGame::help(cocos2d::Ref * ref)
{
	auto scene = Help::createScene();
	Director::getInstance()->replaceScene(scene);
}

// 最高分界面
void StartGame::highScore(cocos2d::Ref * ref)
{
	auto scene = HighScore::createScene();
	Director::getInstance()->replaceScene(scene);
}