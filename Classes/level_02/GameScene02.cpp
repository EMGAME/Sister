//
//  GameScene02.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#include "GameScene02.h"
#include "GameScene04.h"
#include"../UILayer/UILayer.h"
#include "SuccessScene.h"
#include "LoseScene.h"

GameScene02::GameScene02(){}
GameScene02::~GameScene02(){};

Scene* GameScene02::createScene(){
    auto scene = Scene::create();
	auto layer = GameScene02::create();
	scene->addChild(layer);
    
	return scene;
}

bool GameScene02::init(){
    if (!Layer::init()) {
        return false;
    }
    auto winSize = Director::getInstance()->getWinSize();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    
//    auto uiLayer = UILayer::create();
//    uiLayer->setPosition(Point::ZERO);
//    this->addChild(uiLayer);
    //bg粒子
    
    auto particleBg = ParticleSystemQuad::create("new/bg_partical.plist");
    particleBg->retain();
    particleBg->setPosition(Point(winSize.width/2,winSize.height));
    this->addChild(particleBg,20);
    
    m_time = LabelBMFont::create("5.00", "new/daojishi.fnt");
    m_time->setPosition(origin+Point(visibleSize.width-200, visibleSize.height-100));
    this->addChild(m_time);
    time_nm = 5.00;

    this->scheduleUpdate();
    
    
    
    //加载初始文字
    boss = Sprite::create("new/text_duo.png");
    boss->setAnchorPoint(Point::ANCHOR_MIDDLE_BOTTOM);
    boss->setPosition(Point(winSize.width/2,winSize.height+100));
    this->addChild(boss,30);

        auto pSequence2 = Sequence::create(CallFunc::create(
                                                            [&](){
                                                               auto bossAct = MoveTo::create(0.5f, Point(Director::getInstance()->getVisibleSize().width/2, 680));
                                                               auto bossEase = EaseBackInOut::create(EaseBackInOut::create(bossAct));
                                                                boss->runAction(bossEase);}),
                                           DelayTime::create(1.0f),
                                           CallFunc::create(
                                                            [&](){
                                                                boss->runAction(MoveTo::create(0.5f,
                                                                                               Point(Director::getInstance()->getVisibleSize().width/2, Director::getInstance()->getVisibleSize().height+200)));
                                                            }),NULL);
        this->runAction(pSequence2);
    return true;
}

void GameScene02::nextLevel(){
    Director::getInstance()->replaceScene(GameScene04::createScene());
}

void GameScene02::update(float time){
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
        Director::getInstance()->replaceScene(LoseScene::createScene(level02));
    }
}
void GameScene02::restart(){
    Director::getInstance()->replaceScene(GameScene02::createScene());
}

