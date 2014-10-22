//
//  GameScene26.h
//  Sister
//
//  Created by ∑Á∑…“› on 14-8-13.
//
//

#ifndef __Sister__GameScene32__
#define __Sister__GameScene32__

#include "cocos2d.h"
#include "BaseLayer.h"
#include "UISimple.h"
USING_NS_CC;

class GameScene32:public BaseLayer
{
public:

	GameScene32();
	~GameScene32();
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameScene32);

	Sprite* ring;
	Sprite* hand;
	Point beginpos,endpos;
	int touchTimes;
	bool onTouchBegan(Touch *touch,Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
	void update(float tmd);

	UISimple* m_ui;
	void success();
	void lose();
	virtual void restart();
};

#endif /* defined(__Sister__GameScene26__) */
