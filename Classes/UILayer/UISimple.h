#pragma once
#include "cocos2d.h"
#include "PauseLayer.h"
#include "ShareLayer.h"
#include "ShopLayer.h"
#include "FailureLayer.h"
#include "SuccessLayer.h"

#include "ItemLayer.h"
USING_NS_CC;
class UISimple : public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(UISimple);
    
	void btnPauseCallBack(Ref* pSender);
    
	//暂停游戏界面
	PauseLayer* pauseLayer;

    LabelBMFont* m_time;
    float time_nm;
    
    virtual void update(float time);
    
	UISimple();
	~UISimple();
};