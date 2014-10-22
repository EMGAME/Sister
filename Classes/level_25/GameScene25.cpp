//
//  GameScene25.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//
#include "GameScene25.h"
#include "../level_02/LoseScene.h"
#include "../level_02/SuccessScene.h"

Scene* GameScene25::createScene(){
    
	auto scene = Scene::create();
    
	auto layer = GameScene25::create();
	scene->addChild(layer);
    
	return scene;
}

bool GameScene25::init(){
    
	if ( !Layer::init() )
	{
		return false;
	}
    
	a = 0;
    
    Size winSize = Director::getInstance()->getWinSize();
    
    m_ui = UISimple::create();
    this->addChild(m_ui,30);
    
    
    //加载初始文字
    boss = Sprite::create("new/text_zha.png");
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
    
    
	//Size visibleSize = Director::getInstance()->getVisibleSize();
	//Point origin = Director::getInstance()->getVisibleOrigin();
    
    auto bg = Sprite::create("level_25/bg.jpg");
    bg->setPosition(Point::ZERO);
    bg->setAnchorPoint(Point::ZERO);
    this->addChild(bg);
    
    
	shoubi = Sprite::create("level_25/shoubi.png");
	shoubi->setPosition(Point(-5.1f,229.04f));
	shoubi->setRotation(49.78);
	shoubi->setTag(11);
	this->addChild(shoubi);
    
	
     auto shouzhang = Sprite::create("level_25/shouzhang01.png");
     shouzhang->setPosition(Point(250.73f,461.59f));
     shouzhang->setRotation(47.19);
     shouzhang->setTag(12);
     this->addChild(shouzhang,2);
     
     auto finger1 = Sprite::create("level_25/figur01.png");
     finger1->setPosition(Point(253,709.71f));
     finger1->setRotation(9.03);
     finger1->setTag(13);
     this->addChild(finger1,2);
     
     auto finger2 = Sprite::create("level_25/figur02.png");
     finger2->setPosition(Point(381.86f,711.75f));
     finger2->setRotation(30.81);
     finger2->setTag(14);
     this->addChild(finger2,2);
     
     auto finger3 = Sprite::create("level_25/figur03.png");
     finger3->setPosition(Point(468,648));
     finger3->setRotation(46.36);
     finger3->setTag(15);
     this->addChild(finger3,2);
     
     auto finger4 = Sprite::create("level_25/figur04.png");
     finger4->setPosition(Point(511.42f,528.64f));
     finger4->setRotation(55.35);
     finger4->setTag(16);
     this->addChild(finger4,2);
     
     auto finger5 = Sprite::create("level_25/figur05.png");
     finger5->setPosition(Point(418.27f,357.44f));
     finger5->setRotation(83.12);
     finger5->setTag(17);
     this->addChild(finger5,2);

    
    
    
    //球
	 c1 = Sprite::create("level_25/1.png");
	c1->setPosition(Point(418.5,276.5));
	c1->setTag(1);
	this->addChild(c1);
    
	 c2 = Sprite::create("level_25/2.png");
	c2->setPosition(Point(523,446));
	c2->setTag(2);
	this->addChild(c2);
    
	 c3 = Sprite::create("level_25/3.png");
	c3->setPosition(Point(533.5 ,626.5));
	c3->setTag(3);
	this->addChild(c3);
    
	 c4 = Sprite::create("level_25/4.png");
	c4->setPosition(Point(466.5,739.5));
	c4->setTag(4);
	this->addChild(c4);
    
	 c5 = Sprite::create("level_25/5.png");
	c5->setPosition(Point(319.5,739.5));
	c5->setTag(5);
	this->addChild(c5);
    
	//触摸监听
	auto listener = EventListenerTouchOneByOne::create();
    
	//listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(GameScene25::onTouchBegan,this);
    
	listener->onTouchEnded = CC_CALLBACK_2(GameScene25::onTouchEnded,this);
    
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    
    auto listener2 = EventListenerTouchOneByOne::create();
    listener2->setSwallowTouches(true);
    listener2->onTouchBegan = CC_CALLBACK_2(GameScene25::onTouchBegan2, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener2, shoubi);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener2->clone(), shouzhang);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener2->clone(), finger1);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener2->clone(), finger2);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener2->clone(), finger3);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener2->clone(), finger4);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener2->clone(), finger5);
    
    auto m_uiLayer = UISimple::create();
    this->addChild(m_uiLayer);
    
    
	return true;
}

bool GameScene25::onTouchBegan(Touch *touch, Event *unused_event){
    
	location = touch->getLocation();
    
	//C1的触摸范围
	auto C1rect = c1->getBoundingBox();
	//C2的触摸范围
	auto C2rect = c2->getBoundingBox();
	//C3的触摸范围
    auto C3rect = c3->getBoundingBox();
	//C4的触摸范围
	auto C4rect = c4->getBoundingBox();
	//C5的触摸范围
	auto C5rect = c5->getBoundingBox();
 
	
    if (C1rect.containsPoint(location)){
		if (a == 0 ){
            hide(1);
            a = 1;
		}else{
			//lose();
		}
	}
	if (C2rect.containsPoint(location)){
		if (a == 1 ){
			hide(2);
			a = 2;
		}else{
			//lose();
		}
	}
	if (C3rect.containsPoint(location)){
		if (a == 2 ){
			hide(3);
			a = 3;
		}else{
			//lose();
		}
	}
	if (C4rect.containsPoint(location)){
		if (a == 3 ){
			hide(4);
			a = 4;
		}else{
			//lose();
		}
	}
	if (C5rect.containsPoint(location)){
		if (a == 4 ){
			hide(5);
			a = 5;
		}else{
			//lose();
		}
	}
    

	
    return true;
}

void GameScene25::onTouchEnded(Touch *touch, Event *unused_event){
    
	knife = Sprite::create("level_25/knife.png");
	knife->setAnchorPoint(Point::ZERO);
	knife->setPosition(Point(location.x + 25,location.y + 25));
	knife->setVisible(true);
	this->addChild(knife,5);
	knife->runAction(Sequence::create( MoveBy::create(0.1f,Point(-25,-25)),
                                      DelayTime::create(0.2f),
                                      CallFuncN::create(
                                                        [](Node* knife){knife->setVisible(false);}
                                                        ),NULL));
	
	if (a == 5)
	{
        success();
    }
}

void GameScene25::hide(int a){
    
	this->getChildByTag(a)->setVisible(false);
}


bool GameScene25::onTouchBegan2(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){
    auto target = static_cast<Sprite* >(pEvent->getCurrentTarget());
    locationInNode = pTouch->getLocation();
    
    auto point1 = target->convertToNodeSpace(locationInNode);
    if (
        point1.x >= 0 && point1.y >=0 && point1.x <= target->getContentSize().width && point1.y <= target->getContentSize().height
        ) {

        this->runAction(Sequence::create( CallFunc::create(
                                                           [&](){
                                                               auto blood = Sprite::create("level_25/blood.png");
                                                               blood->setPosition(locationInNode);
                                                               blood->setScale(0.1f);
                                                               this->addChild(blood,30);
                                                               blood->runAction(ScaleTo::create(0.5, 1.0f));
                                                           }),
                                         DelayTime::create(1.0f),
                                         CallFunc::create(
                                                          [&](){
                                                              hurt();
                                                          }),
                                         NULL));
        
        knife = Sprite::create("level_25/knife.png");
        knife->setAnchorPoint(Point::ZERO);
        knife->setPosition(Point(locationInNode.x + 25,locationInNode.y + 25));
        knife->setVisible(true);
        this->addChild(knife,5);
        knife->runAction(Sequence::create( MoveBy::create(0.1f,Point(-25,-25)),
                                          DelayTime::create(0.2f),
                                          CallFuncN::create(
                                                            [](Node* knife){knife->setVisible(false);}
                                                            ),NULL));
        return true;
    }
    
    return false;

}

void GameScene25::lose(){
    _eventDispatcher->removeAllEventListeners();
    this->runAction(Sequence::create(
                                     DelayTime::create(1.0f),
                                     CallFunc::create([&](){
        Director::getInstance()->replaceScene(LoseScene::createScene(level26));

    }),NULL));
}

void GameScene25::success(){
        Director::getInstance()->replaceScene(SuccessScene::createScene(level26));
            _eventDispatcher->removeAllEventListeners();
}

void GameScene25::hurt(){
    _eventDispatcher->removeAllEventListeners();
    lose();
}