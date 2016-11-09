#ifndef _START_GAME_H_
#define _START_GAME_H_

#include "cocos2d.h"

USING_NS_CC;

class StartGame : public Layer
{
public:
	//继承layer需要覆写的几个函数
	static Scene * createScene();

	virtual bool init();

	//对游戏开始菜单的响应函数
	void play(cocos2d::Ref * ref);

	//对游戏帮助菜单的响应函数
	void help(cocos2d::Ref * ref);

	//对游戏最高分菜单的响应函数
	void highScore(cocos2d::Ref * ref);

	CREATE_FUNC(StartGame);
public:
	//构造和析构函数，新建项目的时候就自动为我们建立好了，vs还是很方便的
	StartGame(void);
	~StartGame(void);
};

#endif