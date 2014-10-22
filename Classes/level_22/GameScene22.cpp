#include "GameScene22.h"
#include "SimpleAudioEngine.h"
#include "../UILayer/PowerManager.h"

#define FIX_POS(_pos, _min, _max) \
if (_pos < _min)        \
_pos = _min;        \
else if (_pos > _max)   \
_pos = _max;        \

using namespace CocosDenshion;
USING_NS_CC;

Scene* GameScene22::createScene()
{
  
    auto scene = Scene::create();
    
    
    auto layer = GameScene22::create();

   
    scene->addChild(layer);

   
    return scene;
}


bool GameScene22::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    
    //PowerManager::getInstance()->initWithNumber(4);

    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
	auto size = Director::getInstance()->getWinSize();  
	
    m_ui = UISimple::create();
    this->addChild(m_ui,30);
    
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("level_22/scene2.mp3", true);

	 //¼ÓÔØ³õÊ¼ÎÄ×Ö
    boss = Sprite::create("level_22/test_ting.png");
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

    auto bg=Sprite::create("level_22/bg3.png");
	bg->setPosition(Point(size.width/2,size.height/2));
	this->addChild(bg,1);

    ball = Sprite:: create("level_22/ball.png");
	ball->setPosition(Point(189, 988));
	addChild(ball,10,ballTag);

	hole=Sprite::create("level_22/hole.png");
	hole->setPosition(Point(599,192));
	addChild(hole,2);
    return true;
}

void GameScene22::onEnter() {
	Layer::onEnter();
	log("HelloWorldEnter");
	setAccelerometerEnabled(true);
}

void  GameScene22::onAcceleration(Acceleration* acc, Event* unused) {
    
    auto pDir = Director::getInstance();
    
    /*FIXME: Testing on the Nexus S sometimes _ball is NULL */
    if ( ball == NULL ) {
        return;
    }
    
    auto ballSize  = ball->getContentSize();
    
    auto ptNow  = ball->getPosition();
    auto ptTemp = pDir->convertToUI(ptNow);
    
    ptTemp.x += acc->x * 9.81f;
    ptTemp.y -= acc->y * 9.81f;
    
    auto ptNext = pDir->convertToGL(ptTemp);
    FIX_POS(ptNext.x, (VisibleRect::left().x+ballSize.width / 2.0), (VisibleRect::right().x - ballSize.width / 2.0));
    FIX_POS(ptNext.y, (VisibleRect::bottom().y+ballSize.height / 2.0), (VisibleRect::top().y - ballSize.height / 2.0));
    
    ball->setPosition(ptNext);
       
    if(hole->getBoundingBox().intersectsRect(ball->getBoundingBox()))
	{
		ball->setVisible(false);
		this->success();
	}
}

void GameScene22::onExit() {
	Layer::onExit();
	log("HelloWorldExit");
}

void GameScene22::success(){
    this->runAction(Sequence::create(
                                     DelayTime::create(1.0f),
                                     CallFunc::create([&](){
        Director::getInstance()->replaceScene(SuccessScene::createScene(level23));
        
    }),NULL));
}

void GameScene22::lose(){
    this->runAction(Sequence::create(
                                     DelayTime::create(1.0f),
                                     CallFunc::create([&](){
        Director::getInstance()->replaceScene(LoseScene::createScene(level23));
        
    }),NULL));
}