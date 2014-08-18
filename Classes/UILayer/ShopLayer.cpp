//
//  ShopLayer.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//
#define BGTAG 10
#define NODETAG 20
#define MENUTAG 30

#include "ShopGiftLayer.h"
#include "ShopLayer.h"
ShopLayer::ShopLayer(){
    m_shopTipLayer = nullptr;
    m_shopPowerLayer= nullptr;
    m_shopGiftLayer = nullptr;
}
ShopLayer::~ShopLayer(){}

bool ShopLayer::init(SHOP_TYPE TYPE){
    if (!Layer::init()) {
        return false;
    }
    auto winSize = Director::getInstance()->getWinSize();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto Origin = Director::getInstance()->getVisibleOrigin();
  
    controllNode = Node::create();
    this->addChild(controllNode,1);
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ui_shop.plist");
 
    
    auto ShopBg = Sprite::createWithSpriteFrameName("shop_bg.png");
    ShopBg->setAnchorPoint(Point::ANCHOR_MIDDLE_RIGHT);
    ShopBg->setPosition(Point(winSize.width,Origin.y+visibleSize.height/2));
    controllNode->addChild(ShopBg,0);
    
    m_shopGiftLayer = shopGiftLayer::create();
    m_shopGiftLayer->setPosition(Point::ZERO);
    m_shopGiftLayer->setVisible(false);
    
    m_shopPowerLayer = shopPowerLayer::create();
    m_shopPowerLayer->setPosition(Point::ZERO);
    m_shopPowerLayer->setVisible(false);
    
    m_shopTipLayer = shopTipLayer::create();
    m_shopTipLayer->setPosition(Point::ZERO);
    m_shopTipLayer->setVisible(false);
    
    controllNode->addChild(m_shopTipLayer,2);
    controllNode->addChild(m_shopPowerLayer,2);
    controllNode->addChild(m_shopGiftLayer,2);
    
    auto giftBtn2 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("shop_tab_gift1.png"),
                                           Sprite::createWithSpriteFrameName("shop_tab_gift1.png"),
                                           CC_CALLBACK_0(ShopLayer::changeToGiftCallFunc, this));
    
    giftBtn2->setAnchorPoint(Point::ANCHOR_MIDDLE_RIGHT);
    giftBtn2->setPosition(Point(winSize.width-508,winSize.height/2+100));
    
    auto powerBtn2 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("shop_tab_energy1.png"),
                                           Sprite::createWithSpriteFrameName("shop_tab_energy1.png"),
                                           CC_CALLBACK_0(ShopLayer::changeToPowerCallFunc, this));
    
    powerBtn2->setAnchorPoint(Point::ANCHOR_MIDDLE_RIGHT);
    powerBtn2->setPosition(Point(winSize.width-508,winSize.height/2));

    auto tipBtn2 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("shop_tab_tip1.png"),
                                           Sprite::createWithSpriteFrameName("shop_tab_tip1.png"),
                                           CC_CALLBACK_0(ShopLayer::changeTpTipCallFunc, this));
    
    tipBtn2->setAnchorPoint(Point::ANCHOR_MIDDLE_RIGHT);
    tipBtn2->setPosition(Point(winSize.width-508,winSize.height/2-100));
    

    
    auto menu = Menu::create(giftBtn2,powerBtn2,tipBtn2,NULL);
    menu->setPosition(Point::ZERO);
    controllNode->addChild(menu,1);
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ui_common.plist");
    auto closeBtn = MenuItemSprite::create(Sprite::createWithSpriteFrameName("common_btn_close.png"),
                                           Sprite::createWithSpriteFrameName("common_btn_close.png"),
                                           CC_CALLBACK_0(ShopLayer::pushLayer, this));
    
    CCLOG("asfasfasdfasdfadsf");
    //closeBtn->setAnchorPoint(Point::ANCHOR_MIDDLE_RIGHT);
    closeBtn->setPosition(Point(winSize.width-150,
                                       winSize.height/2+200));
    
    auto frontMenu = Menu::create(closeBtn, NULL);
    frontMenu->setPosition(Point::ZERO);
    controllNode->addChild(frontMenu, 9);
    
    
    
    
    switch (TYPE) {
        case SHOP_TYPE_GOLD:
            break;
            m_shopGiftLayer->setVisible(true);
            case SHOP_TYPE_POWER:
            m_shopPowerLayer->setVisible(true);
            break;
            case SHOP_TYPE_TIP:
            m_shopTipLayer->setVisible(true);
            break;
        case SHOP_TYPE_WITHOUTTIP:
            m_shopGiftLayer->setVisible(true);
            tipBtn2->setVisible(false);
    }
    
    
    controllNode->setPosition(Origin+Point(visibleSize.width/2,visibleSize.height+100));
    return true;
}

void ShopLayer::changeToGiftCallFunc(){
    m_shopGiftLayer->setVisible(true);
    m_shopPowerLayer->setVisible(false);
    m_shopTipLayer->setVisible(false);
}

void ShopLayer::changeToPowerCallFunc(){
    m_shopGiftLayer->setVisible(false);
    m_shopPowerLayer->setVisible(true);
    m_shopTipLayer->setVisible(false);
}

void ShopLayer::changeTpTipCallFunc(){
    m_shopGiftLayer->setVisible(false);
    m_shopPowerLayer->setVisible(false);
    m_shopTipLayer->setVisible(true);
}

void ShopLayer::popLayer(Ref* pSender){
    
    //获得窗体大小
	Size visibleSize = Director::getInstance()->getWinSize();
	//截图
	RenderTexture* renderTexture = RenderTexture::create(visibleSize.width, visibleSize.height);
	renderTexture->retain();
	Scene *runningScene = CCDirector::getInstance()->getRunningScene();
	renderTexture->begin();
	runningScene->visit();
	renderTexture->end();
	//下面这句用来测试截图是否成功，经测试成功
	//renderTexture->saveToFile("123.png", Image::Format::PNG);
    
	//将截到的图做背景
	Sprite *_spr = Sprite::createWithTexture(renderTexture->getSprite()->getTexture());
	_spr->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	_spr->setFlippedY(true);  //翻转
	_spr->setColor(Color3B::GRAY);  //颜色（变灰暗）
	this->addChild(_spr, 0, BGTAG);
	
//	//禁止页面菜单
//	uiLayer = (Layer*)pSender;
//	auto uiLayerMenu = (Menu*)uiLayer->getChildByTag(MENUTAG);
//	uiLayerMenu->setEnabled(false);
    
    auto moveTo = MoveTo::create(0.5f, Point::ZERO);
	auto easeBackInOut = EaseBackInOut::create(moveTo);
    controllNode->runAction(easeBackInOut);
}

void ShopLayer::pushLayer(){
    this->getChildByTag(BGTAG)->removeFromParent();
	
//	//激活页面菜单
//	if(uiLayer)
//	{
//		auto uiLayerMenu = (Menu*)uiLayer->getChildByTag(MENUTAG);
//		uiLayerMenu->setEnabled(true);
//	}
    Size visibleSize = Director::getInstance()->getWinSize();
    
	auto moveTo = MoveTo::create(0.5f,Point(visibleSize.width/2,
                                        visibleSize.height+100));
	auto easeBackInOut = EaseBackInOut::create(moveTo);
    controllNode->runAction(easeBackInOut);
}