#include "GameScene31.h"
#include "SimpleAudioEngine.h"
#include "../game.h"
USING_NS_CC;  
using namespace CocosDenshion;

GameScene31::GameScene31(){}
GameScene31::~GameScene31(){}

int tag1=0;
int tag2=0;
int tag3=0;
int tag4=0;
int tag5=0;
int tag=0;

auto size = Director::getInstance()->getWinSize();
Scene* GameScene31::createScene()  
{  
	auto scene = Scene::create();  
	auto layer = GameScene31::create();  
	scene->addChild(layer);  
	return scene;  
}  

bool GameScene31::init()
{
	if ( !Layer::init() )
	{
		 return false;
	}
    Size visibleSize = Director::getInstance()->getVisibleSize();
	auto size = Director::getInstance()->getWinSize();  

	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("level_30/scene2.mp3", true);

	 //¼ÓÔØ³õÊ¼ÎÄ×Ö
    boss = Sprite::create("level_30/test_ting.png");
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


	auto bg=Sprite::create("level_31/scene.png");
	bg->setPosition(Point(size.width/2,size.height/2));
	this->addChild(bg);
	
	finger1=Sprite::create("level_31/finger1.png" );
    finger1->setPosition(Point(size.width*0.685,size.height*0.325));
	this->addChild(finger1,2);

	finger2=Sprite::create("level_31/finger2.png" );
    finger2->setPosition(Point(size.width*0.761,size.height*0.493));
	this->addChild(finger2,2);

	finger3=Sprite::create("level_31/finger3.png" );
	finger3->setPosition(Point(size.width*0.665,size.height*0.57));
	this->addChild(finger3,2);

	finger4=Sprite::create("level_31/finger4.png" );
	finger4->setPosition(Point(size.width*0.52,size.height*0.59));
	this->addChild(finger4,2);

	finger5=Sprite::create("level_31/finger5.png" );
	finger5->setPosition(Point(size.width*0.38,size.height*0.56));
	this->addChild(finger5,2);

	 nail1=Sprite::create("level_31/nail1.png" );
	nail1->setPosition(Point(size.width*0.2,size.height*0.85));
	this->addChild( nail1,3);
	
	 nail2=Sprite::create("level_31/nail2.png");
     nail2->setPosition(Point(size.width*0.5,size.height*0.85));
	this->addChild( nail2,3);

	 nail3=Sprite::create("level_31/nail3.png");
     nail3->setPosition(Point(size.width*0.5,size.height*0.75));
	this->addChild( nail3,3);

	 nail4=Sprite::create("level_31/nail4.png");
	 nail4->setPosition(Point(size.width*0.35,size.height*0.75));
	this->addChild( nail4,3);

	 nail5=Sprite::create("level_31/nail5.png");
	 nail5->setPosition(Point(size.width*0.79,size.height*0.75));
	this->addChild( nail5,3) ;
	
     nail6=Sprite::create("level_31/nail6.png");
	 nail6->setPosition(Point(size.width*0.65,size.height*0.75));
	this->addChild( nail6,3);

	  nail7=Sprite::create("level_31/nail7.png");
	  nail7->setPosition(Point(size.width*0.65,size.height*0.85));
	this->addChild( nail7,3);

	 nail8=Sprite::create("level_31/nail8.png");
	 nail8->setPosition(Point(size.width*0.35,size.height*0.85));
	this->addChild( nail8,3);

	 nail9=Sprite::create("level_31/nail9.png"); 
	  nail9->setPosition(Point(size.width*0.79,size.height*0.85));
	this->addChild( nail9,3); 

	  nail10=Sprite::create("level_31/nail10.png");
	 nail10->setPosition(Point(size.width*0.2,size.height*0.75));
	this->addChild( nail10,3);

    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(true);
	listener1->onTouchBegan = CC_CALLBACK_2(GameScene31::onTouchBegan, this);
	listener1->onTouchMoved = CC_CALLBACK_2(GameScene31::onTouchMoved, this);
	listener1->onTouchEnded = CC_CALLBACK_2(GameScene31::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1,  nail1);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(),  nail2);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(),  nail3);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(),  nail4);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(),  nail5);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(),  nail6);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(),  nail7);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(),  nail8);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(),  nail9);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(),  nail10);

    return true;
}

bool GameScene31::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){
        auto target = static_cast<Sprite* >(pEvent->getCurrentTarget());
        Point locationInNode = pTouch->getLocation();
     //   log("touchx=%f,touchY=%f,targetX=%f,targety=%f",locationInNode.x,locationInNode.y,target->getPositionX(),target->getPositionY());
        Rect pRect = target->getBoundingBox();
        
        if (pRect.containsPoint(locationInNode)) {
            
            return true;
        }
        
        return false;
}

void GameScene31::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){
    auto target = static_cast<Sprite* >(pEvent->getCurrentTarget());
    target->setPosition(target->getPosition()+pTouch->getDelta());
	//auto size = Director::getInstance()->getWinSize();  
	MoveTo* moveTo_1;
    MoveTo* moveTo_2;
	if (finger1->getBoundingBox().containsPoint(nail1->getPosition())) {
		//moveTo_1=MoveTo::create(1.0f,Point(finger1->getPositionX(),finger1->getPositionY()));
		log("success1");
		tag1=1;
    }else{
		//moveTo_1=MoveTo::create(1.0f,Point(size.width*0.2,size.height*0.85));
		tag1=0;
		log("fail1");
    }
	//nail1->runAction(moveTo_1);
	if (finger2->getBoundingBox().containsPoint(nail2->getPosition())) {
		//moveTo_2=MoveTo::create(1.0f,Point(size.width*0.761,size.height*0.493));
		tag2=1;
		log("success2");
    }else{
		//moveTo_2=MoveTo::create(1.0f,Point(size.width*0.5,size.height*0.85));
		tag2=0;
		log("fail2");
    }
	//nail2->runAction(moveTo_2);
	if (finger3->getBoundingBox().containsPoint(nail3->getPosition())) {
	    log("success3");
		tag3=1;
    }else{
	    tag3=0;
		log("fail3");
    }

	if (finger4->getBoundingBox().containsPoint(nail4->getPosition())) {
		log("success4");
		tag4=1;
    }else{
		tag4=0;
		log("fail4");
    }

	if (finger5->getBoundingBox().containsPoint(nail5->getPosition())) {
		log("success5");
		tag5=1;
    }else{
		tag5=0;
		log("fail5");
    }
}

void GameScene31::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){
   tag=tag1+tag2+tag3+tag4+tag5;
   if(tag==5){
	   this->success();
   }
	
}

void GameScene31::success(){
    this->runAction(Sequence::create(
                                     DelayTime::create(1.0f),
                                     CallFunc::create([&](){
        Director::getInstance()->replaceScene(SuccessScene::createScene(level32));
        
    }),NULL));}

void GameScene31::lose(){
    this->runAction(Sequence::create(
                                     DelayTime::create(1.0f),
                                     CallFunc::create([&](){
        Director::getInstance()->replaceScene(LoseScene::createScene(level32));
        
    }),NULL));		}
