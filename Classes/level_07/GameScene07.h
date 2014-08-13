#pragma once
#include "cocos2d.h"
#include "../UILayer/UILayer.h"
USING_NS_CC;
class GameScene07 : public Layer
{
public:
	virtual bool init();
	static Scene* scene();
	CREATE_FUNC(GameScene07);

	GameScene07(void);
	~GameScene07(void);
};

