//
//  GameScene26.h
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#ifndef __Sister__GameScene26__
#define __Sister__GameScene26__

#include "SimpleAudioEngine.h"
#include "extensions/cocos-ext.h"
#include "cocos2d.h"
#include "BaseLayer.h"
#include "../UILayer/UISimple.h"

USING_NS_CC;

class GameScene26 : public BaseLayer
{
public:
	GameScene26();
	~GameScene26();

	static cocos2d::Scene* createScene(); 
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(GameScene26);

	int isTouch,degree;
	double time;
	Sprite* boss;
	RepeatForever* repeatForever;
	void update(float tmd);
	bool onTouchBegan(Touch *touch, Event *unused_event);

	UISimple* m_ui;
	virtual void success();
    virtual void lose();
	virtual void restart();
    
    Sprite* plate;
};
#include <iostream>

#endif /* defined(__Sister__GameScene26__) */
