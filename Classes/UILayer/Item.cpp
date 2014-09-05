//
//  Item.cpp
//  Sister
//
//  Created by EMG on 14-9-4.
//
//

#include "Item.h"

Item* Item::create(ItemType pItemType){

    Item *pRet = new Item();
    
    if (pRet && pRet->init(pItemType))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

Item::Item(){};
Item::~Item(){};

bool Item::init(ItemType pItemType){
    if (!Node::init()) {
        return false;
    }
    
    
    return true;
}