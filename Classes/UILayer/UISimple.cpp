
#include "UISimple.h"
#define MENUTAG 30

bool UISimple::init()
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
	btnPause->setCallback(CC_CALLBACK_1(UISimple::btnPauseCallBack, this));
    btnPause->setAnchorPoint(Point(0,1));
	btnPause->setPosition(Origin+Point(20, visibleSize.height-20));
    
	//加入菜单
	auto menu = Menu::create(btnPause, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 10, MENUTAG);
    
    
    //计时特效
    m_time = LabelBMFont::create("5.00", "new/daojishi.fnt");
    m_time->setPosition(Origin+Point(visibleSize.width-200, visibleSize.height-100));
    this->addChild(m_time);
    time_nm = 5.00;
    
    this->scheduleUpdate();
    
    
	return true;
}

void UISimple::btnPauseCallBack(Ref* pSender)
{
    PauseLayer::pauseGame(this);
}


UISimple::UISimple(void)
{
}


UISimple::~UISimple(void)
{
}


void UISimple::update(float time){
    time_nm -= 0.013;
    m_time->setString(__String::createWithFormat("%.2f",time_nm)->getCString());
    auto timeOut1 = ScaleTo::create(0.1, 2.0);
    auto timeOut2 = ScaleTo::create(0.1, 1.0);
    auto timeOut = Sequence::create(timeOut1,timeOut2, NULL);
    if (time_nm >= 4.9 && time_nm<= 5.1) {
        m_time->runAction(timeOut);
    }else if (time_nm >= 3.9 && time_nm<= 4.1) {
        m_time->runAction(timeOut);
    }else if (time_nm >= 2.9 && time_nm <= 3.1) {
        m_time->runAction(timeOut);
    }else if(time_nm >= 1.9 && time_nm <= 2.1){
        m_time->runAction(timeOut);
    }else if(time_nm >= 0.9 && time_nm <= 1.1){
        m_time->runAction(timeOut);
    }else if (time_nm<=0){
        m_time->setString(__String::create("0.00")->getCString());
            this->unscheduleUpdate();
            auto gameLayerNode = this->getParent();
            //log("uilayer's tag:%d", uiLayer->getTag());
            BaseLayer* baseLayer = (BaseLayer*)gameLayerNode;
            baseLayer->lose();
        }

}