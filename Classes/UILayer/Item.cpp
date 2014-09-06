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
Sprite* Item::getSprite(){
    return mSprite;
}
Item::Item(){};
Item::~Item(){};

bool Item::init(ItemType pItemType){
    if (!Node::init()) {
        return false;
    }
    
    auto listener01 = EventListenerTouchOneByOne::create();
    listener01->setSwallowTouches(false);
    
    listener01->onTouchBegan = CC_CALLBACK_2(Item::onTouchBegan, this);
    listener01->onTouchMoved = CC_CALLBACK_2(Item::onTouchMoved, this);
    listener01->onTouchEnded = CC_CALLBACK_2(Item::onTouchEnded, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener01, this);
    
    switch (pItemType) {
        case ITEM_TYPE_CA:
            bindSprite(Sprite::create("level01/zhuantou.png"));
        break;
        case ITEM_TYPE_FLOWER:
        break;
        case ITEM_TYPE_WATCH:
        break;
        case ITEM_TYPE_WINDOW:
        break;
    }
    return true;
}

void Item::setEnableFalse(){
    
}
void Item::setEnableTrue(){
    
}


bool Item::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){
    return true;
}

void Item::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){
}

void Item::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){
}