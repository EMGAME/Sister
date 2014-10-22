#pragma once
#include "cocos2d.h"
#include "../BaseLayer.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;
using namespace CocosDenshion;
class PauseLayer : public Layer
{
public:
	virtual bool init(Ref* pSender);
	static PauseLayer* create(Ref* pSender);

	//暂停游戏
	static void pauseGame(Ref* pSender);
	//返回游戏
	void returnToGame(Ref* pSender);
	//重置关卡
	void resetGame(Ref* pSender, TouchEventType type);
	//返回主页面
	void returnToHome(Ref* pSender, TouchEventType type);
    void returnToGameCallFunc();

	PauseLayer(void);
	~PauseLayer(void);
private:
	Layer* uiLayer;
    
};

