#ifndef __BG_SCENE_H__
#define __BG_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class  Bg : public cocos2d::Layer
{
public:

	static Scene* createScene();

	virtual bool init();

	CREATE_FUNC(Bg);

public:
	Size visibleSize;
	Point origin;

	// node对象的update方法（ 每一帧都刷新 this->scheduleUpdate(); ）
	virtual void update(float delta);

public:
	Sprite* m_bgSprite1;	// 背景精灵1
	Sprite* m_bgSprite2;	// 背景精灵2
	void initBG();			// 初始化图片背景
};

#endif // 