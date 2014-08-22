#include "HelloWorldScene.h"


USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    
    auto layer = HelloWorld::create();

    scene->addChild(layer);

	//layer->bglayer = backgroundLayer;

    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);


	//²âÊÔµã»÷ÊÂ¼þ
	auto pic = Sprite::create("BlueBall.png");
	pic->setPosition(visibleSize.width * 0.8f , visibleSize.height * 0.5f);
	//pic->setVisible(true);
	this->addChild(pic, 3, 10);

	auto button = MenuItemImage::create("play_nor.png",
		                                  "play_pre.png",
										  CC_CALLBACK_0(HelloWorld::show,this) );
	button->setPosition(visibleSize.width *0.3f,visibleSize.height * 0.5f);
    
	auto button1 = Menu::create(button, NULL);
	button1->setPosition(Point::ZERO);
	this->addChild(button1, 2);

	

	auto aaa = Sprite::create("l12_bg.png");
	aaa->setAnchorPoint(Point(0,0));
	aaa->setPosition(Point::ZERO);
	this->addChild(aaa);

	//±³¾°²ã
	//auto backgroundLayer = Bglayer::create();
	//this->addChild(backgroundLayer,0);
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::show(){

	this->getChildByTag(10)->setVisible(false);

}




