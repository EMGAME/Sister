#include "GameScene11.h"
#include "GameScene10.h"

USING_NS_CC;  

auto size = Director::getInstance()->getWinSize();  
int DrawIsWithKey=0;
//int OpenDraw=0;
int OpenBox=0;
int HaveHand=0;
bool timeRunning = false;

Scene* GameScene10::createScene()  
{  
	
	auto scene = Scene::create();  
	auto layer = GameScene10::create();  
	scene->addChild(layer,1,100);  
	return scene;  
}  

bool GameScene10::init()
{
	if ( !Layer::init() )
	{
		return false;
	}
		
    log("create");
    
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	auto size = Director::getInstance()->getWinSize();  

	//time
	timerLabel = Label::create();
	timerLabel->setColor(Color3B::RED);
	timerLabel->setFontSize(50);
	timerLabel->setString("0.0000");
	timerLabel->setPosition(size.width/2, size.height*0.8);
	this->addChild(timerLabel,10);
	
	
		//start time
	this->startTimer();


	//background
	auto m_bg = Sprite::create("level10/10-background.png");
	//m_bg->setAnchorPoint(Point(0,0));
	m_bg->setPosition(Point(size.width/2,size.height/2));
	this->addChild(m_bg);

	//bed
	/*auto bed=Sprite::create("10-bed.png");
	bed->setAnchorPoint(Point(0,0));
	bed->setPosition(Point(0,0));
	this->addChild(bed,1);*/
    
	//girl
	auto girl=Sprite::create("level10/10-girl.png");
	girl->setAnchorPoint(Point(1,0));
	girl->setPosition(Point(size.width*0.95,0));
	this->addChild(girl,1);

	//ligthlamp
	auto OpenLamp=Sprite::create("level10/10-OpenLamp.png");
	OpenLamp->setAnchorPoint(Point(0,0));
	OpenLamp->setVisible(false);
	OpenLamp->setTag(4);
	OpenLamp->setPosition(Point(size.width*0.30,size.height*0.28));
	this->addChild(OpenLamp,1);

	//password
	auto password=Sprite::create("level10/10-password.png");
	password->setAnchorPoint(Point(0,0));
	password->setPosition(Point(size.width*0.52,size.height*0.30));
	password->setTag(2);
	password->setVisible(false);
	this->addChild(password,3);

	//paper
	/*auto paper=Sprite::create("10-paper.png");
	paper->setAnchorPoint(Point(0,0));
	paper->setPosition(Point(size.width*0.47,size.height*0.25));
	paper->setVisible(true);
	this->addChild(paper,1);*/
   
	//OpenStrongBox
	auto OpenStrongBox=Sprite::create("level10/10-OpenStrongBox.png");
	OpenStrongBox->setAnchorPoint(Point(0,0));
	OpenStrongBox->setPosition(Point(size.width*0.15,size.height*0.50));
	OpenStrongBox->setVisible(false);
	OpenStrongBox->setTag(11);
	this->addChild(OpenStrongBox,1);

	//StrongBox
	auto StrongBox=Sprite::create("level10/10-StrongBox.png");
	StrongBox->setAnchorPoint(Point(0,0));
	StrongBox->setPosition(Point(size.width*0.15,size.height*0.50));
	StrongBox->setVisible(true);
	StrongBox->setTag(10);
	this->addChild(StrongBox,5);

	//OpenDraw
	auto OpenDraw=Sprite::create("level10/10-OpenDrawBox.png");
	OpenDraw->setAnchorPoint(Point(0,0));
	OpenDraw->setPosition(Point(size.width*0.13,size.height*0.70));
	OpenDraw->setVisible(false);
	OpenDraw->setTag(7);
    this->addChild(OpenDraw,1);

	//Draw
	auto Draw=Sprite::create("level10/10-draw.png");
	Draw->setAnchorPoint(Point(0,0));
	Draw->setPosition(Point(size.width*0.13,size.height*0.70));
	Draw->setTag(5);
    Draw->setVisible(true);
	 this->addChild(Draw,7);
	 
	//DrawWithKey
	auto DrawWithKey=Sprite::create("level10/10-drawWithKey.png");
	DrawWithKey->setAnchorPoint(Point(0,0));
	DrawWithKey->setPosition(Point(size.width*0.13,size.height*0.70));
	DrawWithKey->setTag(6);
	DrawWithKey->setVisible(false);
	 this->addChild(DrawWithKey,7);

	 //hole
	 auto hole=Sprite::create("level10/10-hole.png");
	 hole->setAnchorPoint(Point(0,0));
	 hole->setPosition(Point(size.width*0.70,size.height*0.68));
	 hole->setTag(13);
	 this->addChild(hole,1);

	//bed's key
	auto key=Sprite::create("level10/10-key.png");
    key->setPosition(Point(size.width*0.15,size.height*0.10));
	key->setVisible(false);
	key->setTag(1);
	this->addChild(key,10);

	//Draw' key 
	auto key2=Sprite::create("level10/10-key2.png");
    key2->setPosition(Point(size.width*0.23,size.height*0.75));
	key2->setVisible(false);
	key2->setTag(9);
	this->addChild(key2,6);


	//question
	auto question=Sprite::create("level10/10-question.png");
    question->setPosition(Point(size.width*0.67,size.height*0.55));
	question->runAction(RotateBy::create(1.0f,360));
    this->addChild(question,1);

	//hand
	auto hand=Sprite::create("level10/10-hand.png");
    hand->setPosition(Point(size.width*0.23,size.height*0.57));
	hand->setVisible(false);
	hand->setTag(12);
    this->addChild(hand,3);

	//guoguan
	auto guoguan=Sprite::create("level10/10-guoguan.png");
    guoguan->setPosition(Point(size.width/2,size.height/2));
	guoguan->setVisible(false);
	guoguan->setTag(14);
	this->addChild(guoguan,6);

    //click bed for get key
	auto bedItem = MenuItemImage::create("level10/10-bed.png","level10/10-bed.png",  CC_CALLBACK_0(GameScene10::showKey, this));  
	bedItem->setAnchorPoint(Point(0,0));
	bedItem->setPosition(Point(0,0));

	auto bedItem1 = Menu::create(bedItem, NULL);  
	bedItem1->setPosition(Point::ZERO);  
	this->addChild(bedItem1, 1);  
	
	//click paper for get password
	auto paperItem = MenuItemImage::create("level10/10-paper.png","level10/10-paper.png",  CC_CALLBACK_0(GameScene10::showPassword, this));  
	paperItem->setAnchorPoint(Point(0,0));
	paperItem->setPosition(Point(size.width*0.57,size.height*0.27));

    auto paperItem1 = Menu::create(paperItem, NULL);  
	paperItem1->setPosition(Point::ZERO);  
	this->addChild(paperItem1, 1); 

	//click lamp
	auto lampItem = MenuItemImage::create("level10/10-lamp.png","level10/10-lamp.png",  CC_CALLBACK_0(GameScene10::lightLamp, this));  
	lampItem->setAnchorPoint(Point(0,0));
	lampItem->setPosition(Point(size.width*0.40,size.height*0.31));

    auto lampItem1 = Menu::create(lampItem, NULL);  
	lampItem1->setPosition(Point::ZERO);  
	lampItem1->setVisible(true);
	lampItem1->setTag(3);
	this->addChild(lampItem1, 1); 

	//close button
	auto closeItem = MenuItemImage::create("level10/CloseNormal.png","level10/CloseSelected.png",CC_CALLBACK_1(GameScene10::menuCloseCallback, this));
    closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,origin.y + closeItem->getContentSize().height/2));

	auto menu = Menu::create(closeItem, NULL);  
	menu->setPosition(Point::ZERO);  
	this->addChild(menu, 3);
     
	//move bed'key for open draw
    auto listener = EventListenerTouchOneByOne::create();//创建一个触摸监听(单点触摸）  
	listener->onTouchBegan = CC_CALLBACK_2(GameScene10::onTouchBeganDraw, this);//指定触摸的回调函数  
    listener->onTouchEnded = CC_CALLBACK_2(GameScene10::onTouchEndedDraw, this);  
    listener->onTouchMoved = CC_CALLBACK_2(GameScene10::onTouchMovedDraw, this);  
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, key);//将listener放入事件委托中  
    
	//move draw'key for open StrongBox
    auto listener2 = EventListenerTouchOneByOne::create();//创建一个触摸监听(单点触摸）  
	listener2->onTouchBegan = CC_CALLBACK_2(GameScene10::onTouchBeganBox, this);//指定触摸的回调函数  
    listener2->onTouchEnded = CC_CALLBACK_2(GameScene10::onTouchEndedBox, this);  
    listener2->onTouchMoved = CC_CALLBACK_2(GameScene10::onTouchMovedBox, this);  
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener2, key2);//将listener放入事件委托中  
    
	//move Box's hand for hole's money
    auto listener3 = EventListenerTouchOneByOne::create();//创建一个触摸监听(单点触摸）  
	listener3->onTouchBegan = CC_CALLBACK_2(GameScene10::onTouchBeganHole, this);//指定触摸的回调函数  
    listener3->onTouchEnded = CC_CALLBACK_2(GameScene10::onTouchEndedHole, this);  
    listener3->onTouchMoved = CC_CALLBACK_2(GameScene10::onTouchMovedHole, this);  
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener3, hand);//将listener放入事件委托中  

 //加入UILayer
    uiLayer = UILayer::create();
	this->addChild(uiLayer,100);
    log("createadfadfasdfadsf");
    
    return true;
}
void GameScene10::menuCloseCallback(Ref* pSender)  
{  
	 Director::getInstance()->end();
}  

//bool GameScene10::isInSprite(Touch *theTouch,Sprite *sp){  
//    if (sp != NULL) {  
//        //返回当前触摸位置得OpenGL坐标  
//        Point touchPoint = theTouch->getLocation();  
//        //将世界坐标转换为当前得父View的本地坐标  
//        Point reallyPoint = this->getParent()->convertToNodeSpace(touchPoint);  
//        //获取当前基于父View的坐标系  
//        Rect rect = sp->boundingBox();  
//        if (rect.containsPoint(reallyPoint)) {  
//            return true;  
//        }  
//    }  
//    return false;  
//}  

void  GameScene10::showKey(){
	this->getChildByTag(1)->setVisible(true);
	//this->getChildByTag(1)->runAction(Blink::create(1.0f, 5));
};

void GameScene10::showPassword(){
	this->getChildByTag(2)->setVisible(true);
	this->getChildByTag(2)->setRotation(180);
	this->getChildByTag(2)->runAction(RotateTo::create(1.0f,0));
};

void GameScene10::lightLamp(){
	this->getChildByTag(3)->setVisible(false);
	this->getChildByTag(4)->setVisible(true);
	this->removeChild(getChildByTag(5));
	this->getChildByTag(6)->setVisible(true);
	//this->getChildByTag(6)->runAction(Blink::create(1.0f, 5));

	DrawIsWithKey=1;
	
};

bool GameScene10::onTouchBeganDraw(Touch *touch, Event* event){
     return true;
};

void GameScene10::onTouchMovedDraw(Touch *touch, Event* event){
    auto beginPos = touch->getLocationInView();//获得触摸位置  
    beginPos = Director::getInstance()->convertToGL(beginPos);//坐标转换  
  
    auto keyPos = this->getChildByTag(1)->getPosition();//获取位置  
    auto keySize = this->getChildByTag(1)->getContentSize();//获取大小  
    //定制一个框框  
    auto rect = Rect(keyPos.x - keySize.width/2,keyPos.y - keySize.height/2,keySize.width + 20,keySize.height + 20);  
    if(rect.containsPoint(beginPos))//判断触点是否在身上！  
    {  
        auto endPos = touch->getPreviousLocationInView();//获取触摸的前一个位置  
        endPos = Director::getInstance()->convertToGL(endPos);//转换坐标
  
        auto offset = Point(beginPos-endPos);//获取offset，2.14是用ccpSub，3.0后直接用 - 号就可以  
        auto nextPos = Point( keyPos + offset);  
        this->getChildByTag(1)->setPosition(nextPos);  
    }    
};

void GameScene10::onTouchEndedDraw(Touch *touch, Event* event){
	auto size = Director::getInstance()->getWinSize();  
	auto lastPos = touch->getLocationInView();  
    lastPos = Director::getInstance()->convertToGL(lastPos);  
       
    auto DrawPos = this->getChildByTag(6)->getPosition();//获取位置  
    auto DrawSize = this->getChildByTag(6)->getContentSize();//获取大小  
    //定制一个框框  
    auto rect = Rect(DrawPos.x - DrawSize.width/2,DrawPos.y - DrawSize.height/2,DrawSize.width + 30,DrawSize.height + 30);  //建立一个选中区域，女主如果拖动到这个框内就可以瞬移进来，反之是小三进来  
      
    MoveTo* moveTo_1;

  	if(DrawIsWithKey==1){
    if(rect.containsPoint(lastPos))   {
		moveTo_1 = MoveTo::create(0.1f,Point(0,size.height));
		this->getChildByTag(1)->runAction(moveTo_1);
	    this->getChildByTag(6)->setVisible(false);
		this->getChildByTag(7)->setVisible(true);
		this->getChildByTag(1)->setVisible(false);
		this->getChildByTag(9)->setVisible(true);
		DrawIsWithKey=0;
		OpenBox=1;
	 }  else  {  
		  moveTo_1 = MoveTo::create(0.1f,Point(size.width*0.15,size.height*0.10)); 
        this->getChildByTag(1)->runAction(moveTo_1);
 }  
   }

};

bool GameScene10::onTouchBeganBox(Touch *touch, Event* event){
	
	  return true;
};

void  GameScene10::onTouchMovedBox(Touch *touch, Event* event){
	auto beginPos = touch->getLocationInView();//获得触摸位置  
    beginPos = Director::getInstance()->convertToGL(beginPos);//坐标转换  
  
    auto key2Pos = this->getChildByTag(9)->getPosition();//获取位置  
    auto key2Size = this->getChildByTag(9)->getContentSize();//获取大小  
    //定制一个框框  
    auto rect = Rect(key2Pos.x - key2Size.width/2,key2Pos.y - key2Size.height/2,key2Size.width + 20,key2Size.height + 20);  
    if(rect.containsPoint(beginPos))//判断触点是否在身上！  
    {  
        auto endPos = touch->getPreviousLocationInView();//获取触摸的前一个位置  
        endPos = Director::getInstance()->convertToGL(endPos);//转换坐标
  
        auto offset = Point(beginPos-endPos);//获取offset，2.14是用ccpSub，3.0后直接用 - 号就可以  
        auto nextPos = Point( key2Pos + offset);  
        this->getChildByTag(9)->setPosition(nextPos);  
    }    
};

void  GameScene10::onTouchEndedBox(Touch *touch, Event* event){
	auto size = Director::getInstance()->getWinSize();  
	auto lastPos = touch->getLocationInView();  
    lastPos = Director::getInstance()->convertToGL(lastPos);  
       
    auto BoxPos = this->getChildByTag(10)->getPosition();//获取位置  
    auto BoxSize = this->getChildByTag(10)->getContentSize();//获取大小  
    //定制一个框框  
    auto rect = Rect(BoxPos.x - BoxSize.width/2,BoxPos.y - BoxSize.height/2,BoxSize.width + 20,BoxSize.height + 20);  //建立一个选中区域，女主如果拖动到这个框内就可以瞬移进来，反之是小三进来  
      
    MoveTo* moveTo_3;

  if(OpenBox==1){
    if(rect.containsPoint(lastPos))   {  
		moveTo_3 = MoveTo::create(0.1f,Point(size.width,size.height));  
	
	    this->getChildByTag(9)->runAction(moveTo_3);
		this->getChildByTag(11)->setVisible(true);
		this->getChildByTag(10)->setVisible(false);
		this->getChildByTag(9)->setVisible(false);
		this->getChildByTag(12)->setVisible(true);
		OpenBox=0;
		HaveHand=1;
	 }  else  {  
		auto size = Director::getInstance()->getWinSize();  
        moveTo_3 = MoveTo::create(0.1f,Point(size.width*0.23,size.height*0.75));  
        this->getChildByTag(9)->runAction(moveTo_3);
 }  
  }

};


bool GameScene10::onTouchBeganHole(Touch *touch, Event* event){
	 return true;
};

void GameScene10::onTouchMovedHole(Touch *touch, Event* event){
	auto beginPos = touch->getLocationInView();//获得触摸位置  
    beginPos = Director::getInstance()->convertToGL(beginPos);//坐标转换  
  
    auto handPos = this->getChildByTag(12)->getPosition();//获取位置  
    auto handSize = this->getChildByTag(12)->getContentSize();//获取大小  
    //定制一个框框  
    auto rect = Rect(handPos.x - handSize.width/2,handPos.y - handSize.height/2,handSize.width + 20,handSize.height + 10);  
    if(rect.containsPoint(beginPos))//判断触点是否在身上！  
    {  
        auto endPos = touch->getPreviousLocationInView();//获取触摸的前一个位置  
        endPos = Director::getInstance()->convertToGL(endPos);//转换坐标
  
        auto offset = Point(beginPos-endPos);//获取offset，2.14是用ccpSub，3.0后直接用 - 号就可以  
        auto nextPos = Point( handPos + offset);  
        this->getChildByTag(12)->setPosition(nextPos);  
    }    
};

void GameScene10::onTouchEndedHole(Touch *touch, Event* event){
	auto size = Director::getInstance()->getWinSize();  
	auto lastPos = touch->getLocationInView();  
    lastPos = Director::getInstance()->convertToGL(lastPos);  
       
    auto holePos = this->getChildByTag(13)->getPosition();//获取位置  
    auto holeSize = this->getChildByTag(13)->getContentSize();//获取大小  
    //定制一个框框  
    auto rect = Rect(holePos.x - holeSize.width/2,holePos.y - holeSize.height/2,holeSize.width + 25,holeSize.height + 25);  //建立一个选中区域，女主如果拖动到这个框内就可以瞬移进来，反之是小三进来  
      
    MoveTo* moveTo_4;

	if(HaveHand==1){
    if(rect.containsPoint(lastPos))   {  
		moveTo_4= MoveTo::create(0.1f,Point(size.width,size.height));  
	
	    this->getChildByTag(12)->runAction(moveTo_4);
		this->getChildByTag(12)->setVisible(false);
		this->getChildByTag(14)->setVisible(true);
		this->getChildByTag(14)->setRotation(180);
		this->getChildByTag(14)->runAction(Sequence::create(RotateTo::create(1.0f,0),CallFunc::create(this,callfunc_selector(GameScene10::success)),NULL));
		HaveHand=0;
	 }  else  {  
		auto size = Director::getInstance()->getWinSize();  
        moveTo_4 = MoveTo::create(0.1f,Point(size.width*0.23,size.height*0.57));  
        this->getChildByTag(12)->runAction(moveTo_4);
 }  
  }
};

void GameScene10::update(float dt)
{
	long offset = clock()-startTime;

	timerLabel->setString(StringUtils::format("%g",((double)offset)/1000000));

	if((((double)offset)/1000000>60)){
		//this->stopTimer();
		this->lose();
	
	}
}

//开始计时
void GameScene10::startTimer()
{
	if(!timeRunning)
	{
        this->scheduleUpdate();
		startTime = clock();
		//timeRunning = true;
	}
}

//结束计时
void GameScene10::stopTimer()
{
	if(timeRunning)
	{
		unscheduleUpdate();
		timeRunning = false;
	}
}

void GameScene10::success(){
	uiLayer->Success(3);
}

void GameScene10::lose(){
	uiLayer->Lose();
}

void GameScene10::restart(){
	Director::getInstance()->replaceScene(GameScene10::createScene());
	Director::getInstance()->resume();
}

void GameScene10::nextLevel(){
    Director::getInstance()->replaceScene(GameScene11::createScene());
    
}