#include "PauseLayer.h"
#define BGTAG 10
#define NODETAG 20
#define MENUTAG 30

bool PauseLayer::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//����plist
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("ui_pause.plist", "ui_pause.png");
	cache->addSpriteFramesWithFile("ui_common.plist", "ui_common.png");
	//��ͣ����
	auto pauseBg = Sprite::createWithSpriteFrameName("pause_bg.png");
	pauseBg->setPosition(Point::ZERO);
	//�رհ�ť
	auto btnReturnToGame = MenuItemImage::create(); 
	btnReturnToGame->setNormalSpriteFrame(cache->getSpriteFrameByName("common_btn_close.png"));
	//btnPause->setSelectedSpriteFrame(cache->getSpriteFrameByName("common_btn_pause.png"));
	btnReturnToGame->setCallback(CC_CALLBACK_1(PauseLayer::returnToGame, this));
	btnReturnToGame->setPosition(Point(180, 160));
	//���ð�ť
	auto btnResetGame = MenuItemImage::create();
	btnResetGame->setNormalSpriteFrame(cache->getSpriteFrameByName("pause_replay.png"));
	btnResetGame->setCallback(CC_CALLBACK_1(PauseLayer::resetGame, this));
	btnResetGame->setPosition(Point(0, 100));
	//�����水ť
	auto btnReturnToHome = MenuItemImage::create();
	btnReturnToHome->setNormalSpriteFrame(cache->getSpriteFrameByName("pause_return.png"));
	btnReturnToHome->setCallback(CC_CALLBACK_1(PauseLayer::returnToHome, this));
	btnReturnToHome->setPosition(Point::ZERO);
	//������ť
	auto btnMuteSounds = MenuItemImage::create();
	btnMuteSounds->setNormalSpriteFrame(cache->getSpriteFrameByName("pause_music_on.png"));
	btnMuteSounds->setCallback(CC_CALLBACK_1(PauseLayer::muteSound, this));
	btnMuteSounds->setPosition(Point(0, -100));

	auto menu = Menu::create(btnReturnToGame, btnResetGame, btnReturnToHome, btnMuteSounds, NULL);
	menu->setPosition(Point::ZERO);

	auto node = Node::create();
	node->addChild(pauseBg);
	node->addChild(menu);
	node->setPosition(Point(visibleSize.width / 2, visibleSize.height + 200));

	this->addChild(node, 100, NODETAG);
	
	return true;
}

void PauseLayer::pauseGame(Ref* pSender)
{
	//��ô����С
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//��ͼ
	RenderTexture* renderTexture = RenderTexture::create(visibleSize.width, visibleSize.height);  
	renderTexture->retain();  
	Scene *runningScene = CCDirector::getInstance()->getRunningScene();
	renderTexture->begin();  
	runningScene->visit();  
	renderTexture->end();  
	//��������������Խ�ͼ�Ƿ�ɹ��������Գɹ�
	//renderTexture->saveToFile("123.png", Image::Format::PNG);

	//���ص���ͼ������
	Sprite *_spr = Sprite::createWithTexture(renderTexture->getSprite()->getTexture());  
	_spr->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));  
	_spr->setFlippedY(true);  //��ת  
	_spr->setColor(Color3B::GRAY);  //��ɫ����Ұ��� 
	this->addChild(_spr, 90, BGTAG);  
	
	//��ֹҳ��˵�
	uiLayer = (Layer*)pSender;
	auto uiLayerMenu = (Menu*)uiLayer->getChildByTag(MENUTAG);
	uiLayerMenu->setEnabled(false);

	auto moveTo = MoveTo::create(0.5f, Point(visibleSize.width / 2, visibleSize.height / 2));
	auto easeBackInOut = EaseBackInOut::create(moveTo);
	this->getChildByTag(NODETAG)->runAction(easeBackInOut);
}

void PauseLayer::returnToGame(Ref* pSender)
{
	//��ô����С
	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto moveTo = MoveTo::create(0.5f, Point(visibleSize.width / 2, visibleSize.height + 200));
	auto easeBackInOut = EaseBackInOut::create(moveTo);
	this->getChildByTag(NODETAG)->runAction(easeBackInOut);
	this->getChildByTag(BGTAG)->removeFromParent();
	
	//����ҳ��˵�
	if(uiLayer)
	{
		auto uiLayerMenu = (Menu*)uiLayer->getChildByTag(MENUTAG);
		uiLayerMenu->setEnabled(true);
	}
}

void PauseLayer::resetGame(Ref* pSender)
{
	Scene* runningScene = Director::getInstance()->getRunningScene();
	Scene* scene = runningScene->create();

}

void PauseLayer::returnToHome(Ref* pSender)
{

}

void PauseLayer::muteSound(Ref* pSender)
{

}

PauseLayer::PauseLayer(void)
{
	uiLayer = NULL;
}


PauseLayer::~PauseLayer(void)
{
}
