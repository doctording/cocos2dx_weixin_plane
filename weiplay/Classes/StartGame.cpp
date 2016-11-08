#include "StartGame.h"
#include "BgScene.h"

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

	//添加一个游戏开始按钮
	//从xml文件中读取中文显示出来
	auto dictionary = Dictionary::createWithContentsOfFile("fonts\\text.xml");
	Label* playText = Label::createWithTTF(((__String *)(dictionary->objectForKey("play")))->getCString(),
		"fonts\\DFPShaoNvW5-GB.ttf", 40);
	playText->setColor(Color3B(100, 100, 100));

	auto playMenu = MenuItemLabel::create(playText, CC_CALLBACK_1(StartGame::play, this));
	auto menu = Menu::create(playMenu, NULL);
	menu->setPosition(size.width / 2, size.height*0.3);
	this->addChild(menu);

	return true;
}

//开始游戏按钮的响应函数
void StartGame::play(cocos2d::Ref * ref)
{
	//CCLOG("play game!");
	auto scene = Bg::createScene();
	Director::getInstance()->replaceScene(scene);
}