//
//  GameScene20.h
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#ifndef __Sister__GameScene20__
#define __Sister__GameScene20__

#include "cocos2d.h"
USING_NS_CC;

class GameScene20:public Layer{
public:
    GameScene20();
    ~GameScene20();
    
    virtual bool init();
    static Scene* createScene();
    bool onTouchBegan(Touch* pTouch,Event* pEvent);
    void onTouchEnded(Touch* pTouch,Event* pEvent);
    void onTouchMoved(Touch* pTouch,Event* pEvent);

    CREATE_FUNC(GameScene20);
    
    
    //以下是测试内容
    Sprite* m_shoubi;
};

#endif /* defined(__Sister__GameScene20__) */
