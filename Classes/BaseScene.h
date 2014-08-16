#pragma once
#include "cocos2d.h"
USING_NS_CC;
class BaseScene : public Scene
{
public:
	void setTips(std::string tips[3]);
	std::string getTips(int index);

	void restart();

	BaseScene(void);
	~BaseScene(void);
private:
	std::string tips[3];
};

