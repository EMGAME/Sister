//
//  ItemManager.h
//  Sister
//
//  Created by EMG on 14-9-4.
//
//

#ifndef __Sister__ItemManager__
#define __Sister__ItemManager__

#include "cocos2d.h"
USING_NS_CC;

class ItemManager:public Node{
public:
    ItemManager();
    ~ItemManager();
    static ItemManager* getInstance();
    void purge();
    virtual bool init();
    
    CREATE_FUNC(ItemManager);
};

#endif /* defined(__Sister__ItemManager__) */
