#include "GameScene12.h"

USING_NS_CC;

Scene* GameScene12::createScene(){

	auto scene = Scene::create();

	auto backgroundLayer = Bglayer::create();
	scene->addChild(backgroundLayer,0);

	auto layer = GameScene12::create();

	scene->addChild(layer);

	layer->bglayer = backgroundLayer;

	return scene;
}

bool GameScene12::init(){

	if (!Scene::create())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getWinSize();

	//主角
	girl_nor = Girl::create();
	this->addChild(girl_nor,3,5);

	movenum = 0;
	otherlife = 0;
	abc = 0;
    state = 0;

	//添加手链
	hand = Sprite::create("level12/handline.png");
	hand->setPosition(Point(visibleSize.width * 0.5f , visibleSize.height * 0.5f));
	hand->setVisible(false);
	this->addChild(hand,5);

	//点击装备手链功能
	auto button = MenuItemImage::create("level12/play_nor.png",
		                              "level12/play_pre.png",
		                             CC_CALLBACK_0(GameScene12::carry,this));
	button->setPosition(visibleSize.width *0.85f,visibleSize.height * 0.2f);

	auto button1 = Menu::create(button, NULL);
	button1->setPosition(Point::ZERO);
	this->addChild(button1, 2);


	//触摸监听
	auto listener = EventListenerTouchOneByOne::create();

	//listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(GameScene12::onTouchBegan,this);
	

	listener->onTouchEnded = CC_CALLBACK_2(GameScene12::onTouchEnded,this);
	
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//创建这三个怪物并且放入到数组中
	//菜刀
	m1 = Sprite::create("level12/m1.png");
	m1->setPosition(Point(visibleSize.width * 0.6f , visibleSize.height * 0.63f));
	this->addChild(m1);
	/*m1->setScale(0.7,0.7);
	auto move1 = MoveBy::create(1.0f, Point(-190 ,-190));
	auto sm1 = Spawn::create(move1,RotateTo::create(1.0f,1080),NULL);
	m1->runAction(sm1);*/
	m1->setVisible(false);

    //谩骂
	m2 = Sprite::create("level12/m2.png");
	m2->setPosition(Point(visibleSize.width * 0.52f , visibleSize.height * 0.62f));
	this->addChild(m2);
	/*m2->setScale(0.1,0.1);
	auto move2 = MoveBy::create(1.0f, Point(20 ,-130));
	auto sm2 = Spawn::create(move2,ScaleTo::create(1.0f,1.2f,1.2f),NULL);
	m2->runAction(sm2);*/
	m2->setVisible(false);

	//子弹
	m3 = Sprite::create("level12/m3.png");
	m3->setPosition(Point(visibleSize.width * 0.42f , visibleSize.height * 0.62f));
	this->addChild(m3);
	//auto move3 = MoveBy::create(1.0f, Point(180, -150));
	//m3->runAction(move3);
	m3->setVisible(false);


	this->schedule(schedule_selector(GameScene12::loadM),2.0,9,5);

	uiLayer = UILayer::create();
	this->addChild(uiLayer);

	return true;
}

void GameScene12::carry(){

	hand->setVisible(true);
	abc = 1;

}

bool GameScene12::onTouchBegan(Touch *touch, Event *unused_event){

	location1 = touch->getLocation();
	
	//log("%f,%f",location1.x,location1.y);

	return true;
}

void GameScene12::onTouchEnded(Touch *touch, Event *unused_event){

    location2 = touch->getLocation();

	//log("%f,%f",location2.x,location2.y);

	//判断触摸点坐标  然后弯腰
	if (location1.y>location2.y>0 && location1.y-location2.y>location1.x-location2.x)
	{
		girl_nor->moveDown();
		movenum = 1;
	}
	
	//左移
	if (location1.x>location2.x>0 && location1.x-location2.x>location1.y-location2.y)
	{
		girl_nor->moveLeft();
		movenum = 3;
	}

	//右移
	if (location2.x>location1.x>0 && location2.x-location1.x>location2.y-location1.y && location2.x-location1.x>location1.y-location2.y )
	{
		girl_nor->moveRight();
		movenum = 2;
	}
	
}

void GameScene12::loadM(float dt){

	Size visibleSize = Director::getInstance()->getVisibleSize();

    int temp = CCRANDOM_0_1()*100;

	if (temp%3 == 0 ){
			m1->setVisible(true);
			m1->setScale(0.7,0.7);
			state = 1;
			auto move1 = MoveBy::create(1.0f, Point(-190 ,-190));
			auto sm1 = Spawn::create(move1,RotateTo::create(1.0f,1080),NULL);
			auto Pm1 = Place::create(Point(visibleSize.width * 0.6f , visibleSize.height * 0.63f));
			auto Sm1 = Sequence::create(sm1,Pm1,CallFunc::create(CC_CALLBACK_0(GameScene12::Mhide,this)),NULL);
			m1->runAction(Sm1);
		}

	if (temp%3 == 1){
		    m2->setScale(0.1,0.1);
			m2->setVisible(true);
			state = 2 ;
			auto move2 = MoveBy::create(1.0f, Point(20 ,-130));
			auto sm2 = Spawn::create(move2,ScaleTo::create(1.0f,1.2f,1.2f),NULL);
			auto Pm2 = Place::create(Point(visibleSize.width * 0.52f , visibleSize.height * 0.62f));
			auto Sm2 = Sequence::create(sm2,Pm2,CallFunc::create(CC_CALLBACK_0(GameScene12::Mhide,this)),NULL);
			m2->runAction(Sm2);	
		}

	if (temp%3 == 2){
			m3->setVisible(true);
			state = 3 ;
			auto move3 = MoveBy::create(1.0f, Point(180, -150));
			auto Pm3 = Place::create(Point(visibleSize.width * 0.42f , visibleSize.height * 0.62f));
			auto Sm3 = Sequence::create(move3,Pm3,CallFunc::create(CC_CALLBACK_0(GameScene12::Mhide,this)),NULL);
			m3->runAction(Sm3);
		}

}

void GameScene12::Mhide(){

	m1->setVisible(false);
	m2->setVisible(false);
	m3->setVisible(false);
	log("%d",state);
	if(state == 1){
		if (abc == 1){
			if (movenum == 2 ){
				log("you are safe");
				otherlife++;
			}else{
                //MessageBox("you are dead","dead");
				uiLayer->Lose("Girl1 is dead");
			}
		}else{
			//MessageBox("girl is safe,but you are dead","dead");
			uiLayer->Lose("girl1 is safe,but you are dead");
		}
	}

	if(state == 2){
		if (abc == 1){
			if (movenum == 1 ){
				log("you are safe");
				otherlife++;
			}else{
				//MessageBox("you are dead","dead");
				uiLayer->Lose("Girl2 is dead");
			}
		}else{
			//MessageBox("girl is safe,but you are dead","dead");
			uiLayer->Lose("girl2 is safe,but you are dead");
		}
	}

	if(state == 3){
		if (abc == 1){
			if (movenum == 3 ){
				log("you are safe");
				otherlife++;
			}else{
				//MessageBox("you are dead","dead");
				uiLayer->Lose("Girl3 is dead");
			}
		}else{
			//MessageBox("girl is safe,but you are dead","dead");
			uiLayer->Lose("girl3 is safe,but you are dead");
		}
	}

	if (otherlife > 3)
	{
		uiLayer->Success("you and girl ",2);
	}
}

void GameScene12::restart(){ 
	Director::getInstance()->replaceScene(GameScene12::createScene());
	Director::getInstance()->resume();
}