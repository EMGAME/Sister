//
//  SuccessLayer.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-25.
//
//
#include "SuccessLayer.h"
#include "UILayer.h"

SuccessLayer::SuccessLayer(){}
SuccessLayer::~SuccessLayer(){}

bool SuccessLayer::init(){
    if (!Layer::init()) {
        return false;
    }
    
    auto winSize = Director::getInstance()->getWinSize();
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ui_result.plist");
    
    auto bg = Sprite::createWithSpriteFrameName("result_bg_pass.png");
    bg->setPosition(winSize.width/2,winSize.height/2+200);
    this->addChild(bg,0);
    
    auto fg_fail = Sprite::createWithSpriteFrameName("result_fg_pass.png");
    fg_fail->setPosition(winSize.width/2,winSize.height/2+150);
    this->addChild(fg_fail,1);
    
    auto frame = Sprite::createWithSpriteFrameName("result_frame.png");
    frame->setPosition(winSize.width/2,winSize.height/2+200);
    this->addChild(frame,2);
    
    auto bottomBg = Sprite::createWithSpriteFrameName("result_bottom_bg.png");
    bottomBg->setPosition(Point(winSize.width/2, winSize.height/2-100));
    this->addChild(bottomBg,0);
    
    auto lose = Sprite::createWithSpriteFrameName("result_win.png");
    lose->setAnchorPoint(Point::ANCHOR_MIDDLE_TOP);
    lose->setPosition(winSize.width/2,winSize.height/2+450);
    this->addChild(lose,3);
    
    //相关摁钮
    auto nextBtn = MenuItemSprite::create(Sprite::createWithSpriteFrameName("result_btn_next.png"),
                                          Sprite::createWithSpriteFrameName("result_btn_next.png"),
                                          CC_CALLBACK_0(SuccessLayer::nextCallback, this));
    nextBtn->setAnchorPoint(Point::ANCHOR_TOP_RIGHT);
    nextBtn->setPosition(Point(winSize.width/2-90,winSize.height/2-40));
    this->addChild(nextBtn,1);
    
    auto restartBtn = MenuItemSprite::create(Sprite::createWithSpriteFrameName("result_btn_replay.png"),
                                             Sprite::createWithSpriteFrameName("result_btn_replay.png"),
                                             CC_CALLBACK_0(SuccessLayer::restartCallBack, this));
    restartBtn->setAnchorPoint(Point::ANCHOR_TOP_LEFT);
    restartBtn->setPosition(Point(winSize.width/2+90,winSize.height/2-40));
    this->addChild(restartBtn,1);
    
    auto shareBtn = MenuItemSprite::create(Sprite::createWithSpriteFrameName("result_btn_share.png"),
                                           Sprite::createWithSpriteFrameName("result_btn_share.png"),
                                           CC_CALLBACK_0(SuccessLayer::shareCallBack, this));
    shareBtn->setAnchorPoint(Point::ANCHOR_MIDDLE_TOP);
    shareBtn->setPosition(Point(winSize.width/2,winSize.height/2-40));
    this->addChild(shareBtn,1);
    
    auto arrow = Sprite::createWithSpriteFrameName("result_arrow.png");
    arrow->setAnchorPoint(Point::ANCHOR_MIDDLE_TOP);
    arrow->setPosition(Point(winSize.width/2-75,winSize.height/2-150));
    this->addChild(arrow,4);
    
    auto m_string = LabelTTF::create(getTip(), "", 25,Size(400,200));
    m_string->setAnchorPoint(Point::ANCHOR_MIDDLE_TOP);
    m_string ->setPosition(Point(winSize.width/2, winSize.height/2-200));
    this->addChild(m_string,4);
    
    return true;
}

void SuccessLayer::setString(std::string m_string){
    setTip(m_string);
}

void SuccessLayer::nextCallback(){
    
}

void SuccessLayer::shareCallBack(){
    
}

void SuccessLayer::restartCallBack(){
    auto director = Director::getInstance();
	Scene* runningScene = director->getRunningScene();
    auto layer = runningScene->getChildByTag(100);
	BaseLayer* baseLayer = (BaseLayer*)layer;
    baseLayer->restart();
}