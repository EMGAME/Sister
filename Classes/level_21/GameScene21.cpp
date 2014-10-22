#include "GameScene21.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;  
using namespace CocosDenshion;

GameScene21::GameScene21(){

}
GameScene21::~GameScene21(){}

Scene* GameScene21::createScene()  
{  
	auto scene = Scene::create();  
	auto layer = GameScene21::create();  
	scene->addChild(layer);  
	return scene;  
}  

bool GameScene21::init()
{
	if ( !Layer::init() )
	{
		 return false;
	}
    Size visibleSize = Director::getInstance()->getVisibleSize();
	auto size = Director::getInstance()->getWinSize();  

	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("level_21/scene2.mp3", true);

    m_ui = UISimple::create();
    this->addChild(m_ui,30);
    
	 //¼ÓÔØ³õÊ¼ÎÄ×Ö
    boss = Sprite::create("level_21/test_ting.png");
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


	/*auto buttonItem = MenuItemImage::create("play_nor.png","play_pre.png",  CC_CALLBACK_0(scene2::stopDart, this));  
    buttonItem->setPosition(Point(150,50));
    auto buttonItem1 = Menu::create(buttonItem, NULL);  
	buttonItem1->setPosition(size.width*0.6,size.height*0.1);
	this->addChild(buttonItem1,2 );  */

	auto bg=Sprite::create("level_21/bg1.png");
	bg->setPosition(Point(size.width/2,size.height/2));
	this->addChild(bg,1);

	auto borad=Sprite::create("level_21/borad.png");
	borad->setPosition(Point(size.width/2,size.height/2));
	this->addChild(borad,2);
	
	center=Sprite::create("level_21/center.png");
	center->setPosition(Point(size.width*0.49,size.height/2+10));
	this->addChild(center,2);

	dart=Sprite::create("level_21/dart.png");
	dart->setAnchorPoint(Point(0,0));
	dart->setPosition(Point(size.width*0.7,size.height*0.1));
	this->addChild(dart,2);
	
	heart=Sprite::create("level_21/heart.png") ;
	heart->setPosition(Point(size.width/2-13,size.height/2-260));
	heart->runAction(RepeatForever::create(Sequence::create(MoveBy::create(1.0,Point(0,600)),MoveBy::create(1.0,Point(0,-600)),NULL)));
	this->addChild(heart,2,3);

	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->onTouchBegan = CC_CALLBACK_2(GameScene21::onTouchBegan, this);
	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);
   
    return true;
}

void GameScene21::stopDart(){
	/*auto size = Director::getInstance()->getWinSize();  
	this->getChildByTag(3)->stopAllActions();
	heart->setVisible(false);
	dart->runAction(Sequence::create(ScaleTo::create(0.25, 2.0),MoveTo::create(0.3,Point(heart->getPositionX()+30,heart->getPositionY()+30)),ScaleTo::create(0.25, 0.5),Sequence::create(MoveBy::create(0.1,Point(20,0)),MoveBy::create(0.1,Point(-20,0)),MoveBy::create(0.1,Point(15,0)),MoveBy::create(0.1,Point(-15,0)),MoveBy::create(0.1,Point(10,0)),MoveBy::create(0.1,Point(-10,0))),NULL));
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	SimpleAudioEngine::sharedEngine()->playEffect("dart.mp3",false);*/
	
	/*if((dart->getPositionY()>(size.height/2-40))&&(dart->getPositionY()<(size.height/+60))){
		log("success");
    }else
	{
		log("fail");
	}*/
	/*if (center->getBoundingBox().containsPoint(dart->getPosition())) {
       log("success");
    }else{
       log("fail");
    }*/
	
}
bool GameScene21::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){
   // auto size = Director::getInstance()->getWinSize();  
	this->getChildByTag(3)->stopAllActions();
	heart->setVisible(false);
	dart->runAction(Sequence::create(
                                     ScaleTo::create(0.25, 2.0),
                                     MoveTo::create(0.3,Point(heart->getPositionX(),heart->getPositionY()+10)),
                                     ScaleTo::create(0.25, 0.5),
                                     Sequence::create(MoveBy::create(0.1,Point(20,0)),
                                                      MoveBy::create(0.1,Point(-20,0)),
                                                      MoveBy::create(0.1,Point(15,0)),
                                                      MoveBy::create(0.1,Point(-15,0)),
                                                      MoveBy::create(0.1,Point(10,0)),
                                                      MoveBy::create(0.1,Point(-10,0)),NULL),NULL));
    
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	SimpleAudioEngine::sharedEngine()->playEffect("level_21/dart.mp3",false);
	int finish=1;
   
	if(finish==1){
		if(center->getBoundingBox().containsPoint(heart->getPosition())){
		this->success();
	}else
	{
	this->lose();
	}
	}
	return true;
}

void GameScene21::success(){
    this->runAction(Sequence::create(
                                     DelayTime::create(1.0f),
                                     CallFunc::create([&](){
        Director::getInstance()->replaceScene(SuccessScene::createScene(level22));
        
    }),NULL));
}

void GameScene21::lose(){
    this->runAction(Sequence::create(
                                     DelayTime::create(1.0f),
                                     CallFunc::create([&](){
        Director::getInstance()->replaceScene(LoseScene::createScene(level22));
        
    }),NULL));
}

  


