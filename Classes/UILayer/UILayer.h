#pragma once
#include "cocos2d.h"
#include "PauseLayer.h"
#include "ShareLayer.h"
#include "ShopLayer.h"
USING_NS_CC;
class UILayer : public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(UILayer);

	void btnPauseCallBack(Ref* pSender);
	void btnTipCallBack(Ref* pSender);
	void btnCallBack(Ref* pSender);
	void btnHelpCallBack(Ref* pSender);
    void popSuccessLayer();
    void Fail();
    void Success();
    
	//暂停游戏界面
	PauseLayer* pauseLayer;
	//分享界面
	ShareLayer* shareLayer;
    
    ShopLayer* tipLayer;
    ShopLayer* powerLayer;

	UILayer(void);
	~UILayer(void);
};

