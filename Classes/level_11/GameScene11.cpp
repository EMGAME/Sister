#include "GameScene11.h"
#include "GameScene12.h"
#include "CCVector.h"
USING_NS_CC;



Scene* GameScene11::createScene(){
	auto scene = Scene::create();

	auto layer = GameScene11::create();

	scene->addChild(layer);

	return scene;
}

bool GameScene11::init(){
	if ( !Layer::init() )
	{
		return false;
	}

	setpermise(0);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();


	//加载背景
	auto background = Sprite::create("level11/background.png");
	background->setPosition(Point(visibleSize.width *0.5,visibleSize.height * 0.5));
	this->addChild(background);

	//隐藏物品手链
	auto glassbox = MenuItemImage::create("level11/glassbox.png",
		"level11/glassbox.png",
		CC_CALLBACK_0(GameScene11::hidden,this));
	glassbox->setPosition(visibleSize.width * 0.7,visibleSize.height * 0.85);

	auto button5 = Menu::create(glassbox, NULL);
	button5->setPosition(Point::ZERO);
	this->addChild(button5, 5);

	//脸
	/*face1 = MenuItemImage::create("level11/faceSad.png",
	"level11/faceLaugh.png",
	CC_CALLBACK_0(GameScene11::face,this));
	face1->setPosition(visibleSize.width * 0.237,visibleSize.height * 0.63);
	face1->setEnabled(false);

	button1 = Menu::create(face1, NULL);
	button1->setPosition(Point::ZERO);
	this->addChild(button1, 2);*/
	face1 = Sprite::create("level11/faceSad.png");
	face1->setPosition(visibleSize.width * 0.237,visibleSize.height * 0.63);
	this->addChild(face1);

	face2 = Sprite::create("level11/faceLaugh.png");
	face2->setPosition(visibleSize.width * 0.237,visibleSize.height * 0.63);
	face2->setVisible(false);
	this->addChild(face2);

	//玫瑰花
	auto flower = MenuItemImage::create("level11/flower1.png",
		"level11/flower2.png",
		CC_CALLBACK_0(GameScene11::flower,this));
	flower->setPosition(visibleSize.width * 0.8,visibleSize.height * 0.6);

	auto button2 = Menu::create(flower, NULL);
	button2->setPosition(Point::ZERO);
	this->addChild(button2, 2);

	//酒杯
	auto glass = MenuItemImage::create("level11/glass2.png",
		"level11/glass4.png",
		CC_CALLBACK_0(GameScene11::glass,this));
	glass->setPosition(visibleSize.width * 0.5,visibleSize.height * 0.6);

	auto button3 = Menu::create(glass, NULL);
	button3->setPosition(Point::ZERO);
	this->addChild(button3,2,4);

	auto glass2 = Sprite::create("level11/glass1.png");
	glass2->setPosition(visibleSize.width * 0.5,visibleSize.height * 0.6);
	glass2->setVisible(false);
	this->addChild(glass2,2,5);
	

	//小丑面具
	auto clown = MenuItemImage::create("level11/clown1.png",
		"level11/clown2.png",
		CC_CALLBACK_0(GameScene11::clown,this));
	clown->setPosition(visibleSize.width * 0.85,visibleSize.height * 0.16);

	auto button4 = Menu::create(clown, NULL);
	button4->setPosition(Point::ZERO);
	this->addChild(button4,2);
		

	//手链
	handline = Sprite::create("level11/handline2.png");
	handline->setPosition(Point(visibleSize.width * 0.7,visibleSize.height * 0.85));
	handline->setVisible(false);
	this->addChild(handline,2);

	//测试容器vector
	/*Vector<Sprite*> sp_vec;
	sp_vec.pushBack(face);
	sp_vec.pushBack(handline);

	for (auto& e : sp_vec)
	{
	e->runAction(MoveBy::create(5.0f,Point(0,-100)));
	}*/

	//测试
	//auto blue = Sprite::create("CloseNormal.png");
	//blue->setPosition(Point(visibleSize.width * 0.2,visibleSize.height * 0.2));
	//this->addChild(blue);

	//auto red  = Sprite::create("redball.png");
	//red->setPosition(Point(visibleSize.width * 0.8,visibleSize.height * 0.2));
	//this->addChild(red);

	//blue->runAction(MoveBy::create(1.0f,Point(100,0)));
 //   red->runAction(MoveBy::create(1.5f,Point(-100,0)));

	//blue->runAction(Spawn::create(RotateBy::create(3.0f,360),ScaleTo::create(1.0f,10.0f),NULL));

	////延迟2.5s，用1s时间跳了3次，跳跃高度100像素，并且向右移动了30像素  
	//red->runAction(Sequence::create(DelayTime::create(2.5f),JumpBy::create(2.0f,Point(30,0),100,3),NULL));  

	//触摸监听
	auto listener = EventListenerTouchOneByOne::create();

	//listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(GameScene11::onTouchBegan,this);


	listener->onTouchEnded = CC_CALLBACK_2(GameScene11::onTouchEnded,this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//UI
	uiLayer = UILayer::create();
	uiLayer->setTag(1);
	this->addChild(uiLayer);

	Director::getInstance()->resume();

	return true;
}

void GameScene11::clown(){

	//MessageBox("Beautiful girl said 'oh! that is not funny,keep away from me' ","fail");
	uiLayer->Lose("Beautiful girl said 'oh! that is not funny,keep away from me'");
}

void GameScene11::flower(){

	//MessageBox("Beautiful girl said 'he he!'","fail");
	uiLayer->Lose("Beautiful girl said 'he he!'");
}

void GameScene11::glass(){
	//this->getChildByTag(4)->runAction(RotateBy::create(0.5f,90));
	this->getChildByTag(4)->setVisible(false);
	this->getChildByTag(5)->setVisible(true);
	this->getChildByTag(5)->runAction(RotateBy::create(0.5f,-90));
	//face1->setEnabled(true);
	setpermise(1) ;
	log("p=%d",getpermise());
}

void GameScene11::face(){

	MessageBox("Beautiful girl laugh","success");
}

void GameScene11::hidden(){

	handline->setVisible(true);
	auto move = MoveBy::create(1.0f,Point(0,-100));
	handline->runAction(move);

}

bool GameScene11::onTouchBegan(Touch *touch, Event *unused_event){
	if (permise == 1)
	{
		location1 = touch->getLocation();
		return true;
	}else
	{
		return false;
	}
}

void GameScene11::onTouchEnded(Touch *touch, Event *unused_event){
	Size visibleSize = Director::getInstance()->getVisibleSize();
	location2 = touch->getLocation();
	log("%f,%f",visibleSize.width * 0.237,visibleSize.height * 0.63);
	log("%f,%f",location1.x,location1.y);
	log("%f,%f",location2.x,location2.y);
	if (visibleSize.width * 0.237 < location1.x && location1.x <visibleSize.width * 0.237 + 100 &&
		visibleSize.height * 0.63 - 100 < location1.y && location1.y < visibleSize.height * 0.63)
	{
		log("111111111111111111111");
		if (visibleSize.width * 0.237 < location2.x && location2.x <visibleSize.width * 0.237 + 100 &&
			visibleSize.height * 0.63 < location2.y && location2.y < visibleSize.height * 0.63 + 100)
		{
			log("222222222222222222");
			face2->setVisible(true);
			//MessageBox("girl is laugh","success");
			uiLayer->Success("guoguan",3);
		}
	}

}

void GameScene11::restart(){
	Director::getInstance()->replaceScene(GameScene11::createScene());
	Director::getInstance()->resume();
	log("11111111111111111");
}

void GameScene11::nextLevel(){
    Director::getInstance()->replaceScene(GameScene12::createScene());
}