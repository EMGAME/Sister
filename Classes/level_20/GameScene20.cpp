//
//  GameScene20.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#include "GameScene20.h"


GameScene20::GameScene20(){}
GameScene20::~GameScene20(){}

Scene* GameScene20::createScene(){
    auto scene = Scene::create();
    auto layer = GameScene20::create();
    scene->addChild(layer,0,100);
    return scene;
}

bool GameScene20::init(){
    if (!Layer::init()) {
        return false;
    }

    auto winSize = Director::getInstance()->getWinSize();
    
    //m_shoubi = Sprite::create("new/shoubi.png");
    m_shoubi->setPosition(Point(winSize.width/2,winSize.height/2));
    m_shoubi->setRotation(45);
    addChild(m_shoubi);
    
    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(true);
    
    listener1->onTouchBegan = CC_CALLBACK_2(GameScene20::onTouchBegan, this);
    listener1->onTouchMoved = CC_CALLBACK_2(GameScene20::onTouchMoved, this);
    listener1->onTouchEnded = CC_CALLBACK_2(GameScene20::onTouchEnded, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, m_shoubi);
    
    return true;
    
}

bool GameScene20::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){
    auto target = static_cast<Sprite* >(pEvent->getCurrentTarget());
    Point locationInNode = pTouch->getLocation();
    
    auto point1 = target->convertToNodeSpace(locationInNode);
    if (
        //point1.x >= 0 && point1.y >=0 && point1.x <= 175 && point1.y <= 415
        point1.x >= 0 && point1.y >=0 && point1.x <= target->getContentSize().width && point1.y <= target->getContentSize().height
        ) {
        log("perfect");
        return true;
    }
    
    return false;

}

void GameScene20::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){

}

void GameScene20::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){

}