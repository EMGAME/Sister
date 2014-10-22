//
//  LoseScene.cpp
//  Sister
//
//  Created by 风飞逸 on 14-9-18.
//
//

#include "../StartScene.h"
#include "LoseScene.h"
#include "PowerManager.h"



LoseScene::LoseScene(){
    mNum = level01;
    //血量减1
    PowerManager::getInstance()->subPower(1);
}
LoseScene::~LoseScene(){
    _emitter->release();
}

Scene* LoseScene::createScene(LevelNum pNum){
    auto layer = LoseScene::create(pNum);
    auto scene = Scene::create();
    scene->addChild(layer);
    return scene;
}

LoseScene* LoseScene::create(LevelNum pNum){
    LoseScene *pRet = new LoseScene();
    
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

bool LoseScene::init(LevelNum pNum){
    if (!Layer::init()) {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto winSize = Director::getInstance()->getWinSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    
    auto bg = Sprite::create("new/lose_bg.jpg");
    bg->setAnchorPoint(Point::ZERO);
    bg->setPosition(Point::ZERO);
    this->addChild(bg,0);

    
    //关卡自动跳转
    auto mlevelManager = LevelManager::create();
    mNum = pNum;
    
    auto sequence = Sequence::create(DelayTime::create(4.0f),
                                     CallFunc::create(
                                                      [&](){
                                                          log("%d",mNum);
                                                          mlevelManager->replaceScene(mNum);}),NULL);
    
    
    
    this->runAction(sequence);
    
    
    //加载大叔
    ArmatureDataManager::getInstance()->addArmatureFileInfo("paopao03/NewAnimation.ExportJson");
    
    
    auto OldUncle = Armature::create( "NewAnimation");
    OldUncle->setPosition(Point(230,40));
    OldUncle->setAnchorPoint(Point::ZERO);
    OldUncle->getAnimation()->play("Animation1");
    this->addChild(OldUncle,30);

    
    
    //毁灭动画
    auto des01 = ScaleTo::create(0.8f, 2.0f);
    auto des02 = RotateTo::create(0.05f, 15);
    auto des03 = RotateTo::create(0.05f, -15);
    auto desRotate = Repeat::create(Sequence::create(des02,des03, NULL),10);
    auto desSeq = Sequence::create(des01,desRotate,NULL);
    
    //毁灭动画爆炸粒子预加载
    _emitter = ParticleSystemQuad::create("new/exp.plist");
    _emitter->retain();
    
    //创建玫瑰动画
    auto mg_act01 = RotateTo::create(0.5f, 45);
    auto mg_act02 = RotateTo::create(0.5f, -45);
    auto mg_act = Sequence::create(mg_act01,mg_act02, NULL);
    auto act = RepeatForever::create(mg_act);
    
    ArmatureDataManager::getInstance()->addArmatureFileInfo("paopao03/paopao.ExportJson");
    
    
    meigui01 = Armature::create( "paopao");
    meigui01->setPosition(origin+Point(visibleSize.width-260, visibleSize.height-50));
    //meigui01->setAnchorPoint(Point::ANCHOR_TOP_RIGHT);
    meigui01->getAnimation()->play("normal");
    this->addChild(meigui01,30);
    
    meigui02 = Armature::create( "paopao");
    meigui02->setPosition(origin+Point(visibleSize.width-190, visibleSize.height-50));
    //meigui02->setAnchorPoint(Point::ANCHOR_TOP_RIGHT);
    meigui02->getAnimation()->play("normal");
    this->addChild(meigui02,30);
    
    meigui03 = Armature::create( "paopao");
    meigui03->setPosition(origin+Point(visibleSize.width-120, visibleSize.height-50));
    //meigui03->setAnchorPoint(Point::ANCHOR_TOP_RIGHT);
    meigui03->getAnimation()->play("normal");
    this->addChild(meigui03,30);
    
    meigui04 = Armature::create( "paopao");
    meigui04->setPosition(origin+Point(visibleSize.width-50, visibleSize.height-50));
    //meigui04->setAnchorPoint(Point::ANCHOR_TOP_RIGHT);
    meigui04->getAnimation()->play("normal");
    this->addChild(meigui04,30);

    
    log("powermanager = %d",PowerManager::getInstance()->readPower());
    

    
    switch (PowerManager::getInstance()->readPower()) {
        case 3:
            meigui01->setVisible(true);
            
            meigui01->runAction(Sequence::create(desSeq->clone(),
                                                 CallFunc::create([&](){meigui01->setVisible(false);
                                                                      _emitter->setPosition(meigui01->getPosition());
                                                                      this->addChild(_emitter, 10);
                                                                      }), NULL));
            
            meigui02->setVisible(true);
            meigui03->setVisible(true);
            meigui04->setVisible(true);
            
            if (pNum == finalLevel) {
                initText(LEVEL_TYPE_OVER);
            }else{
                initText(LEVEL_TYPE_NEXT);
            }

            break;
        case 2:
            meigui01->setVisible(false);
            meigui02->setVisible(true);
            meigui02->runAction(Sequence::create(desSeq->clone(),
                                                 CallFunc::create([&](){meigui02->setVisible(false);
                                                 _emitter->setPosition(meigui02->getPosition());
                                                 this->addChild(_emitter, 10);
                                                                        }),
                                                 NULL));
            meigui03->setVisible(true);
            meigui04->setVisible(true);
            
            if (pNum == finalLevel) {
                initText(LEVEL_TYPE_OVER);
            }else{
                initText(LEVEL_TYPE_NEXT);
            }
            
            break;
        case 1:
            meigui01->setVisible(false);
            meigui02->setVisible(false);
            meigui03->setVisible(true);
            meigui03->runAction(Sequence::create(desSeq->clone(),
                                                 CallFunc::create([&](){meigui03->setVisible(false);
                                                 _emitter->setPosition(meigui03->getPosition());
                                                 this->addChild(_emitter, 10);}),
                                                 
                                                 NULL));
            meigui04->setVisible(true);
            
            if (pNum == finalLevel) {
                initText(LEVEL_TYPE_OVER);
            }else{
                initText(LEVEL_TYPE_NEXT);
            }
            
            break;
        case 0:
            meigui01->setVisible(false);
            meigui02->setVisible(false);
            meigui03->setVisible(false);
            meigui04->setVisible(true);
            meigui04->runAction(Sequence::create(desSeq->clone(),
                                                 CallFunc::create(
                                                                  [&](){meigui04->setVisible(false);
                                                                      _emitter->setPosition(meigui04->getPosition());
                                                                      this->addChild(_emitter, 10);}),
                                                 DelayTime::create(2.0f),
                                                 CallFunc::create(
                                                                  [&](){Director::getInstance()->replaceScene(StartScene::createScene());
            
                                                                  }),NULL));
            initText(LEVEL_TYPE_OVER);
            
            break;
    }
    
    return true;

}
void LoseScene::gameOver(){
    log("gameover");
}

void LoseScene::initText(LEVEL_TYPE pLevelType){
    auto winSize = Director::getInstance()->getWinSize();
    
    next = Sprite::create("new/text_lose.png");
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
    
    over = Sprite::create("new/text_over.png");
    over->setAnchorPoint(Point::ANCHOR_MIDDLE_BOTTOM);
    over->setPosition(Point(winSize.width/2,winSize.height+100));
    this->addChild(over,30);
    
    if (pLevelType == LEVEL_TYPE_BOSS) {
        auto pSequence2 = Sequence::create(DelayTime::create(1.0f),
                                           CallFunc::create(
                                                            [&](){
                                                                bossAct = MoveTo::create(0.5f, Point(Director::getInstance()->getVisibleSize().width/2, 680));
                                                                bossEase = EaseBackInOut::create(EaseBackInOut::create(bossAct));
                                                                next->runAction(bossEase);}),
                                           DelayTime::create(1.0f),
                                           CallFunc::create(
                                                            [&](){
                                                                readyAct = MoveTo::create(0.5f, Point(Director::getInstance()->getVisibleSize().width/2,420));
                                                                readyEase = EaseBackInOut::create(EaseBackInOut::create(readyAct));
                                                                ready->runAction(readyEase);
                                                            }),
                                           DelayTime::create(1.0f),
                                           CallFunc::create(
                                                            [&](){
                                                                startAct = MoveTo::create(0.5f, Point(Director::getInstance()->getVisibleSize().width/2, 170));
                                                                startEase = EaseBackInOut::create(EaseBackInOut::create(startAct));
                                                                start->runAction(startEase);
                                                            }),
                                           NULL);
        this->runAction(pSequence2);
        
    }else if (pLevelType == LEVEL_TYPE_NEXT){
        auto pSequence = Sequence::create(DelayTime::create(1.0f),
                                          CallFunc::create(
                                                           [&](){
                                                               nextAct = MoveTo::create(0.5f, Point(Director::getInstance()->getVisibleSize().width/2, 680));
                                                               nextEase = EaseBackInOut::create(EaseBackInOut::create(nextAct));
                                                               next->runAction(nextEase);}),
                                          DelayTime::create(1.0f),
                                          CallFunc::create(
                                                           [&](){
                                                               readyAct = MoveTo::create(0.5f, Point(Director::getInstance()->getVisibleSize().width/2,420));
                                                               readyEase = EaseBackInOut::create(EaseBackInOut::create(readyAct));
                                                               ready->runAction(readyEase);
                                                           }),
                                          DelayTime::create(1.0f),
                                          CallFunc::create(
                                                           [&](){
                                                               startAct = MoveTo::create(0.5f, Point(Director::getInstance()->getVisibleSize().width/2, 170));
                                                               startEase = EaseBackInOut::create(EaseBackInOut::create(startAct));
                                                               start->runAction(startEase);
                                                           }),
                                          NULL);
        this->runAction(pSequence);
    }else if(pLevelType == LEVEL_TYPE_OVER){
        auto pSequence = Sequence::create(DelayTime::create(1.0f),
                                          CallFunc::create(
                                                           [&](){
                                                               overAct = MoveTo::create(0.5f, Point(Director::getInstance()->getVisibleSize().width/2, 420));
                                                               overEase = EaseBackInOut::create(EaseBackInOut::create(overAct));
                                                               over->runAction(overEase);}),
                                          NULL);
        this->runAction(pSequence);
    }
}

