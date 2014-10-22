//
//  SuccessLayer.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-25.
//
//
#include "SuccessLayer.h"
#include "UILayer.h"

#define BGTAG 10


SuccessLayer::SuccessLayer(){}
SuccessLayer::~SuccessLayer(){}

bool SuccessLayer::init(Ref* pSender){
    if (!Layer::init()) {
        return false;
    }
    
    uiLayer = (Layer*)pSender;
    
    auto winSize = Director::getInstance()->getWinSize();

    controllNode = Node::create();
    controllNode->setPosition(Point::ZERO);
    this->addChild(controllNode,100);
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ui_result.plist");
    
    auto bg = Sprite::create("UI/ui_success_bg.png");
    bg->setPosition(winSize.width/2,winSize.height/2);
    controllNode->addChild(bg,1);
    
    //相关摁钮

    Button* nextBtn = Button::create();
    nextBtn->loadTextureNormal("UI/ui_btn_next.png",UI_TEX_TYPE_LOCAL);
    nextBtn->setTouchEnabled(true);
    nextBtn->addTouchEventListener(this, toucheventselector(SuccessLayer::nextCallback));
    //nextBtn->setAnchorPoint(Point::ZERO);
    nextBtn->setPosition(Point(593,228));
    controllNode->addChild(nextBtn,1);
    
    Button* returnBtn = Button::create();
    returnBtn->loadTextureNormal("UI/ui_btn_home.png",UI_TEX_TYPE_LOCAL);
    returnBtn->setTouchEnabled(true);
    returnBtn->addTouchEventListener(this, toucheventselector(SuccessLayer::homeCallBack));
    //returnBtn->setAnchorPoint(Point::ZERO);
    returnBtn->setPosition(Point(174,228));
    controllNode->addChild(returnBtn,1);
    
    Button* shareBtn = Button::create();
    shareBtn->loadTextureNormal("UI/ui_btn_share.png",UI_TEX_TYPE_LOCAL);
    shareBtn->setTouchEnabled(true);
    shareBtn->addTouchEventListener(this, toucheventselector(SuccessLayer::shareCallBack));
    //shareBtn->setAnchorPoint(Point::ZERO);
    shareBtn->setPosition(Point(389,192));
    controllNode->addChild(shareBtn,1);
    
//    auto arrow = Sprite::createWithSpriteFrameName("result_arrow.png");
//    arrow->setAnchorPoint(Point::ANCHOR_MIDDLE_TOP);
//    arrow->setPosition(Point(winSize.width/2-75,winSize.height/2-150));
//    controllNode->addChild(arrow,4);
    
    
    star1 = Sprite::createWithSpriteFrameName("result_star.png");
    star1->setPosition(winSize.width/2-120, winSize.height/2);
   // star1->runAction(starAction);
    star1->setVisible(false);
    controllNode->addChild(star1,6);
    
    star2 = Sprite::createWithSpriteFrameName("result_star.png");
    star2->setPosition(winSize.width/2, winSize.height/2);
   // star2->runAction(starAction);
    star2->setVisible(false);
    controllNode->addChild(star2,6);
    
    star3 = Sprite::createWithSpriteFrameName("result_star.png");
    star3->setPosition(winSize.width/2+120, winSize.height/2);
   // star3->runAction(starAction);
    star3->setVisible(false);
    controllNode->addChild(star3,6);
 
    controllNode->setPosition(winSize.width,winSize.height);
    
	//截图
	RenderTexture* renderTexture = RenderTexture::create(winSize.width, winSize.height);
	renderTexture->retain();
	Scene *runningScene = CCDirector::getInstance()->getRunningScene();
	renderTexture->begin();
	runningScene->visit();
	renderTexture->end();
	//下面这句用来测试截图是否成功，经测试成功
	//renderTexture->saveToFile("123.png", Image::Format::PNG);
    
	//将截到的图做背景
	Sprite *_spr = Sprite::createWithTexture(renderTexture->getSprite()->getTexture());
	_spr->setPosition(Point(winSize.width / 2, winSize.height / 2));
	_spr->setFlippedY(true);  //翻转
	_spr->setColor(Color3B::GRAY);  //颜色（变灰暗）
	this->addChild(_spr, 0, BGTAG);
    
    auto moveTo = MoveTo::create(0.5f, Point::ZERO);
    
	auto easeBackInOut = EaseBackInOut::create(moveTo);
    controllNode->runAction(easeBackInOut);
    
    return true;
}

void SuccessLayer::setString(std::string m_string){
    setTip(m_string);
}

void SuccessLayer::nextCallback(Ref* pSender,TouchEventType type){
    switch (type) {
            
        case  cocos2d::ui::TOUCH_EVENT_ENDED:
            
        {    auto gameLayerNode = uiLayer->getParent();
            BaseLayer* baseLayer = (BaseLayer*)gameLayerNode;
            baseLayer->nextLevel();
            
            break;}
            
        default:
            break;
    }
}

void SuccessLayer::shareCallBack(Ref* pSender,TouchEventType type){
    switch (type) {
            
        case  cocos2d::ui::TOUCH_EVENT_ENDED:
            
        {
            
            break;}
            
        default:
            break;
    }
}

void SuccessLayer::homeCallBack(Ref* pSender,TouchEventType type){
    switch (type) {
            
        case  cocos2d::ui::TOUCH_EVENT_ENDED:
            
        {    auto gameLayerNode = uiLayer->getParent();
            BaseLayer* baseLayer = (BaseLayer*)gameLayerNode;
            baseLayer->restart();
            
            break;}
            
        default:
            break;
    }
}

void SuccessLayer::pushLayer(Ref* pSender,int starNum){
    

    auto scene = Scene::create();
    auto tipLayer = SuccessLayer::create(pSender);
    tipLayer->showStar(starNum);
    scene->addChild(tipLayer);
    Director::getInstance()->pushScene(scene);
    
}

SuccessLayer* SuccessLayer::create(Ref* pSender)
{
    SuccessLayer *pRet = new SuccessLayer();
    if (pRet && pRet->init(pSender))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}
void SuccessLayer::showStar(int starNum){
    if ((starNum < 1 || starNum >3)) {log("你妹啊！星星数范围1~3"); return;}
    switch (starNum) {
        case 1:
            star1->setVisible(true);
            break;
        case 2:
            star1->setVisible(true);
            star2->setVisible(true);
            break;
        case 3:
            star1->setVisible(true);
            star2->setVisible(true);
            star3->setVisible(true);
            break;
    }
}