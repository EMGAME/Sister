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
	//��������
	void logic(float dt);
private:
   Sprite* bg1;
   Sprite* bg2;

   

};

#endif