//
//  ShopGiftLayer.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-16.
//
//

#include "ShopGiftLayer.h"
USING_NS_CC;

shopGiftLayer::shopGiftLayer(){
    m_ShopLayer = nullptr;
}
shopGiftLayer::~shopGiftLayer(){}

bool shopGiftLayer::init(){
    if (!Layer::init()) {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getWinSize();
    auto Origin = Point(0, 0);
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ui_shop.plist");
    
    giftBtn1 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("shop_tab_gift2.png"),
                                           Sprite::createWithSpriteFrameName("shop_tab_gift2.png"),
                                           CC_CALLBACK_0(shopGiftLayer::showLayerCallFunc, this));
    giftBtn1->setAnchorPoint(Point::ANCHOR_MIDDLE_RIGHT);
    giftBtn1->setPosition(Origin+Point(visibleSize.width-508,visibleSize.height/2+100));
    
    buyItem01 = MenuItemLabel::create(LabelTTF::create("0.1day", "", 40),
                                          CC_CALLBACK_0(shopGiftLayer::buyCallFunc01,this));

    buyItem01->setColor(Color3B(0, 0, 0));
    buyItem01->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
    buyItem01->setPosition(Origin+Point(visibleSize.width - 450,visibleSize.height/2+100));
    
    buyItem02= MenuItemLabel::create(LabelTTF::create("6yuan = 400gold", "", 40),
                                          CC_CALLBACK_0(shopGiftLayer::buyCallFunc02,this));
    buyItem02->setColor(Color3B(0, 0, 0));
    buyItem02->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
    buyItem02->setPosition(Origin+Point(visibleSize.width - 450,visibleSize.height/2 ));
    
    buyItem03 = MenuItemLabel::create(LabelTTF::create("12yuan= 1000gold", "", 40),
                                          CC_CALLBACK_0(shopGiftLayer::buyCallFunc03,this));
    buyItem03->setColor(Color3B(0, 0, 0));
    buyItem03->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
    buyItem03->setPosition(Origin+Point(visibleSize.width - 450,visibleSize.height/2-100));
    
    
    m_ShopLayer = Menu::create(giftBtn1,buyItem01,buyItem02,buyItem03, NULL);
    m_ShopLayer->setPosition(Point::ZERO);
    
    this->addChild(m_ShopLayer);
    
    

    
    return true;
}
void shopGiftLayer::showLayerCallFunc(){
    m_ShopLayer->setVisible(true);
    m_ShopLayer->setEnabled(true);
    
}

void shopGiftLayer::hideLayerCallFunc(){
    m_ShopLayer->setVisible(false);
    m_ShopLayer->setEnabled(false);

    
    log("asdf");
    
}

void shopGiftLayer::buyCallFunc01(){
    log("call01");
}
void shopGiftLayer::buyCallFunc02(){

}
void shopGiftLayer::buyCallFunc03(){

}