//
//  GameScene36.cpp
//  Sister
//
//  Created by EMG on 14-10-15.
//
//

#include "GameScene36.h"
#include "game.h"

bool GameScene36::init()
{
    
    m_ui = UISimple::create();
    this->addChild(m_ui,30);
    
    
    Size winSize = Director::getInstance()->getWinSize();
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("level_36/level36.plist");
    
    //背景
    auto bg = Sprite::create("level_36/bg.png");
    bg->setPosition(Point(winSize.width / 2, winSize.height / 2));
    this->addChild(bg);
    
    //加入12个键
    initKey();
    
    //纸条
    initPaper();
    
    //输入密码区域
    auto passwordLabel = Label::create("", "fonts/comic sans ms.ttf", 80);
    passwordLabel->setAnchorPoint(Point(0, 0.5));
    passwordLabel->setPosition(270, 545);
    passwordLabel->setColor(Color3B(117, 79, 49));
    this->addChild(passwordLabel, 10, LABELTAG);
    
    return true;
}

void GameScene36::keyCallBack0(Ref* pSender, TouchEventType type)
{
    switch (type)
    {
        case TOUCH_EVENT_ENDED:
        {
            Label* passwordLabel = (Label*)this->getChildByTag(LABELTAG);
            const string str = passwordLabel->getString();
            if (str.length() < 5) {
                passwordLabel->setString(str + "0");
            }
            break;
        }
        default:
            break;
    }
}

void GameScene36::keyCallBack1(Ref* pSender, TouchEventType type)
{
    switch (type)
    {
        case TOUCH_EVENT_ENDED:
        {
            Label* passwordLabel = (Label*)this->getChildByTag(LABELTAG);
            const string str = passwordLabel->getString();
            if (str.length() < 5) {
                passwordLabel->setString(str + "1");
            }
            break;
        }
        default:
            break;
    }
}

void GameScene36::keyCallBack2(Ref* pSender, TouchEventType type)
{
    switch (type)
    {
        case TOUCH_EVENT_ENDED:
        {
            Label* passwordLabel = (Label*)this->getChildByTag(LABELTAG);
            const string str = passwordLabel->getString();
            if (str.length() < 5) {
                passwordLabel->setString(str + "2");
            }
            break;
        }
        default:
            break;
    }
}

void GameScene36::keyCallBack3(Ref* pSender, TouchEventType type)
{
    switch (type)
    {
        case TOUCH_EVENT_ENDED:
        {
            Label* passwordLabel = (Label*)this->getChildByTag(LABELTAG);
            const string str = passwordLabel->getString();
            if (str.length() < 5) {
                passwordLabel->setString(str + "3");
            }
            break;
        }
        default:
            break;
    }
}

void GameScene36::keyCallBack4(Ref* pSender, TouchEventType type)
{
    switch (type)
    {
        case TOUCH_EVENT_ENDED:
        {
            Label* passwordLabel = (Label*)this->getChildByTag(LABELTAG);
            const string str = passwordLabel->getString();
            if (str.length() < 5) {
                passwordLabel->setString(str + "4");
            }
            break;
        }
        default:
            break;
    }
}

void GameScene36::keyCallBack5(Ref* pSender, TouchEventType type)
{
    switch (type)
    {
        case TOUCH_EVENT_ENDED:
        {
            Label* passwordLabel = (Label*)this->getChildByTag(LABELTAG);
            const string str = passwordLabel->getString();
            if (str.length() < 5) {
                passwordLabel->setString(str + "5");
            }
            break;
        }
        default:
            break;
    }
}

void GameScene36::keyCallBack6(Ref* pSender, TouchEventType type)
{
    switch (type)
    {
        case TOUCH_EVENT_ENDED:
        {
            Label* passwordLabel = (Label*)this->getChildByTag(LABELTAG);
            const string str = passwordLabel->getString();
            if (str.length() < 5) {
                passwordLabel->setString(str + "6");
            }
            break;
        }
        default:
            break;
    }
}

void GameScene36::keyCallBack7(Ref* pSender, TouchEventType type)
{
    switch (type)
    {
        case TOUCH_EVENT_ENDED:
        {
            Label* passwordLabel = (Label*)this->getChildByTag(LABELTAG);
            const string str = passwordLabel->getString();
            if (str.length() < 5) {
                passwordLabel->setString(str + "7");
            }
            break;
        }
        default:
            break;
    }
}

void GameScene36::keyCallBack8(Ref* pSender, TouchEventType type)
{
    switch (type)
    {
        case TOUCH_EVENT_ENDED:
        {
            Label* passwordLabel = (Label*)this->getChildByTag(LABELTAG);
            const string str = passwordLabel->getString();
            if (str.length() < 5) {
                passwordLabel->setString(str + "8");
            }
            break;
        }
        default:
            break;
    }
}

void GameScene36::keyCallBack9(Ref* pSender, TouchEventType type)
{
    switch (type)
    {
        case TOUCH_EVENT_ENDED:
        {
            Label* passwordLabel = (Label*)this->getChildByTag(LABELTAG);
            const string str = passwordLabel->getString();
            if (str.length() < 5) {
                passwordLabel->setString(str + "9");
            }
            break;
        }
        default:
            break;
    }
}

void GameScene36::keyCallBack10(Ref* pSender, TouchEventType type)
{
    switch (type)
    {
        case TOUCH_EVENT_ENDED:
        {
            const char* passwordStr = __String::createWithFormat("%d", passwordNumber)->getCString();
            Label* passwordLabel = (Label*)this->getChildByTag(LABELTAG);
            const string str = passwordLabel->getString();
            if(str == passwordStr)
            {
                success();
            }
            else
            {
                lose();
            }
            break;
        }
        default:
            break;
    }
}

void GameScene36::keyCallBack11(Ref* pSender, TouchEventType type)
{
    switch (type)
    {
        case TOUCH_EVENT_ENDED:
        {
            Label* passwordLabel = (Label*)this->getChildByTag(LABELTAG);
            const string str = passwordLabel->getString();
            if (str.length() < 5) {
                passwordLabel->setString(str + ".");
            }
            break;
        }
        default:
            break;
    }
}

void GameScene36::initPaper()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    //产生随机密码
    std::uniform_int_distribution<unsigned> u(10000,99999);
    std::default_random_engine e;
    e.seed((unsigned)time(NULL));
    int random_number = u(e);
    passwordNumber = random_number;
    const char* passwordStr = __String::createWithFormat("%d", passwordNumber)->getCString();
    auto number = Label::create(passwordStr, "fonts/comic sans ms.ttf", 70);
    number->setPosition(Point(206, -50));
    number->setColor(Color3B(117, 79, 49));
    number->setRotation(-6.0f);
    auto paper = Sprite::createWithSpriteFrameName("paper.png");
    paper->setAnchorPoint(Point(0, 0.5));
    auto paperNode = Node::create();
    paperNode->addChild(paper);
    paperNode->addChild(number);
    paperNode->setPosition(Point(origin.x, visibleSize.height + 100 + origin.y));
    this->addChild(paperNode);
    
    auto moveIn = MoveTo::create(0.3f, Point(origin.x, visibleSize.height - 100 + origin.y));
    auto easeMoveIn = EaseBackInOut::create(moveIn);
    auto moveOut = MoveTo::create(0.3f, Point(origin.x, visibleSize.height + 100 + origin.y));
    auto easeMoveOut = EaseBackInOut::create(moveOut);
    auto seqInOut = Sequence::create(easeMoveIn, DelayTime::create(0.8f), easeMoveOut, NULL);
    paperNode->runAction(seqInOut);

}

void GameScene36::initKey()
{
    //键，12个键的位置
    Point pos[12] = {Point(252, 421), Point(375, 421), Point(503, 421),
                    Point(255, 335), Point(375, 335), Point(500, 335),
                    Point(262, 253), Point(375, 253), Point(495, 253),
                    Point(271, 162), Point(375, 162), Point(490, 162)};
    //键，随机12个键的位置
    int randPos[12]={0,1,2,3,4,5,6,7,8,9,10,11};
    std::uniform_int_distribution<unsigned> u(0,11);
    std::default_random_engine e;
    e.seed((unsigned)time(NULL));
    for (int i = 0; i < 12; i++)
    {
        int random_number = u(e);
        swap(randPos[i], randPos[random_number]);
    }
    
    //加入键
    auto key0 = Button::create();
    key0->setPosition(pos[randPos[0]]);
	key0->loadTextureNormal("normal0.png", UI_TEX_TYPE_PLIST);
    key0->loadTexturePressed("pressed0.png", UI_TEX_TYPE_PLIST);
	key0->addTouchEventListener(this, toucheventselector(GameScene36::keyCallBack0));
    this->addChild(key0);
    auto key1 = Button::create();
    key1->setPosition(pos[randPos[1]]);
	key1->loadTextureNormal("normal1.png", UI_TEX_TYPE_PLIST);
    key1->loadTexturePressed("pressed1.png", UI_TEX_TYPE_PLIST);
	key1->addTouchEventListener(this, toucheventselector(GameScene36::keyCallBack1));
    this->addChild(key1);
    auto key2 = Button::create();
    key2->setPosition(pos[randPos[2]]);
	key2->loadTextureNormal("normal2.png", UI_TEX_TYPE_PLIST);
    key2->loadTexturePressed("pressed2.png", UI_TEX_TYPE_PLIST);
	key2->addTouchEventListener(this, toucheventselector(GameScene36::keyCallBack2));
    this->addChild(key2);
    auto key3 = Button::create();
    key3->setPosition(pos[randPos[3]]);
	key3->loadTextureNormal("normal3.png", UI_TEX_TYPE_PLIST);
    key3->loadTexturePressed("pressed3.png", UI_TEX_TYPE_PLIST);
	key3->addTouchEventListener(this, toucheventselector(GameScene36::keyCallBack3));
    this->addChild(key3);
    auto key4 = Button::create();
    key4->setPosition(pos[randPos[4]]);
	key4->loadTextureNormal("normal4.png", UI_TEX_TYPE_PLIST);
    key4->loadTexturePressed("pressed4.png", UI_TEX_TYPE_PLIST);
	key4->addTouchEventListener(this, toucheventselector(GameScene36::keyCallBack4));
    this->addChild(key4);
    auto key5 = Button::create();
    key5->setPosition(pos[randPos[5]]);
	key5->loadTextureNormal("normal5.png", UI_TEX_TYPE_PLIST);
    key5->loadTexturePressed("pressed5.png", UI_TEX_TYPE_PLIST);
	key5->addTouchEventListener(this, toucheventselector(GameScene36::keyCallBack5));
    this->addChild(key5);
    auto key6 = Button::create();
    key6->setPosition(pos[randPos[6]]);
	key6->loadTextureNormal("normal6.png", UI_TEX_TYPE_PLIST);
    key6->loadTexturePressed("pressed6.png", UI_TEX_TYPE_PLIST);
	key6->addTouchEventListener(this, toucheventselector(GameScene36::keyCallBack6));
    this->addChild(key6);
    auto key7 = Button::create();
    key7->setPosition(pos[randPos[7]]);
	key7->loadTextureNormal("normal7.png", UI_TEX_TYPE_PLIST);
    key7->loadTexturePressed("pressed7.png", UI_TEX_TYPE_PLIST);
	key7->addTouchEventListener(this, toucheventselector(GameScene36::keyCallBack7));
    this->addChild(key7);
    auto key8 = Button::create();
    key8->setPosition(pos[randPos[8]]);
	key8->loadTextureNormal("normal8.png", UI_TEX_TYPE_PLIST);
    key8->loadTexturePressed("pressed8.png", UI_TEX_TYPE_PLIST);
	key8->addTouchEventListener(this, toucheventselector(GameScene36::keyCallBack8));
    this->addChild(key8);
    auto key9 = Button::create();
    key9->setPosition(pos[randPos[9]]);
	key9->loadTextureNormal("normal9.png", UI_TEX_TYPE_PLIST);
    key9->loadTexturePressed("pressed9.png", UI_TEX_TYPE_PLIST);
	key9->addTouchEventListener(this, toucheventselector(GameScene36::keyCallBack9));
    this->addChild(key9);
    auto key10 = Button::create();
    key10->setPosition(pos[randPos[10]]);
	key10->loadTextureNormal("normalok.png", UI_TEX_TYPE_PLIST);
    key10->loadTexturePressed("pressedok.png", UI_TEX_TYPE_PLIST);
	key10->addTouchEventListener(this, toucheventselector(GameScene36::keyCallBack10));
    this->addChild(key10);
    auto key11 = Button::create();
    key11->setPosition(pos[randPos[11]]);
	key11->loadTextureNormal("normalpoint.png", UI_TEX_TYPE_PLIST);
    key11->loadTexturePressed("pressedpoint.png", UI_TEX_TYPE_PLIST);
	key11->addTouchEventListener(this, toucheventselector(GameScene36::keyCallBack11));
    this->addChild(key11);
}

Scene* GameScene36::createScene()
{
    Scene* scene = Scene::create();
    Layer* layer = GameScene36::create();
    scene->addChild(layer);
    return scene;
}

GameScene36::GameScene36()
{
}

void GameScene36::success(){
    this->runAction(Sequence::create(
                                     DelayTime::create(1.0f),
                                     CallFunc::create([&](){
        Director::getInstance()->replaceScene(SuccessScene::createScene(level36));
        
    }),NULL));
}

void GameScene36::lose(){
    this->runAction(Sequence::create(
                                     DelayTime::create(1.0f),
                                     CallFunc::create([&](){
        Director::getInstance()->replaceScene(LoseScene::createScene(level36));
        
    }),NULL));
}

void GameScene36::restart(){
    Director::getInstance()->replaceScene(GameScene36::createScene());
}