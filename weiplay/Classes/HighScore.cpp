#include "HighScore.h"
#include "StartGame.h"
#include "SaveData.h"

HighScore::HighScore(void)
{}

HighScore::~HighScore(void)
{}

Scene * HighScore::createScene()
{
	auto scene = Scene::create();
	auto layer = HighScore::create();

	scene->addChild(layer);

	return scene;
}

bool HighScore::init()
{
	if (!Layer::init())
		return false;

	auto size = Director::getInstance()->getWinSize();

	//设置背景图片
	auto background = Sprite::create("AirplaneResource\\ui\\shoot_background\\background.png");
	background->setPosition(Point(size.width / 2, size.height / 2));
	this->addChild(background);

	//从xml文件中读取中文显示出来
	auto dictionary = Dictionary::createWithContentsOfFile("fonts\\text.xml");
	
	int hightScore = SaveData::sharedUserData()->getHighScore();
	
	auto score_str = __String::createWithFormat("High Score is: %d", hightScore);
	auto score_label = Label::createWithTTF(score_str->getCString(), "fonts\\arial.ttf", 40);
	score_label->setPosition(Point(size.width / 2, size.height / 2));
	score_label->setColor(Color3B(100, 100, 100));
	this->addChild(score_label);


	//添加回到游戏的菜单
	auto returnItem = MenuItemImage::create();
	//returnItem->setNormalSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("AirplaneResource\\ui\\shoot_background\\btn_finish.png"));
	SpriteFrame *pSpriteFrame = SpriteFrame::create("AirplaneResource\\ui\\shoot_background\\btn_finish.png", Rect(0, 0, 150, 48));
	returnItem->setNormalSpriteFrame(pSpriteFrame);
	returnItem->setCallback(CC_CALLBACK_1(HighScore::backGame, this));

	auto menu = Menu::create(returnItem, NULL);
	menu->setPosition(Point(size.width / 2, size.height*0.3));
	this->addChild(menu, 1);

	return true;
}

void HighScore::backGame(Ref * ref)
{
	auto scene = StartGame::createScene();
	Director::getInstance()->replaceScene(scene);
}