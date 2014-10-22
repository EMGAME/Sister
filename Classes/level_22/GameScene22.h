#ifndef _SCENE3_H__
#define _SCENE3_H__

#include "cocos2d.h"
#include "game.h"
#include "VisibleRect.h"
#include "../UILayer/UISimple.h"
#define ballTag 100
#define SPEED 30.0
USING_NS_CC;
class GameScene22 : public BaseLayer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
	virtual void onEnter();
	virtual void onExit();
	virtual void onAcceleration(Acceleration *acc, Event *unused_event);
    virtual void success();
	virtual void lose();
	Sprite* boss;
	Sprite* hole;
    Sprite* ball;
    
    UISimple* m_ui;
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene22);
};

#endif // __SCENE4_H__
