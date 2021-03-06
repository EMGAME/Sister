//
//  GameScene02.h
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#ifndef __Sister__GameScene02__
#define __Sister__GameScene02__

#include "cocos2d.h"
#include "../BaseLayer.h"
USING_NS_CC;

class GameScene02:public BaseLayer{
public:
    GameScene02();
    ~GameScene02();
    
    static Scene* createScene();
    
    //下一关
    virtual void nextLevel();
    virtual bool init();
    
    CREATE_FUNC(GameScene02);
    
    virtual void update(float time);

    virtual void restart();
    LabelBMFont* m_time;
    float time_nm;
    
    Sprite* boss;
    
    //bool onContactBegin(EventCustom *event, const PhysicsContact& contact);
};
#endif /* defined(__Sister__GameScene02__) */
