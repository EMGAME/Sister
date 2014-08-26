//
//  ScorllMainlayer02.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-12.
//
//

#include "ScorllMainlayer02.h"
#include "SimpleAudioEngine.h"
#include "game.h"
using namespace CocosDenshion;

ScorllMainlayer02::ScorllMainlayer02()
{
}

ScorllMainlayer02::~ScorllMainlayer02()
{
}

bool ScorllMainlayer02::init()
{
    bool bRet = false;
    
    do {
        Size size = CCDirector::getInstance()->getWinSize();
        //初始化信息
        SpriteFrameCache *cache = SpriteFrameCache::getInstance();
        cache->addSpriteFramesWithFile("thumbs.plist");
        
        auto closeItem01 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("thumb_level7.png"),
                                                  Sprite::createWithSpriteFrameName("thumb_level7.png"),
                                                  CC_CALLBACK_1(ScorllMainlayer02::menuCloseCallback01, this));
        closeItem01->setPosition(Point(size.width*0.5-120,size.height*0.5+200));
        
        auto closeItem02 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("thumb_level8.png"),
                                                  Sprite::createWithSpriteFrameName("thumb_level8.png"),
                                                  CC_CALLBACK_1(ScorllMainlayer02::menuCloseCallback02, this));
        closeItem02->setPosition(Point(size.width*0.5+120,size.height*0.5+200));
        
        auto closeItem03 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("thumb_level9.png"),
                                                  Sprite::createWithSpriteFrameName("thumb_level9.png"),
                                                  CC_CALLBACK_1(ScorllMainlayer02::menuCloseCallback03, this));
        closeItem03->setPosition(Point(size.width*0.5-120,size.height*0.5));
        
        auto closeItem04 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("thumb_level10.png"),
                                                  Sprite::createWithSpriteFrameName("thumb_level10.png"),
                                                  CC_CALLBACK_1(ScorllMainlayer02::menuCloseCallback04, this));
        closeItem04->setPosition(Point(size.width*0.5+120,size.height*0.5));
        
        auto closeItem05 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("thumb_level11.png"),
                                                  Sprite::createWithSpriteFrameName("thumb_level11.png"),
                                                  CC_CALLBACK_1(ScorllMainlayer02::menuCloseCallback05, this));
        closeItem05->setPosition(Point(size.width*0.5-120,size.height*0.5-200));
        
        auto closeItem06 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("thumb_level12.png"),
                                                  Sprite::createWithSpriteFrameName("thumb_level12.png"),
                                                  CC_CALLBACK_1(ScorllMainlayer02::menuCloseCallback06, this));
        closeItem06->setPosition(Point(size.width*0.5+120,size.height*0.5-200));
        
        
        auto menu = Menu::create(closeItem01,closeItem02,closeItem03,closeItem04,closeItem05,closeItem06,NULL);
        menu->setPosition(Point::ZERO);
        this->addChild(menu, 1);
        
        
        bRet = true;
    } while (0);
    
    return bRet;
    
}

void ScorllMainlayer02::menuCloseCallback01(cocos2d::Ref* pSender){
    log("SS");
}
void ScorllMainlayer02::menuCloseCallback02(cocos2d::Ref* pSender){
    
}
void ScorllMainlayer02::menuCloseCallback03(cocos2d::Ref* pSender){
   // Director::getInstance()->replaceScene(Level09::createScene());
}
void ScorllMainlayer02::menuCloseCallback04(cocos2d::Ref* pSender){
	//Director::getInstance()->replaceScene(GameScene10::createScene());
}

void ScorllMainlayer02::menuCloseCallback05(cocos2d::Ref* pSender){
    
}
void ScorllMainlayer02::menuCloseCallback06(cocos2d::Ref* pSender){
    
}
