//
//  GameScene02.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#include "GameScene02.h"
#include "GameScene04.h"
#include"../UILayer/UILayer.h"
GameScene02::GameScene02(){}
GameScene02::~GameScene02(){};

Scene* GameScene02::createScene(){
    auto scene = Scene::create();
    auto layer = GameScene02::create();
    scene->addChild(layer);
    return scene;
}

bool GameScene02::init(){
    if (!Layer::init()) {
        return false;
    }
    auto uiLayer = UILayer::create();
    uiLayer->setPosition(Point::ZERO);
    this->addChild(uiLayer);
    
    uiLayer->Success("这一关啥都木有。。。", 3);
    
    return true;
}

void GameScene02::nextLevel(){
    Director::getInstance()->replaceScene(GameScene04::createScene());
}