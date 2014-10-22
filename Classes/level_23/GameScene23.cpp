#include "GameScene23.h"
#include "game.h"
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
    Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	auto size = Director::getInstance()->getWinSize();  

    
    m_ui = UISimple::create();
    this->addChild(m_ui,30);
    
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("level_21/scene2.mp3", true);
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
	
	  boy=Sprite::create("level_23/boy.png");
	boy->setAnchorPoint(Point(1,0));
	boy->setPosition(Point(size.width,size.height*0.40));
	this->addChild(boy,2);

   	smile=Sprite::create("level_23/smile.png");
    smile->setPosition(Point(size.width*0.81,size.height*0.54));
	smile->setVisible(false);
	this->addChild(smile,2);

	cry=Sprite::create("level_23/cry.png");
    cry->setPosition(Point(size.width*0.81,size.height*0.54));
	this->addChild(cry,2);


	auto light=Sprite::create("level_23/light.png");
	light->setAnchorPoint(Point(0,1));
	light->setPosition(Point(0,size.height));
	this->addChild(light,2);

	auto table=Sprite::create("level_23/table.png");
	table->setAnchorPoint(Point(0,0));
	table->setPosition(Point(0,0));
	this->addChild(table,3);

    cup=Sprite::create("level_23/cup.png");
    cup->setAnchorPoint(Point(0, 0));
	cup->setPosition(Point(0, size.height*0.4));
	cup->runAction(MoveTo::create(3.0f,Point(size.width,size.height*0.4)));
	this->addChild(cup,3);

	auto cup2=Sprite::create("level_23/cup.png");
    cup2->setAnchorPoint(Point(0, 0));
	cup2->setPosition(Point(size.width*0.94,size.height*0.4));
	cup2->setVisible(false);
	this->addChild(cup2,3,11);

	hand=Sprite::create("level_23/hand.png");
	hand->setPosition(Point(size.width*0.94,size.height*0.42));
	hand->setVisible(false);
	this->addChild(hand,3);

	this->schedule(schedule_selector(GameScene23::hideHand),1.5f);

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
		this->getChildByTag(11)->setVisible(true);
        cry->setVisible(false);
		smile->setVisible(true);
	    this->success();
	 }
	return true;
}

void GameScene23::success(){
    this->runAction(Sequence::create(
                                     DelayTime::create(1.0f),
                                     CallFunc::create([&](){
        Director::getInstance()->replaceScene(SuccessScene::createScene(level24));
        
    }),NULL));
}
void GameScene23::lose(){

    this->runAction(Sequence::create(
                                     DelayTime::create(1.0f),
                                     CallFunc::create([&](){
        Director::getInstance()->replaceScene(LoseScene::createScene(level24));
        
    }),NULL));

}

