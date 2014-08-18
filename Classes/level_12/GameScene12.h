#ifndef GameScene12_h
#define GameScene12_h

#include "cocos2d.h"
#include "Bglayer.h"
#include "Girl.h"
#include "../BaseLayer.h"


class GameScene12 : public BaseLayer{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(GameScene12);

	bool onTouchBegan(Touch *touch, Event *unused_event);
	//void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);

    virtual void restart();


	Point location1;
	Point location2;

	Sprite* m1;
	Sprite* m2;
	Sprite* m3;
	Sprite* hand;
	//num 添加标志位
	int movenum;
	int numOfM1;
	int numOfM2;
	int numOfM3;
	int allstop;
	int state;
	int abc;
private:

	//装备手链
	void carry();

	//刷新菜刀
	void refresh(float dt);
	//删除菜刀
	void del(float dt);

	void reset(float dt);
	void logic(float dt);


	Bglayer* bglayer;
	Girl* girl_nor;

	void Movedown();
};

#endif