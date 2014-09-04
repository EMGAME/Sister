//
//  GameScene13.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#include "GameScene13.h"

Scene* GameScene13::createScene()  {
	auto scene = Scene::create();  
	auto layer = GameScene13::create();  
	scene->addChild(layer);  
	return scene;  
}

bool GameScene13::init()
{
	if ( !Layer::init() )
	{
		return false;
	}
	auto size = Director::getInstance()->getWinSize();  

	//background
	auto m_bg = Sprite::create("level_13/13-background.png");
	m_bg->setPosition(Point(size.width/2,size.height/2));
	this->addChild(m_bg);

 //加入UILayer
    uiLayer = UILayer::create();
	this->addChild(uiLayer,100);
    Director::getInstance()->resume();
}