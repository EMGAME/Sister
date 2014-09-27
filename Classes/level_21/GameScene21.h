#ifndef __SCENE2_H__  
#define __SCENE2_H__  
#include "cocos2d.h"  
#include "../UILayer/UISimple.h"
#include "game.h"
USING_NS_CC;  

class GameScene21 :  public BaseLayer
{  
public:  
	GameScene21();
	~GameScene21();
	static cocos2d::Scene* createScene();  
	virtual bool init();  
	void stopDart();
	bool onTouchBegan(Touch* pTouch,Event* pEvent);
	virtual void success();
	virtual void lose();

	Sprite* boss;
	Sprite* heart;
	Sprite* dart;
	Sprite* center;	
	Point* location1;
    
    
    UISimple* m_ui;
    
	CREATE_FUNC(GameScene21);  

 };  

#endif  __SCENE2_H__  