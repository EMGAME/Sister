#ifndef __SCENE31_H__  
#define __SCENE31_H__  
#include "cocos2d.h"  
#include "UISimple.h"
#include "BaseLayer.h"
USING_NS_CC;  

class GameScene31 :  public BaseLayer
{  
public:  
	GameScene31();
	~GameScene31();
	static cocos2d::Scene* createScene();  
	virtual bool init();  
	
	bool onTouchBegan(Touch* pTouch,Event* pEvent);
    void onTouchEnded(Touch* pTouch,Event* pEvent);
    void onTouchMoved(Touch* pTouch,Event* pEvent);
	void success();
	void lose();

	Sprite* boss;
	Sprite* finger1; 
	Sprite* finger2;
	Sprite* finger3;
	Sprite* finger4;
	Sprite* finger5;
	Sprite* nail1;
	Sprite* nail2;
	Sprite* nail3;
	Sprite* nail4;
	Sprite* nail5;
	Sprite* nail6;
	Sprite* nail7;
	Sprite* nail8;
	Sprite* nail9;
	Sprite* nail10;

    UISimple* m_ui;
	
	CREATE_FUNC(GameScene31);  
	
 };  

#endif  __SCENE31_H__  