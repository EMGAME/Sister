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
	numOfM1 = 0;
	numOfM2 = 0;
	numOfM3 = 0;
	otherlife = 1;
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
	m1->setPosition(Point(visibleSize.width * 0.5f , visibleSize.height * 0.85f));
	this->addChild(m1);
	m1->setVisible(false);
	M_Vetor.pushBack(m1);

    //谩骂
	m2 = Sprite::create("level12/m2.png");
	m2->setPosition(Point(visibleSize.width * 0.5f , visibleSize.height * 0.7f));
	this->addChild(m2);
	m2->setVisible(false);
	M_Vetor.pushBack(m2);

	//子弹
	m3 = Sprite::create("level12/m3.png");
	m3->setPosition(Point(visibleSize.width * 0.5f , visibleSize.height * 0.5f));
	this->addChild(m3);
	m3->setVisible(false);
	M_Vetor.pushBack(m3);


	//this->schedule(schedule_selector(GameScene12::loadM),2.0,9,5);


	return true;
}

void GameScene12::carry(){
	hand->setVisible(true);
	abc = 1;

}

//void GameScene12::logic(float dt){
//	bglayer->logic(dt);
//}
 
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
		movenum = 2;
	}

	//右移
	if (location2.x>location1.x>0 && location2.x-location1.x>location2.y-location1.y && location2.x-location1.x>location1.y-location2.y )
	{
		girl_nor->moveRight();
		movenum = 3;
	}
	
}

void GameScene12::loadM(float dt){

	Size visibleSize = Director::getInstance()->getVisibleSize();

	/*for (Sprite *m : M_Vetor)
	{*/
		int temp = CCRANDOM_0_1()*100;

		//log("%d",temp);

		/*if (m->getNumberOfRunningActions() == 0) 
		{
		this->createM(temp%3);
		log("%d",temp%3);
		}*/

		if (temp%3 == 0 && numOfM1 < 3){
			m1->setVisible(true);
			state = 1;
			auto move1 = MoveBy::create(1.0f, Point(0, -350));
			auto Pm1 = Place::create(Point(visibleSize.width * 0.5f , visibleSize.height * 0.85f));
			auto Sm1 = Sequence::create(move1,Pm1,CallFunc::create(CC_CALLBACK_0(GameScene12::Mhide,this)),NULL);
			m1->runAction(Sm1);
			numOfM1++;
			log("m1+%d",numOfM1);
		}

		if (temp%3 == 1 && numOfM2 < 3){
			m2->setVisible(true);
			state = 2 ;
			auto move2 = MoveBy::create(1.0f, Point(0, -300));
			auto Pm2 = Place::create(Point(visibleSize.width * 0.5f , visibleSize.height * 0.7f));
			auto Sm2 = Sequence::create(move2,Pm2,CallFunc::create(CC_CALLBACK_0(GameScene12::Mhide,this)),NULL);
			m2->runAction(Sm2);
			numOfM2++;
			log("m2+%d",numOfM2);	
		}

		if (temp%3 == 2 && numOfM3 < 3){
			m3->setVisible(true);
			state = 3 ;
			auto move3 = MoveBy::create(1.0f, Point(90, -90));
			auto Pm3 = Place::create(Point(visibleSize.width * 0.5f , visibleSize.height * 0.5f));
			auto Sm3 = Sequence::create(move3,Pm3,CallFunc::create(CC_CALLBACK_0(GameScene12::Mhide,this)),NULL);
			m3->runAction(Sm3);
			numOfM3++;
			log("m3+%d",numOfM3);
		}

	/*}*/
}

//void GameScene12::createM(int a){
//
//	Size visibleSize = Director::getInstance()->getVisibleSize();
//
//	if (a == 0){
//		//m1->runAction( MoveBy::create(1.0f, Point(0, -350)));
//		auto move1 = MoveBy::create(1.0f, Point(0, -350));
//		auto Pm1 = Place::create(Point(visibleSize.width * 0.5f , visibleSize.height * 0.85f));
//		auto Sm1 = Sequence::create(move1,Pm1,move1->clone(),Pm1->clone(),move1->clone(),NULL);
//		m1->runAction(Sm1);
//	}
//
//	if (a == 1){
//		m2->runAction(MoveBy::create(1.0f, Point(0, -300)));
//	}
//	if (a == 2){
//		m3->runAction(MoveBy::create(1.0f, Point(90, -90)));
//	}
//}

void GameScene12::Mhide(){

	/*if (a == 1){
	m1->setVisible(false);
	}
	if (a == 2){
	m2->setVisible(false);
	}
	if (a == 3){
	m3->setVisible(false);

	}*/
	//log("123");
	m1->setVisible(false);
	m2->setVisible(false);
	m3->setVisible(false);
	log("%d",state);
	if(state == 1){
		if (abc == 1){
			if (movenum == 2 ){
				log("you are safe");
			}else{
                MessageBox("you are dead","dead");
			}
		}else{
			MessageBox("girl is safe,but you are dead","dead");
		}
	}

	if(state == 2){
		if (abc == 1){
			if (movenum == 1 ){
				log("you are safe");
			}else{
				MessageBox("you are dead","dead");
			}
		}else{
			MessageBox("girl is safe,but you are dead","dead");
		}
	}

	if(state == 3){
		if (abc == 1){
			if (movenum == 3 ){
				log("you are safe");
			}else{
				MessageBox("you are dead","dead");
			}
		}else{
			MessageBox("girl is safe,but you are dead","dead");
		}
	}

	if (numOfM3 == 3 && numOfM1 == 3 && numOfM2 == 3)
	{
		MessageBox("guoguanl ", "success");
	}
}