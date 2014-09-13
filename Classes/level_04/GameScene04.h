//  GameScene04.h
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#ifndef __Sister__GameScene04__
#define __Sister__GameScene04__

#include "cocos2d.h"
#include "../UILayer/UILayer.h"
#include "BaseLayer.h"
USING_NS_CC;

class GameScene04 : public BaseLayer
{
public :

	GameScene04();
	~GameScene04();

	static Scene* createScene();
	virtual bool init();
	virtual void restart();

	CREATE_FUNC(GameScene04);

	UILayer* m_ui;

	SpriteFrameCache* cache; 
	Sprite* diamondItem;
	Sprite* dressItem;
	Sprite* roseItem;
	Sprite* chocolateItem;
	Sprite* sorryItem;
	Sprite* goodGirl;
	Sprite* coconutItem;
	Sprite* washboard;
	Sprite* sadGirl;

	int diaFlag; // 标记精灵是否被romove 
	int dreFlag;
	int roseFlag;
	int choFlag,sorryFlag;
	int cocoFlag,washboardFlag;

	Rect diamondRect,dressRect,roseRect,chocolateRect,cocoRect,sorryRect,washboardRect;
	Rect getRect(Sprite* sprite);

	Point goodGirlPos; // 美女坐标
	Point endPos;
	Point origin;
	int is_successful;
	Size visibleSize;
	Size winSize;

	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchesMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
	void moveToGirl(Sprite* sprite,int &flag);

	// 椰子掉下摔碎
	void cocoDrop(Sprite* sprite);
	void update(float tmd);  //更新函数
	void addRuinCoco(float tmd);
	void changeGirl(float tmd);
	void sayThanksCallBack();
	void sayNoCallBack();
    
    //下一关
    virtual void nextLevel();
};

#endif
#include <iostream>
