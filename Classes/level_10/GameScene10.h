#ifndef __GameScene10_SCENE_H__  
#define __GameScene10_SCENE_H__  
#include "BaseLayer.h"
#include "cocos2d.h"  
#include "../UILayer/UILayer.h"
USING_NS_CC;  

class GameScene10 :  public BaseLayer  
{  

private:
		Label *timerLabel;
	    long startTime;
		
public:  
	static cocos2d::Scene* createScene();  
	virtual bool init();  

	UILayer* uiLayer;
	  
	//判断精灵是否点击  
 /*   bool isInSprite(Touch *theTouch,Sprite *sp);  */
	
	void showKey();
	void showPassword();
	void lightLamp();
	

	bool onTouchBeganDraw(Touch *touch, Event* event);
	void onTouchMovedDraw(Touch *touch, Event* event);
	void onTouchEndedDraw(Touch *touch, Event* event);

	
	bool onTouchBeganBox(Touch *touch, Event* event);
	void onTouchMovedBox(Touch *touch, Event* event);
	void onTouchEndedBox(Touch *touch, Event* event);

	bool onTouchBeganHole(Touch *touch, Event* event);
	void onTouchMovedHole(Touch *touch, Event* event);
	void onTouchEndedHole(Touch *touch, Event* event);

    void menuCloseCallback(cocos2d::Ref* pSender);  
	
	//开始计时
	void startTimer();

	//结束计时
	void stopTimer();

	virtual void update(float dt);

	void success();
    void lose();
	virtual void restart();
	
	CREATE_FUNC(GameScene10);  
	
 };  

#endif  _GameScene10_SCENE_H__  