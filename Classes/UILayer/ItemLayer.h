//
//  ItemLayer.h
//  Sister
//
//  Created by EMG on 14-8-22.
//
//

#ifndef __Sister__ItemLayer__
#define __Sister__ItemLayer__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "tinyxml2/tinyxml2.h"
USING_NS_CC;
using namespace tinyxml2;


//道具类型
enum ITEM_TYPE{
    ITEM_TYPE_WINDOW = 01,//窗帘
    ITEM_TYPE_FLOWER = 02,//花
    ITEM_TYPE_WATCH  = 03,//手表
    ITEM_TYPE_CA     = 04,//钙片
};

class ItemLayer : public Layer
{
public:
    CREATE_FUNC(ItemLayer);
    virtual bool init();
    void initItemXML();
    
    //道具栏初始化，使用前调用
    void ItemInit(Rect pRect,ITEM_TYPE mType);
    //返回所选物品是否被包含
    bool ItemIsContained();
    
    void menuCallBack();
    
    void showItems();
    void hideItems();
    
    void addToItems(Node* pSender, int id);
    void addToItemsCallBack(Node* pSender);
    
    bool onTouchBegan(Touch* pTouch,Event* pEvent);
    void onTouchEnded(Touch* pTouch,Event* pEvent);
    void onTouchMoved(Touch* pTouch,Event* pEvent);
    
private:
    Vector<Sprite*> m_AllEnableItems;
    Vector<Sprite*> m_ShowedItems;
    Node* enableItem;
    Point startPosition;
    bool isShowed;
    
    CC_SYNTHESIZE(Rect, m_Rect, mRect);
    CC_SYNTHESIZE(Sprite*, cur_Sprite, curSprite);
    CC_SYNTHESIZE(ITEM_TYPE, cur_Type, curType);
};

#endif /* defined(__Sister__ItemLayer__) */
