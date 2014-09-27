//
//  ScorllMainlayer06.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-12.
//
//

#include "ScorllMainlayer06.h"
#include "SimpleAudioEngine.h"
#include "game.h"

using namespace CocosDenshion;

ScorllMainlayer06::ScorllMainlayer06()
{
}

ScorllMainlayer06::~ScorllMainlayer06()
{
}

bool ScorllMainlayer06::init()
{
    bool bRet = false;
    
    do {
        Size size = CCDirector::getInstance()->getWinSize();
        //初始化信息
        SpriteFrameCache *cache = SpriteFrameCache::getInstance();
        cache->addSpriteFramesWithFile("ui_select.plist");
        
        auto waitImage = Sprite::create("new/girl.png");
        waitImage->setPosition(Point(size.width/2, size.height/2));
        this->addChild(waitImage);
        
        auto listener1 = EventListenerTouchOneByOne::create();
        listener1->setSwallowTouches(false);
        
        listener1->onTouchBegan = CC_CALLBACK_2(ScorllMainlayer06::onTouchBegan, this);
        listener1->onTouchEnded = CC_CALLBACK_2(ScorllMainlayer06::onTouchEnded, this);
        
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, waitImage);
        
        bRet = true;
    } while (0);
    
    return bRet;
    
}

bool ScorllMainlayer06::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){
        auto target = static_cast<Sprite* >(pEvent->getCurrentTarget());
        Point locationInNode = pTouch->getLocation();
        Rect pRect = target->getBoundingBox();
        
        if (pRect.containsPoint(locationInNode)) {

            log("true");
        return true;
        }
        
        return false;
}


void ScorllMainlayer06::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){
    
    auto target = static_cast<Sprite* >(pEvent->getCurrentTarget());
    Point locationInNode = pTouch->getLocation();
    Rect pRect = target->getBoundingBox();
    
    if (pRect.containsPoint(locationInNode)) {

    log("true2");
    Director::getInstance()->replaceScene(GameScene21::createScene());
    }

}
