#ifndef _START_GAME_H_
#define _START_GAME_H_

#include "cocos2d.h"

USING_NS_CC;

class StartGame : public Layer
{
public:
	//�̳�layer��Ҫ��д�ļ�������
	static Scene * createScene();

	virtual bool init();

	//����Ϸ��ʼ�˵�����Ӧ����
	void play(cocos2d::Ref * ref);

	//����Ϸ�����˵�����Ӧ����
	void help(cocos2d::Ref * ref);

	//����Ϸ��߷ֲ˵�����Ӧ����
	void highScore(cocos2d::Ref * ref);

	CREATE_FUNC(StartGame);
public:
	//����������������½���Ŀ��ʱ����Զ�Ϊ���ǽ������ˣ�vs���Ǻܷ����
	StartGame(void);
	~StartGame(void);
};

#endif