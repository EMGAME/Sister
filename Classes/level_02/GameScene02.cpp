//
//  GameScene02.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#include "GameScene02.h"
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
    
    return true;
}