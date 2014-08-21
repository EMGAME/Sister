//
//  GameScene01.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#include "GameScene01.h"
#include "../UILayer/UILayer.h"
USING_NS_CC;

GameScene01::GameScene01(){}
GameScene01::~GameScene01(){}

Scene* GameScene01::createScene(){
    auto scene = Scene::create();
    auto layer = GameScene01::create();
    scene->addChild(layer,0,100);
    return scene;
}

bool GameScene01::init(){
    if (!Layer::init()) {
        return false;
    }
    auto winSize = Director::getInstance()->getWinSize();
    
    auto bg = Sprite::create("level_01/l1bg.png");
    bg->setPosition(winSize.width/2,winSize.height/2);
    this->addChild(bg,1);

    auto m_ui = UILayer::create();
    m_ui->setPosition(Point::ZERO);
    this->addChild(m_ui,10);
    
    
    auto m_zhuantou = Sprite::create("level_01/zhuantou.png");
    m_zhuantou->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
    m_zhuantou->setPosition(Point(430,59));
    this->addChild(m_zhuantou,0);
    
    auto m_jinggai = Sprite::create("level_01/jinggai.png");
    m_jinggai->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
    m_jinggai->setPosition(Point(427,81));
    this->addChild(m_jinggai,2);
    
    auto m_ludeng = Sprite::create("level_01/ludeng.png");
    m_ludeng->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
    m_ludeng->setPosition(Point(640,81));
    this->addChild(m_ludeng,2);
    
    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(true);
    
    listener1->onTouchBegan = CC_CALLBACK_2(GameScene01::onTouchBegan, this);
    listener1->onTouchMoved = CC_CALLBACK_2(GameScene01::onTouchMoved, this);
    listener1->onTouchEnded = CC_CALLBACK_2(GameScene01::onTouchEnded, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, m_zhuantou);
    


    
//    auto listener2 = EventListenerTouchOneByOne::create();
//    listener2->setSwallowTouches(true);
//    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener2, m_jinggai);
//    
//    auto listener3 = EventListenerTouchOneByOne::create();
//    listener3->setSwallowTouches(true);
//    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener3, m_ludeng);
    
    
    return true;
}

void GameScene01::restart(){
    Director::getInstance()->replaceScene(GameScene01::createScene());
    Director::getInstance()->resume();
}

bool GameScene01::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){
    return true;
}

void GameScene01::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){
}

void GameScene01::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){

}

void GameScene01::ListenerTouchBegan(){
    log("ListenerTouchBegan");
}

