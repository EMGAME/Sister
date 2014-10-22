//
//  GameScene27.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#include "GameScene27.h"
#include "game.h"

GameScene27::GameScene27(){
	power = 0;
	time = 5.0;
}
GameScene27::~GameScene27(){
}
Scene* GameScene27::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene27::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene27::init(){
	if ( !Layer::init() )
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	Size winSize = Director::getInstance()->getWinSize(); 

	m_ui = UISimple::create();
	m_ui->setPosition(Point::ZERO);
	this->addChild(m_ui,10);

	//加载初始文字
	boss = Sprite::create("new/text_bai.png");
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
	auto closeItem = MenuItemImage::create(
											"CloseNormal.png",
											"CloseSelected.png",
											CC_CALLBACK_1(GameScene27::menuCloseCallback, this));
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
												origin.y + closeItem->getContentSize().height/2));

	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 5);

	auto bg = Sprite::create("new/bg27.png");
	bg->setPosition(768/2,1136/2);
	this->addChild(bg,1);

	compare = Sprite::create("new/compare1.png");
	compare->setPosition(768/2,1136/3);
	this->addChild(compare,1);

	createHPSlider();

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GameScene27::onTouchBegan, this);//指定触摸的回调函数  
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);//将listener放入事件委托中  

	scheduleUpdate();
	schedule(schedule_selector(GameScene27::update),1.0f);

	return true;
}

void GameScene27::update(float tmd){
	schedule(schedule_selector(GameScene27::tremble),1.0f);
	
	time-=0.013;
	if (time<=0)
	{
		lose();
	}
}

bool GameScene27::onTouchBegan(Touch *touch, Event *unused_event){
	power += 1;

	m_hpSlider->setValue(power);
	if (power>=30)
	{
		compare->setVisible(false);
		auto pos = compare->getPosition();
		auto victory = Sprite::create("new/success.png");
		victory->setPosition(pos);
		this->addChild(victory,2);
		log("success");
		success();
	}

	return true;
}



void GameScene27::createHPSlider() {
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	m_hpSlider = ControlSlider::create(
		CCSprite::create("new/powerBg.png"),
		CCSprite::create("new/power.png"),
		CCSprite::create("new/sliderThumb.png"));
	m_hpSlider->setAnchorPoint(Point(0,0));
	m_hpSlider->setPosition(Point(100,914));

	m_hpSlider->setTouchEnabled(false);	// 让滑动条不可以滑动修改数值
	m_hpSlider->setMaximumValue(30);	// 最大值
	m_hpSlider->setMinimumValue(0);		// 最小值
	m_hpSlider->setValue(0);			// 当前值
	this->addChild(m_hpSlider, 3);
}

void GameScene27::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->replaceScene(GameScene28::createScene());

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void GameScene27::restart(){
	Director::getInstance()->replaceScene(GameScene27::createScene());
	Director::getInstance()->resume();
}

void GameScene27::lose(){
    
    this->runAction(Sequence::create(
                                     DelayTime::create(1.0f),
                                     CallFunc::create([&](){
        Director::getInstance()->replaceScene(LoseScene::createScene(level28));
        
    }),NULL));}
void GameScene27::success(){
    
    this->runAction(Sequence::create(
                                     DelayTime::create(1.0f),
                                     CallFunc::create([&](){
        Director::getInstance()->replaceScene(SuccessScene::createScene(level28));
        
    }),NULL));}

void GameScene27::tremble(float tmd){
	auto animation1 = Animation::create();
	for (int n=1;n<=2;n++)
	{
		char szName[100] = {0};
		sprintf(szName,"new/compare%d.png",n);
		animation1->addSpriteFrameWithFileName(szName);
	}
	animation1->setDelayPerUnit(0.4f);
	animation1->setRestoreOriginalFrame(true);
	auto action1 = Animate::create(animation1);
	compare->runAction(action1) ;
}