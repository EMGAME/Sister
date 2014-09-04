#ifndef Bglayer_h
#define Bglayer_h

#include "cocos2d.h"

USING_NS_CC;

class Bglayer : public Layer{

public:
    Bglayer();
	~Bglayer();
	CREATE_FUNC(Bglayer);

	virtual bool init();
	//±³¾°¹ö¶¯
	void logic(float dt);
private:
   Sprite* bg1;
   Sprite* tree1;
   Sprite* tree2;
   Sprite* tree3;
 
};

#endif