//
//  ScrollViewScene.h
//  Sister
//
//  Created by 风飞逸 on 14-8-12.
//
//

#ifndef __Sister__ScrollViewScene__
#define __Sister__ScrollViewScene__

#include "cocos2d.h"
#include"../UILayer/ShopLayer.h"

USING_NS_CC;

class ScrollViewScene: public Scene
{
    
public:
    ScrollViewScene();
    virtual bool init();
    CREATE_FUNC(ScrollViewScene);
    
    void backBtnCallback(cocos2d::Ref* pSender);

    void gitfBtnCallback(cocos2d::Ref* pSender);
    ShopLayer* m_shopLayer;
    
    static Scene* createScene();
    static ScrollViewScene *sharedSC();
    
 };

#endif /* defined(__Sister__ScrollViewScene__) */
