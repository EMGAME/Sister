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

bool SuccessLayer::init(Ref* pSender,std::string passTip){
    if (!Layer::init()) {
        return false;
    }
    
    uiLayer = (Layer*)pSender;
    
    auto winSize = Director::getInstance()->getWinSize();

    controllNode = Node::create();
    controllNode->setPosition(Point::ZERO);
    this->addChild(controllNode,100);
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ui_result.plist");
    
    auto bg = Sprite::createWithSpriteFrameName("result_bg_pass.png");
    bg->setPosition(winSize.width/2,winSize.height/2+230);
    controllNode->addChild(bg,1);
    
    auto fg_fail = Sprite::createWithSpriteFrameName("result_fg_pass.png");
    fg_fail->setPosition(winSize.width/2,winSize.height/2+150);
    controllNode->addChild(fg_fail,1);
    
    auto frame = Sprite::createWithSpriteFrameName("result_frame.png");
    frame->setPosition(winSize.width/2,winSize.height/2+200);
    controllNode->addChild(frame,5);
    
    auto bottomBg = Sprite::createWithSpriteFrameName("result_bottom_bg.png");
    bottomBg->setPosition(Point(winSize.width/2, winSize.height/2-100));
    controllNode->addChild(bottomBg,0);
    
    auto lose = Sprite::createWithSpriteFrameName("result_win.png");
    lose->setAnchorPoint(Point::ANCHOR_MIDDLE_TOP);
    lose->setPosition(winSize.width/2,winSize.height/2+450);
    controllNode->addChild(lose,6);
    
    //相关摁钮
    auto nextBtn = MenuItemSprite::create(Sprite::createWithSpriteFrameName("result_btn_next.png"),
                                          Sprite::createWithSpriteFrameName("result_btn_next.png"),
                                          CC_CALLBACK_0(SuccessLayer::nextCallback, this));
    nextBtn->setAnchorPoint(Point::ANCHOR_TOP_RIGHT);
    nextBtn->setPosition(Point(winSize.width/2-90,winSize.height/2-40));
   // controllNode->addChild(nextBtn,1);
    
    auto restartBtn = MenuItemSprite::create(Sprite::createWithSpriteFrameName("result_btn_replay.png"),
                                             Sprite::createWithSpriteFrameName("result_btn_replay.png"),
                                             CC_CALLBACK_0(SuccessLayer::restartCallBack, this));
    restartBtn->setAnchorPoint(Point::ANCHOR_TOP_LEFT);
    restartBtn->setPosition(Point(winSize.width/2+90,winSize.height/2-40));
   // controllNode->addChild(restartBtn,1);
    
    auto shareBtn = MenuItemSprite::create(Sprite::createWithSpriteFrameName("result_btn_share.png"),
                                           Sprite::createWithSpriteFrameName("result_btn_share.png"),
                                           CC_CALLBACK_0(SuccessLayer::shareCallBack, this));
    shareBtn->setAnchorPoint(Point::ANCHOR_MIDDLE_TOP);
    shareBtn->setPosition(Point(winSize.width/2,winSize.height/2-40));
   // controllNode->addChild(shareBtn,1);
    
    auto m_Menu = Menu::create(nextBtn,shareBtn,restartBtn, NULL);
    m_Menu->setPosition(Point::ZERO);
    controllNode->addChild(m_Menu,4);
    
    auto arrow = Sprite::createWithSpriteFrameName("result_arrow.png");
    arrow->setAnchorPoint(Point::ANCHOR_MIDDLE_TOP);
    arrow->setPosition(Point(winSize.width/2-75,winSize.height/2-150));
    controllNode->addChild(arrow,4);
    
    auto m_string = LabelTTF::create(passTip, "", 25,Size(400,200));
    m_string->setAnchorPoint(Point::ANCHOR_MIDDLE_TOP);
    m_string ->setPosition(Point(winSize.width/2, winSize.height/2-200));
    controllNode->addChild(m_string,4);
    

//    auto starAction = RepeatForever::create(starSequence);
    
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

void SuccessLayer::nextCallback(){
//这个留空，为防止乱掉所有项目做完后再添加
}

void SuccessLayer::shareCallBack(){
    
}

void SuccessLayer::restartCallBack(){
    auto gameLayerNode = uiLayer->getParent();
	BaseLayer* baseLayer = (BaseLayer*)gameLayerNode;
    baseLayer->restart();
}

void SuccessLayer::pushLayer(Ref* pSender,int starNum,std::string passTip){
    

    auto scene = Scene::create();
    auto tipLayer = SuccessLayer::create(pSender,passTip);
    tipLayer->showStar(starNum);
    scene->addChild(tipLayer);
    Director::getInstance()->pushScene(scene);
    
    log("SuccessLayer::pushLayer");

}

SuccessLayer* SuccessLayer::create(Ref* pSender,std::string passTip)
{
    SuccessLayer *pRet = new SuccessLayer();
    if (pRet && pRet->init(pSender,passTip))
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