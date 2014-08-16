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
    
    Node* n_GoldLayer;
    Node* n_PowerLayer;
    Node* n_TipLayer;
    Node* allLayer;
    
    void SwitchToGoldLayerCallFunc();
    void SwitchToTipLayerCallFunc();
    void SwitchToPowerLayerCallFunc();
    
    void CreatePowerLayer();
    void CreateTipLayer();
    
    shopGiftLayer* m_GoldShopLayer;
    
    
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
protected:
    ShopLayer();
    ~ShopLayer();
    
    // SHOP_TYPE M_SHOP_TYPE;
};

#endif /* defined(__Sister__ShopLayer__) */
