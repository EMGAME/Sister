//
//  ItemManager.cpp
//  Sister
//
//  Created by EMG on 14-9-4.
//
//

#include "ItemManager.h"
static ItemManager* _sharedItemManager = nullptr;
ItemManager::ItemManager(){};
ItemManager::~ItemManager(){};

ItemManager* ItemManager::getInstance(){
    if (!_sharedItemManager) {
        _sharedItemManager = new ItemManager();
        _sharedItemManager->init();
    }
    return _sharedItemManager;
}

void ItemManager::purge(){
    CC_SAFE_RELEASE(_sharedItemManager);
}

bool ItemManager::init(){
    bool pRet = false;
    do{
    

        pRet = true;
    }while (0);
    return pRet;
}
