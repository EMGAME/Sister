#include "GameScene28.h"

USING_NS_CC;

GameScene28::GameScene28(){
	isAttack1=isAttack3=1;
	time=5.0;
}
GameScene28::~GameScene28(){
}

Scene* GameScene28::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene28::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene28::init(){
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
	boss = Sprite::create("new/text_duo.png");
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
    
	auto bg = Sprite::create("new/bg28.png");
	bg->setPosition(768/2,1136/2);
	this->addChild(bg,0);
    
	fish = CCSprite::create("new/fish.png");
	fish->setPosition(400,60);
	this->addChild(fish,2);
    
	fishMM = Sprite::create("new/fishMM.png");
	fishMM->setPosition(400,1030);
	fishMM->setRotation(180);
	this->addChild(fishMM,1);
    
	shark1 = Sprite::create("new/shark1.png");
	shark1->setScale(0.7);
	shark1->setPosition(-shark1->getContentSize().width/2,330);
	this->addChild(shark1,2);
    
	shark1_clo = Sprite::create("new/shark1_clo.png");
	shark1_clo->setScale(0.6);
	shark1_clo->setPosition(-shark1->getContentSize().width/2,317);
	shark1_clo->setVisible(false);
	this->addChild(shark1_clo,2);
    
	shark3 = Sprite::create("new/shark3.png");
	shark3->setScale(0.7);
	shark3->setPosition(-shark3->getContentSize().width/2,650);
	this->addChild(shark3,2);
    
	shark3_clo = Sprite::create("new/shark3_clo.png");
	shark3_clo->setScale(0.6);
	shark3_clo->setPosition(-shark3->getContentSize().width/2,637);
	shark3_clo->setVisible(false);
	this->addChild(shark3_clo,2);
    
	scheduleUpdate();
	schedule(schedule_selector(GameScene28::update),1.0f);
    
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GameScene28::onTouchBegan, this);//指定触摸的回调函数
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);//将listener放入事件委托中
    
	return true;
}

void GameScene28::update(float tmd){
	if(isAttack1){
		scheduleOnce(schedule_selector(GameScene28::shark1Attack),1.0f);
	}
	if (isAttack3)
	{
		scheduleOnce(schedule_selector(GameScene28::shark3Attack),2.5f);
	}
	if(fish->getBoundingBox().intersectsRect(shark1_clo->getBoundingBox())||
	   fish->getBoundingBox().intersectsRect(shark3_clo->getBoundingBox())){
        // log("failure");
		lose();
	}else if(fish->getBoundingBox().containsPoint(fishMM->getPosition()-Point(0,fishMM->getContentSize().width/3))){
		//log("success");
		success();
	}
	time-=0.013;
	if ((time)<=0)
	{
		log("%f",time);
		lose();
	}
}

void GameScene28::shark1Attack(float tmd){
	auto attack = MoveBy::create(2.5f,Point(800+shark1->getContentSize().width,0));
	auto convert = FlipX::create(0.1f);
	auto attack1 = MoveBy::create(2.5f,Point(-(800+shark1->getContentSize().width),0));
	actionAttack = Sequence::create(attack,convert,attack1,NULL);
	shark1->runAction(actionAttack);
	shark1_clo->runAction(actionAttack->clone());
	isAttack1=0;
}
void GameScene28::shark3Attack(float tmd){
	auto attack = MoveBy::create(2,Point(800+shark1->getContentSize().width,0));
	auto convert = FlipX::create(0.1f);
	auto attack1 = MoveBy::create(1.5f,Point(-(800+shark1->getContentSize().width),0));
	auto actionAttack = Sequence::create(attack,convert,attack1,NULL);
	shark3->runAction(actionAttack);
	shark3_clo->runAction(actionAttack->clone());
	isAttack3=0;
}

bool GameScene28::onTouchBegan(Touch *touch, Event *unused_event){
	Home();
	return true;
}


void GameScene28::Home(){
	auto movehome = MoveBy::create(0.1f,Point(0,30));
	fish->runAction(movehome);
}

void GameScene28::restart(){
	Director::getInstance()->replaceScene(GameScene28::createScene());
	Director::getInstance()->resume();
}

void GameScene28::lose(){
    Director::getInstance()->replaceScene(LoseScene::createScene(level30));

}
void GameScene28::success(){
    Director::getInstance()->replaceScene(SuccessScene::createScene(level30));
}
