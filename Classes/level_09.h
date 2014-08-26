#ifndef __level_09_SCENE_H__  
#define __level_09_SCENE_H__  
#include "BaseLayer.h"
#include "cocos2d.h"  
#include "UILayer/UILayer.h"

USING_NS_CC;  

class Level09 :  public BaseLayer  
{  
public:  
	static cocos2d::Scene* createScene();  
	virtual bool init();  

	void showRubbish2();
	void showSaoZhou();
	void moveUFO();
	
	void menuCloseCallback(cocos2d::Ref* pSender);  
	CREATE_FUNC(Level09);  
	
	bool onTouchBeganTree(Touch *touch, Event* event);
	void onTouchEndedTree(Touch *touch, Event* event);
	
	
	
	/*bool onTouchBeganCar(Touch *touch, Event* event);
	void onTouchMovedCar(Touch *touch, Event* event);*/

	virtual void onEnter();
	virtual void onExit();
	virtual void onAcceleration(Acceleration *acc, Event *unused_event);
	
	virtual void restart();

	

    Point location1;
    Point location2;

	Point saozhouPos;
	Point location4;

	Point carPoint;
};  

#endif  __level_09_SCENE_H__  