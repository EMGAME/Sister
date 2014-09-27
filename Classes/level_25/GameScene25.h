//
//  GameScene25.h
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#ifndef __Sister__GameScene25__
#define __Sister__GameScene25__

#include <iostream>
#include "cocos2d.h"
#include "BaseLayer.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

class GameScene25 : public BaseLayer{
public:
	static Scene* createScene();
    
	virtual bool init();
    
	CREATE_FUNC(GameScene25);
    
	bool onTouchBegan(Touch *touch, Event *unused_event);
	//void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
    
    bool onTouchBegan2(Touch* touch,Event *unused_event);
    
    
	void hide(int a);
    
	Point location;
	Sprite* knife;
	
	Sprite* shoubi;
    Sprite* c1;
    Sprite* c2;
    Sprite* c3;
    Sprite* c4;
    Sprite* c5;

    Sprite* boss;
    
    virtual void lose();
    virtual void success();
    void hurt();

    
    Point locationInNode;
    
	int a;
};
#endif /* defined(__Sister__GameScene25__) */