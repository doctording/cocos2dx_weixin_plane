#ifndef _GAME_OVER_H_
#define _GAME_OVER_H_
#include "cocos2d.h"
//��ʼ��Ϸ����
#include "StartGame.h"

USING_NS_CC;

//��Ϸ��������
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
	//�ص���Ϸ�Ļص�����
	void backGame(Ref * ref);
};

#endif