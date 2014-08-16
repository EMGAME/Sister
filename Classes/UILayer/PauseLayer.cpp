
#include "PauseLayer.h"
#include "../SelectScene/ScrollViewScene.h"
#define BGTAG 10
#define NODETAG 20
#define MENUTAG 30

bool PauseLayer::init()
{
	Size visibleSize = Director::getInstance()->getWinSize();
	//加载plist
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("ui_pause.plist", "ui_pause.png");
	cache->addSpriteFramesWithFile("ui_common.plist", "ui_common.png");
	//暂停界面
	auto pauseBg = Sprite::createWithSpriteFrameName("pause_bg.png");
	pauseBg->setPosition(Point::ZERO);
	//关闭按钮
	auto btnReturnToGame = MenuItemImage::create(); 
	btnReturnToGame->setNormalSpriteFrame(cache->getSpriteFrameByName("common_btn_close.png"));
	//btnPause->setSelectedSpriteFrame(cache->getSpriteFrameByName("common_btn_pause.png"));
	btnReturnToGame->setCallback(CC_CALLBACK_1(PauseLayer::returnToGame, this));
	btnReturnToGame->setPosition(Point(180, 160));
	//重置按钮
	auto btnResetGame = MenuItemImage::create();
	btnResetGame->setNormalSpriteFrame(cache->getSpriteFrameByName("pause_replay.png"));
	btnResetGame->setCallback(CC_CALLBACK_1(PauseLayer::resetGame, this));
	btnResetGame->setPosition(Point(0, 100));
	//主界面按钮
	auto btnReturnToHome = MenuItemImage::create();
	btnReturnToHome->setNormalSpriteFrame(cache->getSpriteFrameByName("pause_return.png"));
	btnReturnToHome->setCallback(CC_CALLBACK_1(PauseLayer::returnToHome, this));
	btnReturnToHome->setPosition(Point::ZERO);
	//静音按钮
	btnMuteSounds = MenuItemImage::create();
	if (soundFlag)
	{
		btnMuteSounds->setNormalSpriteFrame(cache->getSpriteFrameByName("pause_music_off.png"));
	} 
	else
	{
		btnMuteSounds->setNormalSpriteFrame(cache->getSpriteFrameByName("pause_music_on.png"));
	}
	btnMuteSounds->setCallback(CC_CALLBACK_1(PauseLayer::muteSound, this));
	btnMuteSounds->setPosition(Point(0, -100));

	auto menu = Menu::create(btnReturnToGame, btnResetGame, btnReturnToHome, btnMuteSounds, NULL);
	menu->setPosition(Point::ZERO);

	auto node = Node::create();
	node->addChild(pauseBg);
	node->addChild(menu);
	node->setPosition(Point(visibleSize.width / 2, visibleSize.height + 400));

	this->addChild(node, 100, NODETAG);
	
	return true;
}

void PauseLayer::pauseGame(Ref* pSender)
{
	//获得窗体大小
	Size visibleSize = Director::getInstance()->getWinSize();
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
	
	//禁止页面菜单
	uiLayer = (Layer*)pSender;
	auto uiLayerMenu = (Menu*)uiLayer->getChildByTag(MENUTAG);
	uiLayerMenu->setEnabled(false);

	auto moveTo = MoveTo::create(0.5f, Point(visibleSize.width / 2, visibleSize.height / 2));
	auto easeBackInOut = EaseBackInOut::create(moveTo);
	this->getChildByTag(NODETAG)->runAction(easeBackInOut);
}

void PauseLayer::returnToGame(Ref* pSender)
{
	//获得窗体大小
	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto moveTo = MoveTo::create(0.5f, Point(visibleSize.width / 2, visibleSize.height + 400));
	auto easeBackInOut = EaseBackInOut::create(moveTo);
	this->getChildByTag(NODETAG)->runAction(easeBackInOut);
	this->getChildByTag(BGTAG)->removeFromParent();
	
	//激活页面菜单
	if(uiLayer)
	{
		auto uiLayerMenu = (Menu*)uiLayer->getChildByTag(MENUTAG);
		uiLayerMenu->setEnabled(true);
	}
}

void PauseLayer::resetGame(Ref* pSender)
{
	auto director = Director::getInstance();
	Scene* runningScene = director->getRunningScene();
	BaseScene* scene = (BaseScene*)runningScene;
	scene->restart();
}

void PauseLayer::returnToHome(Ref* pSender)
{
    CCDirector::getInstance()->replaceScene(ScrollViewScene::createScene());
}

void PauseLayer::muteSound(Ref* pSender)
{
	auto audioEngine = SimpleAudioEngine::getInstance();
	auto cache = SpriteFrameCache::getInstance();
	auto userDefault = UserDefault::getInstance();
	if (soundFlag)	//true表示音乐已经关闭
	{
		audioEngine->playBackgroundMusic("game_playing.mp3");
		btnMuteSounds->setNormalSpriteFrame(cache->getSpriteFrameByName("pause_music_on.png"));
		soundFlag = false;
		userDefault->setBoolForKey("soundFlag", false);
	}
	else
	{
		audioEngine->stopBackgroundMusic();
		btnMuteSounds->setNormalSpriteFrame(cache->getSpriteFrameByName("pause_music_off.png"));
		soundFlag = true;
		userDefault->setBoolForKey("soundFlag", true);
	}
}

PauseLayer::PauseLayer(void)
{
	uiLayer = NULL;
	soundFlag = UserDefault::getInstance()->getBoolForKey("soundFlag");
}


PauseLayer::~PauseLayer(void)
{
}
