#ifndef GameScene12_h
#define GameScene12_h

#include "cocos2d.h"
#include "level_12/Bglayer.h"
#include "level_12/Girl.h"


class GameScene12 : public cocos2d::Layer{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(GameScene12);

	bool onTouchBegan(Touch *touch, Event *unused_event);
	//void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);


	Point location1;
	Point location2;

	Sprite* m1;
	Sprite* m2;
	Sprite* m3;
	Sprite* hand;
	//num ���ӱ�־λ
	int movenum;
	int numOfM1;
	int numOfM2;
	int numOfM3;
	int otherlife;
	int state;
	int abc;

	//����һ���������������
	cocos2d::Vector<cocos2d::Sprite*> M_Vetor;
private:

	//װ������
	void carry();
    // ��������
	void logic(float dt);

	//�������һ��
	void loadM(float dt);

	void Mhide();
	//void createM(int a);


	Bglayer* bglayer;
	Girl* girl_nor;

};

#endif