//
//  GameScene06.h
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#ifndef __Sister__GameScene06__
#define __Sister__GameScene06__

#include "cocos2d.h"
#include "../UILayer/UILayer.h"
#include "BaseLayer.h"

USING_NS_CC;
class GameScene06:public BaseLayer
{
public:
	GameScene06();
	~GameScene06();

	CREATE_FUNC(GameScene06);
	static Scene* createScene();
	virtual bool init();
	virtual void restart();// 重新开始游戏
	void sayThanksCallBack();// 游戏闯关失败
	void sayNoCallBack();// 游戏闯关成功
	void addSprite();// 游戏中添加精灵
	void update(float tmd);// 更新函数
	// 触摸移动
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchesMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
	Rect getRect(Sprite* sprite);// 获取矩形范围
	void isEnableL(Ref* pSender);
	void isEnableR(Ref* pSender);

	SpriteFrameCache* cache;
	UILayer* m_ui;
	Size visibleSize,winSize;
	Sprite* toy1;
	Sprite* toy2;
	Sprite* net;
	MenuItemImage* pressL;
	MenuItemImage* pressR;
	Rect netRect;
 
	int isCatch;
    
    //下一关
    virtual void nextLevel();
};

#include <iostream>
#endif /* defined(__Sister__GameScene06__) */
