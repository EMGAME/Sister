//
//  ShopPowerLayer.h
//  Sister
//
//  Created by 风飞逸 on 14-8-16.
//
//

#ifndef __Sister__ShopPowerLayer__
#define __Sister__ShopPowerLayer__

#include"cocos2d.h"
USING_NS_CC;


class shopPowerLayer:public cocos2d::Layer{
public:
    shopPowerLayer();
    ~shopPowerLayer();
    
    virtual bool init();
    
    void showLayerCallFunc();
    void hideLayerCallFunc();
    
    void buyCallFunc01();
    void buyCallFunc02();
    void buyCallFunc03();
    
    CREATE_FUNC(shopPowerLayer);
    cocos2d::Menu* m_ShopLayer;
protected:
    MenuItem* giftBtn1;
    MenuItem* buyItem01;
    MenuItem* buyItem02;
    MenuItem* buyItem03;
    
};

#endif /* defined(__Sister__ShopPowerLayer__) */
