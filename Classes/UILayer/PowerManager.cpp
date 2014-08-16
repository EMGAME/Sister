//
//  PowerManager.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-14.
//
//

#include "PowerManager.h"
static PowerManager* s_sharedPowerManager = nullptr;
PowerManager::PowerManager(){
    setPowerNum(0);
}

PowerManager* PowerManager::getInstance(){
    if (!s_sharedPowerManager)
    {
        s_sharedPowerManager = new PowerManager();
        s_sharedPowerManager->init();
    }
    return s_sharedPowerManager;
}
void PowerManager::purge(){
    CC_SAFE_RELEASE(s_sharedPowerManager);
}

bool PowerManager::init(){
    bool bRet = false;
    do{
        
        setPowerNum(readPower());

        bRet = true;
    }while (0);
    return bRet;
}

void PowerManager::restMgr(){
    setPowerNum(0);
    savePower();
}


void PowerManager::addPower(int number){
    setPowerNum(getPowerNum()+number);
    savePower();
}

void PowerManager::subPower(int number){
    if (getPowerNum()-number >= 0) {
        setPowerNum(getPowerNum()-number);
        savePower();
    }else{
        return;
    }
}

void PowerManager::savePower(){
    CCUserDefault::getInstance()->setIntegerForKey("Power", getPowerNum());
}

int PowerManager::readPower(){
    return CCUserDefault::getInstance()->getIntegerForKey("Power", 0);
    
}

void PowerManager::clickReducePower(){
    subPower(1);
}

void PowerManager::initWithNumber(int number){
    setPowerNum(number);
    savePower();
}