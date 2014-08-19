#include "GameScene12.h"
#include "../UILayer/UILayer.h"

USING_NS_CC;

Scene* GameScene12::createScene(){

	auto scene = Scene::create();

	auto backgroundLayer = Bglayer::create();
	scene->addChild(backgroundLayer,0);

	auto layer = GameScene12::create();

	scene->addChild(layer,0,100);
    
	layer->bglayer = backgroundLayer;

	return scene;
}

bool GameScene12::init(){

	if (!Scene::create())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//Ö÷½Ç
	girl_nor = Girl::create();
	this->addChild(girl_nor,3,5);

	movenum = 0;
	numOfM1 = 0;
	numOfM2 = 0;
	numOfM3 = 0;
	allstop = 0;
	abc = 0;
    state = 1;

	//Ìí¼ÓÊÖÁ´
	hand = Sprite::create("handline.png");
	hand->setPosition(Point(visibleSize.width * 0.5f , visibleSize.height * 0.5f));
	hand->setVisible(false);
	this->addChild(hand);


	//²Ëµ¶
	/*auto m1 = Sprite::create("m1.png");
	m1->setPosition(Point(visibleSize.width * 0.5f , visibleSize.height * 0.85f));
	this->addChild(m1);

	auto moveBy1 = MoveBy::create(2.0f, Point(0, -300));
	m1->runAction(moveBy1);*/

    //Ã¡Âî
	/*auto m2 = Sprite::create("m2.png");
	m2->setPosition(Point(visibleSize.width * 0.5f , visibleSize.height * 0.7f));
	this->addChild(m2);

	auto moveBy2 = MoveBy::create(2.0f, Point(0, -300));
	m2->runAction(moveBy2);*/

	//×Óµ¯
	/*auto m3 = Sprite::create("m3.png");
	m3->setPosition(Point(visibleSize.width * 0.5f , visibleSize.height * 0.5f));
	this->addChild(m3);

	auto moveBy3 = MoveBy::create(2.0f, Point(0, -200));
	m3->runAction(moveBy3);*/

	//µã»÷¾«Áé±ä»»¹¦ÄÜ
	auto button = MenuItemImage::create("play_nor.png",
		                              "play_pre.png",
		                             CC_CALLBACK_0(GameScene12::carry,this));
	button->setPosition(visibleSize.width *0.85f,visibleSize.height * 0.2f);

	auto button1 = Menu::create(button, NULL);
	button1->setPosition(Point::ZERO);
	this->addChild(button1, 2);

	//²âÊÔ111111111111
	/*auto aaaaaaa = Sprite::create("RedBall.png");
	aaaaaaa->setPosition(visibleSize.width *0.2f,visibleSize.height * 0.2f);
	this->addChild(aaaaaaa);

	auto movetest = MoveBy::create(1.0f, Point(90, 0));
	auto pp = (Point(visibleSize.width *0.2f,visibleSize.height * 0.2f));
	auto s = Sequence::create(movetest,pp,movetest->clone(),pp,movetest->clone());
	aaaaaaa->runAction(s);*/

	//´¥Ãþ¼àÌý
	auto listener = EventListenerTouchOneByOne::create();

	//listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(GameScene12::onTouchBegan,this);
	

	listener->onTouchEnded = CC_CALLBACK_2(GameScene12::onTouchEnded,this);
	
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//Í³Ò»Âß¼­¿ØÖÆ
	this->schedule(schedule_selector(GameScene12::logic));
	this->schedule(schedule_selector(GameScene12::reset),1,10000,2);

	//²Ëµ¶²»¶ÏµÄµôÂä
	this->schedule(schedule_selector(GameScene12::refresh),1.5,1000,3);
	this->schedule(schedule_selector(GameScene12::del),1.5,1000,4);

	if (numOfM1 ==3)
	{
		state = 2;
	}
	if (numOfM2 ==3)
	{
		state = 3;
	}
	if (numOfM3 == 3)
	{
		state = 4;
	}
    
    auto m_uiLayer = UILayer::create();
    m_uiLayer->setPosition(Point::ZERO);
    addChild(m_uiLayer,100);

    Director::getInstance()->resume();

	return true;
}

void GameScene12::carry(){
	hand->setVisible(true);
	abc = 1;

}
void GameScene12::logic(float dt){
	bglayer->logic(dt);
}
 
//void GameScene12::Movedown(){
//     girl_nor->moveDown();
//}

void GameScene12::reset(float dt){

	girl_nor->backNormal();
   
}

bool GameScene12::onTouchBegan(Touch *touch, Event *unused_event){

	location1 = touch->getLocation();
	
	//log("%f,%f",location1.x,location1.y);

	return true;
}

void GameScene12::onTouchEnded(Touch *touch, Event *unused_event){

    location2 = touch->getLocation();

	//log("%f,%f",location2.x,location2.y);

	//ÅÐ¶Ï´¥Ãþµã×ø±ê  È»ºóÍäÑü
	if (location1.y>location2.y>0 && location1.y-location2.y>location1.x-location2.x)
	{
		girl_nor->moveDown();
		movenum = 1;
	}
	
	//×óÒÆ
	if (location1.x>location2.x>0 && location1.x-location2.x>location1.y-location2.y)
	{
		girl_nor->moveLeft();
		movenum = 2;
		log("left");
	}

	//ÓÒÒÆ
	if (location2.x>location1.x>0 && location2.x-location1.x>location2.y-location1.y && location2.x-location1.x>location1.y-location2.y )
	{
		girl_nor->moveRight();
		movenum = 3;
		log("right");
	}
	
}

void GameScene12::refresh(float dt){

	Size visibleSize = Director::getInstance()->getVisibleSize();


	if (numOfM1 < 3 ){
	     m1 = Sprite::create("m1.png");
	     m1->setPosition(Point(visibleSize.width * 0.5f , visibleSize.height * 0.85f));
	     m1->setVisible(true);
	     this->addChild(m1);
	     log("caidao+%d",numOfM1);
	  
		 auto move1 = MoveBy::create(1.0f, Point(0, -350));
	     m1->runAction(move1);

	     numOfM1++;
	}

	if (numOfM1 == 3  && numOfM2 < 3 ){
		m2 = Sprite::create("m2.png");
		m2->setPosition(Point(visibleSize.width * 0.5f , visibleSize.height * 0.7f));
		m2->setVisible(true);
		this->addChild(m2);
		log("manma+%d",numOfM2);

		auto moveBy2 = MoveBy::create(1.0f, Point(0, -300));
		m2->runAction(moveBy2);

		numOfM2++;
	}

	if (numOfM1 == 3  && numOfM2 == 3 && numOfM3 < 3 ){
		m3 = Sprite::create("m3.png");
		m3->setPosition(Point(visibleSize.width * 0.5f , visibleSize.height * 0.5f));
		m3->setVisible(true);
		this->addChild(m3);
		log("zidan+%d",numOfM3);

		auto moveBy3 = MoveBy::create(1.0f, Point(90, -90));
		m3->runAction(moveBy3);


		numOfM3++;
	}

}
void GameScene12::del(float dt){
	 
	Size visibleSize = Director::getInstance()->getVisibleSize();

	if (numOfM1 == 3 && numOfM2 == 3 && numOfM3 == 3)
	{
		allstop = 1;
	}

	if (numOfM1 <= 3 && numOfM2 < 2 ){
	      if (m1->getPositionX() == visibleSize.width * 0.5f && m1->getPositionY() < visibleSize.height * 0.85f )
	      {
		     m1->setVisible(false);
		     this->removeChild(m1);
		     log("del11111111111");
	       }
	}
	if (numOfM1 == 3 && numOfM2 <= 3 && allstop == 0){
	     if (m2->getPositionX() == visibleSize.width * 0.5f && m2->getPositionY() < visibleSize.height * 0.7f )
	    {
		    m2->setVisible(false);
			//m1->setVisible(false);
		    this->removeChild(m2);
			//this->removeChild(m1);
		    log("del222222222222");
	     }  
	}
	if (numOfM1 == 3 && numOfM2 == 3 && numOfM3 <= 3 && allstop ==  0 ){
		if (m3->getPositionX() < visibleSize.width * 0.5f || m3->getPositionY() < visibleSize.height * 0.5f )
		{
			//m2->setVisible(false);
			//this->removeChild(m2);
			m3->setVisible(false);
			this->removeChild(m3);
			log("del33333333333333");
		}  
	}
	

	log("%d",movenum);

	if (movenum == 2 && abc == 1 && state ==1){
	    log("you are safe");
	}else{
		MessageBox("you are dead","dead");
	}
	/*if (movenum == 3 && abc == 1 && state ==2){
		log("you are safe");
	}else{
		MessageBox("you are dead","dead");
	}
	if (movenum == 4 && abc == 1 && state ==3){
		log("you are safe");
	}else{
		MessageBox("you are dead","dead");
	}*/
	

	//CCLOG("%f,%f",m1->getPositionX(),m1->getPositionY());
}


void GameScene12::restart(){
    Director::getInstance()->replaceScene(GameScene12::createScene());
    Director::getInstance()->resume();
    log("GameScene11Restart");
}