//
//  ShopTipLayer.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-16.
//
//

#include "ShopTipLayer.h"
USING_NS_CC;

shopTipLayer::shopTipLayer(){
    m_ShopLayer = nullptr;

}
shopTipLayer::~shopTipLayer(){}

bool shopTipLayer::init(){
    if (!Layer::init()) {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getWinSize();
    auto Origin = Point(0, 0);
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ui_shop.plist");
    
      
    TipBtn1 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("shop_tab_tip2.png"),
                                      Sprite::createWithSpriteFrameName("shop_tab_tip2.png"),
                                      CC_CALLBACK_0(shopTipLayer::showLayerCallFunc, this));
    TipBtn1->setAnchorPoint(Point::ANCHOR_MIDDLE_RIGHT);
    TipBtn1->setPosition(Origin+Point(visibleSize.width-508,visibleSize.height/2-100));
    
    buyItem01 = MenuItemLabel::create(LabelTTF::create("第一条提示=5金币", "", 40),
                                      CC_CALLBACK_0(shopTipLayer::buyCallFunc01,this));
    buyItem01->setColor(Color3B(0, 0, 0));
    buyItem01->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
    buyItem01->setPosition(Origin+Point(visibleSize.width - 450,visibleSize.height/2+100));
    
    buyItem02= MenuItemLabel::create(LabelTTF::create("第二条提示=50金币", "", 40),
                                     CC_CALLBACK_0(shopTipLayer::buyCallFunc02,this));
    buyItem02->setColor(Color3B(0, 0, 0));
    buyItem02->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
    buyItem02->setPosition(Origin+Point(visibleSize.width - 450,visibleSize.height/2 ));
    
    buyItem03 = MenuItemLabel::create(LabelTTF::create("第三条提示=50金币", "", 40),
                                      CC_CALLBACK_0(shopTipLayer::buyCallFunc03,this));
    buyItem03->setColor(Color3B(0, 0, 0));
    buyItem03->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
    buyItem03->setPosition(Origin+Point(visibleSize.width - 450,visibleSize.height/2-100));
    
    
    m_ShopLayer = Menu::create(TipBtn1,buyItem01,buyItem02,buyItem03, NULL);
    m_ShopLayer->setPosition(Point::ZERO);
    this->addChild(m_ShopLayer);
    
    
    
    return true;
}
void shopTipLayer::showLayerCallFunc(){
    m_ShopLayer->setVisible(true);
    m_ShopLayer->setEnabled(true);
    
}

void shopTipLayer::hideLayerCallFunc(){
    m_ShopLayer->setVisible(false);
    m_ShopLayer->setEnabled(false);
    
    
    log("asdf");
    
}

void shopTipLayer::buyCallFunc01(){
    log("call01");
}
void shopTipLayer::buyCallFunc02(){
    
}
void shopTipLayer::buyCallFunc03(){
    
}