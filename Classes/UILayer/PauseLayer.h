#pragma once
#include "cocos2d.h"
#include "../BaseScene.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace CocosDenshion;
class PauseLayer : public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(PauseLayer);

	//暂停游戏
	void pauseGame(Ref* pSender);
	//返回游戏
	void returnToGame(Ref* pSender);
	//重置关卡
	void resetGame(Ref* pSender);
	//返回主页面
	void returnToHome(Ref* pSender);
	//设置静音
	void muteSound(Ref* pSender);

	PauseLayer(void);
	~PauseLayer(void);
private:
	Layer* uiLayer;
	bool soundFlag;	//false开音乐，true关音乐
	MenuItemImage* btnMuteSounds;
};
