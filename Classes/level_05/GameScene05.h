//
//  GameScene05.h
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#ifndef __Sister__GameScene05__
#define __Sister__GameScene05__

#include "cocos2d.h";
#include "../UILayer/UILayer.h"
#include "BaseLayer.h"

USING_NS_CC;

class GameScene05 : public BaseLayer
{
public:
	GameScene05();
	~GameScene05();

	virtual bool init();
	virtual void restart();
	static Scene* createScene();

	CREATE_FUNC(GameScene05);
	
	int flag1,flag2,flag3,flag4,flag5,flag6,flag7,flag8,flag9,start;
	int flagScrew_l,flagScrew_r,flagHandle,flagPaper,flagMessage,flagPlate,rightDrop,leftDrop,flag;

	bool onTouchBegan(Touch *touch, Event *unused_event);
	UILayer* m_ui;
	Rect rect1,rect2,rect3,rect4,rect5,rect6,rect7,rect8,rect9,handleRect,paperRect,leftScrewRect;
	Rect messageRect,rightScrewRect,doorplateRect;

	SpriteFrameCache* cache;
	Sprite* no_1;
	Sprite*	no_2;
	Sprite* no_3;
	Sprite* no_4;
	Sprite* no_5;
	Sprite* no_6;
	Sprite* no_7;
	Sprite* no_8;
	Sprite* no_9;
	Sprite* handle;
	Sprite* paper;
	Sprite* leftscrew;
	Sprite* rightscrew;
	Sprite* doorplate;
	Sprite* new_1;
	Sprite* new_2;
	Sprite* new_3;
	Sprite* new_4;
	Sprite* new_5;
	Sprite* new_6;
	Sprite* new_7;
	Sprite* new_8;
	Sprite* new_9;
	Sprite* success;
	Sprite* message;
	Sprite* beautifulGirl;
	Sprite* ok;

	Size visibleSize;
	Size winSize;
	Point origin;

	Point screwRPos,screwLPos;

	Rect getRect(Sprite* sprite);

	void update(float tmd);
	void addSprite();
	void change(Sprite* sprite);
	void removeSprite(Sprite* sprite);
	void setFlag(float tmd);
	void popOk(float tmd);
	void sayThanksCallBack();
	void sayNoCallBack();

    
    //下一关
    virtual void nextLevel();
};
#endif
#include <iostream>
