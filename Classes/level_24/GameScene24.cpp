//
//  GameScene24.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#include "GameScene24.h"

Scene* GameScene24::createScene(){
	auto scene = Scene::createWithPhysics();

	Vect gravity(0,0);
	scene->getPhysicsWorld()->setGravity(gravity);

	//开启测试模式
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	//创建一个世界
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//创建一个空心盒子刚体，作为我们游戏世界的边界（避免游戏内的物体跑出屏幕） 
	//参数分别是刚体大小。材质（其实就是我们一些预设的数据）、边线厚度
	auto body = PhysicsBody::createEdgeBox(Size(visibleSize.width,visibleSize.height),PHYSICSBODY_MATERIAL_DEFAULT,3);
	body->getShape(0)->setFriction(0.0f);
	body->getShape(0)->setRestitution(1.001f);
	body->getShape(0)->setDensity(1.0f);

	//创建一个节点用于承载刚体，这样刚体就能参与到游戏的物理世界
	auto node = Node::create();
	node->setPosition(visibleSize.width/2,visibleSize.height/2);
	node->setPhysicsBody(body);
	scene->addChild(node);

	auto layer = GameScene24::create();
	scene->addChild(layer);

	return scene;
}

bool GameScene24::init(){

	if ( !Layer::init() )
	{
		return false;
	}

    m_ui = UISimple::create();
    this->addChild(m_ui, 30);
    
    
	Size visibleSize = Director::getInstance()->getWinSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	zidan = false;
	time = 5.0;

	//背景
	auto bg = Sprite::create("level_24/bg.jpg");
	bg->setPosition(Point(visibleSize.width* 0.5f,visibleSize.height * 0.5f));
	this->addChild(bg);
	//创建月亮
	moon = Sprite::create("level_24/hand1.png");
	moon->setPosition(Point(visibleSize.width * 0.5f,visibleSize.height * 0.5f));
	moon->setAnchorPoint(Point::ANCHOR_MIDDLE);
	moon->setTag(13);
	this->addChild(moon);

	auto body = PhysicsBody::createCircle(moon->getContentSize().width * 0.5f);
	body->getShape(0)->setFriction(0.0f);
	body->getShape(0)->setRestitution(1.001f);
	body->getShape(0)->setDensity(1.0f);
	body->setCategoryBitmask(1);    // 0001
	body->setCollisionBitmask(1);   // 0001
	body->setContactTestBitmask(1); // 0001
	body->setGravityEnable(false);
	moon->setPhysicsBody(body);
	body->applyImpulse(Vect(3500000, 0));


	//创建锯齿边缘
	auto border = Sprite::create("level_24/border.png");
	Size borderSize = border->getContentSize();

	auto border1 = createBorder(Point(borderSize.width * 0.9f, borderSize.height * 0.7f));
	this->addChild(border1);

	auto border2 = createBorder(Point(visibleSize.width - borderSize.width * 0.5f, borderSize.height * 0.7f));
	border2->setFlippedX(true);
	this->addChild(border2);

	auto border3 = createBorder(Point(visibleSize.width * 0.5f, visibleSize.height * 0.15f));
	borderSize = border3->getContentSize();
	border3->setRotation(90.0f);
	this->addChild(border3);

	auto border4 = createBorder(Point(visibleSize.width * 0.5f, visibleSize.height * 0.8f));
	borderSize = border4->getContentSize();
	border4->setRotation(90.0f);
	this->addChild(border4);
	
	//子弹
	shoot = Sprite::create("level_24/zidan1.png");
	shoot->setPosition(Point( visibleSize.width * 0.5f,visibleSize.height * 0.15f+40));
	shoot->setVisible(false);
	shoot->setAnchorPoint(Point::ANCHOR_MIDDLE);
	shoot->setTag(14);
	this->addChild(shoot);

	body1 = PhysicsBody::createCircle(shoot->getContentSize().width * 0.5f);
	body1->setCategoryBitmask(1);    // 0001
	body1->setCollisionBitmask(1);   // 0001
	body1->setContactTestBitmask(1); // 0001
	shoot->setPhysicsBody(body1);

	//加载初始文字
	boss = Sprite::create("new/text_she.png");
	boss->setAnchorPoint(Point::ANCHOR_MIDDLE_BOTTOM);
	boss->setPosition(Point(visibleSize.width/2,visibleSize.height+100));
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


	//触摸监听
	auto listener = EventListenerTouchOneByOne::create();

	//listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(GameScene24::onTouchBegan,this);

	listener->onTouchEnded = CC_CALLBACK_2(GameScene24::onTouchEnded,this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//碰撞监听
	auto contactListener = EventListenerPhysicsContact::create();

	contactListener->onContactBegin = CC_CALLBACK_1(GameScene24::onContactBegin, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	//5秒内无动作失败
	this->schedule(schedule_selector(GameScene24::update));
	return true;
}

bool GameScene24::onTouchBegan(Touch *touch, Event *unused_event){

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point location = touch->getLocation();

	if (zidan == false){
		  shoot->setVisible(true);
	      shoot->runAction(MoveTo::create(0.001f,Point(location.x,visibleSize.height * 0.15f+40)));
          body1->applyImpulse(Vect(0, 40000));
	
	      zidan = true;
	}
	return true;
}

void GameScene24::onTouchEnded(Touch *touch, Event *unused_event){

	Point a = moon->getPosition();
	//log("1+%f+%f",a.x,a.y);


}

Sprite* GameScene24::createBorder(Point pos){

	auto border = Sprite::create("level_24/border.png");

	Size borderSize = border->getContentSize();

	auto body = PhysicsBody::createBox(borderSize);
	body->setDynamic(false);
	body->getShape(0)->setFriction(0.0f);
	body->getShape(0)->setRestitution(1.001f);
	body->getShape(0)->setDensity(1.0f);

	body->setCategoryBitmask(1);    // 0001
	body->setCollisionBitmask(1);   // 0001
	body->setContactTestBitmask(1); // 0001
	border->setPhysicsBody(body);
	border->setPosition(pos);

	return border;
}

bool GameScene24::onContactBegin(PhysicsContact& contact){

	auto nodeA = (Sprite*)contact.getShapeA()->getBody()->getNode();

	auto nodeB = (Sprite*)contact.getShapeB()->getBody()->getNode();

	if (nodeA->getTag() == 13 && nodeB->getTag() == 14)
	{
		success();
	}
	if (nodeB->getTag() == 13 && nodeA->getTag() == 14)
	{
		success();
	}
	if (nodeB->getTag() == 14 && nodeA->getTag() != 14)
	{
		lose();
	}
	if (nodeA->getTag() == 14 && nodeB->getTag() != 14)
	{
		lose();
	}


	return true;
}

void GameScene24::onExit(){

	Layer::onExit();

	_eventDispatcher->removeEventListenersForTarget(this);

}

void GameScene24::success(){
    Director::getInstance()->replaceScene(SuccessScene::createScene(level25));
    log("success");
}

void GameScene24::lose(){
    this->runAction(Sequence::create(
                                     DelayTime::create(1.0f),
                                     CallFunc::create([&](){
        Director::getInstance()->replaceScene(LoseScene::createScene(level25));
        
    }),NULL));
}

void GameScene24::update(float dt){
	time -= 0.013;
	if(time < 0){
		lose();
	}
}