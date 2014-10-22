//
//  GameScene21.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#include "GameScene33.h"
#include "../game.h"

GameScene33::GameScene33(){
    time=5.0
    ;
	touchNum=0;
	i = 0;
}
GameScene33::~GameScene33(){
}

Scene* GameScene33::createScene(){
	auto scene = Scene::create();
	auto layer = GameScene33::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene33::init(){
	Size winSize = Director::getInstance()->getWinSize();

	m_ui = UISimple::create();
	m_ui->setPosition(Point::ZERO);
	this->addChild(m_ui,10);

	// 添加背景
	auto bg = Sprite::create("new/bg33.png");
	bg->setPosition(winSize.width/2,winSize.height/2);
	this->addChild(bg);
	// 帧动画的第一针
	original = Sprite::create("new/01.png");
	original->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	original->setPosition(Point(130,158));
	original->setVisible(false);
	this->addChild(original,11);
	// 水滴滴下的感觉
	drop = Sprite::create("new/drop.png");
	drop->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	drop->setPosition(Point(253,578));
	drop->setVisible(false);
	this->addChild(drop);
	// 对屏幕监听的实现
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GameScene33::onTouchBegan,this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
	// 开启update 
	scheduleUpdate();
	schedule(schedule_selector(GameScene33::update),1.0f);
	// 添加向瓶内加水的例子
	createVSlider();

	return true;
}

bool GameScene33::onTouchBegan(Touch *touch,Event *unused_event){

	if (touchNum<=25)
	{
		touchNum += 1;
		volume = touchNum;
		m_VSlider->setValue(volume);
		//水滴滴下的函数
		dropWater();
	}else
	{
		i += 1;
		volume  = touchNum + 4*i;
		m_VSlider->setValue(volume);
		//水滴滴下的函数
		dropWater();
	}

	if(volume>50){
		original->setVisible(true);
		auto animation1 = Animation::create();
		for (int n=1;n<=9;n++)
		{
			char szName[100] = {0};
			sprintf(szName,"new/0%d.png",n);
			animation1->addSpriteFrameWithFileName(szName);
		}

		animation1->setDelayPerUnit(0.2f);
		animation1->setRestoreOriginalFrame(true);
		auto action1 = Animate::create(animation1);
		original->runAction(action1) ;

		schedule(schedule_selector(GameScene33::fail),1.5f);
		// 失败 
		log("no");
	}

	return true;
}

void GameScene33::update(float tmd){
    time-= 0.013;
	if (time<=0.5) {
        log("%f",time);
        if (volume==50) {
            success();
        }
    }
}

void GameScene33::createVSlider() {
	m_VSlider = ControlSlider::create(
		CCSprite::create("new/emptyBottle.png"),
		CCSprite::create("new/liquid.png"),
		CCSprite::create("new/symbol.png"));
	m_VSlider->setPosition(Point::ZERO);
	m_VSlider->setAnchorPoint(Point::ANCHOR_TOP_LEFT);

	m_VSlider->setEnabled(false);	// 让滑动条不可以滑动修改数值
	m_VSlider->setMaximumValue(50);	// 最大值
	m_VSlider->setMinimumValue(0);	// 最小值
	m_VSlider->setValue(0);			// 当前值

	auto hp_node = Node::create();
	hp_node->addChild(m_VSlider);
	hp_node->setAnchorPoint(Point::ANCHOR_TOP_LEFT);
	hp_node->setPosition(Point(130,158));
	hp_node->setRotation(-90);

	this->addChild(hp_node, 10);
}

void GameScene33::dropWater(){
	drop->setVisible(true);
	auto fall = MoveBy::create(0.5f,Point(0,-20));
	drop->runAction(fall);
	scheduleOnce(schedule_selector(GameScene33::unVisible),0.5f);
}
void GameScene33::unVisible(float tmd){
	drop->setVisible(false);
	drop->setPosition(Point(252,570));
}

void GameScene33::restart(){
	Director::getInstance()->replaceScene(GameScene33::createScene());
	Director::getInstance()->resume();
}

void GameScene33::lose(){
    this->runAction(Sequence::create(
                                     DelayTime::create(1.0f),
                                     CallFunc::create([&](){
        Director::getInstance()->replaceScene(LoseScene::createScene(level39));
        
    }),NULL));
}

void GameScene33::success(){
    this->runAction(Sequence::create(
                                     DelayTime::create(1.0f),
                                     CallFunc::create([&](){
        Director::getInstance()->replaceScene(SuccessScene::createScene(level39));
        
    }),NULL));
}
void GameScene33::fail(float tmd){
    lose();
}