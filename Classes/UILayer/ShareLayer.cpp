#include "ShareLayer.h"
#define BGTAG 10
#define NODETAG 20
#define MENUTAG 30

bool ShareLayer::init()
{
	return true;
}

void ShareLayer::shareGame(Ref* pSender)
{
	//获得窗体大小
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//截图
	RenderTexture* renderTexture = RenderTexture::create(visibleSize.width, visibleSize.height);  
	renderTexture->retain();  
	Scene *runningScene = CCDirector::getInstance()->getRunningScene();
	renderTexture->begin();  
	runningScene->visit();  
	renderTexture->end(); 

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

	//auto moveTo = MoveTo::create(0.5f, Point(visibleSize.width / 2, visibleSize.height / 2));
	//auto easeBackInOut = EaseBackInOut::create(moveTo);
	//this->getChildByTag(NODETAG)->runAction(easeBackInOut);
}

void ShareLayer::returnToGame(Ref* pSender)
{
	//获得窗体大小
	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto moveTo = MoveTo::create(0.5f, Point(visibleSize.width / 2, visibleSize.height + 200));
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

ShareLayer::ShareLayer(void)
{
}


ShareLayer::~ShareLayer(void)
{
}
