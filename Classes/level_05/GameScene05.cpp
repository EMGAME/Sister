//
//  GameScene05.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#include "GameScene05.h"
#include "GameScene06.h"
USING_NS_CC;

GameScene05::GameScene05(){

	flag1=flag2=flag3=flag4=flag5=flag6=flag7=flag8=flag9=flagScrew_l=flagScrew_r=flagHandle=flagPaper=flagPlate=1;
	rightDrop=leftDrop=start=1;
	flagMessage=flag=0;


}
GameScene05::~GameScene05(){
}

Scene* GameScene05::createScene()
{
	auto scene = Scene::create();

	auto layer = GameScene05::create();

	scene->addChild(layer);

	return scene;
}

bool GameScene05::init()
{
	if(!Layer::init())
	{
		return false;
	}

	origin = Director::getInstance()->getVisibleOrigin();
	visibleSize = Director::getInstance()->getVisibleSize();
	winSize = Director::getInstance()->getWinSize();

	//加载plist资源
	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("level_05/level05_common.plist","level_05/level05_common.png");

	auto listener = EventListenerTouchOneByOne::create();//创建一个触摸监听(单点触摸）  
	listener->onTouchBegan = CC_CALLBACK_2(GameScene05::onTouchBegan, this);//指定触摸的回调函数  
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);//将listener放入事件委托中  

	scheduleUpdate();
	schedule(schedule_selector(GameScene05::update),1.0f);

	m_ui = UILayer::create();
	m_ui->setPosition(Point::ZERO);
	this->addChild(m_ui,10);

	addSprite();

	return true;
} 

void GameScene05::addSprite()
{
	auto white = Sprite::create();
	white->setSpriteFrame(cache->getSpriteFrameByName("white.png"));
	white->setPosition(Point(winSize.width/2,winSize.height/2));
	this->addChild(white,-1);

	auto bg = Sprite::create();
	bg->setSpriteFrame(cache->getSpriteFrameByName("level05_bg.png"));
	bg->setPosition(Point(winSize.width/2,winSize.height/2));
	this->addChild(bg,0);

	no_1 = Sprite::create();
	no_1->setSpriteFrame(cache->getSpriteFrameByName("level05_no_1.png"));
	no_1->setAnchorPoint(Point(0,0));
	no_1->setPosition(Point(428,548));
	this->addChild(no_1,2,1);

	no_2 = Sprite::create();
	no_2->setSpriteFrame(cache->getSpriteFrameByName("level05_no_2.png"));
	no_2->setAnchorPoint(Point(0,0));
	no_2->setPosition(Point(494,548));
	this->addChild(no_2,2,2);

	no_3 = Sprite::create();
	no_3->setSpriteFrame(cache->getSpriteFrameByName("level05_no_3.png"));
	no_3->setAnchorPoint(Point(0,0));
	no_3->setPosition(Point(563,548));
	this->addChild(no_3,2,3);

	no_4 = Sprite::create();
	no_4->setSpriteFrame(cache->getSpriteFrameByName("level05_no_4.png"));
	no_4->setAnchorPoint(Point(0,0));
	no_4->setPosition(Point(428,458));
	this->addChild(no_4,2,4);

	no_5 = Sprite::create();
	no_5->setSpriteFrame(cache->getSpriteFrameByName("level05_no_5.png"));
	no_5->setAnchorPoint(Point(0,0));
	no_5->setPosition(Point(494,458));
	this->addChild(no_5,2,5);

	no_6 = Sprite::create();
	no_6->setSpriteFrame(cache->getSpriteFrameByName("level05_no_6.png"));
	no_6->setAnchorPoint(Point(0,0));
	no_6->setPosition(Point(563,458));
	this->addChild(no_6,2,6);

	no_7 = Sprite::create();
	no_7->setSpriteFrame(cache->getSpriteFrameByName("level05_no_7.png"));
	no_7->setAnchorPoint(Point(0,0));
	no_7->setPosition(Point(428,368));
	this->addChild(no_7,2,7);

	no_8 = Sprite::create();
	no_8->setSpriteFrame(cache->getSpriteFrameByName("level05_no_8.png"));
	no_8->setAnchorPoint(Point(0,0));
	no_8->setPosition(Point(494,368));
	this->addChild(no_8,2,8);

	no_9 = Sprite::create();
	no_9->setSpriteFrame(cache->getSpriteFrameByName("level05_no_9.png"));
	no_9->setAnchorPoint(Point(0,0));
	no_9->setPosition(Point(563,368));
	this->addChild(no_9,2,9);

	auto pwdbox = Sprite::create();
	pwdbox->setSpriteFrame(cache->getSpriteFrameByName("level05_pwdbox.png"));
	pwdbox->setAnchorPoint(Point(0,0));
	pwdbox->setPosition(Point(400,332));
	this->addChild(pwdbox,1);

	handle = Sprite::create();
	handle->setSpriteFrame(cache->getSpriteFrameByName("level05_handle.png"));
	handle->setAnchorPoint(Point(0,0));
	handle->setPosition(Point(122,370));
	this->addChild(handle,1,10);

	doorplate = Sprite::create();
	doorplate->setSpriteFrame(cache->getSpriteFrameByName("level05_doorplate.png"));
	doorplate->setAnchorPoint(Point(0,0));
	doorplate->setPosition(Point(100,484));
	this->addChild(doorplate,1);

	paper = Sprite::create();
	paper->setSpriteFrame(cache->getSpriteFrameByName("level05_paper.png"));
	paper->setAnchorPoint(Point(0,0));
	paper->setPosition(Point(282,36));
	this->addChild(paper,1,20);

	leftscrew = Sprite::create();
	leftscrew->setSpriteFrame(cache->getSpriteFrameByName("level05_screw.png"));
	leftscrew->setAnchorPoint(Point(0,0));
	leftscrew->setPosition(Point(158,540));
	this->addChild(leftscrew,2,11);
	screwLPos=leftscrew->getPosition();

	rightscrew = Sprite::create();
	rightscrew->setSpriteFrame(cache->getSpriteFrameByName("level05_screw.png"));
	rightscrew->setAnchorPoint(Point(0,0));
	rightscrew->setPosition(Point(260,540));
	this->addChild(rightscrew,2,12);
	screwRPos=rightscrew->getPosition();
}

void GameScene05::update(float tmd)
{
	if(flag1&&flag3&&flag4&&flag5&&flag7&&flag9&&flagScrew_r&&(flagScrew_l==0)&&(flag6==0)&&(flag8==0)&&(flag2==0)){
		if(start){
			start=0;
			scheduleOnce(schedule_selector(GameScene05::popOk),1);
		}
		if(flag){
			success = Sprite::create();
			success->setSpriteFrame(cache->getSpriteFrameByName("level05_success.png"));
			success->setPosition(Point(winSize.width/2,winSize.height/2));
			this->addChild(success,5);

			beautifulGirl = Sprite::create();
			beautifulGirl->setSpriteFrame(cache->getSpriteFrameByName("level05_beautifulGirl.png"));
			beautifulGirl->setAnchorPoint(Point(0,0));
			beautifulGirl->setPosition(Point(118,162));
			this->addChild(beautifulGirl,6);

			sayNoCallBack();

		}
	}

	if((flagScrew_l==0)&&flagScrew_r){
		if(rightDrop&&(screwLPos.y-10)>=leftscrew->getPosition().y){
			auto posX = rightscrew->getPosition().x+rightscrew->getContentSize().width/2;
			auto posY = rightscrew->getPosition().y+rightscrew->getContentSize().height/2;

			doorplate->setPosition(Point(doorplate->getPositionX()+doorplate->getContentSize().width*0.75,
				doorplate->getPositionY()+doorplate->getContentSize().height*0.5));
			doorplate->setAnchorPoint(Point(0.75,0.5));

			auto rotateBy = RotateBy::create(0.5,-90);
			doorplate->runAction(rotateBy);
			rightDrop=0;
		}
	}
	if((flagScrew_r==0)&&flagScrew_l){
		if(leftDrop&&(screwRPos.y-10)>=rightscrew->getPosition().y){
			auto posX = leftscrew->getPosition().x+leftscrew->getContentSize().width/2;
			auto posY = leftscrew->getPosition().y+leftscrew->getContentSize().height/2;
			doorplate->setPosition(Point(doorplate->getPositionX()+doorplate->getContentSize().width*0.25,
				doorplate->getPositionY()+doorplate->getContentSize().height*0.5));
			doorplate->setAnchorPoint(Point(0.25,0.5));

			auto rotateTo = RotateTo::create(1,90);
			doorplate->runAction(rotateTo);
			leftDrop=0;
		}
	}
	if((flagScrew_l==0)&&(flagScrew_r==0)){
		if((screwLPos.y-10)>=leftscrew->getPosition().y&&(screwRPos.y-10)>=rightscrew->getPosition().y&&flagPlate){
			Point endPos = Point(doorplate->getPosition().x,doorplate->getPosition().y-300);
			auto plateDrop = MoveBy::create(1.5f,Point(0,-300));
			auto fadeout = FadeOut::create(1.5f);

			auto action = Sequence::create(plateDrop,fadeout,NULL);
			doorplate->runAction(action);
			flagPlate=0;
		}
	}
}

bool GameScene05::onTouchBegan(Touch *touch, Event *unused_event)
{

	auto beginPos = touch->getLocationInView();//获得触摸位置  
	beginPos = Director::getInstance()->convertToGL(beginPos);//坐标转换  

	if(flag1)
	{
		rect1 = getRect(no_1);
		if(rect1.containsPoint(beginPos)){
			change(no_1);
		}else
			;
	}
	if(flag2)
	{
		rect2 = getRect(no_2);
		if(rect2.containsPoint(beginPos)){
			change(no_2);
		}else
			;
	}
	if(flag3)
	{
		rect3 = getRect(no_3);
		if(rect3.containsPoint(beginPos)){
			change(no_3);
		}else
			;
	}
	if(flag4)
	{
		rect4 = getRect(no_4);
		if(rect4.containsPoint(beginPos)){
			change(no_4);
		}else
			;
	}
	if(flag5)
	{
		rect5 = getRect(no_5);
		if(rect5.containsPoint(beginPos)){
			change(no_5);
		}else
			;
	}
	if(flag6)
	{
		rect6 = getRect(no_6);
		if(rect6.containsPoint(beginPos)){
			change(no_6);
		}else
			;
	}
	if(flag7)
	{
		rect7= getRect(no_7);
		if(rect7.containsPoint(beginPos)){
			change(no_7);
		}else
			;
	}
	if(flag8)
	{
		rect8 = getRect(no_8);
		if(rect8.containsPoint(beginPos)){
			change(no_8);
		}else
			;
	}
	if(flag9)
	{
		rect9 = getRect(no_9);
		if(rect9.containsPoint(beginPos)){
			change(no_9);
		}else
			;
	}
	if(flagScrew_r)
	{
		rightScrewRect = getRect(rightscrew);
		if(rightScrewRect.containsPoint(beginPos)){
			change(rightscrew);
		}else
			;
	}
	if(flagScrew_l)
	{
		leftScrewRect = getRect(leftscrew);
		if(leftScrewRect.containsPoint(beginPos)){
			change(leftscrew);
		}else
			;
	}
	if(flagPaper)
	{
		paperRect = getRect(paper);
		if(paperRect.containsPoint(beginPos)){
			change(paper);
		}else
			;
	}
	if(flagMessage)
	{
		messageRect = Rect(message->getPosition().x - message->getContentSize().width/2,message->getPosition().y 
			- message->getContentSize().height/2,message->getContentSize().width,message->getContentSize().height);
		if(messageRect.containsPoint(beginPos)){
			change(message);
		}else
			;
	}
	if(flagHandle)
	{
		handleRect = getRect(handle);
		if(handleRect.containsPoint(beginPos)){
			change(handle);
		}else
			;
	}

	return true;
}

Rect GameScene05::getRect(Sprite* sprite)
{
	auto Pos = sprite->getPosition();
	auto Size = sprite->getContentSize();
	Rect rect = Rect(Pos.x ,Pos.y ,Size.width ,Size.height);

	return rect;
}

void GameScene05::change(Sprite* sprite)
{
	Point pos = sprite->getPosition();
	int tag = sprite->getTag();

	if(tag>=1&&tag<=9){
		this->removeChild(sprite);
		switch (tag)
		{
		case 1:
			//		new_1 = Sprite::create("level_05/level05_new_1.png");
			//			
			//		new_1->setAnchorPoint(Point(0,0));
			//		new_1->setPosition(pos);
			//		this->addChild(new_1,2);
			flag1 = 0;
			break;
		case 2:
			//		new_2 = Sprite::create("level_05/level05_new_2.png");
			//		new_2->setAnchorPoint(Point(0,0));
			//		new_2->setPosition(pos);
			//		this->addChild(new_2,2);
			flag2=0;
			break;
		case 3:
			//		new_3 = Sprite::create("level_05/level05_new_3.png");
			//		new_3->setAnchorPoint(Point(0,0));
			//		new_3->setPosition(pos);
			//		this->addChild(new_3,2);
			flag3=0;
			break;
		case 4:
			//		new_4 = Sprite::create("level_05/level05_new_4.png");
			//		new_4->setAnchorPoint(Point(0,0));
			//		new_4->setPosition(pos);
			//		this->addChild(new_4,2);
			flag4=0;
			break;
		case 5:
			//		new_5 = Sprite::create("level_05/level05_new_5.png");
			//		new_5->setAnchorPoint(Point(0,0));
			//		new_5->setPosition(pos);
			//		this->addChild(new_5,2);
			flag5=0;
			break;
		case 6:
			//		new_6 = Sprite::create("level_05/level05_new_6.png");
			//		new_6->setAnchorPoint(Point(0,0));
			//		new_6->setPosition(pos);
			//		this->addChild(new_6,2);
			flag6=0;
			break;
		case 7:
			//		new_7 = Sprite::create("level_05/level05_new_7.png");
			//		new_7->setAnchorPoint(Point(0,0));
			//		new_7->setPosition(pos);
			//		this->addChild(new_7,2);
			flag7=0;
			break;
		case 8:
			//		new_8 = Sprite::create("level_05/level05_new_8.png");
			//		new_8->setAnchorPoint(Point(0,0));
			//		new_8->setPosition(pos);
			//		this->addChild(new_8,2);
			flag8=0;
			break;
		case 9:
			//		new_9 = Sprite::create("level_05/level05_new_9.png");
			//		new_9->setAnchorPoint(Point(0,0));
			//		new_9->setPosition(pos);
			//		this->addChild(new_9,2);
			flag9=0;
			break;
		}
	}else{
		if(tag==10)
		{
			auto handleDrop = MoveBy::create(1.5f,Point(0,-300));
			auto fadeout = FadeOut::create(1); 
			auto action = Sequence::create(handleDrop,fadeout,NULL);

			sprite->runAction(action);
			flagHandle=0;
		}
		if(tag==11){
			auto rotateto = CCRotateTo::create(1, 270);
			auto screwDrop = MoveBy::create(1.5f,Point(0,-300));
			auto fadeout = FadeOut::create(1.5f);
			leftscrew->setPosition(Point(leftscrew->getPositionX()+leftscrew->getContentSize().width*0.5,
				leftscrew->getPositionY()+leftscrew->getContentSize().height*0.5));
			leftscrew->setAnchorPoint(Point(0.5,0.5));

			auto action = Sequence::create(rotateto,screwDrop,fadeout,NULL);
			sprite->runAction(action);
			flagScrew_l=0;
		}
		if(tag==12){
			auto rotateto = CCRotateTo::create(1,270);
			auto screwDrop = MoveBy::create(1.5f,Point(0,-300));
			auto fadeout = FadeOut::create(1.5f);
			rightscrew->setPosition(Point(rightscrew->getPositionX()+rightscrew->getContentSize().width*0.5,
				rightscrew->getPositionY()+rightscrew->getContentSize().height*0.5));
			rightscrew->setAnchorPoint(Point(0.5,0.5));

			auto action = Sequence::create(rotateto,screwDrop,fadeout,NULL);
			sprite->runAction(action);
			flagScrew_r=0;
		}
		if(tag==20){
			message = Sprite::create();
			message->setSpriteFrame(cache->getSpriteFrameByName("level05_message.png"));
			message->setPosition(Point(640/2,960/2));
			this->addChild(message,4,21);

			flagMessage=1;
			flagPaper=0;
		}
		if(tag==21){
			this->removeChild(message);

			flagMessage=0;
			flagPaper=1;
		}
	}
}

void GameScene05::removeSprite(Sprite* sprite){
	this->removeChild(sprite);
}

void GameScene05::setFlag(float tmd){

	flag=1;
}

void GameScene05::popOk(float tmd){
	ok = Sprite::create();
	ok->setSpriteFrame(cache->getSpriteFrameByName("level05_ok.png"));
	ok->setAnchorPoint(Point(0,0));
	ok->setPosition(Point(242,314));

	this->addChild(ok);
	auto scaleto = CCScaleTo ::create(1.5f, 2);
	ok->runAction(scaleto);

	scheduleOnce(schedule_selector(GameScene05::setFlag),1.5f);
}

void GameScene05::sayThanksCallBack(){
	m_ui->Lose("foolish man!");
}

void GameScene05::sayNoCallBack(){
	m_ui->Success("You success!", 3);
}

void GameScene05::restart(){
	Director::getInstance()->replaceScene(GameScene05::createScene());
	Director::getInstance()->resume();
}

void GameScene05::nextLevel(){
    Director::getInstance()->replaceScene(GameScene06::createScene());
}