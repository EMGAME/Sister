//
//  Item.h
//  Sister
//
//  Created by EMG on 14-9-4.
//
//

#ifndef __Sister__Item__
#define __Sister__Item__

#include "cocos2d.h"
USING_NS_CC;
enum ItemType{
    ITEM_TYPE_WINDOW = 01,//窗帘
    ITEM_TYPE_FLOWER = 02,//花
    ITEM_TYPE_WATCH  = 03,//手表
    ITEM_TYPE_CA     = 04,//钙片
};
class Item :public Node{
public:
    Item();
    ~Item();
    
    Sprite* mSprite;
    
    virtual bool init(ItemType pItemType);
    
    bool bindSprite(Sprite* pSprite);
    static Item* create(ItemType pItemType);
    Sprite* getSprite();
    
    void setEnableFalse();
    void setEnableTrue();
    
    CC_SYNTHESIZE(ItemType, m_Type, curType);
    CC_SYNTHESIZE(Point, m_startPos, startPos);
    CC_SYNTHESIZE(int, m_restNum, restNum);
    
    bool onTouchBegan(Touch* pTouch,Event* pEvent);
    void onTouchMoved(Touch* pTouch,Event* pEvent);
    void onTouchEnded(Touch* pTouch,Event* pEvent);
    
};

#endif /* defined(__Sister__Item__) */
