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

class ItemLayer : public Layer
{
public:
    CREATE_FUNC(ItemLayer);
    virtual bool init();
    void initItemXML();
    void menuCallBack();
    
    void showItems();
    void hideItems();
    
    void addToItems(Node* pSender, int id);
    void addToItemsCallBack(Node* pSender);
    
private:
    Vector<Sprite*> m_AllEnableItems;
    Vector<Sprite*> m_ShowedItems;
    Node* enableItem;
    bool isShowed;
};

#endif /* defined(__Sister__ItemLayer__) */
