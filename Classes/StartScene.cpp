//
//  StartScene.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-11.
//
//

#include "StartScene.h"
#include "SelectScene/ScrollViewScene.h"
#include "UILayer/SuccessLayer.h"
USING_NS_CC;

Scene* StartScene::createScene(){
    auto scene = Scene::create();
    auto layer = StartScene::create();
    scene->addChild(layer);
    return scene;
}

bool StartScene::init(){
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto winSize = Director::getInstance()->getWinSize();
    
    MenuItemLabel* startGameBtn = MenuItemLabel::create(Label::create("StartGame", "", 40),CC_CALLBACK_0(StartScene::startGame, this));
    
    startGameBtn->setPosition(Point(winSize.width/2,winSize.height/2 - 200));
    
    auto startMenu = Menu::create(startGameBtn, NULL);
    startMenu->setPosition(Point::ZERO);
    this->addChild(startMenu);
    return true;
}

void StartScene::startGame(){

    CCDirector::getInstance()->replaceScene(CCTransitionFade::create(0.5, ScrollViewScene::createScene()));
}