//
//  SuccessScene.cpp
//  Sister
//
//  Created by 风飞逸 on 14-9-18.
//
//
#include "../StartScene.h"
#include "SuccessScene.h"
#include "PowerManager.h"
#include "cocostudio/CocoStudio.h"

using namespace cocostudio;

//文字从天而降的时间
float tileShowTime = 0.5f;

SuccessScene::SuccessScene(){
    mNum = level01;
}
SuccessScene::~SuccessScene(){}
Scene* SuccessScene::createScene(LevelNum pNum){
    auto layer = SuccessScene::create(pNum);
    auto scene = Scene::create();
    scene->addChild(layer);
    return scene;
}

SuccessScene* SuccessScene::create(LevelNum pNum){
    SuccessScene *pRet = new SuccessScene();

    if (pRet && pRet->init(pNum))
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

bool SuccessScene::init(LevelNum pNum){
    if (!Layer::init()) {
        return false;
    }
    //mScene = pScene;

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Size winSize = Director::getInstance()->getWinSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    initText(LEVEL_TYPE_BOSS);

	auto bg2 = Sprite::create("new/01.jpg");
	bg2->setAnchorPoint(Point(0,0));
	bg2->setPosition(Point::ZERO);
	this->addChild(bg2,1);

    //bg粒子
    auto particleBg = ParticleSystemQuad::create("new/bg_partical.plist");
    particleBg->retain();
    particleBg->setPosition(Point(winSize.width/2,winSize.height ));
    this->addChild(particleBg,20);
    particleBg->release();
    
    Animation* animation = Animation::create();
	for (int i=1;i<10;i++)
	{
		char szName[100] = {0};
		sprintf(szName,"new/0%d.jpg",i);
		animation->addSpriteFrameWithFileName(szName);
	}
    
	animation->setDelayPerUnit(2.0f /24.0f);
	animation->setRestoreOriginalFrame(true);
    
	Animate* action = CCAnimate::create(animation);
    
	bg2->runAction(RepeatForever::create(action));
    auto mlevelManager = LevelManager::create();

    mNum = pNum;
    
    auto sequence = Sequence::create(DelayTime::create(4.0f),
                                     CallFunc::create([&](){
                                                          log("replaceNum = %d",pNum);
                                                          mlevelManager->replaceScene(mNum);
                                                            }),NULL);
    
    this->runAction(sequence);
    
    //创建玫瑰动画
    auto mg_act01 = RotateTo::create(0.5f, 45);
    auto mg_act02 = RotateTo::create(0.5f, -45);
    auto mg_act = Sequence::create(mg_act01,mg_act02, NULL);
    auto act = RepeatForever::create(mg_act);
    

    ArmatureDataManager::getInstance()->addArmatureFileInfo("paopao03/paopao.ExportJson");
    
    
    auto meigui01 = Armature::create( "paopao");
    meigui01->setPosition(origin+Point(visibleSize.width-220, visibleSize.height-10));
    meigui01->setAnchorPoint(Point::ANCHOR_TOP_RIGHT);
    meigui01->getAnimation()->play("normal");
    this->addChild(meigui01,30);
    
    auto meigui02 = Armature::create( "paopao");
    meigui02->setPosition(origin+Point(visibleSize.width-150, visibleSize.height-10));
    meigui02->setAnchorPoint(Point::ANCHOR_TOP_RIGHT);
    meigui02->getAnimation()->play("normal");
    this->addChild(meigui02,30);
    
    auto meigui03 = Armature::create( "paopao");
    meigui03->setPosition(origin+Point(visibleSize.width-80, visibleSize.height-10));
    meigui03->setAnchorPoint(Point::ANCHOR_TOP_RIGHT);
    meigui03->getAnimation()->play("normal");
    this->addChild(meigui03,30);
    
    auto meigui04 = Armature::create( "paopao");
    meigui04->setPosition(origin+Point(visibleSize.width-10, visibleSize.height-10));
    meigui04->setAnchorPoint(Point::ANCHOR_TOP_RIGHT);
    meigui04->getAnimation()->play("normal");
    this->addChild(meigui04,30);
    
    
    switch (PowerManager::getInstance()->readPower()) {
        case 4:
            meigui01->setVisible(true);
            meigui02->setVisible(true);
            meigui03->setVisible(true);
            meigui04->setVisible(true);

            break;
        case 3:
            meigui01->setVisible(false);
            meigui02->setVisible(true);
            meigui03->setVisible(true);
            meigui04->setVisible(true);

            break;
        case 2:
            meigui01->setVisible(false);
            meigui02->setVisible(false);
            meigui03->setVisible(true);
            meigui04->setVisible(true);
            break;
        case 1:
            meigui01->setVisible(false);
            meigui02->setVisible(false);
            meigui03->setVisible(false);
            meigui04->setVisible(true);
            break;
     }

    log("%d",PowerManager::getInstance()->readPower());
    
    
    //创建过关文字
    
    
    return true;
}

void SuccessScene::initText(LEVEL_TYPE pLevelType){
    auto winSize = Director::getInstance()->getWinSize();
    
    next = Sprite::create("new/text_next.png");
    next->setAnchorPoint(Point::ANCHOR_MIDDLE_BOTTOM);
    next->setPosition(Point(winSize.width/2,winSize.height+100));
    this->addChild(next,30);
    
    boss = Sprite::create("new/text_boss.png");
    boss->setAnchorPoint(Point::ANCHOR_MIDDLE_BOTTOM);
    boss->setPosition(Point(winSize.width/2,winSize.height+100));
    this->addChild(boss,30);
    
    ready = Sprite::create("new/text_ready.png");
    ready->setAnchorPoint(Point::ANCHOR_MIDDLE_BOTTOM);
    ready->setPosition(Point(winSize.width/2,winSize.height+100));
    this->addChild(ready,30);
    
    start = Sprite::create("new/text_start.png");
    start->setAnchorPoint(Point::ANCHOR_MIDDLE_BOTTOM);
    start->setPosition(Point(winSize.width/2,winSize.height+100));
    this->addChild(start,30);
    
    bossAct = MoveTo::create(1.0f, Point(winSize.width/2, 680));
    
    bossEase = EaseBackInOut::create(bossAct);
    if (pLevelType == LEVEL_TYPE_BOSS) {
        auto pSequence2 = Sequence::create(DelayTime::create(1.0f),
                                           CallFunc::create(
                                                            [&](){
                                                                bossAct = MoveTo::create(tileShowTime, Point(Director::getInstance()->getVisibleSize().width/2, 680));
                                                                bossEase = EaseBackInOut::create(bossAct);
                                                                next->runAction(bossEase);}),
                                           DelayTime::create(1.0f),
                                           CallFunc::create(
                                                            [&](){
                                                                readyAct = MoveTo::create(tileShowTime, Point(Director::getInstance()->getVisibleSize().width/2,420));
                                                                readyEase = EaseBackInOut::create(readyAct);
                                                                ready->runAction(readyEase);
                                                            }),
                                           DelayTime::create(1.0f),
                                           CallFunc::create(
                                                            [&](){
                                                                startAct = MoveTo::create(tileShowTime, Point(Director::getInstance()->getVisibleSize().width/2, 170));
                                                                startEase = EaseBackInOut::create(startAct);
                                                                start->runAction(startEase);
                                                            }),
                                           NULL);
        this->runAction(pSequence2);

    }else if (pLevelType == LEVEL_TYPE_NEXT){
            auto pSequence = Sequence::create(DelayTime::create(1.0f),
                                              CallFunc::create(
                                                               [&](){
                                                                   nextAct = MoveTo::create(tileShowTime, Point(Director::getInstance()->getVisibleSize().width/2, 680));
                                                                   nextEase = EaseBackInOut::create(nextAct);
                                                                   next->runAction(nextEase);}),
                                              DelayTime::create(1.0f),
                                              CallFunc::create(
                                                               [&](){
                                                                   readyAct = MoveTo::create(tileShowTime, Point(Director::getInstance()->getVisibleSize().width/2,420));
                                                                   readyEase = EaseBackInOut::create(readyAct);
                                                                   ready->runAction(readyEase);
                                                               }),
                                              DelayTime::   create(1.0f),
                                              CallFunc::create(
                                                               [&](){
                                                                   startAct = MoveTo::create(tileShowTime, Point(Director::getInstance()->getVisibleSize().width/2, 170));
                                                                   startEase = EaseBackInOut::create(startAct);
                                                                   start->runAction(startEase);
                                                               }),
                                              NULL);
            this->runAction(pSequence);
    }
}
