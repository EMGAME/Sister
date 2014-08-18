#pragma once
#include "cocos2d.h"
USING_NS_CC;
class BaseLayer : public Layer
{
public:
	void setTips(std::string tips[3]);
	std::string getTips(int index);

    CREATE_FUNC(BaseLayer);
    
	BaseLayer(void);
	~BaseLayer(void);
	std::string tips[3];
    
    virtual void restart(){};
};


