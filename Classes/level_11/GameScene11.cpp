#include "GameScene11.h"
#include "CCVector.h"
#include "../UILayer/UILayer.h"
USING_NS_CC;

Scene* GameScene11::createScene(){
	auto scene = Scene::create();

	auto layer = GameScene11::create();

	scene->addChild(layer, 0, 100);

	return scene;
}

bool GameScene11::init(){
	if ( !Layer::init() )
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	//加载背景
	auto background = Sprite::create("level11/bgbg.png");
	background->setPosition(Point(visibleSize.width *0.5,visibleSize.height * 0.5));
	this->addChild(background);

	//隐藏物品手链

	//脸
	auto face = MenuItemImage::create("level11/faceCry.png",
		"level11/faceLaugh.png",
		CC_CALLBACK_0(GameScene11::face,this));
	face->setPosition(visibleSize.width * 0.25,visibleSize.height * 0.568);

	auto button1 = Menu::create(face, NULL);
	button1->setPosition(Point::ZERO);
	this->addChild(button1, 2);

	//玫瑰花
	auto flower = MenuItemImage::create("level11/flower1.png",
		"level11/flower2.png",
		CC_CALLBACK_0(GameScene11::flower,this));
	flower->setPosition(visibleSize.width * 0.8,visibleSize.height * 0.5);

	auto button2 = Menu::create(flower, NULL);
	button2->setPosition(Point::ZERO);
	this->addChild(button2, 2);

	//酒杯
	auto glass = MenuItemImage::create("level11/glass1.png",
		"level11/glass2.png",
		CC_CALLBACK_0(GameScene11::glass,this));
	glass->setPosition(visibleSize.width * 0.5,visibleSize.height * 0.5);

	auto button3 = Menu::create(glass, NULL);
	button3->setPosition(Point::ZERO);
	this->addChild(button3, 3);

	//小丑面具
	auto clown = MenuItemImage::create("level11/clown1.png",
		"level11/clown2.png",
		CC_CALLBACK_0(GameScene11::clown,this));
	clown->setPosition(visibleSize.width * 0.7,visibleSize.height * 0.16);

	auto button4 = Menu::create(clown, NULL);
	button4->setPosition(Point::ZERO);
	this->addChild(button4, 2);
		

	//手链
	auto handline = Sprite::create("level11/handline.png");
	handline->setPosition(Point(visibleSize.width * 0.6,visibleSize.height * 0.85));
	handline->setVisible(false);
	this->addChild(handline,6);

    auto m_uiLayer = UILayer::create();
    m_uiLayer->setPosition(Point::ZERO);
    this->addChild(m_uiLayer,100);
    
    Director::getInstance()->resume();

    
	//测试容器vector
	/*Vector<Sprite*> sp_vec;
	sp_vec.pushBack(face);
	sp_vec.pushBack(handline);

	for (auto& e : sp_vec)
	{
	e->runAction(MoveBy::create(5.0f,Point(0,-100)));
	}*/


	return true;
}

void GameScene11::clown(){

	MessageBox("Beautiful girl said 'oh! that is not funny,keep away from me' ","fail");
}
void GameScene11::flower(){

	MessageBox("Beautiful girl said 'he he!'","fail");
}
void GameScene11::glass(){
	MessageBox("Beautiful girl said 'Who are you'","fail");
}

void GameScene11::face(){
	MessageBox("Beautiful girl laugh","success");
}

void GameScene11::restart(){
    Director::getInstance()->replaceScene(GameScene11::createScene());
    Director::getInstance()->resume();
    log("GameScene11Restart");
}