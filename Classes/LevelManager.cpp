//
//  LevelManager.cpp
//  Sister
//
//  Created by 风飞逸 on 14-9-18.
//
//

#include "LevelManager.h"
#include "game.h"
#include "StartScene.h"

bool LevelManager::init(){
    return true;
}

void LevelManager::replaceScene(LevelNum pLevelNum){
    
    //在这里添加要跳转的关卡
    switch (pLevelNum) {
        case level01:
            Director::getInstance()->replaceScene(GameScene01::createScene());
            break;
        case level02:
            Director::getInstance()->replaceScene(GameScene02::createScene());
            break;
        case level03:
            break;
            case level04:
            break;
            case level05:
            break;
            case level06:
            break;
            case level07:
            break;
            case level08:
            break;
            
        case level21:
            Director::getInstance()->replaceScene(GameScene21::createScene());
            break;
        case level22:
            Director::getInstance()->replaceScene(GameScene22::createScene());
            break;
        case level23:
            Director::getInstance()->replaceScene(GameScene23::createScene());
            break;
            
        case level24:
            Director::getInstance()->replaceScene(GameScene24::createScene());
            break;
            
        case level25:
            Director::getInstance()->replaceScene(GameScene25::createScene());
            break;
            
        case level26:
            Director::getInstance()->replaceScene(GameScene26::createScene());
            break;
        case level27:
            Director::getInstance()->replaceScene(GameScene27::createScene());
            break;
        case level28:
            Director::getInstance()->replaceScene(GameScene28::createScene());
            break;
            
            case level29:
            break;
            
            case level30:
            Director::getInstance()->replaceScene(GameScene30::createScene());
            break;
            
        case level31:
            Director::getInstance()->replaceScene(GameScene31::createScene());
            break;
        case level32:
            Director::getInstance()->replaceScene(GameScene32::createScene());
            break;
        case level33:
            Director::getInstance()->replaceScene(GameScene33::createScene());
            break;
        case level34:
            Director::getInstance()->replaceScene(GameScene33::createScene());
            break;
        case level35:
            Director::getInstance()->replaceScene(GameScene33::createScene());
            break;
        case level36:
            Director::getInstance()->replaceScene(GameScene36::createScene());
            break;
        case level39:
            Director::getInstance()->replaceScene(GameScene39::createScene());
            break;
        case finalLevel:
            Director::getInstance()->replaceScene(StartScene::createScene());
            break;
            
    }
}