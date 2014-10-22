//
//  GameScene28.h
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#ifndef __Sister__GameScene28__
#define __Sister__GameScene28__

#include "extensions/cocos-ext.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "BaseLayer.h"
#include "../UILayer/UISimple.h"
#include "../game.h"

using namespace cocos2d::extension;
USING_NS_CC;




class GameScene28:public BaseLayer
{
public:
	GameScene28();
	~GameScene28();
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameScene28);

	Sprite* fish;
	Sprite* fishMM;
	Sprite* shark1;
	Sprite* shark1_clo;
	Sprite* shark3;
    Sprite* shark3_clo;
	Sequence* actionAttack;
	Sprite* boss;
	RepeatForever* repeatA;
	int isAttack1,isAttack3;
	double time;
	void Home();
	void update(float tmd);
	void shark1Attack(float tmd);
	void shark3Attack(float tmd);
	bool onTouchBegan(Touch *touch, Event *unused_event);
	
	UISimple* m_ui;
	virtual void success();
	virtual void lose();
	virtual void restart();
};

#endif /* defined(__Sister__GameScene28__) */
