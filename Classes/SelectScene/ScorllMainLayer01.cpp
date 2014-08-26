//
//  ScorllMainLayer01.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-12.
//
//

#include "ScorllMainLayer01.h"
#include "SimpleAudioEngine.h"
#include "game.h"

using namespace CocosDenshion;

ScorllMainLayer01::ScorllMainLayer01()
{
}

ScorllMainLayer01::~ScorllMainLayer01()
{
}

bool ScorllMainLayer01::init()
{
    bool bRet = false;
    
    do {
        Size size = CCDirector::getInstance()->getWinSize();
        //初始化信息
        SpriteFrameCache *cache = SpriteFrameCache::getInstance();
        cache->addSpriteFramesWithFile("thumbs.plist");
        
        auto closeItem01 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("thumb_level1.png"),
                                             Sprite::createWithSpriteFrameName("thumb_level1.png"),
                                             CC_CALLBACK_1(ScorllMainLayer01::menuCloseCallback01, this));
        closeItem01->setPosition(Point(size.width*0.5-120,size.height*0.5+200));
        
        auto closeItem02 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("thumb_level2.png"),
                                                  Sprite::createWithSpriteFrameName("thumb_level2.png"),
                                                  CC_CALLBACK_1(ScorllMainLayer01::menuCloseCallback02, this));
        closeItem02->setPosition(Point(size.width*0.5+120,size.height*0.5+200));
        
        auto closeItem03 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("thumb_level3.png"),
                                                  Sprite::createWithSpriteFrameName("thumb_level3.png"),
                                                  CC_CALLBACK_1(ScorllMainLayer01::menuCloseCallback03, this));
        closeItem03->setPosition(Point(size.width*0.5-120,size.height*0.5));
        
        auto closeItem04 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("thumb_level4.png"),
                                                  Sprite::createWithSpriteFrameName("thumb_level4.png"),
                                                  CC_CALLBACK_1(ScorllMainLayer01::menuCloseCallback04, this));
        closeItem04->setPosition(Point(size.width*0.5+120,size.height*0.5));
        
        auto closeItem05 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("thumb_level5.png"),
                                                  Sprite::createWithSpriteFrameName("thumb_level5.png"),
                                                  CC_CALLBACK_1(ScorllMainLayer01::menuCloseCallback05, this));
        closeItem05->setPosition(Point(size.width*0.5-120,size.height*0.5-200));
        
        auto closeItem06 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("thumb_level6.png"),
                                                  Sprite::createWithSpriteFrameName("thumb_level6.png"),
                                                  CC_CALLBACK_1(ScorllMainLayer01::menuCloseCallback06, this));
        closeItem06->setPosition(Point(size.width*0.5+120,size.height*0.5-200));

        
        auto menu = Menu::create(closeItem01,closeItem02,closeItem03,closeItem04,closeItem05,closeItem06,NULL);
        menu->setPosition(Point::ZERO);
        this->addChild(menu, 1);
        
        
        bRet = true;
    } while (0);
    
    return bRet;
}

void ScorllMainLayer01::menuCloseCallback01(cocos2d::Ref* pSender){
    Director::getInstance()->replaceScene(GameScene07::scene());
}
void ScorllMainLayer01::menuCloseCallback02(cocos2d::Ref* pSender){
   // Director::getInstance()->replaceScene(GameScene11::createScene());
}
void ScorllMainLayer01::menuCloseCallback03(cocos2d::Ref* pSender){
    //Director::getInstance()->replaceScene(GameScene12::createScene());
}
void ScorllMainLayer01::menuCloseCallback04(cocos2d::Ref* pSender){
    Director::getInstance()->replaceScene(GameScene01::createScene());
}

void ScorllMainLayer01::menuCloseCallback05(cocos2d::Ref* pSender){
    
}
void ScorllMainLayer01::menuCloseCallback06(cocos2d::Ref* pSender){
    
}
