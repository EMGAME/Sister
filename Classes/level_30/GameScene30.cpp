#include "GameScene30.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;  
using namespace CocosDenshion;

GameScene30::GameScene30(){
	
}
GameScene30::~GameScene30(){}

    int leftAdd=0;
	int rightAdd=0;
    
	int leftTag1=0;
	int leftTag2=0;
	int leftTag3=0;
	int leftTag4=0;
	int leftTag5=0;
	int leftTag6=0;
	
	int rightTag1=0;
	int rightTag2=0;
	int rightTag3=0;
	int rightTag4=0;
	int rightTag5=0;
	int rightTag6=0;

Scene* GameScene30::createScene()  
{  
	auto scene = Scene::create();  
	auto layer = GameScene30::create();  
	scene->addChild(layer);  
	return scene;  
}  

bool GameScene30::init()
{
	if ( !Layer::init() )
	{
		 return false;
	}
    Size visibleSize = Director::getInstance()->getVisibleSize();
	auto size = Director::getInstance()->getWinSize();  

	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("level_30/scene2.mp3", true);

    m_ui = UISimple::create();
    this->addChild(m_ui,30);
    
    
    
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


	auto bg=Sprite::create("level_30/bg1.png");
	bg->setPosition(Point(size.width/2,size.height/2));
	this->addChild(bg);
	
	boy=Sprite::create("level_30/boy.png");
	boy->setPosition(Point(size.width*0.5,size.height*0.63));
	this->addChild(boy,1);

	boy2=Sprite::create("level_30/boy2.png");
	boy2->setPosition(Point(size.width*0.5,size.height*0.63));
	boy2->setVisible(false);
	this->addChild(boy2,1);
	
	leftHand=Sprite::create("level_30/leftHand.png");
	//leftHand->setAnchorPoint(Point(0,0));
	leftHand->setPosition(Point(size.width*0.33,size.height*0.555));
	this->addChild(leftHand,1);

	rightHand=Sprite::create("level_30/rightHand.png");
	//rightHand->setAnchorPoint(Point(0,0));
	rightHand->setPosition(Point(size.width*0.69,size.height*0.555)) ;
	this->addChild(rightHand,1);

	bag1=Sprite::create("level_30/1.png" );
	//bag1->setAnchorPoint(Point(1,1));
	bag1->setPosition(Point(size.width*0.1,size.height*0.2));
	this->addChild(bag1,2);
	
	bag2=Sprite::create("level_30/2.png");
	//bag2->setAnchorPoint(Point(0,0));
	bag2->setPosition(Point(size.width*0.25,size.height*0.2));
	this->addChild(bag2,2);

	bag3=Sprite::create("level_30/3.png");
	//bag3->setAnchorPoint(Point(0,0));
	bag3->setPosition(Point(size.width*0.4,size.height*0.2));
	this->addChild(bag3,2);

	bag4=Sprite::create("level_30/4.png");
	//bag4->setAnchorPoint(Point(0,0));
	bag4->setPosition(Point(size.width*0.55,size.height*0.2));
	this->addChild(bag4,2);

	bag5=Sprite::create("level_30/5.png");
	//bag5->setAnchorPoint(Point(0,0));
	bag5->setPosition(Point(size.width*0.70,size.height*0.2));
	this->addChild(bag5,2);
	
    bag6=Sprite::create("level_30/6.png");
	//bag6->setAnchorPoint(Point(0,0));
	bag6->setPosition(Point(size.width*0.90,size.height*0.2));
	this->addChild(bag6,2);

    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(true);
	listener1->onTouchBegan = CC_CALLBACK_2(GameScene30::onTouchBegan, this);
	listener1->onTouchMoved = CC_CALLBACK_2(GameScene30::onTouchMoved, this);
	listener1->onTouchEnded = CC_CALLBACK_2(GameScene30::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, bag1);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), bag2);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), bag3);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), bag4);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), bag5);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), bag6);

    return true;
}


bool GameScene30::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){
      
         auto target = static_cast<Sprite* >(pEvent->getCurrentTarget());
        Point locationInNode = pTouch->getLocation();
     //   log("touchx=%f,touchY=%f,targetX=%f,targety=%f",locationInNode.x,locationInNode.y,target->getPositionX(),target->getPositionY());
        Rect pRect = target->getBoundingBox();
        
        if (pRect.containsPoint(locationInNode)) {
            
            return true;
        }
        
        return false;
}

void GameScene30::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){
    auto target = static_cast<Sprite* >(pEvent->getCurrentTarget());
    target->setPosition(target->getPosition()+pTouch->getDelta());
	
    Point Pos1 = convertToWorldSpace(leftHand->getPosition());
	Size size1 = leftHand->getContentSize();
    
    Rect  Rect1 = Rect(Pos1.x -size1.width/2,
                                Pos1.y -size1.height/2,
                                size1.width,
                                size1.height);

	if (bag1->getBoundingBox().intersectsRect( Rect1)) {

		//bag1->runAction(MoveTo::create(0.1f,Point(Pos1.x,Pos1.y)));
		leftTag1=3;
    }else{
		
		//bag1->runAction(MoveTo::create(0.1f,Point(bag1->getPositionX(),bag1->getPositionY())));
		leftTag1=0;
    }
	
	if (leftHand->getBoundingBox().intersectsRect(bag2->getBoundingBox())) {

		leftTag2=1;
    }else{

		leftTag2=0;
    }

	if (leftHand->getBoundingBox().intersectsRect(bag3->getBoundingBox())) {
	
		leftTag3=1;
    }else{
		
		leftTag3=0;
    }

	if (leftHand->getBoundingBox().intersectsRect(bag4->getBoundingBox())) {
	
		leftTag4=2;
    }else{
	
		leftTag4=0;
    }

	if (leftHand->getBoundingBox().intersectsRect(bag5->getBoundingBox())) {

		leftTag5=3;
    }else{
	
		leftTag5=0;
    }

	if (leftHand->getBoundingBox().intersectsRect(bag6->getBoundingBox())) {
	
		leftTag6=2;
    }else{
		
		leftTag6=0;
    }

	
	
	
	if (rightHand->getBoundingBox().intersectsRect(bag1->getBoundingBox())) {
	
		rightTag1=3;
    }else{
		
		rightTag1=0;
    }
	
	if (rightHand->getBoundingBox().intersectsRect(bag2->getBoundingBox())) {
		
		rightTag2=1;
    }else{
	
		rightTag2=0;
    }
	
	if (rightHand->getBoundingBox().intersectsRect(bag3->getBoundingBox())) {
	
		rightTag3=1;
    }else{
	
		rightTag3=0;
    }
	
	if (rightHand->getBoundingBox().intersectsRect(bag4->getBoundingBox())) {
		
		rightTag4=2;
    }else{
		
		rightTag4=0;
    }
	
	if (rightHand->getBoundingBox().intersectsRect(bag5->getBoundingBox())) {
		
		rightTag5=3;
    }else{
		
		rightTag5=0;
    }
	
	if (rightHand->getBoundingBox().intersectsRect(bag6->getBoundingBox())) {
	
		rightTag6=2;
    }else{
		
		rightTag6=0;
    }

	leftAdd=leftTag1+leftTag2+leftTag3+leftTag4+leftTag5+leftTag6;
	rightAdd=rightTag1+rightTag2+rightTag3+rightTag4+rightTag5+rightTag6;

	}


void GameScene30::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){
    log("leftAdd=%d",leftAdd);
	log("rightAdd=%d",rightAdd);
	if(leftAdd>rightAdd){
		boy->setVisible(false);
		boy2->setVisible(true);
		boy2->runAction(RotateTo::create(1.0,-10));
		
	}else if(rightAdd>leftAdd){
		boy->setVisible(false);
		boy2->setVisible(true);
	    boy2->runAction(RotateTo::create(1.0,10));
	}
	if(leftAdd==rightAdd){
		boy->setVisible(true);
		boy2->setVisible(false);
		 boy->runAction(RotateTo::create(1.0,0));
		
	}
	if(leftAdd==rightAdd&&leftAdd==6){
		boy->setVisible(true);
		boy2->setVisible(false);
		 boy->runAction(RotateTo::create(1.0,0));
		this->success();
	}
}



void GameScene30::success(){
    this->runAction(Sequence::create(
                                     DelayTime::create(1.0f),
                                     CallFunc::create([&](){
        Director::getInstance()->replaceScene(SuccessScene::createScene(level31));
        
    }),NULL));
}

void GameScene30::lose(){
    this->runAction(Sequence::create(
                                     DelayTime::create(1.0f),
                                     CallFunc::create([&](){
        Director::getInstance()->replaceScene(LoseScene::createScene(level31));
        
    }),NULL));
}

  