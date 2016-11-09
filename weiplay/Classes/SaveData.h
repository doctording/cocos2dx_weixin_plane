#ifndef _SAVE_DATA_H_
#define _SAVE_DATA_H_
#include "cocos2d.h"

USING_NS_CC;

class SaveData
{
public:
	//���µ�set��get���������������úͻ�ȡ��Ϸ���ݵ�
	int getHighScore();
	void setHighScore(int score);
	static SaveData * sharedUserData();
	//��Appdelegate�����������е��ã������ͷ�m_userData���ݳ�Ա
	void freeUserData();
private:
	//�����Ƿ񲥷ű������ֵĳ�Ա����
	int m_high_score;
	static SaveData * m_userData;
	//�ڹ��캯����������һЩ��ʼ���Ĳ���
	SaveData();
};

#endif