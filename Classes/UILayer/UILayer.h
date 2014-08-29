#pragma once
#include "cocos2d.h"
#include "PauseLayer.h"
#include "ShareLayer.h"
#include "ShopLayer.h"
<<<<<<< HEAD
#include "FailureLayer.h"
#include "SuccessLayer.h"

=======
#include "ItemLayer.h"
>>>>>>> gamescene07
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
    void Lose(std::string loseTip);
    void Success(std::string passTip,int starNum);
    
	//暂停游戏界面
	PauseLayer* pauseLayer;
	//分享界面
	ShareLayer* shareLayer;
    //商店界面
    ShopLayer* tipLayer;
    ShopLayer* powerLayer;
    //失败界面
    FailureLayer* m_failureLayer;
    //胜利界面
    SuccessLayer* m_successLayer;

	UILayer(void);
	~UILayer(void);
};

