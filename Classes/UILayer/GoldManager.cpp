//
//  GoldManager.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#include "GoldManager.h"
static GoldManager* s_sharedGoldManager = nullptr;
GoldManager::GoldManager(){
    setGoldNum(0);
}

GoldManager* GoldManager::getInstance(){
    if (!s_sharedGoldManager)
    {
        s_sharedGoldManager = new GoldManager();
        s_sharedGoldManager->init();
    }
    return s_sharedGoldManager;
}
void GoldManager::purge(){
    CC_SAFE_RELEASE(s_sharedGoldManager);
}

bool GoldManager::init(){
    bool pRet = false;
    do{
    
    setGoldNum(readGold());
        pRet = true;
    }while (0);
    return pRet;
}


void GoldManager::restMgr(){
    setGoldNum(0);
    saveGold();
}


void GoldManager::addGold(int number){
    setGoldNum(getGoldNum()+number);
    saveGold();
}

void GoldManager::subGold(int number){
    if (getGoldNum()-number >= 0) {
        setGoldNum(getGoldNum()-number);
        saveGold();
    }else{
        return;
    }
}

void GoldManager::saveGold(){
    CCUserDefault::getInstance()->setIntegerForKey("Gold", getGoldNum());
}

int GoldManager::readGold(){
    return CCUserDefault::getInstance()->getIntegerForKey("Gold", 0);

}

void GoldManager::initWithNumber(int number){
    setGoldNum(number);
    saveGold();
}