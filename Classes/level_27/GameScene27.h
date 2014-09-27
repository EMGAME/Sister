//
//  GameScene27.h
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#ifndef __Sister__GameScene27__
#define __Sister__GameScene27__
#include "extensions/cocos-ext.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "BaseLayer.h"
#include "../UILayer/UISimple.h"


USING_NS_CC;

using namespace cocos2d::extension;


class GameScene27:public BaseLayer
{
public:
	GameScene27();
	~GameScene27();
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameScene27);

	Sprite* compare;
	Sprite* boss;
	double time;
	int power;
	void update(float tmd);
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void createHPSlider();
	ControlSlider* m_hpSlider;
	void menuCloseCallback(cocos2d::Ref* pSender);
	UISimple* m_ui;
    
	virtual void success();
	virtual void lose();
	virtual void restart();
};

#include <iostream>

#endif /* defined(__Sister__GameScene27__) */
