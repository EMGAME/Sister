#pragma once
#include "cocos2d.h"
USING_NS_CC;
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
};

