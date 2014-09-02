//
//  GameScene01.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#include "GameScene01.h"
#include "../UILayer/UILayer.h"
USING_NS_CC;

GameScene01::GameScene01(){}
GameScene01::~GameScene01(){}

Scene* GameScene01::createScene(){
    auto scene = Scene::create();
    auto layer = GameScene01::create();
    scene->addChild(layer,0,100);
    return scene;
}

bool GameScene01::init(){
    if (!Layer::init()) {
        return false;
    }
    auto winSize = Director::getInstance()->getWinSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    auto bg = Sprite::create("level_01/l1bg.png");
    bg->setPosition(winSize.width/2,winSize.height/2);
    this->addChild(bg,1);

    m_ui = UILayer::create();
    m_ui->setPosition(Point::ZERO);
    this->addChild(m_ui,10);
    
   
    m_sister = Sprite::create("level_01/sister.png");
    m_sister->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
    m_sister->setPosition(Point(206, 175));
    this->addChild(m_sister,1);
    
    m_zhuantou = Sprite::create("level_01/zhuantou.png");
    m_zhuantou->setAnchorPoint(Point::ANCHOR_MIDDLE_RIGHT);
    m_zhuantou->setPosition(Point(544,130));
    this->addChild(m_zhuantou,1);
    
    m_jinggai = Sprite::create("level_01/jinggai.png");
    m_jinggai->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
    m_jinggai->setPosition(Point(427,81));
    this->addChild(m_jinggai,2);
    
    m_ludeng = Sprite::create("level_01/ludeng.png");
    m_ludeng->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
    m_ludeng->setPosition(Point(640,81));
    this->addChild(m_ludeng,2);
    

    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(true);
    
    listener1->onTouchBegan = [](Touch *pTouch,Event *pEvent){
        auto target = static_cast<Sprite* >(pEvent->getCurrentTarget());
        Point locationInNode = pTouch->getLocation();
        log("touchx=%f,touchY=%f,targetX=%f,targety=%f",locationInNode.x,locationInNode.y,target->getPositionX(),target->getPositionY());
        Rect pRect = target->getBoundingBox();
        
        if (pRect.containsPoint(locationInNode)) {
            
            return true;
        }
        
        return false;
    };
    
    listener1->onTouchMoved = CC_CALLBACK_2(GameScene01::onTouchMoved, this);
    listener1->onTouchEnded = CC_CALLBACK_2(GameScene01::onTouchEnded, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, m_jinggai);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), m_zhuantou);
    
//  创建Tip层
    
    initTipLayer();
    TipLayer->setPosition(origin+Point(0,-300));
    this->addChild(TipLayer,10);
    this->scheduleUpdate();
    return true;
}

void GameScene01::restart(){
    Director::getInstance()->replaceScene(GameScene01::createScene());
    Director::getInstance()->resume();
}

void GameScene01::update(float delta){

}

void GameScene01::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){
    auto target = static_cast<Sprite* >(pEvent->getCurrentTarget());
    target->setPosition(target->getPosition()+pTouch->getDelta());
    if (m_sister->getBoundingBox().containsPoint(m_zhuantou->getPosition())) {
        m_sister->runAction(TintTo::create(0, 200, 200, 200));
    }else{
        m_sister->runAction(TintTo::create(0, 255, 255, 255));
    }
}

void GameScene01::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){
    if (m_sister->getBoundingBox().containsPoint(m_zhuantou->getPosition())) {
        TipLayer->runAction(MoveTo::create(0.2f,Director::getInstance()->getVisibleOrigin()+Point::ZERO));
        m_sister->setVisible(false);
    }
}

void GameScene01::initTipLayer(){
    TipLayer = Layer::create();
    
    auto winSize = Director::getInstance()->getVisibleSize();
    
    auto m_big = Sprite::create("level_01/sister_big.png");
    m_big->setAnchorPoint(Point::ZERO);
    m_big->setPosition(Point::ZERO);
    TipLayer->addChild(m_big);
    
    auto m_board = Sprite::create("level_01/tip.png");
    m_board->setAnchorPoint(Point::ANCHOR_BOTTOM_RIGHT);
    m_board->setPosition(Point(winSize.width, 0));
    TipLayer->addChild(m_board);
    
    auto thanks = MenuItemLabel::create(LabelTTF::create("thank", "", 20),
                                        CC_CALLBACK_0(GameScene01::sayThanksCallBack, this));
    thanks->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
    thanks->setColor(Color3B(0, 0, 0));
    thanks->setPosition(Point(winSize.width-270, 50));
    
    auto no = MenuItemLabel::create(LabelTTF::create("no", "", 20),
                                        CC_CALLBACK_0(GameScene01::sayNoCallBack, this));
    no->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
    no->setColor(Color3B(0, 0, 0));
    no->setPosition(Point(winSize.width-270, 20));
    
    auto t_n_menu = Menu::create(thanks,no, NULL);
    t_n_menu->setPosition(Point::ZERO);
    TipLayer->addChild(t_n_menu);
    
}

void GameScene01::sayThanksCallBack(){
    m_ui->Lose("er");
}

void GameScene01::sayNoCallBack(){
    m_ui->Success("haha", 3);
}