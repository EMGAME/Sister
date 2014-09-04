#ifndef GameScene12_h
#define GameScene12_h

#include "cocos2d.h"
#include "Bglayer.h"
#include "Girl.h"
#include "BaseLayer.h"
#include "../UILayer/UILayer.h"

USING_NS_CC;

class GameScene12 : public BaseLayer{
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
	//num 添加标志位
	int movenum;
	int numOfM1;
	int numOfM2;
	int numOfM3;
	int otherlife;
	int state;
	int abc;

	//增加一个数组来保存怪物
	//cocos2d::Vector<cocos2d::Sprite*> M_Vetor;


	UILayer* uiLayer;
	virtual void restart();
	
private:

	//装备手链
	void carry();
    
	//随机加载一个
	void loadM(float dt);

	void Mhide();
	
	Bglayer* bglayer;
	Girl* girl_nor;

};


#endif