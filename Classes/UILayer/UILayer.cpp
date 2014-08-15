#include "UILayer.h"
#define MENUTAG 30

bool UILayer::init()
{
	//获取屏幕大小
	Size winSize = Director::getInstance()->getWinSize();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    Point Origin = Director::getInstance()->getVisibleOrigin();
   
	//加载plist资源
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("ui_common.plist", "ui_common.png");
	//暂停按钮
	auto btnPause = MenuItemImage::create(); 
	btnPause->setNormalSpriteFrame(cache->getSpriteFrameByName("common_btn_pause.png"));
	//btnPause->setSelectedSpriteFrame(cache->getSpriteFrameByName("common_btn_pause.png"));
	btnPause->setCallback(CC_CALLBACK_1(UILayer::btnPauseCallBack, this));
    btnPause->setAnchorPoint(Point(0,1));
	btnPause->setPosition(Origin+Point(20, visibleSize.height-20));
	//提示按钮
	auto btnTip = MenuItemImage::create();
	btnTip->setNormalSpriteFrame(cache->getSpriteFrameByName("common_btn_tip.png"));
	btnTip->setCallback(CC_CALLBACK_1(UILayer::btnTipCallBack, this));
    btnTip->setAnchorPoint(Point::ANCHOR_TOP_LEFT);
	btnTip->setPosition(Origin+Point(140, visibleSize.height - 20));
	//体力按钮
	auto btn = MenuItemImage::create();
	btn->setNormalSpriteFrame(cache->getSpriteFrameByName("common_btn.png"));
	btn->setCallback(CC_CALLBACK_1(UILayer::btnCallBack, this));
    btn->setAnchorPoint(Point::ANCHOR_TOP_RIGHT);
	btn->setPosition(Origin+Point(visibleSize.width-120, visibleSize.height - 20));
	//求助按钮
	auto btnHelp = MenuItemImage::create();
	btnHelp->setNormalSpriteFrame(cache->getSpriteFrameByName("common_btn_help.png"));
	btnHelp->setCallback(CC_CALLBACK_1(UILayer::btnHelpCallBack, this));
    btnHelp->setAnchorPoint(Point::ANCHOR_TOP_RIGHT);
	btnHelp->setPosition(Origin+Point(visibleSize.width-20, visibleSize.height - 20));
    
    log("%f",visibleSize.width);

	//加入菜单
	auto menu = Menu::create(btnPause, btnTip, btn, btnHelp, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 10, MENUTAG);

	//初始化各种Layer
	pauseLayer = PauseLayer::create();
	this->addChild(pauseLayer);
	shareLayer = ShareLayer::create();
	this->addChild(shareLayer);

	return true;
}

void UILayer::btnPauseCallBack(Ref* pSender)
{
	pauseLayer->pauseGame(this);
}

void UILayer::btnTipCallBack(Ref* pSender)
{
	MessageBox("tipCallBack", "tipCallBack");
}

void UILayer::btnCallBack(Ref* pSender)
{
	MessageBox("CallBack", "CallBack");
}

void UILayer::btnHelpCallBack(Ref* pSender)
{
	shareLayer->shareGame(this);
}

UILayer::UILayer(void)
{
}


UILayer::~UILayer(void)
{
}
