#pragma once
#include "cocos2d.h"
USING_NS_CC;
class ShareLayer : public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(ShareLayer);
	//����������Ϸ
	void shareGame(Ref* pSender);
	//������Ϸ
	void returnToGame(Ref* pSender);
	ShareLayer(void);
	~ShareLayer(void);
private:
	Layer* uiLayer;
};

