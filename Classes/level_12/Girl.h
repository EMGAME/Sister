#ifndef Girl_h
#define Girl_h

#include "cocos2d.h"

USING_NS_CC;

class Girl : public cocos2d::Node{
public:
	
	Girl();
	~Girl();

	CREATE_FUNC(Girl);
	virtual bool init();

	void backNormal();

	void moveDown();
	void moveRight();
	void moveLeft();

	//bool moveLeft();
	//bool moveRight();

};
#endif