#include "GameScene39.h"
#include "../game.h"

Scene* GameScene39::createScene(){

	auto scene = Scene::create();

	auto layer = GameScene39::create();

	scene->addChild(layer);

	return scene;
}

bool GameScene39::init(){
	
    m_ui = UISimple::create();
    this->addChild(m_ui, 30);
    
	Size visibleSize = Director::getInstance()->getWinSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	a = 0;

	//背景和左下角的手
	auto bg = Sprite::create("level_39/bg.png");
	bg->setPosition(Point(visibleSize.width * 0.5f,visibleSize.height * 0.5f));
	this->addChild(bg);

	auto hand = Sprite::create("level_39/hand.png");
	hand->setPosition(Point(visibleSize.width * 0.6f,visibleSize.height * 0.4f));
	this->addChild(hand);



	//plist加载
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("level_39/level39.plist","level_39/level39.png");
	
	auto black1 = Sprite::createWithSpriteFrameName("black.png");
	black1->setPosition(Point(275,220));
	black1->setScale(1.4);
	//black1->setVisible(false);
	this->addChild(black1,10);

	auto black2 = Sprite::createWithSpriteFrameName("black.png");
	black2->setPosition(Point(585,540));
	//black2->setVisible(false);
	this->addChild(black2,8);

	auto black3 = Sprite::createWithSpriteFrameName("black.png");
	black3->setPosition(Point(212,692));
	black3->setScale(0.8);
	//black3->setVisible(false);
	this->addChild(black3,6);

	auto black4 = Sprite::createWithSpriteFrameName("black.png");
	black4->setPosition(Point(462,846));
	black4->setScale(0.5);
	//black4->setVisible(false);
	this->addChild(black4,4);

	auto black5 = Sprite::createWithSpriteFrameName("black.png");
	black5->setPosition(Point(354,958));
	black5->setScale(0.3);
	//black5->setVisible(false);
	this->addChild(black5,2);

	//小偷
	thief1 = Sprite::createWithSpriteFrameName("thief.png");
	thief1->setPosition(Point(286,300));
	thief1->setVisible(false);
	this->addChild(thief1,9);

	thief2 = Sprite::createWithSpriteFrameName("thief.png");
	thief2->setPosition(Point(588,584));
	thief2->setScale(0.8);
	thief2->setVisible(false);
	this->addChild(thief2,7);

	thief3 = Sprite::createWithSpriteFrameName("thief.png");
	thief3->setPosition(Point(226,733));
	thief3->setScale(0.5);
	thief3->setVisible(false);
	this->addChild(thief3,5);

	thief4 = Sprite::createWithSpriteFrameName("thief.png");
	thief4->setPosition(Point(462,874));
	thief4->setScale(0.4);
	thief4->setVisible(false);
	this->addChild(thief4,3);

	thief5 = Sprite::createWithSpriteFrameName("thief.png");
	thief5->setPosition(Point(352,964));
	thief5->setScale(0.2);
	thief5->setVisible(false);
	this->addChild(thief5,1);

	//控制小偷位置变换
	this->schedule(schedule_selector(GameScene39::thiefMove),1,5,0);

	//触摸监听
	auto listener = EventListenerTouchOneByOne::create();

	//listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(GameScene39::onTouchBegan,this);

	listener->onTouchEnded = CC_CALLBACK_2(GameScene39::onTouchEnded,this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void GameScene39::thiefMove(float dt){
	a ++;

	if (a ==1){
		thief1->runAction(Sequence::create(
			CallFunc::create([&](){thief1->setVisible(true);}),
			MoveBy::create(0.5f,Point(0,170)),
			MoveBy::create(0.5f,Point(0,-170)),
			 NULL));
	}else if (a == 2)
	{
		thief1->setVisible(false);
		thief2->runAction(Sequence::create(
			CallFunc::create([&](){thief2->setVisible(true);}),
			MoveBy::create(0.5f,Point(0,130)),
			MoveBy::create(0.5f,Point(0,-130)),
			NULL));
	}else if (a == 3)
	{
		thief2->setVisible(false);
		thief3->runAction(Sequence::create(
			CallFunc::create([&](){thief3->setVisible(true);}),
			MoveBy::create(0.5f,Point(0,110)),
			MoveBy::create(0.5f,Point(0,-110)),
			NULL));
	}else if (a == 4)
	{
		thief3->setVisible(false);
		thief4->runAction(Sequence::create(
			CallFunc::create([&](){thief4->setVisible(true);}),
			MoveBy::create(0.5f,Point(0,70)),
			MoveBy::create(0.5f,Point(0,-70)),
			NULL));
	}else if(a == 5)
	{
		thief4->setVisible(false);
		thief5->runAction(Sequence::create(
			CallFunc::create([&](){thief5->setVisible(true);}),
			MoveBy::create(0.5f,Point(0,50)),
			MoveBy::create(0.5f,Point(0,-50)),
			NULL));
	}else if(a == 6)
	{
        thief5->setVisible(false);
	}

}

bool GameScene39::onTouchBegan(Touch *touch, Event *unused_event){
	
	auto location = touch->getLocation();
	
	auto rect2 = thief2->getBoundingBox();
	auto rect3 = thief3->getBoundingBox();
	auto rect4 = thief4->getBoundingBox();
	auto rect5 = thief5->getBoundingBox();

	if (a == 2)
	{
		if (rect2.containsPoint(location))
		{
			success();
		}
	}else if (a == 3)
	{
		if (rect3.containsPoint(location))
		{
			success();
		}
	}else if ( a == 4 )
	{
		if (rect4.containsPoint(location))
		{
			success();
		}
	}else if (a == 5)
	{
		if (rect5.containsPoint(location))
		{
			success();
		}
	}
	
	return true;
}

void GameScene39::onTouchEnded(Touch *touch, Event *unused_event){

}

void GameScene39::success(){
    this->runAction(Sequence::create(
                                     DelayTime::create(1.0f),
                                     CallFunc::create([&](){
        Director::getInstance()->replaceScene(SuccessScene::createScene(level39));
        
    }),NULL));}

void GameScene39::lose(){
    this->runAction(Sequence::create(
                                     DelayTime::create(1.0f),
                                     CallFunc::create([&](){
        Director::getInstance()->replaceScene(LoseScene::createScene(level39));
        
    }),NULL));}

void GameScene39::restart(){

}