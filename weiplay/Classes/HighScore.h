#ifndef _HIGH_SCORE_H_
#define _HIGH_SCORE_H_
#include "cocos2d.h"
//开始游戏场景
#include "StartGame.h"

USING_NS_CC;

//游戏结束场景
class HighScore : public Layer
{
public:
	HighScore(void);
	~HighScore(void);
public:
	static Scene * createScene();
	bool init();
	CREATE_FUNC(HighScore);
public:
	//回到游戏的回调函数
	void backGame(Ref * ref);
};

#endif