
#include "PauseLayer.h"
#include "StartScene.h"
#define NODETAG 10
//#define RESETTAG 20
//#define HOMETAG 30
//#define GAMETAG 40

bool PauseLayer::init(Ref* pSender)
{
    //保存uiLayer的引用
    uiLayer = (Layer*)pSender;
    
	Size visibleSize = Director::getInstance()->getWinSize();
	//加载plist
	//auto cache = SpriteFrameCache::getInstance();
	//cache->addSpriteFramesWithFile("ui_pause.plist", "ui_pause.png");
	//cache->addSpriteFramesWithFile("ui_common.plist", "ui_common.png");
    
	//重置按钮
	auto btnResetGame = Button::create();
	btnResetGame->loadTextureNormal("UI/ui_btn_replay.png", UI_TEX_TYPE_LOCAL);
	btnResetGame->addTouchEventListener(this, toucheventselector(PauseLayer::resetGame));
	btnResetGame->setPosition(Point(-230, 180));
    //this->addChild(btnResetGame, 100, RESETTAG);
	//主界面按钮
	auto btnReturnToHome = Button::create();
	btnReturnToHome->loadTextureNormal("UI/ui_btn_home.png", UI_TEX_TYPE_LOCAL);
	btnReturnToHome->addTouchEventListener(this, toucheventselector(PauseLayer::returnToHome));
	btnReturnToHome->setPosition(Point(0, 180));
    //this->addChild(btnReturnToHome, 100, HOMETAG);
	//继续按钮
	auto btnContinue = Button::create();
	btnContinue->loadTextureNormal("UI/ui_btn_resume.png", UI_TEX_TYPE_LOCAL);
	btnContinue->addTouchEventListener(this, toucheventselector(PauseLayer::returnToGame));
	btnContinue->setPosition(Point(230, 180));
    //this->addChild(btnContinue, 100, GAMETAG);
    
    auto bg = Sprite::create("UI/ui_pasue_bg.jpg");
    bg->setAnchorPoint(Point(0.5, 0));
    bg->setPosition(Point(0, 0));
    
    /*
	//截图
	RenderTexture* renderTexture = RenderTexture::create(visibleSize.width, visibleSize.height);
	renderTexture->retain();
	Scene *runningScene = CCDirector::getInstance()->getRunningScene();
	renderTexture->begin();
	runningScene->visit();
	renderTexture->end();
	//下面这句用来测试截图是否成功，经测试成功
	//renderTexture->saveToFile("123.png", Image::Format::PNG);
    
	//将截到的图做背景

	Sprite *_spr = Sprite::createWithTexture(renderTexture->getSprite()->getTexture());
	_spr->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
    _spr->setFlippedY(true);  //翻转
	_spr->setColor(Color3B::GRAY);  //颜色（变灰暗）
	this->addChild(_spr, 90, BGTAG);
    */
    
    auto moveTo = MoveTo::create(0.3f, Point(visibleSize.width / 2, 0));
    auto easeBackInOut = EaseBackInOut::create(moveTo);
    
	//btnResetGame->runAction(easeBackInOut);
    //btnReturnToHome->runAction(Sequence::create(DelayTime::create(0.1f), easeBackInOut->clone(), NULL));
    //btnContinue->runAction(Sequence::create(DelayTime::create(0.2f), easeBackInOut->clone(), NULL));
    
    auto node = Node::create();
    node->addChild(bg);
    node->addChild(btnContinue);
    node->addChild(btnResetGame);
    node->addChild(btnReturnToHome);
    node->setPosition(Point(visibleSize.width / 2, visibleSize.height + 200));
    node->runAction(easeBackInOut);
    this->addChild(node, 100, NODETAG);
	
	return true;
}

void PauseLayer::pauseGame(Ref* pSender)
{
    auto scene = Scene::create();
    auto layer = PauseLayer::create(pSender);
    scene->addChild(layer);
    
    auto director = Director::getInstance();
    director->pushScene(scene);
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void PauseLayer::returnToGame(Ref* pSender)
{
	//获得窗体大小
	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto moveTo = MoveTo::create(0.5f, Point(visibleSize.width / 2, visibleSize.height + 200));
	auto easeBackInOut = EaseBackInOut::create(moveTo);
    auto returnToGameAction = Sequence::create(easeBackInOut, CallFunc::create(CC_CALLBACK_0(PauseLayer::returnToGameCallFunc, this)), NULL);
	this->getChildByTag(NODETAG)->runAction(returnToGameAction);
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

void PauseLayer::resetGame(Ref* pSender, TouchEventType type)
{
    switch (type)
    {
        case TOUCH_EVENT_ENDED:
        {
            auto gameLayerNode = uiLayer->getParent();
            BaseLayer* baseLayer = (BaseLayer*)gameLayerNode;
            baseLayer->restart();
            break;
        }
        default:
            break;
    }
}

void PauseLayer::returnToHome(Ref* pSender, TouchEventType type)
{
    switch (type)
    {
        case TOUCH_EVENT_ENDED:
        {
            Director::getInstance()->resume();
            CCDirector::getInstance()->replaceScene(StartScene::createScene());
            break;
        }
        default:
            break;

    }
}

void PauseLayer::returnToGameCallFunc(){
    Director::getInstance()->popScene();
}

PauseLayer* PauseLayer::create(Ref* pSender)
{
    PauseLayer *pRet = new PauseLayer();
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

PauseLayer::PauseLayer(void)
{
	uiLayer = NULL;
}


PauseLayer::~PauseLayer(void)
{
}
