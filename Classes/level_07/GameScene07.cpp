<<<<<<< HEAD
//
//  GameScene07.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#include "GameScene07.h"
=======
#include "GameScene07.h"

bool GameScene07::init()
{
	if(!Layer::init())
	{
		return false;
	}

	//获取屏幕大小
	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto bg = Sprite::create("l11_bg.jpg");
	bg->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(bg);

	//加入UILayer
	auto uiLayer = UILayer::create();
	this->addChild(uiLayer);

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
>>>>>>> UILayer
