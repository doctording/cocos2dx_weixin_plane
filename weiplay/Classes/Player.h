#include "cocos2d.h"

USING_NS_CC;

class  PlaneLayer : public cocos2d::Layer
{
public:
    
	PlaneLayer(void){}

	~PlaneLayer(void){}

	static PlaneLayer* create();

	virtual bool init();

public:
	static PlaneLayer* sharedPlane; //提供sharedPlane全局指针

	Sprite* plane;

	void moveLeftOrRight(char c); // 飞机的移动属性
};