#include "level_09.h"
#include "CCEventDispatcher.h"
#include "CCEventListenerTouch.h" 


USING_NS_CC;  


static bool rubbishISHave=true;
MoveTo*  moveTo_5;
int HaveUFO=0;
int MoveCar=0;
int havePlane=0;
int movePlane=0;

Scene* Level09::createScene()  
{  
	auto scene = Scene::create();  
	auto layer = Level09::create();  
	scene->addChild(layer,1,100);  
	return scene;  
}  

bool Level09::init()
{
	if ( !Layer::init() )
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	auto size = Director::getInstance()->getWinSize();  

	//background
	auto m_bg = Sprite::create("level09/09-background.png");
	//m_bg->setAnchorPoint(Point(0,0));
	m_bg->setPosition(Point(size.width/2,size.height/2));
	this->addChild(m_bg);

	//car
	auto car = Sprite::create("level09/car.png");
	car->setPosition(Point(0,size.height*0.55));
	car->setTag(111);
	this->addChild(car,3);

	//plane
	auto plane= Sprite::create("level09/plane.png");
    plane->setTag(130);
	plane->setVisible(false);
	this->addChild(plane,3);

	//tree
	auto tree = Sprite::create("level09/tree.png");
	tree->setPosition(Point(size.width*0.40,size.height*0.10));
	tree->setTag(112);
	this->addChild(tree,2);

	//rubbish
	auto rubbish = Sprite::create("level09/rubbish.png");
	rubbish->setPosition(Point(size.width*0.93,size.height*0.30));
	rubbish->setTag(115);
	rubbish->setVisible(true);
	this->addChild(rubbish,2);

	//rubbish2
	auto rubbish2 = Sprite::create("level09/rubbish.png");
	rubbish2->setPosition(Point(size.width*0.91,size.height*0.35));
	rubbish2->setTag(114);
	rubbish2->setVisible(false);
	this->addChild(rubbish2,2);

	
      //no guoguan scene
		auto guoguan = Sprite::create("level09/weiguoguan.png");
	    guoguan->setPosition(Point(size.width/2,size.height/2));
		guoguan->setTag(119);
		guoguan->setVisible(false);
		this->addChild(guoguan,4);

	   //click
		auto UFO = MenuItemImage::create("level09/bianshen.png","level09/bianshen1.png",  CC_CALLBACK_0(Level09::moveUFO, this));  
    UFO->setPosition(Point(size.width*0.90,size.height*0.85));
    auto UFO1 = Menu::create(UFO, NULL);  
	UFO1->setPosition(Point::ZERO);  
	UFO1->setVisible(false);
	UFO1->setTag(121);
	
    this->addChild(UFO1, 4);  
	
	//saozhou button
	auto saozhouItem = MenuItemImage::create("level09/saozhou.png","level09/saozhou.png",  CC_CALLBACK_0(Level09::showSaoZhou, this));  
    saozhouItem->setPosition(Point(size.width*0.39,size.height*0.12));

	auto saozhouItem1 = Menu::create(saozhouItem, NULL);  
	saozhouItem1->setPosition(Point::ZERO);  
	saozhouItem1->setTag(120);
	saozhouItem1->setVisible(false);
	this->addChild(saozhouItem1, 3);  


	 //basket button
	auto rubbishItem = MenuItemImage::create("level09/basket.png","level09/basket.png",  CC_CALLBACK_0(Level09::showRubbish2, this));  
    rubbishItem->setPosition(Point(size.width*0.30,size.height*0.70));

	auto rubbishItem1 = Menu::create(rubbishItem, NULL);  
	rubbishItem1->setPosition(Point::ZERO);  

	this->addChild(rubbishItem1, 2);  
	 
	//close button
	auto closeItem = MenuItemImage::create("level09/CloseNormal.png","level09/CloseSelected.png",CC_CALLBACK_1(Level09::menuCloseCallback, this));

	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,origin.y + closeItem->getContentSize().height/2));

	auto menu = Menu::create(closeItem, NULL);  
	menu->setPosition(Point::ZERO);  
	this->addChild(menu, 3);  
	

	

//touch tree for show saozhou
 auto listener2 = EventListenerTouchOneByOne::create();//创建一个触摸监听
 listener2->onTouchBegan=CC_CALLBACK_2(Level09::onTouchBeganTree,this);
 listener2->onTouchEnded=CC_CALLBACK_2(Level09::onTouchEndedTree,this);
 _eventDispatcher->addEventListenerWithSceneGraphPriority(listener2,tree);
 
 //move car
 moveTo_5=MoveTo::create(10.0f,Point(size.width*0.75,size.height*0.40));
 car->runAction(Sequence::create( moveTo_5,CallFunc::create(this,callfunc_selector(Level09::finishSaozou))));
rubbish->runAction(JumpBy::create(1.0f,Point(30,0),100,3)); 

//touch car
//auto listener3 = EventListenerTouchOneByOne::create();//创建一个触摸监听
// listener3->onTouchBegan=CC_CALLBACK_2(Level09::onTouchBeganCar,this);
// listener3->onTouchMoved = CC_CALLBACK_2(Level09::onTouchMovedCar, this);  
// _eventDispatcher->addEventListenerWithSceneGraphPriority(listener3,car);

 //加入UILayer
	uiLayer = UILayer::create();
	this->addChild(uiLayer,100);

return true;
}

void Level09::onEnter() {
	Layer::onEnter();
	log("Enter");
	setAccelerometerEnabled(true);
}

void  Level09::onAcceleration(Acceleration* acc, Event* unused) {
	
	 auto size = Director::getInstance()->getWinSize();  
	
	 float nowGX = (acc->x)*9.81f;
     float nowGY = (acc->y)*9.81f;
 if((nowGX<-10.0||nowGX>10.0)&&(nowGY<-10.0||nowGY>10.0))
 {
     this->getChildByTag(121)->setVisible(true);
	 this->getChildByTag(111)->stopAction(moveTo_5);
	 HaveUFO=1;

	}
	}



void Level09::menuCloseCallback(Ref* pSender)  
{  
	 Director::getInstance()->end();
}  

void Level09::showRubbish2(){
	
	this->getChildByTag(114)->setVisible(true);
}

void Level09::moveUFO(){
	auto size = Director::getInstance()->getWinSize(); 
	

	if(HaveUFO==1){
		
	 MoveCar=1;
	}
	if(MoveCar==1){
		this->getChildByTag(111)->runAction(MoveBy::create(1.0f,Point(0,240)));
		this->getChildByTag(111)->stopAllActions();
		this->getChildByTag(111)->setVisible(false);
	    havePlane=1;
    }
	if(havePlane==1){
		carPoint=this->getChildByTag(111)->getPosition();
		this->getChildByTag(130)->setVisible(true);
		this->getChildByTag(130)->setPosition(Point(carPoint.x,carPoint.y));
	    this->getChildByTag(130)->runAction(Sequence::create(MoveBy::create(1.5f,Point(700,0)),CallFunc::create(this,callfunc_selector(Level09::finishPlane))));
		
	
	}
}

void  Level09::finishPlane(){
	uiLayer->Success("guo guan",3);
}


void Level09::showSaoZhou(){
	

	auto rubbishPos = this->getChildByTag(114)->getPosition();//获取位置  
    auto rubbishSize = this->getChildByTag(114)->getContentSize();//获取大小  
    MoveTo*  moveTo_1 = MoveTo::create(0.7f,Point(rubbishPos.x,rubbishPos.y));  
	this->getChildByTag(120)->runAction(moveTo_1);
	this->getChildByTag(115)->setVisible(false);
    this->getChildByTag(114)->setVisible(false);
	this->getChildByTag(119)->setVisible(true);
	this->getChildByTag(119)->setRotation(180);
    this->getChildByTag(119)->runAction(Sequence::create(RotateTo::create(1.0f,0),CallFunc::create(this,callfunc_selector(Level09::finishSaozou))));
	}
void Level09::finishSaozou(){
	uiLayer->Lose("guo guan");
}

bool Level09::onTouchBeganTree(Touch *touch, Event* event){
	location1=touch->getLocation();
	return true;
};

void Level09::onTouchEndedTree(Touch *touch, Event* event){
	auto size = Director::getInstance()->getWinSize();  
	location2=touch->getLocation();

   	if(location2.x>location1.x)
	{
	this->getChildByTag(120)->setVisible(true);
	this->getChildByTag(120)->runAction(MoveTo::create(0.3f,Point(size.width*0.20,0)));
	}
	
};



//bool Level09::onTouchBeganCar(Touch *touch, Event* event){
//		return true;
//};
//void Level09::onTouchMovedCar(Touch *touch, Event* event){
//    auto beginPos = touch->getLocationInView();//获得触摸位置  
//    beginPos = Director::getInstance()->convertToGL(beginPos);//坐标转换  
//   
//	auto carPos = this->getChildByTag(111)->getPosition();//获取位置  
//    auto carSize = this->getChildByTag(111)->getContentSize();//获取大小  
//    //定制一个框框  
//    auto rect = Rect(carPos.x - carSize.width/2,carPos.y - carSize.height/2,carSize.width + 10,carSize.height + 10);  
//    if(rect.containsPoint(beginPos))//判断触点是否在身上！  
//    {  
//		this->getChildByTag(111)->runAction(Blink::create(1.0f, 3));
//    }    
//};

void Level09::onExit() {

	Layer::onExit();
	log("HelloWorldExit");
}

void Level09::restart(){
    Director::getInstance()->replaceScene(Level09::createScene());
  
}
