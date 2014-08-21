//
//  GameScene01.h
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#ifndef __Sister__GameScene01__
#define __Sister__GameScene01__

#include "cocos2d.h"
#include "BaseLayer.h"

USING_NS_CC;

class GameScene01:public BaseLayer{
public:
    GameScene01();
    ~GameScene01();
    
    virtual bool init();
    virtual void restart();
    static Scene* createScene();
    
    // 触摸事件相关
    bool onTouchBegan(Touch *pTouch, Event  *pEvent);
    void onTouchMoved(Touch *pTouch, Event  *pEvent);
    void onTouchEnded(Touch *pTouch, Event  *pEvent);

    void ListenerTouchBegan();
    
    CREATE_FUNC(GameScene01);
};

#endif /* defined(__Sister__GameScene01__) */
