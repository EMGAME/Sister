#ifndef __Sister__GameScene39__
#define __Sister__GameScene39__

#include <iostream>
#include "cocos2d.h"
#include "BaseLayer.h"
#include "UISimple.h"

USING_NS_CC;

class GameScene39 : public BaseLayer{

public:
	static cocos2d::Scene* createScene();

	bool init();

	void thiefMove(float dt);

	CREATE_FUNC(GameScene39);

	bool onTouchBegan(Touch *touch, Event *unused_event);
	//void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);

	virtual void success();
	virtual void lose();
    virtual void restart();

	int a ;

	Sprite* thief1;
	Sprite* thief2;
	Sprite* thief3;
	Sprite* thief4;
	Sprite* thief5;
    
    UISimple* m_ui;
};

#endif 