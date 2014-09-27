#ifndef __SCENE1_H__  
#define __SCENE1_H__  
#include "cocos2d.h"  
#include "SimpleAudioEngine.h"
#include "../game.h"
using namespace CocosDenshion;
USING_NS_CC;  

class GameScene23 :  public BaseLayer
{  
public:  
	 GameScene23(
		
		 );
    ~GameScene23();
	static cocos2d::Scene* createScene();  
	virtual bool init();  
	

    virtual void hideHand(float dt);
    void moveCup();
	bool onTouchBegan(Touch* pTouch,Event* pEvent);
	virtual void success();
    virtual void lose();
	
	Sprite* boy;
	Sprite* point2;
	Sprite* point1;
	Sprite* cup;
	Sprite* hand;
	Sprite* boss;

	Animation* animation1 ;
	Animate*   action1 ;
	Animation* animation ;
	Animate*   action ;
	CREATE_FUNC(GameScene23);  
	
    UISimple* m_ui;
    
 };  

#endif  __SCENE1_H__  