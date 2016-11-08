#ifndef __ENEMY_BASE_H__
#define __ENEMY_BASE_H__

#include "cocos2d.h"

USING_NS_CC;

/*
�л��� ͬ���̳���Sprite
	ӵ�е�����
		��ʼ��
		��ը����
		�л��ƶ�
*/
class EnemyBase : public Sprite
{
public:
	EnemyBase(void);
	~EnemyBase(void);
public:
	bool init();
	CREATE_FUNC(EnemyBase);
public:
	//��ʼ���л�����ߴ�����Ҫʹ�õ��������֣��ṩĬ�ϲ���
	void initEnemy(std::string name = "AirplaneResource\\ui\\shoot\\enemy1", int count = 4);

	//��ը����
	void blowUp();
	
	void onEnterTransitionDidFinish();
	
	//�л��ƶ�
	void move(float tm);
	
	void setHp(int hp);
	int getHp();

	void hit();
private:
	
	//���start-end��Χ�ڵ�һ�������
	int getRandomNumber(int start, int end);
	
	//�л���ƫ����
	enum { OFFSET = 5 };
	
	//��ʼ���л��õ�����������
	std::string m_frameName;
	
	//��ըЧ������������
	int m_count;

	//�л���Ѫ��ֵ
	int m_hp;
};

#endif