//
//  GameScene07.h
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#ifndef __Sister__GameScene07__
#define __Sister__GameScene07__

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

#endif /* defined(__Sister__GameScene07__) */
