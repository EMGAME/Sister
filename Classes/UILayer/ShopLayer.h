//
//  ShopLayer.h
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#ifndef __Sister__ShopLayer__
#define __Sister__ShopLayer__

#include "cocos2d.h"
#include "ShopGiftLayer.h"
#include "ShopPowerLayer.h"
#include "ShopTipLayer.h"
using namespace cocos2d;

//用来判断第首次进入时所在的的标签页
enum SHOP_TYPE{
    SHOP_TYPE_TIP,//提示时进入
    SHOP_TYPE_POWER,//体力时进入
    SHOP_TYPE_GOLD,//购买金币时进入
};

class ShopLayer:public cocos2d::Layer{
public:
    
    virtual bool init(SHOP_TYPE TYPE);
    static ShopLayer* create(SHOP_TYPE create_ShopType)
    {
        ShopLayer *pRet = new ShopLayer();
        
        if (pRet && pRet->init(create_ShopType))
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }
    
    void changeToGiftCallFunc();
    void changeToPowerCallFunc();
    void changeTpTipCallFunc();
    
    void popLayer(Ref* pSender);
    void pushLayer();
    
    Layer* uiLayer;
    
    Node* controllNode;
    
    
    
    
    shopGiftLayer* m_shopGiftLayer;
    shopTipLayer* m_shopTipLayer;
    shopPowerLayer* m_shopPowerLayer;
protected:
    ShopLayer();
    ~ShopLayer();
    
    // SHOP_TYPE M_SHOP_TYPE;
};

#endif /* defined(__Sister__ShopLayer__) */
