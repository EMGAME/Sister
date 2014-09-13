//
//  GameScene04.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#include "GameScene04.h"
#include "GameScene05.h"
USING_NS_CC;

GameScene04::GameScene04(){
	dreFlag = 1;
	roseFlag = 2;
	dreFlag = 3;
	choFlag = 4;
	cocoFlag = 5;
	sorryFlag=1;
	is_successful=0;

}
GameScene04::~GameScene04(){

}
Scene* GameScene04::createScene()
{
	auto scene = Scene ::create();
	auto layer = GameScene04::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene04::init()
{
	if(!Layer::init())
	{
		return false;
	}
	scheduleUpdate();
	schedule(schedule_selector(GameScene04::update),1.0f);

	visibleSize = Director::getInstance()->getVisibleSize();
	winSize = Director::getInstance()->getWinSize();
	origin = Point(0,0);

	m_ui = UILayer::create();
	m_ui->setPosition(Point::ZERO);
	this->addChild(m_ui,10);

	auto listener = EventListenerTouchOneByOne::create();//创建一个触摸监听(单点触摸）  
	listener->onTouchBegan = CC_CALLBACK_2(GameScene04::onTouchBegan, this);//指定触摸的回调函数  
	listener->onTouchMoved = CC_CALLBACK_2(GameScene04::onTouchesMoved,this);
	listener->onTouchEnded = CC_CALLBACK_2(GameScene04::onTouchEnded,this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);//将listener放入事件委托中  

	//加载plist资源
	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("level_04/level04_common.plist","level_04/level04_common.png");

	// 钻戒
	diamondItem = Sprite::create();
	diamondItem->setSpriteFrame(cache->getSpriteFrameByName("level04_diamond.png"));
	diamondItem->setAnchorPoint(Point(0,0));
	diamondItem->setPosition(Point(130,80));
	this->addChild(diamondItem,2);

	// 连衣裙
	dressItem = Sprite::create();
	dressItem->setSpriteFrame(cache->getSpriteFrameByName("level04_dress.png"));
	dressItem->setAnchorPoint(Point(0,0));
	dressItem->setPosition(Point(250,90));
	this->addChild(dressItem,2);

	// 玫瑰花
	roseItem = Sprite::create();
	roseItem->setSpriteFrame(cache->getSpriteFrameByName("level04_rose.png"));
	roseItem->setAnchorPoint(Point(0,0));
	roseItem->setPosition(Point(481,90));
	this->addChild(roseItem,2);

	// 巧克力
	chocolateItem = Sprite::create();
	chocolateItem->setSpriteFrame(cache->getSpriteFrameByName("level04_cho.png"));
	chocolateItem->setAnchorPoint(Point(0,0));
	chocolateItem->setPosition(Point(616,80));
	this->addChild(chocolateItem,2);

	// 跪地认错
	sorryItem = Sprite::create();
	sorryItem->setSpriteFrame(cache->getSpriteFrameByName("level04_orz.png"));
	sorryItem->setAnchorPoint(Point(0,0));
	sorryItem->setPosition(Point(359,100));
	this->addChild(sorryItem,2);

	//椰果
	coconutItem = Sprite::create();
	coconutItem->setSpriteFrame(cache->getSpriteFrameByName("level04_coconut.png"));
	coconutItem->setAnchorPoint(Point(0,0));
	coconutItem->setPosition(Point(630,950));
	this->addChild(coconutItem,2);

	// 美女
	goodGirl = Sprite::create();
	goodGirl->setSpriteFrame(cache->getSpriteFrameByName("level04_mm_nor.png"));
	goodGirl->setAnchorPoint(Point(0,0));
	goodGirl->setPosition(Point(150,252));
	this->addChild(goodGirl,1);

	// sadGirl
	auto pos = goodGirl->getPosition();
	sadGirl = Sprite::create();
	sadGirl->setSpriteFrame(cache->getSpriteFrameByName("level04_sadGirl.png"));
	sadGirl->setAnchorPoint(Point(0,0));
	sadGirl->setPosition(pos);
	this->addChild(sadGirl);
	sadGirl->setVisible(false);

	//椅子
	auto bench =Sprite::create();
	bench->setSpriteFrame(cache->getSpriteFrameByName("level04_bench.png"));
	bench->setAnchorPoint(Point(0,0));
	bench->setPosition(Point(10,296));
	this->addChild(bench,2);

	// 海鸥
	auto mew = Sprite::create();
	mew->setSpriteFrame(cache->getSpriteFrameByName("level04_mew.png"));
	mew->setAnchorPoint(Point(0,0));
	mew->setPosition(Point(62,1050));
	this->addChild(mew,1);

	// 椰子树
	auto tree = Sprite::create();
	tree->setSpriteFrame(cache->getSpriteFrameByName("level04_tree.png"));
	tree->setAnchorPoint(Point(0,0));
	tree->setPosition(Point(372,354));
	this->addChild(tree,2);

	// 搓衣板
	washboard = Sprite::create();
	washboard->setSpriteFrame(cache->getSpriteFrameByName("level04_washboard.png"));
	washboard->setAnchorPoint(Point(0,0));
	washboard->setPosition(Point(512,480));
	this->addChild(washboard,1);

	//美女接收礼物的位置
	goodGirlPos = goodGirl->getPosition();
	auto goodGirlSize = goodGirl->getContentSize();
	goodGirlPos = Point(goodGirlPos.x + goodGirlSize.width/3, goodGirlPos.y + goodGirlSize.height/5*2);

	auto white = Sprite::create();
	white->setSpriteFrame(cache->getSpriteFrameByName("white.png"));
	white->setPosition(Point(winSize.width/2,winSize.height/2));
	this->addChild(white,-1);

	auto bg = Sprite::create();
	bg->setSpriteFrame(cache->getSpriteFrameByName("level04_bg.png"));
	bg->setPosition(Point(winSize.width/2,winSize.height/2));
	this->addChild(bg,0);

	return true;
}


bool GameScene04::onTouchBegan(Touch* touch, Event *event)  
{  
	auto beginPos = touch->getLocationInView();//获得触摸位置  
	beginPos = Director::getInstance()->convertToGL(beginPos);//坐标转换  

	if(diaFlag)
	{
		diamondRect = getRect(diamondItem);
		if(diamondRect.containsPoint(beginPos)){
			moveToGirl(diamondItem,diaFlag);
			CCLog("I want to give myGF diamond!");
		}else
			;
	}
	if(dreFlag)
	{
		dressRect = getRect(dressItem);
		if(dressRect.containsPoint(beginPos))
		{
			moveToGirl(dressItem,dreFlag);
		}else
			;
	}
	if (roseFlag)
	{
		roseRect = getRect(roseItem);
		if(roseRect.containsPoint(beginPos))
		{
			moveToGirl(roseItem,roseFlag);
		}else
			;
	}
	if(choFlag){
		chocolateRect = getRect(chocolateItem);
		if(chocolateRect.containsPoint(beginPos))
		{
			moveToGirl(chocolateItem,choFlag);
		}else
			;
	}
	if(cocoFlag){
		cocoRect = getRect(coconutItem);
		if(cocoRect.containsPoint(beginPos))
		{
			cocoDrop(coconutItem);
		}else
			;
	}

	return true;
}   

void GameScene04::onTouchesMoved(Touch* touch,Event* event){

	auto beginPos = touch->getLocationInView();//获得触摸位置  
	beginPos = Director::getInstance()->convertToGL(beginPos);//坐标转换  


	if(washboardFlag){
		washboardRect = getRect(washboard);
		if(washboardRect.containsPoint(beginPos)){
			auto washboardPos = washboard->getPosition();
			auto washboardSize= washboard->getContentSize();

			auto endPos = touch->getPreviousLocationInView();//获取触摸的前一个位置  
			endPos = Director::sharedDirector()->convertToGL(endPos);//转换坐标  

			auto offset = Point(beginPos-endPos); 
			auto nextPos = Point(washboardPos + offset);
			washboard->setPosition(nextPos);    
		}
	}
	if(sorryFlag){
		sorryRect = getRect(sorryItem);
		if (sorryRect.containsPoint(beginPos))
		{
			//分享后得提示
		}
	}
}

void GameScene04::onTouchEnded(Touch* touch, Event  *event)  
{  
	auto lastPos = touch->getLocationInView();  
	lastPos = Director::getInstance()->convertToGL(lastPos);  

	if(washboardFlag){

		if(washboardRect.containsPoint(goodGirlPos)){
			auto pos = goodGirl->getPosition();
			auto happyGirl = Sprite::create();
			happyGirl->setSpriteFrame(cache->getSpriteFrameByName("level04_happyGirl.png"));
			happyGirl->setAnchorPoint(Point(0,0));
			happyGirl->setPosition(pos);
			this->removeChild(goodGirl); 
			this->addChild(happyGirl);

			is_successful=1;

			sayNoCallBack();
			washboardFlag=0;
		}
	}

}  

void GameScene04::moveToGirl(Sprite* sprite,int &flag)
{
	MoveTo* toGirl = MoveTo::create(0.5f,goodGirlPos); 
	sprite->runAction(toGirl);
}

// 实现更新
void GameScene04::update(float tmd)
{
	if(is_successful){
		dreFlag = 0;
		roseFlag = 0;
		dreFlag = 0;
		choFlag = 0;
		sorryFlag=0;
	}
	if(diaFlag){
		diamondRect = getRect(diamondItem);
		if(diamondRect.containsPoint(goodGirlPos))
		{
			this->removeChild(diamondItem);

			goodGirl->setVisible(false);
			sadGirl->setVisible(true);

			scheduleOnce(schedule_selector(GameScene04::changeGirl),1);

			diaFlag = 0;
			//应该还有扣金币之类的接口

			// 这里加一个用手抓收礼物的动画
		}
		else
			;
	}
	if(dreFlag){
		dressRect = getRect(dressItem);
		if(dressRect.containsPoint(goodGirlPos))
		{
			this->removeChild(dressItem);

			goodGirl->setVisible(false);
			sadGirl->setVisible(true);

			scheduleOnce(schedule_selector(GameScene04::changeGirl),1);

			dreFlag = 0;
		}
		else
			;
	}
	if(roseFlag){
		roseRect = getRect(roseItem);
		if(roseRect.containsPoint(goodGirlPos))
		{
			this->removeChild(roseItem);

			goodGirl->setVisible(false);
			sadGirl->setVisible(true);

			scheduleOnce(schedule_selector(GameScene04::changeGirl),1);
			roseFlag = 0;
		}
		else
			;
	}
	if(choFlag){
		chocolateRect = getRect(chocolateItem);
		if(chocolateRect.containsPoint(goodGirlPos))
		{
			this->removeChild(chocolateItem);

			goodGirl->setVisible(false);
			sadGirl->setVisible(true);

			scheduleOnce(schedule_selector(GameScene04::changeGirl),1);
			choFlag = 0;
		}
		else
			;
	}
}

void GameScene04::cocoDrop(Sprite* sprite)
{
	MoveBy* cocoBy = MoveBy::create(1.5f,Point(0,-650));
	sprite->runAction(cocoBy);

	scheduleOnce(schedule_selector(GameScene04::addRuinCoco),1.5f);
}

Rect GameScene04::getRect(Sprite* sprite)
{
	auto Pos = sprite->getPosition();
	auto Size = sprite->getContentSize();
	Rect rect = Rect(Pos.x ,Pos.y ,Size.width ,Size.height);

	return rect;
}

void GameScene04::addRuinCoco(float tmd){
	//清除椰子  加载椰子摔碎的图片
	endPos=coconutItem->getPosition();
	this->removeChild(coconutItem);
	cocoFlag=0;
	Sprite* cocoRuin = Sprite::create();
	cocoRuin->setSpriteFrame(cache->getSpriteFrameByName("level04_ruincoco.png"));
	cocoRuin->setAnchorPoint(Point(0,0));
	cocoRuin->setPosition(endPos);
	this->addChild(cocoRuin,3);
}

void GameScene04::changeGirl(float tmd){

	goodGirl->setVisible(true);
	sadGirl->setVisible(false);
}

void GameScene04::restart(){
	Director::getInstance()->replaceScene(GameScene04::createScene());
	Director::getInstance()->resume();
}

void GameScene04::sayThanksCallBack(){
	m_ui->Lose("foolish man!");
}

void GameScene04::sayNoCallBack(){
	m_ui->Success("You success!", 3);
}

void GameScene04::nextLevel(){
    Director::getInstance()->replaceScene(GameScene05::createScene());
}