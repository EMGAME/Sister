//
//  ShopGiftLayer.h
//  Sister
//
//  Created by 风飞逸 on 14-8-16.
//
//

#ifndef __Sister__ShopGiftLayer__
#define __Sister__ShopGiftLayer__

#include "cocos2d.h"
USING_NS_CC;

class shopGiftLayer:public cocos2d::Layer{
public:
    shopGiftLayer();
    ~shopGiftLayer();
    
    virtual bool init();
    
    void showLayerCallFunc();
    void hideLayerCallFunc();
    
    void buyCallFunc01();
    void buyCallFunc02();
    void buyCallFunc03();
    
    CREATE_FUNC(shopGiftLayer);
    cocos2d::Menu* m_ShopLayer;
    cocos2d::Menu* menuBtn2;
protected:
    MenuItem* giftBtn1;
    MenuItem* giftBtn2;
    MenuItem* buyItem01;
    MenuItem* buyItem02;
    MenuItem* buyItem03;
    
};

#endif /* defined(__Sister__ShopGiftLayer__) */
