#ifndef __SCENE1_H__  
#define __SCENE1_H__  
#include "cocos2d.h"  
#include "SimpleAudioEngine.h"
#include "../UILayer/UISimple.h"
#include "BaseLayer.h"

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
    Sprite* cup;
	Sprite* hand;
	Sprite* boss;
	Sprite* cry;
	Sprite* smile;
    UISimple* m_ui;
    CREATE_FUNC(GameScene23);  
	
 };  

#endif  __SCENE1_H__