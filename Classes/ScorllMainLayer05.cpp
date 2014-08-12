//
//  ScorllMainlayer05.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-12.
//
//

#include "ScorllMainlayer05.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

ScorllMainlayer05::ScorllMainlayer05()
{
}

ScorllMainlayer05::~ScorllMainlayer05()
{
}

bool ScorllMainlayer05::init()
{
    bool bRet = false;
    
    do {
        Size size = CCDirector::getInstance()->getWinSize();
        //初始化信息
        SpriteFrameCache *cache = SpriteFrameCache::getInstance();
        cache->addSpriteFramesWithFile("thumbs.plist");
        
        auto closeItem01 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("thumb_level25.png"),
                                                  Sprite::createWithSpriteFrameName("thumb_level25.png"),
                                                  CC_CALLBACK_1(ScorllMainlayer05::menuCloseCallback01, this));
        closeItem01->setPosition(Point(size.width*0.5-120,size.height*0.5+200));
        
        auto closeItem02 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("thumb_level26.png"),
                                                  Sprite::createWithSpriteFrameName("thumb_level26.png"),
                                                  CC_CALLBACK_1(ScorllMainlayer05::menuCloseCallback02, this));
        closeItem02->setPosition(Point(size.width*0.5+120,size.height*0.5+200));
        
        auto closeItem03 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("thumb_level27.png"),
                                                  Sprite::createWithSpriteFrameName("thumb_level27.png"),
                                                  CC_CALLBACK_1(ScorllMainlayer05::menuCloseCallback03, this));
        closeItem03->setPosition(Point(size.width*0.5-120,size.height*0.5));
        
        auto closeItem04 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("thumb_level28.png"),
                                                  Sprite::createWithSpriteFrameName("thumb_level28.png"),
                                                  CC_CALLBACK_1(ScorllMainlayer05::menuCloseCallback04, this));
        closeItem04->setPosition(Point(size.width*0.5+120,size.height*0.5));
        
        auto closeItem05 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("thumb_level29.png"),
                                                  Sprite::createWithSpriteFrameName("thumb_level29.png"),
                                                  CC_CALLBACK_1(ScorllMainlayer05::menuCloseCallback05, this));
        closeItem05->setPosition(Point(size.width*0.5-120,size.height*0.5-200));
        
        auto closeItem06 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("thumb_level30.png"),
                                                  Sprite::createWithSpriteFrameName("thumb_level30.png"),
                                                  CC_CALLBACK_1(ScorllMainlayer05::menuCloseCallback06, this));
        closeItem06->setPosition(Point(size.width*0.5+120,size.height*0.5-200));
        
        
        auto menu = Menu::create(closeItem01,closeItem02,closeItem03,closeItem04,closeItem05,closeItem06,NULL);
        menu->setPosition(Point::ZERO);
        this->addChild(menu, 1);
        
        
        bRet = true;
    } while (0);
    
    return bRet;
    
}

void ScorllMainlayer05::menuCloseCallback01(cocos2d::Ref* pSender){
    log("SS");
}
void ScorllMainlayer05::menuCloseCallback02(cocos2d::Ref* pSender){
    
}
void ScorllMainlayer05::menuCloseCallback03(cocos2d::Ref* pSender){
    
}
void ScorllMainlayer05::menuCloseCallback04(cocos2d::Ref* pSender){
    
}

void ScorllMainlayer05::menuCloseCallback05(cocos2d::Ref* pSender){
    
}
void ScorllMainlayer05::menuCloseCallback06(cocos2d::Ref* pSender){
    
}
