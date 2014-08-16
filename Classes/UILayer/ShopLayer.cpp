//
//  ShopLayer.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//
#include "ShopGiftLayer.h"

#include "ShopLayer.h"
ShopLayer::ShopLayer(){}
ShopLayer::~ShopLayer(){}

bool ShopLayer::init(SHOP_TYPE TYPE){
    if (!Layer::init()) {
        return false;
    }
    auto winSize = Director::getInstance()->getWinSize();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto Origin = Director::getInstance()->getVisibleOrigin();
    
    allLayer = Node::create();
    n_PowerLayer = Node::create();
    n_TipLayer=Node::create();
    n_GoldLayer = Node::create();
 
    auto frameCache = SpriteFrameCache::getInstance();
    frameCache->addSpriteFramesWithFile("ui_shop.plist");
    
    auto ShopBg = Sprite::createWithSpriteFrameName("shop_bg.png");
    ShopBg->setAnchorPoint(Point::ANCHOR_MIDDLE_RIGHT);
    ShopBg->setPosition(Point(winSize.width,Origin.y+visibleSize.height/2));
    this->addChild(ShopBg);
 
    CreatePowerLayer();
    this->addChild(n_PowerLayer,3);
//
//    CreateTipLayer();
//    allLayer->addChild(n_TipLayer,3);
//                        
    
    this->addChild(allLayer);
    
    m_GoldShopLayer =shopGiftLayer::create();
    this->addChild(m_GoldShopLayer,4);
    
    
    switch (TYPE) {
        case SHOP_TYPE_GOLD:
            break;
            case SHOP_TYPE_POWER:
            log("power");
            break;
            case SHOP_TYPE_TIP:
            log("tip");
            break;
    }

    return true;
}


void ShopLayer::CreatePowerLayer(){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto Origin = Director::getInstance()->getVisibleOrigin();

    auto powerBtn2 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("shop_tab_energy2.png"),
                                            Sprite::createWithSpriteFrameName("shop_tab_energy2.png"),
                                            CC_CALLBACK_0(ShopLayer::SwitchToTipLayerCallFunc, this));
    
    powerBtn2->setAnchorPoint(Point::ANCHOR_MIDDLE_RIGHT);
    powerBtn2->setPosition(Origin+Point(visibleSize.width-508,visibleSize.height/2));
    this->addChild(powerBtn2);

}

void ShopLayer::CreateTipLayer(){
//    auto visibleSize = Director::getInstance()->getVisibleSize();
//    auto Origin = Director::getInstance()->getVisibleOrigin();
//
//    auto tipBtn2 = Sprite::createWithSpriteFrameName("shop_tab_tip2.png");
//    tipBtn2->setAnchorPoint(Point::ANCHOR_MIDDLE_RIGHT);
//    tipBtn2->setPosition(Origin+Point(visibleSize.width-508,visibleSize.height/2-100));
//    n_TipLayer->addChild(tipBtn2);
//
}

void ShopLayer::SwitchToGoldLayerCallFunc(){

}

void ShopLayer::SwitchToTipLayerCallFunc(){
    m_GoldShopLayer->hideLayerCallFunc();
}

void ShopLayer::SwitchToPowerLayerCallFunc(){

}