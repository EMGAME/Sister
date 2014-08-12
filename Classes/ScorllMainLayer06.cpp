//
//  ScorllMainlayer06.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-12.
//
//

#include "ScorllMainlayer06.h"
#include "SimpleAudioEngine.h"

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
        
        auto waitImage = Sprite::createWithSpriteFrameName("sel_continue.png");
        waitImage->setPosition(Point(size.width/2, size.height/2));
        this->addChild(waitImage);
        
        
        bRet = true;
    } while (0);
    
    return bRet;
    
}
