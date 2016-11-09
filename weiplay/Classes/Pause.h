#ifndef _PAUSE_H_
#define _PAUSE_H_
#include "cocos2d.h"

USING_NS_CC;

class Pause : public Layer
{
public:
	Pause(void);
	~Pause(void);
public:
	bool init();
	static Scene * scene(RenderTexture* sqr, bool isFlip); // 把上一场景的截图作为背景，重新create
	static Scene * createScene();
	CREATE_FUNC(Pause);

	// 键盘事件
	void onKeyPressed(EventKeyboard::KeyCode keycode, cocos2d::Event *event);
	void onKeyReleased(EventKeyboard::KeyCode keycode, cocos2d::Event *event);
};

#endif