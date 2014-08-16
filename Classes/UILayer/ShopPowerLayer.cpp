//
//  shopPowerLayer02.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-16.
//
//

#include "shopPowerLayer.h"
USING_NS_CC;

shopPowerLayer::shopPowerLayer(){

    m_ShopLayer = nullptr;
}
shopPowerLayer::~shopPowerLayer(){}

bool shopPowerLayer::init(){
    if (!Layer::init()) {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getWinSize();
    auto Origin = Point(0, 0);
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ui_shop.plist");
    
    giftBtn1 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("shop_tab_energy2.png"),
                                      Sprite::createWithSpriteFrameName("shop_tab_energy2.png"),
                                      CC_CALLBACK_0(shopPowerLayer::showLayerCallFunc, this));
    giftBtn1->setAnchorPoint(Point::ANCHOR_MIDDLE_RIGHT);
    giftBtn1->setPosition(Origin+Point(visibleSize.width-508,visibleSize.height/2));
    
    buyItem01 = MenuItemLabel::create(LabelTTF::create("200点=200金币", "", 40),
                                      CC_CALLBACK_0(shopPowerLayer::buyCallFunc01,this));
    buyItem01->setColor(Color3B(0, 0, 0));
    buyItem01->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
    buyItem01->setPosition(Origin+Point(visibleSize.width - 450,visibleSize.height/2+100));
    
    buyItem02= MenuItemLabel::create(LabelTTF::create("1000点=700金币", "", 40),
                                     CC_CALLBACK_0(shopPowerLayer::buyCallFunc02,this));
    buyItem02->setColor(Color3B(0, 0, 0));
    buyItem02->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
    buyItem02->setPosition(Origin+Point(visibleSize.width - 450,visibleSize.height/2 ));
    
    buyItem03 = MenuItemLabel::create(LabelTTF::create("无限体力=1000金币", "", 40),
                                      CC_CALLBACK_0(shopPowerLayer::buyCallFunc03,this));
    buyItem03->setColor(Color3B(0, 0, 0));
    buyItem03->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
    buyItem03->setPosition(Origin+Point(visibleSize.width - 450,visibleSize.height/2-100));
    
    
    m_ShopLayer = Menu::create(giftBtn1,buyItem01,buyItem02,buyItem03, NULL);
    m_ShopLayer->setPosition(Point::ZERO);
    this->addChild(m_ShopLayer);
    
    
    
    return true;
}
void shopPowerLayer::showLayerCallFunc(){
    m_ShopLayer->setVisible(true);
    m_ShopLayer->setEnabled(true);
    
}

void shopPowerLayer::hideLayerCallFunc(){
    m_ShopLayer->setVisible(false);
    m_ShopLayer->setEnabled(false);
    
    
    log("asdf");
    
}

void shopPowerLayer::buyCallFunc01(){
    log("call01");
}
void shopPowerLayer::buyCallFunc02(){
    
}
void shopPowerLayer::buyCallFunc03(){
    
}