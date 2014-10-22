//
//  StartScene.h
//  Sister
//
//  Created by 风飞逸 on 14-8-11.
//
//

#ifndef __Sister__StartScene__
#define __Sister__StartScene__

#include "cocos2d.h"

class StartScene:public cocos2d::Layer{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(StartScene);
    
    void classBtnCallBack();
    void zanBtnCallBack();
    void crazyBtnCallBack();
    
    void share();
    void shareInit();
};

#endif /* defined(__Sister__StartScene__) */
