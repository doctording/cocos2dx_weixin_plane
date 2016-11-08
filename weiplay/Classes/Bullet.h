#ifndef __BULLET_H__
#define __BULLET_H__

#include "cocos2d.h"

USING_NS_CC;

/*
�ӵ� �̳о�����
	���Լ�������
		��ʼ��
		�Լ��ƶ�
	�ӵ����������ڣ�����ר�Ž���һ���������������ӵ�
*/
class  Bullet : public Sprite 
{
public:
	Bullet(void){}
	~Bullet(void){}

public:

	virtual bool init();
	CREATE_FUNC(Bullet);
	virtual void onEnterTransitionDidFinish();

public:
	//��ʼ���ӵ�
	void initBullet(std::string name);

	//�ӵ��ƶ�
	void move(float tm);
};

#endif