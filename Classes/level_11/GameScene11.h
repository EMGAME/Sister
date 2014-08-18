#ifndef GameScene11_h
#define GameScene11_h

#include "cocos2d.h"
#include "BaseLayer.h"

class GameScene11 : public BaseLayer {
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
    virtual void restart();

	CREATE_FUNC(GameScene11);

	void clown();
	void flower();
	void glass();
	void face();
};
#endif