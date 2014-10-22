#pragma once
#include "cocos2d.h"
USING_NS_CC;
class ShareLayer : public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(ShareLayer);
	//弹出分享游戏
	void shareGame(Ref* pSender);
	//返回游戏
	void returnToGame(Ref* pSender);
	ShareLayer(void);
	~ShareLayer(void);
private:
	Layer* uiLayer;
};

