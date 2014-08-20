//
//  ShopTipLayer.h
//  Sister
//
//  Created by 风飞逸 on 14-8-16.
//
//

#ifndef __Sister__ShopTipLayer__
#define __Sister__ShopTipLayer__


#include "cocos2d.h"
USING_NS_CC;

class shopTipLayer:public cocos2d::Layer{
public:
    shopTipLayer();
    ~shopTipLayer();
    
    virtual bool init();
    
    void showLayerCallFunc();
    void hideLayerCallFunc();
    
    void buyCallFunc01();
    void buyCallFunc02();
    void buyCallFunc03();
    
    CREATE_FUNC(shopTipLayer);
    cocos2d::Menu* m_ShopLayer;
protected:
    MenuItem* TipBtn1;
    MenuItemLabel* buyItem01;
    MenuItemLabel* buyItem02;
    MenuItemLabel* buyItem03;
    
};

#endif /* defined(__Sister__ShopTipLayer__) */
