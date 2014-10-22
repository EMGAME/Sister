#ifndef __SCENE30_H__  
#define __SCENE30_H__  
#include "cocos2d.h"  
#include "BaseLayer.h"
#include "../UILayer/UISimple.h"
#include "../game.h"

USING_NS_CC;  

class GameScene30 :  public BaseLayer
{  
public:  
	GameScene30();
	~GameScene30();
	static cocos2d::Scene* createScene();  
	virtual bool init();  
	
	bool onTouchBegan(Touch* pTouch,Event* pEvent);
    void onTouchEnded(Touch* pTouch,Event* pEvent);
    void onTouchMoved(Touch* pTouch,Event* pEvent);
	virtual void success();
	virtual void lose();

	Sprite* boy2;
	Sprite* boss;
	Sprite* leftHand;
    Sprite* rightHand;
	Sprite* boy;
	Sprite* bag1;
	Sprite* bag2;
	Sprite* bag3;
	Sprite* bag4;
	Sprite* bag5;
	Sprite* bag6;
	
    UISimple* m_ui;
    
    
	CREATE_FUNC(GameScene30);  
	
 };  

#endif  __SCENE30_H__  