//
//  ScorllMainLayer04.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-12.
//
//

#include "ScorllMainLayer04.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

ScorllMainLayer04::ScorllMainLayer04()
{
}

ScorllMainLayer04::~ScorllMainLayer04()
{
}

bool ScorllMainLayer04::init()
{
    bool bRet = false;
    
    do {
        Size size = CCDirector::getInstance()->getWinSize();
        //初始化信息
        SpriteFrameCache *cache = SpriteFrameCache::getInstance();
        cache->addSpriteFramesWithFile("thumbs.plist");
        
        auto closeItem01 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("thumb_level19.png"),
                                             Sprite::createWithSpriteFrameName("thumb_level19.png"),
                                             CC_CALLBACK_1(ScorllMainLayer04::menuCloseCallback01, this));
        closeItem01->setPosition(Point(size.width*0.5-120,size.height*0.5+200));
        
        auto closeItem02 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("thumb_level20.png"),
                                                  Sprite::createWithSpriteFrameName("thumb_level20.png"),
                                                  CC_CALLBACK_1(ScorllMainLayer04::menuCloseCallback02, this));
        closeItem02->setPosition(Point(size.width*0.5+120,size.height*0.5+200));
        
        auto closeItem03 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("thumb_level21.png"),
                                                  Sprite::createWithSpriteFrameName("thumb_level21.png"),
                                                  CC_CALLBACK_1(ScorllMainLayer04::menuCloseCallback03, this));
        closeItem03->setPosition(Point(size.width*0.5-120,size.height*0.5));
        
        auto closeItem04 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("thumb_level22.png"),
                                                  Sprite::createWithSpriteFrameName("thumb_level22.png"),
                                                  CC_CALLBACK_1(ScorllMainLayer04::menuCloseCallback04, this));
        closeItem04->setPosition(Point(size.width*0.5+120,size.height*0.5));
        
        auto closeItem05 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("thumb_level23.png"),
                                                  Sprite::createWithSpriteFrameName("thumb_level23.png"),
                                                  CC_CALLBACK_1(ScorllMainLayer04::menuCloseCallback05, this));
        closeItem05->setPosition(Point(size.width*0.5-120,size.height*0.5-200));
        
        auto closeItem06 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("thumb_level24.png"),
                                                  Sprite::createWithSpriteFrameName("thumb_level24.png"),
                                                  CC_CALLBACK_1(ScorllMainLayer04::menuCloseCallback06, this));
        closeItem06->setPosition(Point(size.width*0.5+120,size.height*0.5-200));

        
        auto menu = Menu::create(closeItem01,closeItem02,closeItem03,closeItem04,closeItem05,closeItem06,NULL);
        menu->setPosition(Point::ZERO);
        this->addChild(menu, 1);
        
        
        bRet = true;
    } while (0);
    
    return bRet;
}

void ScorllMainLayer04::menuCloseCallback01(cocos2d::Ref* pSender){
    log("SS");
}
void ScorllMainLayer04::menuCloseCallback02(cocos2d::Ref* pSender){
    
}
void ScorllMainLayer04::menuCloseCallback03(cocos2d::Ref* pSender){
    
}
void ScorllMainLayer04::menuCloseCallback04(cocos2d::Ref* pSender){
    
}

void ScorllMainLayer04::menuCloseCallback05(cocos2d::Ref* pSender){
    
}
void ScorllMainLayer04::menuCloseCallback06(cocos2d::Ref* pSender){
    
}
