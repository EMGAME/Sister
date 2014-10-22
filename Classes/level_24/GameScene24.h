//
//  GameScene24.h
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#ifndef __Sister__GameScene24__
#define __Sister__GameScene24__

#include <iostream>
#include "cocos2d.h"
#include "../game.h"
#include "../UILayer/UISimple.h"


USING_NS_CC;

class GameScene24 : public BaseLayer{
public:
	static Scene* createScene();

	virtual bool init();

	bool onTouchBegan(Touch *touch, Event *unused_event);
	//void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);

	//创建锯齿边框
	Sprite* createBorder(Point pos);
	//碰撞监听
	bool onContactBegin(PhysicsContact& contact);
	
	virtual void success();
    virtual void lose();
	void update(float dt);
	//取消监听
	void onExit();

	CREATE_FUNC(GameScene24);

	Sprite* boss;
	Sprite* shoot;
	Sprite* moon;

	PhysicsBody* body1;
	bool zidan;
	double time;
    
    UISimple* m_ui;
};
#endif /* defined(__Sister__GameScene24__) */
