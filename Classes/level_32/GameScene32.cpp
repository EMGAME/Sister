//
//  GameScene21.cpp
//  Sister
//
//  Created by ����� on 14-8-13.
//
//

#include "GameScene32.h"
#include "game.h"

GameScene32::GameScene32(){
	touchTimes=0;
}
GameScene32::~GameScene32(){
}

Scene* GameScene32::createScene(){
	auto scene = Scene::create();
	auto layer = GameScene32::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene32::init(){
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Size winSize = Director::getInstance()->getWinSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	m_ui = UISimple::create();
	m_ui->setPosition(Point::ZERO);
	this->addChild(m_ui,10);

	// ��ӱ���
	auto bg = Sprite::create("new/bg32.png");
	bg->setPosition(visibleSize.width/2,visibleSize.height/2);
	this->addChild(bg);
	// һ������ָ����
	hand = Sprite::create("new/ringHand.png");
	hand->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	hand->setPosition(108,0);
	this->addChild(hand,1);
	// ��ָ
	ring = Sprite::create("new/hand.png");
	ring->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	ring->setPosition(Point(158,162));
	this->addChild(ring,2);
	// ����Ļ������ʵ��
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GameScene32::onTouchBegan,this);
	listener->onTouchMoved = CC_CALLBACK_2(GameScene32::onTouchMoved,this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
	// ����update 
	scheduleUpdate();
	schedule(schedule_selector(GameScene32::update),1.0f);

	return true;
}

bool GameScene32::onTouchBegan(Touch *touch,Event *unused_event){
	beginpos = touch->getLocationInView();//��ô���λ��
	beginpos = Director::getInstance()->convertToGL(beginpos);//ת��������
	//log("%f",beginpos.y);
	return true;
}
void GameScene32::onTouchMoved(Touch *touch, Event *unused_event){
	endpos = touch->getPreviousLocationInView();//��ȡ����������λ��
	endpos = Director::getInstance()->convertToGL(endpos);

	Point offset = ccpSub(endpos,beginpos);
	//log("%f   %f   %f",beginpos.y,endpos.y,offset.y);
	if (offset.x!=0)
	{
		if (ring->getPosition().y-158<=128)
		{
			//  ����ָ����Ļ�����»�����ʱ��,��ָ�����ƶ���ʱ��ָ��������
			auto toRight = MoveBy::create(0.2f,Point(0,0.8));
			ring->runAction(toRight);
		}else if(ring->getPosition().y-158>128){
			//  ��ʱ��ָ�����Ŀ�
			auto toRight = MoveBy::create(0.2f,Point(0,3));
			ring->runAction(toRight);
		}
	}
}

void GameScene32::update(float tmd){
	if(ring->getPosition().y-158>=308)
	{
		// �����ָ����ָ�Ѿ�����  ��˵����ָ�Ѿ�ժ���ˣ������ɹ�����
		// ʧ��ֻ���ڳ���ʱ�仹û��ժ����ָʱ������ʧ�ܽ���
		log("success!!");
		success();
	}
}

void GameScene32::restart(){
	Director::getInstance()->replaceScene(GameScene32::createScene());
	Director::getInstance()->resume();
}

void GameScene32::lose(){
    this->runAction(Sequence::create(
                                     DelayTime::create(1.0f),
                                     CallFunc::create([&](){
        Director::getInstance()->replaceScene(LoseScene::createScene(level33));
        
    }),NULL));
}
void GameScene32::success(){
    this->runAction(Sequence::create(
                                     DelayTime::create(1.0f),
                                     CallFunc::create([&](){
        Director::getInstance()->replaceScene(SuccessScene::createScene(level33));
        
    }),NULL));
}