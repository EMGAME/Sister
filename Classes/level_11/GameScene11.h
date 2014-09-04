#ifndef GameScene11_h
#define GameScene11_h

#include "cocos2d.h"
#include "BaseLayer.h"
#include "../UILayer/UILayer.h"

USING_NS_CC;

class GameScene11 : public BaseLayer{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(GameScene11);

	//int permise;
	//MenuItemImage* face1;
	//Menu* button1;
	Sprite* face1;
	Sprite* face2;

	Point location1;
	Point location2;
	bool onTouchBegan(Touch *touch, Event *unused_event);
	//void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);


	void clown();
	void flower();
	void glass();
	void face();
	void hidden();

	CC_SYNTHESIZE(int,permise,permise);
	virtual void restart();

	UILayer* uiLayer;

private:
	cocos2d::Sprite* handline;
};

#endif