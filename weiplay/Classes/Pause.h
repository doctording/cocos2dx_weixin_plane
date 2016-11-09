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
	static Scene * scene(RenderTexture* sqr, bool isFlip); // ����һ�����Ľ�ͼ��Ϊ����������create
	static Scene * createScene();
	CREATE_FUNC(Pause);

	// �����¼�
	void onKeyPressed(EventKeyboard::KeyCode keycode, cocos2d::Event *event);
	void onKeyReleased(EventKeyboard::KeyCode keycode, cocos2d::Event *event);
};

#endif