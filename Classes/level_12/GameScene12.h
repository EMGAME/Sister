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
	//num ÃÌº”±Í÷æŒª
	int movenum;
	int numOfM1;
	int numOfM2;
	int numOfM3;
	int otherlife;
	int state;
	int abc;

	//‘ˆº”“ª∏ˆ ˝◊È¿¥±£¥Êπ÷ŒÔ
	//cocos2d::Vector<cocos2d::Sprite*> M_Vetor;


	UILayer* uiLayer;
	virtual void restart();
    //下一关
    virtual void nextLevel();
private:
    
	//◊∞±∏ ÷¡¥
	void carry();
    
	//ÀÊª˙º”‘ÿ“ª∏ˆ
	void loadM(float dt);

	void Mhide();
	
	Bglayer* bglayer;
	Girl* girl_nor;

};


#endif