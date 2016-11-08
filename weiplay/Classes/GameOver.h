#ifndef _GAME_OVER_H_
#define _GAME_OVER_H_
#include "cocos2d.h"
//开始游戏场景
#include "StartGame.h"

USING_NS_CC;

//游戏结束场景
class GameOver : public Layer
{
public:
	GameOver(void);
	~GameOver(void);
public:
	static Scene * createScene();
	bool init();
	CREATE_FUNC(GameOver);
public:
	//回到游戏的回调函数
	void backGame(Ref * ref);
};

#endif