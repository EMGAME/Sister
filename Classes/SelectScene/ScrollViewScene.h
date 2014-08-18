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
<<<<<<< HEAD
=======
#include"../UILayer/ShopLayer.h"
>>>>>>> master

USING_NS_CC;

class ScrollViewScene: public Scene
{
    
public:
    ScrollViewScene();
    virtual bool init();
    CREATE_FUNC(ScrollViewScene);
    
    void backBtnCallback(cocos2d::Ref* pSender);
<<<<<<< HEAD
    
    static Scene* createScene();
    static ScrollViewScene *sharedSC();
};
=======
    void gitfBtnCallback(cocos2d::Ref* pSender);
    ShopLayer* m_shopLayer;
    
    static Scene* createScene();
    static ScrollViewScene *sharedSC();
    
 };
>>>>>>> master

#endif /* defined(__Sister__ScrollViewScene__) */
