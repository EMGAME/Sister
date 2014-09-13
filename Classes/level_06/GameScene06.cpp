//
//  GameScene06.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//
#include "GameScene06.h"
#include "level_09.h"

USING_NS_CC;

GameScene06::GameScene06(){
	isCatch = 0;// 表示toy2没有被逮住
}
GameScene06::~GameScene06(){}

Scene* GameScene06::createScene(){
	auto scene = Scene::create();
	auto layer = GameScene06::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene06::init(){
	if(!Layer::init()){
		return false;
	}
	visibleSize = Director::getInstance()->getVisibleSize();
	winSize = Director::getInstance()->getWinSize();
	
	//加载plist资源
	/*cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("");*/
	//　UI层
	m_ui = UILayer::create();
	m_ui->setPosition(Point::ZERO);
	this->addChild(m_ui,10);
	// 加载精灵
	addSprite();
	// 开启更新
	scheduleUpdate();
	schedule(schedule_selector(GameScene06::update),1.0f);

	auto listener = EventListenerTouchOneByOne::create();//创建一个触摸监听(单点触摸）  
	listener->onTouchBegan = CC_CALLBACK_2(GameScene06::onTouchBegan, this);//指定触摸的回调函数  
	listener->onTouchMoved = CC_CALLBACK_2(GameScene06::onTouchesMoved,this);
	listener->onTouchEnded = CC_CALLBACK_2(GameScene06::onTouchEnded,this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);//将listener放入事件委托中  

	// 左按钮
	pressL = MenuItemImage::create("level_06/pressL.png","level_06/pressL.png");
	//pressL->setNormalSpriteFrame(cache->getSpriteFrameByName("pressL.png"));
	pressL->setScale(2);
	pressL->setCallback(CC_CALLBACK_1(GameScene06::isEnableL, this));
	pressL->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	pressL->setPosition(Point(100,200));

	// 右按钮
	pressR = MenuItemImage::create("level_06/pressR.png","level_06/pressR.png");
	//pressR->setNormalSpriteFrame(cache->getSpriteFrameByName("pressR.png"));
	pressR->setScale(2);
	pressR->setCallback(CC_CALLBACK_1(GameScene06::isEnableR, this));
	pressR->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	pressR->setPosition(Point(400,200));

	auto pMenu = Menu::create(pressR,pressL,NULL);
	pMenu->setPosition(Point(0,0));
	this->addChild(pMenu,4);

	return true;
}

void GameScene06::addSprite(){
	toy1 = Sprite::create("level_06/toy1.png");
	//toy1->setSpriteFrame(cache->getSpriteFrameByName(""));
	toy1->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	toy1->setPosition(Point(0,400));
	this->addChild(toy1,2);

	toy2 = Sprite::create("level_06/toy2.png");
	//toy2->setSpriteFrame(cache->getSpriteFrameByName(""));
	toy2->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	toy2->setPosition(Point(0,700));
	this->addChild(toy2,2);

	net = Sprite::create("level_06/net.png");
	net->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	net->setPosition(Point(100,600));
	this->addChild(net,2);
}

void GameScene06::update(float tmd){

	auto toy1PX = toy1->getPosition().x + toy1->getContentSize().width;
	auto toy2PX = toy2->getPosition().x + toy2->getContentSize().width;
	if(isCatch==0&&toy1PX<=winSize.width){
		auto toy1_move = MoveBy::create(1.0f,Point(2,0));
		toy1->runAction(toy1_move);
	}
	// 成功判断
	if (toy2PX>=winSize.width&&toy2PX>toy1PX)
	{
		sayNoCallBack();
	}else if(toy1PX>=winSize.width&&toy1PX>toy2PX)
	{
		sayThanksCallBack();
	}
}

bool GameScene06::onTouchBegan(Touch *touch, Event *event){
	auto beginPos = touch->getLocationInView();//获得触摸的位置
	beginPos = Director::getInstance()->convertToGL(beginPos);// 位置转换
	return true;
}
void GameScene06::onTouchesMoved(Touch* touch,Event* event){
	auto beginPos = touch->getLocationInView();//获得触摸的位置
	beginPos = Director::getInstance()->convertToGL(beginPos);// 位置转换

	netRect = getRect(net);
	if (netRect.containsPoint(beginPos))
	{
		auto netPos = net->getPosition();
		auto netSize= net->getContentSize();

		auto endPos = touch->getPreviousLocationInView();//获取触摸的前一个位置  
		endPos = Director::sharedDirector()->convertToGL(endPos);//转换坐标  

		auto offset = Point(beginPos-endPos); 
		auto nextPos = Point(netPos + offset);
		net->setPosition(nextPos);    
	}
}
void GameScene06::onTouchEnded(Touch* touch, Event  *event)  
{  
	auto lastPos = touch->getLocationInView();  
	lastPos = Director::getInstance()->convertToGL(lastPos); 
	auto toy1Pos = toy1->getPosition() + Point(toy1->getContentSize().width/2,toy1->getContentSize().height/2);
	if(netRect.containsPoint(toy1Pos)){
		isCatch = 1;
	}else{
		isCatch = 0;
	}
}  

Rect GameScene06::getRect(Sprite* sprite)
{
	auto pos = sprite->getPosition();
	auto size = sprite->getContentSize();
	Rect rect = Rect(pos.x ,pos.y ,size.width ,size.height);
	return rect;
}
void GameScene06::isEnableL(Ref* pSender){
	auto toy2PX = toy2->getPosition().x + toy2->getContentSize().width;
	if(toy2PX<=winSize.width){
		pressL->setEnabled(false);
		pressR->setEnabled(true);
		auto move = MoveBy::create(0.1f,Point(10,0));
		toy2->runAction(move);
	}
}
void GameScene06::isEnableR(Ref* pSender){
	auto toy2PX = toy2->getPosition().x + toy2->getContentSize().width;
	if(toy2PX<=winSize.width){
		pressR->setEnabled(false);
		pressL->setEnabled(true);
		auto move = MoveBy::create(0.1f,Point(10,0));
		toy2->runAction(move);
	}
}

void GameScene06::sayThanksCallBack(){
	m_ui->Lose("Foolish man!");
}

void GameScene06::sayNoCallBack(){
	m_ui->Success("You success", 3);
}
void GameScene06::restart(){
	Director::getInstance()->replaceScene(GameScene06::createScene());
	Director::getInstance()->resume();
}

void GameScene06::nextLevel(){
    Director::getInstance()->replaceScene(Level09::createScene());
}