#include "GameScene23.h"

USING_NS_CC;  


GameScene23::GameScene23(){
 float time=5.00;
}
GameScene23::~GameScene23(){}


Scene* GameScene23::createScene()  
{  
	auto scene = Scene::create();  
	auto layer = GameScene23::create();  
	scene->addChild(layer);  
	return scene;  
}  

bool GameScene23::init()
{
	if ( !Layer::init() )
	{
		return false;
	}
    
    m_ui = UISimple::create();
    this->addChild(m_ui,30);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	auto size = Director::getInstance()->getWinSize();  

	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("level_23/scene2.mp3", true);
	//¼ÓÔØ³õÊ¼ÎÄ×Ö
    boss = Sprite::create("level_23/test_ting.png");
    boss->setAnchorPoint(Point::ANCHOR_MIDDLE_BOTTOM);
	boss->setPosition(Point(size.width/2,size.height+100));
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

	auto bg=Sprite::create("level_23/bg2.png");
	bg->setPosition(Point(size.width/2,size.height/2));
	this->addChild(bg,1);
	
	auto boyWithCup=Sprite::create("level_23/h2.png");
	boyWithCup->setPosition(Point(size.width*0.83,size.height*0.51));
	boyWithCup->setVisible(false);
	this->addChild(boyWithCup,5,3);

    boy=Sprite::create("level_23/boy.png");
	boy->setAnchorPoint(Point(1,0));
	boy->setPosition(Point(size.width,size.height*0.27));
	this->addChild(boy,2);
	
	auto table=Sprite::create("level_23/table.png");
	table->setAnchorPoint(Point(0,0));
	table->setPosition(Point(0,0));
	this->addChild(table,3);

    cup=Sprite::create("level_23/cup.png");
    cup->setAnchorPoint(Point(0, 0));
	cup->setPosition(Point(0, size.height*0.4));
	cup->runAction(MoveTo::create(1.8f,Point(size.width,size.height*0.4)));
	this->addChild(cup,3);

	point1=Sprite::create("level_23/h1.png");
	point1->setPosition(Point(size.width*0.83,size.height*0.515));
	this->addChild(point1,5) ;

	point2=Sprite::create("level_23/b1.png");
	point2->setPosition(Point(size.width*0.65,size.height*0.6));
	this->addChild(point2,2);

	hand=Sprite::create("level_23/hand.png");
	hand->setPosition(Point(size.width*0.94,size.height*0.42));
	hand->setVisible(false);
	this->addChild(hand,3);

	animation1 = Animation::create();
	for (int i=1;i<4;i++)
	{
		char szName[100] = {0};
		sprintf(szName,"level_23/b%d.png",i);
		animation1->addSpriteFrameWithFileName(szName);
	 }

	animation1->setDelayPerUnit(0.4f);
	animation1->setRestoreOriginalFrame(true);
	action1 = CCAnimate::create(animation1);
	point2->runAction(action1) ;

	
	
	this->schedule(schedule_selector(GameScene23::hideHand),1.0f);

	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->onTouchBegan = CC_CALLBACK_2(GameScene23::onTouchBegan, this);
	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);

	return true;
}



void GameScene23::hideHand(float  dt)  {
	hand->setVisible(false);
} 

bool GameScene23::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){
		auto size = Director::getInstance()->getWinSize(); 
	hand->setVisible(true);
	if(hand->getBoundingBox().intersectsRect(cup->getBoundingBox())){
		cup->setVisible(false);
		this->removeChild(boy);
animation = Animation::create();
	for (int i=1;i<4;i++)
	{
		char szName[100] = {0};
		sprintf(szName,"level_23/h%d.png",i);
		animation->addSpriteFrameWithFileName(szName);
	}

	animation->setDelayPerUnit(0.3f);
	animation->setRestoreOriginalFrame(true);
	action = CCAnimate::create(animation);
	point1->runAction(action);
	this->getChildByTag(3)->setVisible(true);
		this->success();
    }else{
        this->lose();
    }
	return true;
}

void GameScene23::success(){
    Director::getInstance()->replaceScene(SuccessScene::createScene(level24));
}

void GameScene23::lose(){
    this->runAction(Sequence::create(
                                     DelayTime::create(1.0f),
                                     CallFunc::create([&](){
        Director::getInstance()->replaceScene(LoseScene::createScene(level24));
        
    }),NULL));

}