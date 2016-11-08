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

	// node�����update������ ÿһ֡��ˢ�� this->scheduleUpdate(); ��
	virtual void update(float delta);

public:
	Sprite* m_bgSprite1;	// ��������1
	Sprite* m_bgSprite2;	// ��������2
	void initBG();			// ��ʼ��ͼƬ����
};

#endif // 