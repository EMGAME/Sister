//
//  GameScene13.h
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#ifndef __Sister__GameScene13__
#define __Sister__GameScene13__


#include <iostream>
#include "BaseLayer.h"
#include "cocos2d.h"  
#include "../UILayer/UILayer.h"
USING_NS_CC;  

class GameScene13 :  public BaseLayer  
{  

private:
		Label *timerLabel;
	    long startTime;
		
public:  
	static cocos2d::Scene* createScene();  
	virtual bool init();  

	UILayer* uiLayer;
	  

   // void menuCloseCallback(cocos2d::Ref* pSender);  
	
	/*void success();
    void lose();
	virtual void restart();
	*/
	CREATE_FUNC(GameScene13);  
	
 };  


#endif /* defined(__Sister__GameScene13__) */
