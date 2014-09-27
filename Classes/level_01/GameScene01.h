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
#include "../UILayer/UILayer.h"

USING_NS_CC;

class GameScene01:public BaseLayer{
public:
    GameScene01();
    ~GameScene01();
    
    virtual bool init();
    //重新开始游戏功能
    virtual void restart();
    //下一关
    virtual void nextLevel();
    
    static Scene* createScene();
    
    void update(float delta);
    
    void initTipLayer();

    void onTouchEnded(Touch* pTouch,Event* pEvent);
    void onTouchMoved(Touch* pTouch,Event* pEvent);
    void sayThanksCallBack();
    void sayNoCallBack();
    
    Sprite* m_sister;
    Sprite* m_zhuantou;
    Sprite* m_jinggai;
    Sprite* m_ludeng;
    UILayer* m_ui;
    
    Layer* TipLayer;
    CREATE_FUNC(GameScene01);
    
    
    //以下是测试内容
    Sprite* m_shoubi;
    
};

#endif /* defined(__Sister__GameScene01__) */
