#ifndef _HIGH_SCORE_H_
#define _HIGH_SCORE_H_
#include "cocos2d.h"
//��ʼ��Ϸ����
#include "StartGame.h"

USING_NS_CC;

//��Ϸ��������
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
	//�ص���Ϸ�Ļص�����
	void backGame(Ref * ref);
};

#endif