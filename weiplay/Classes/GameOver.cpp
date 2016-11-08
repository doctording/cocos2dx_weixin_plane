#include "GameOver.h"

GameOver::GameOver(void)
{
}

GameOver::~GameOver(void)
{
}

Scene * GameOver::createScene()
{
	auto scene = Scene::create();
	auto layer = GameOver::create();
	scene->addChild(layer);

	return scene;
}

bool GameOver::init()
{
	if (!Layer::init())
		return false;

	auto size = Director::getInstance()->getWinSize();

	//设置背景图片
	auto background = Sprite::create("AirplaneResource\\ui\\shoot_background\\gameover.png");
	background->setPosition(Point(size.width / 2, size.height / 2));
	this->addChild(background);

	//添加回到游戏的菜单
	auto returnItem = MenuItemImage::create();
	//returnItem->setNormalSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("AirplaneResource\\ui\\shoot_background\\btn_finish.png"));
	SpriteFrame *pSpriteFrame = SpriteFrame::create("AirplaneResource\\ui\\shoot_background\\btn_finish.png", Rect(0, 0, 150, 48));
	returnItem->setNormalSpriteFrame(pSpriteFrame);
	returnItem->setCallback(CC_CALLBACK_1(GameOver::backGame, this));
	
	auto menu = Menu::create(returnItem, NULL);
	menu->setPosition(Point(size.width / 2, size.height*0.3));
	this->addChild(menu,1);

	//添加玩家得分到结束界面 TODO
	auto score_int = 0; 
	auto score_str = __String::createWithFormat("%d", score_int);
	auto score = Label::createWithTTF(score_str->getCString(), "fonts\\arial.ttf", 40);
	score->setPosition(Point(size.width / 2, size.height / 2));
	score->setColor(Color3B(100, 100, 100));
	this->addChild(score);

	return true;
}

void GameOver::backGame(Ref * ref)
{
	//切换到开始游戏的场景
	Director::getInstance()->replaceScene(StartGame::createScene());
}