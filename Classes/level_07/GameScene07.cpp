
//
//  GameScene07.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#include "GameScene07.h"

bool GameScene07::init()
{
	if(!Layer::init())
	{
		return false;
	}

	//获取屏幕大小
	Size visibleSize = Director::getInstance()->getVisibleSize();
    Size winSize = Director::getInstance()->getWinSize();
    
	auto bg = Sprite::create("l11_bg.jpg");
	bg->setPosition(winSize.width / 2, winSize.height / 2);
	this->addChild(bg);

    auto moveacti = MoveBy::create(2.0f, Point(400, 400));
    bg->runAction(moveacti);
    
	//加入UILayer
	auto uiLayer = UILayer::create();
	this->addChild(uiLayer);
    
    Director::getInstance()->resume();

	return true;
}

Scene* GameScene07::scene()
{
	auto scene = Scene::create();
	auto layer = GameScene07::create();
	scene->addChild(layer);
	return scene;
}

GameScene07::GameScene07(void)
{
}


GameScene07::~GameScene07(void)
{
}

void GameScene07::restart(){
    Director::getInstance()->replaceScene(GameScene07::scene());
    Director::getInstance()->resume();
    log("GameScene07Restart");
}

