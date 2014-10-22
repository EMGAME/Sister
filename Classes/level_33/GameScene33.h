//
//  GameScene26.h
//  Sister
//
//  Created by ∑Á∑…“› on 14-8-13.
//
//

#ifndef __Sister__GameScene33__
#define __Sister__GameScene33__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
using namespace cocos2d::extension;
USING_NS_CC;
#include "BaseLayer.h"
#include "UISimple.h"

class GameScene33:public BaseLayer
{
public:

	GameScene33();
	~GameScene33();
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameScene33);

	ControlSlider* m_VSlider;
	Sprite* drop;
	Sprite* original;
    double time;
	int touchNum,volume,i;
	bool onTouchBegan(Touch *touch,Event *unused_event);
	void update(float tmd);
	void createVSlider();
	void judge(float tmd);
	void dropWater();
	void unVisible(float tmd);
    void fail(float tmd);

	UISimple* m_ui;
	virtual void success();
	virtual void lose();
	virtual void restart();
};

#endif /* defined(__Sister__GameScene26__) */
