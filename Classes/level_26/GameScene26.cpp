//
//  GameScene26.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#include "GameScene26.h"
#include "game.h"
#include "../level_02/LoseScene.h"
#include "../level_02/SuccessScene.h"

//#include "SimpleAudioEngine.h"
//#include "extensions/cocos-ext.h"
//using namespace  CocosDenshion;
//USING_NS_CC_EXT;


GameScene26::GameScene26(){
	isTouch=1;
	degree=0;
	time = 5.0;
}
GameScene26::~GameScene26(){
}
Scene* GameScene26::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene26::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene26::init()
{
	if ( !Layer::init() )
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Size winSize = Director::getInstance()->getWinSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	m_ui = UISimple::create();
	m_ui->setPosition(Point::ZERO);
	this->addChild(m_ui,10);

	//加载初始文字
	boss = Sprite::create("new/text_ting.png");
	boss->setAnchorPoint(Point::ANCHOR_MIDDLE_BOTTOM);
	boss->setPosition(Point(winSize.width/2,winSize.height+100));
	this->addChild(boss,30);
	auto pSequence2 = Sequence::create(CallFunc::create(
		[&](){
			auto bossAct = MoveTo::create(0.5f, Point(Director::getInstance()->getVisibleSize().width/2, 680));
			auto bossEase = EaseBackInOut::create(bossAct);
			boss->runAction(bossEase);}),
				DelayTime::create(1.0f),
				CallFunc::create(
				[&](){
					boss->runAction(MoveTo::create(0.5f,
						Point(Director::getInstance()->getVisibleSize().width/2, Director::getInstance()->getVisibleSize().height+200)));
			}),NULL);
			this->runAction(pSequence2);
			// 切换关卡  以后删去
			auto closeItem = MenuItemImage::create(
				"CloseNormal.png",
				"CloseSelected.png",
				CC_CALLBACK_1(GameScene26::menuCloseCallback, this));
			closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
				origin.y + closeItem->getContentSize().height/2));
			auto menu = Menu::create(closeItem, NULL);
			menu->setPosition(Point::ZERO);
			this->addChild(menu, 5);


			auto bg = Sprite::create("new/bg26.png");
			bg->setPosition(768/2,1136/2);
			this->addChild(bg,1);

			plate = Sprite::create("new/turnPlate.png");
			plate->setAnchorPoint(Point::ANCHOR_MIDDLE);
			plate->setPosition(384,614);
			this->addChild(plate,1);

			scheduleUpdate();
			schedule(schedule_selector(GameScene26::update),1.0f);

			auto listener = EventListenerTouchOneByOne::create();//创建一个触摸监听(单点触摸）  
			listener->onTouchBegan = CC_CALLBACK_2(GameScene26::onTouchBegan, this);//指定触摸的回调函数  
			_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);//将listener放入事件委托中  

			auto rotate = RotateBy::create(1,360);
			repeatForever = RepeatForever::create(rotate);
			//plate->runAction(repeatForever);

			//加载音效
			SimpleAudioEngine::sharedEngine()->preloadEffect("new/KeypressStandard.mp3");
			SimpleAudioEngine::sharedEngine()->playBackgroundMusic("new/scene.mp3",true);
			return true;
}

bool GameScene26::onTouchBegan(Touch *touch, Event *unused_event){
	stopAction(repeatForever);
	isTouch=0;
	degree %= 360;
	if (315<degree&&degree<360)
	{
		log("touchDegree = %d",degree);
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		SimpleAudioEngine::sharedEngine()->playEffect("new/end.mp3");
		//log("success");
        this->unscheduleUpdate();
		success();
	}else{
        //log("touchDegree = %d",degree);

		//log("failure");
        
        this->unscheduleUpdate();

		lose();
	}

	return true;
}

void GameScene26::update(float tmd){
	if(isTouch){
		degree += 6;
        plate->setRotation(degree);
	}
	time-=0.013;
	if (time<=0)
	{
		lose();
	}
}

void GameScene26::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->replaceScene(GameScene27::createScene());

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void GameScene26::restart(){
	Director::getInstance()->replaceScene(GameScene26::createScene());
	Director::getInstance()->resume();
}

void GameScene26::lose(){
    this->runAction(Sequence::create(
                                     DelayTime::create(1.0f),
                                     CallFunc::create([&](){
        Director::getInstance()->replaceScene(LoseScene::createScene(level27));
        
    }),NULL));
}

void GameScene26::success(){
    Director::getInstance()->replaceScene(SuccessScene::createScene(level27));
}