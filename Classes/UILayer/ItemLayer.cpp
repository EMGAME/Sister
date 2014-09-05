//
//  ItemLayer.cpp
//  Sister
//
//  Created by EMG on 14-8-22.
//
//

#include "ItemLayer.h"

bool ItemLayer::init()
{
    Size winSize = Director::getInstance()->getWinSize();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ui_common.plist");
    auto menuItemSprite = MenuItemSprite::create(Sprite::createWithSpriteFrameName("common_btn_home.png"), Sprite::createWithSpriteFrameName("common_btn_home.png"), CC_CALLBACK_0(ItemLayer::menuCallBack, this));
    
    menuItemSprite->setAnchorPoint(Point::ANCHOR_BOTTOM_RIGHT);
    menuItemSprite->setPosition(origin + Point(visibleSize.width - 15, 25));
    auto menu = Menu::create(menuItemSprite, NULL);
    menu->setPosition(Point::ZERO);
    
    isShowed = false;
    
    //测试模式
    m_Rect = Rect(200, 200, 200, 200);
    setcurType(ITEM_TYPE_WATCH);
    
    this->addChild(menu);
    
    return true;
}

void ItemLayer::initItemXML()
{
    
    //要储存XML文件的路径
    std::string filePath = FileUtils::getInstance()->getWritablePath() + "sisterItem.xml";
    //log("filePath:%s", filePath.c_str());
    //xml文档
    tinyxml2::XMLDocument *pDoc = new tinyxml2::XMLDocument();
    if (NULL==pDoc) {
        return;
    }
    
    //判断文件是否存在，存在则跳出
    pDoc->LoadFile(filePath.c_str());
    //得到跟节点
    XMLElement *rootEle = pDoc->RootElement();
    if (rootEle) {
        return;
    }
    
    //xml声明
    XMLDeclaration *pDel = pDoc->NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\"");
    if (NULL==pDel) {
        return;
    }
    pDoc->LinkEndChild(pDel);
    //根节点sisterItems
    XMLElement *sisterItemsElement = pDoc->NewElement("sisterItems");
    sisterItemsElement->SetAttribute("version", "1.0");//给节点设置属性
    pDoc->LinkEndChild(sisterItemsElement);
    //节点item
    XMLElement *itemElement = pDoc->NewElement("item");
    itemElement->SetAttribute("id", 01);
    itemElement->SetAttribute("enable", true);
    itemElement->LinkEndChild(pDoc->NewText("common_btn_home.png"));
    sisterItemsElement->LinkEndChild(itemElement);
    
    itemElement = pDoc->NewElement("item");
    itemElement->SetAttribute("id", 02);
    itemElement->LinkEndChild(pDoc->NewText("common_btn_close.png"));
    itemElement->SetAttribute("enable", true);
    sisterItemsElement->LinkEndChild(itemElement);
    
    itemElement = pDoc->NewElement("item");
    itemElement->SetAttribute("id", 03);
    itemElement->LinkEndChild(pDoc->NewText("common_btn_help.png"));
    itemElement->SetAttribute("enable", true);
    sisterItemsElement->LinkEndChild(itemElement);
    
    itemElement = pDoc->NewElement("item");
    itemElement->SetAttribute("id", 04);
    itemElement->LinkEndChild(pDoc->NewText("common_btn_libao.png"));
    itemElement->SetAttribute("enable", true);
    sisterItemsElement->LinkEndChild(itemElement);
    
    itemElement = pDoc->NewElement("item");
    itemElement->SetAttribute("id", 05);
    itemElement->LinkEndChild(pDoc->NewText("common_btn_pause.png"));
    itemElement->SetAttribute("enable", true);
    sisterItemsElement->LinkEndChild(itemElement);
    
    pDoc->SaveFile(filePath.c_str());//保存文件 参数：路径
    pDoc->Print();//打印
    delete pDoc;

}

void ItemLayer::menuCallBack()
{
    //xml文件路径
    std::string filePath = FileUtils::getInstance()->getWritablePath() + "sisterItem.xml";
    //log("path:%s", filePath.c_str());
    //xmlDoc
    tinyxml2::XMLDocument *pDoc = new tinyxml2::XMLDocument();
    pDoc->LoadFile(filePath.c_str());
    //得到跟节点
    XMLElement *rootEle = pDoc->RootElement();
    //跟节点的第一个子节点item
    XMLElement *itemEle = rootEle->FirstChildElement();
    
    m_AllEnableItems.clear();
    
    
    do{
        bool enable = false;
        itemEle->QueryBoolAttribute("enable", &enable);
        if (enable) {
            //strcpy(fileName, itemEle->GetText());
            auto itemSprite = Sprite::createWithSpriteFrameName(itemEle->GetText());
            m_AllEnableItems.pushBack(itemSprite);
        }
        itemEle = itemEle->NextSiblingElement();
    }while (itemEle);
    
    
    
    if (isShowed == false) {
        showItems();
    }else{
        hideItems();
    }
    
    
    //保存xml
    pDoc->SaveFile(filePath.c_str());
}

void ItemLayer::showItems()
{
    enableItem = Node::create();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    int x = visibleSize.width-100, y = 25,tag = 1;
    float delayTime = 0;
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = CC_CALLBACK_2(ItemLayer::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(ItemLayer::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(ItemLayer::onTouchEnded, this);
    
    
    for(auto itemSprite : m_AllEnableItems)
    {
        itemSprite->setAnchorPoint(Point::ANCHOR_BOTTOM_RIGHT);
        itemSprite->setPosition(origin + Point(visibleSize.width - 15, 25));
        
        auto itemAction = MoveTo::create(0.4f, origin+Point(x, y));
        
        auto actionDelay = DelayTime::create(delayTime);
        auto ease = EaseBackInOut::create(itemAction);
        
        auto sequence = Sequence::create(actionDelay,ease, NULL);
        
        itemSprite->runAction(sequence);
        
        x -= 100;
        delayTime += 0.1;
        tag += 1;
    
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), itemSprite);
        startPosition = itemSprite->getPosition();
        
        enableItem->addChild(itemSprite,1,tag);
    }
    this->addChild(enableItem,1,1);
    isShowed = true;
}

void ItemLayer::hideItems(){
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    float delayTime = 0;
    
    for(auto itemSprite : m_AllEnableItems)
    {
        itemSprite->setAnchorPoint(Point::ANCHOR_BOTTOM_RIGHT);
        
        auto itemAction = MoveTo::create(0.4f, origin + Point(visibleSize.width - 15, 25));
        
        auto actionDelay = DelayTime::create(delayTime);
        auto ease = EaseBackInOut::create(itemAction);
        
        auto sequence = Sequence::create(actionDelay,ease,CallFunc::create([&](){enableItem->removeChild(itemSprite);}),
                                         NULL);
        
        itemSprite->runAction(sequence);
        delayTime += 0.1;
        
        enableItem->removeChild(itemSprite);
    }
    this->removeChild(enableItem);
    isShowed = false;
}



void ItemLayer::addToItems(Node* pSender, int id)
{
    //执行物品飞向物品栏按钮的动画
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    auto moveTo = MoveTo::create(1.0f, origin + Point(visibleSize.width - 60, 50));
    auto seq = Sequence::create(moveTo, CallFunc::create(CC_CALLBACK_0(ItemLayer::addToItemsCallBack, this, pSender)), NULL);
    pSender->runAction(seq);
    
    //xml文件路径
    std::string filePath = FileUtils::getInstance()->getWritablePath() + "sisterItem.xml";
    //xmlDoc
    tinyxml2::XMLDocument *pDoc = new tinyxml2::XMLDocument();
    pDoc->LoadFile(filePath.c_str());
    //得到跟节点
    XMLElement *rootEle = pDoc->RootElement();
    //跟节点的第一个子节点item
    XMLElement *itemEle = rootEle->FirstChildElement();
    do{
        int itemId = 0;
        itemEle->QueryIntAttribute("id", &itemId);
        if (itemId == id) {
            itemEle->SetAttribute("enable", true);
            break;
        }
        itemEle = itemEle->NextSiblingElement();
    }while (itemEle);
    //保存xml
    pDoc->SaveFile(filePath.c_str());
}

void ItemLayer::addToItemsCallBack(Node* pSender)
{
    pSender->removeFromParent();
}
void ItemLayer::ItemInit(cocos2d::Rect pRect,ITEM_TYPE mTypes){
    setmRect(pRect);
    setcurType(mTypes);

}
bool ItemLayer::ItemIsContained(){
    return getmRect().containsPoint(getcurSprite()->getPosition());
}

bool ItemLayer::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){
    auto target = static_cast<Sprite* >(pEvent->getCurrentTarget());
    Point locationInNode = pTouch->getLocation();
    Rect pRect = target->getBoundingBox();
    
    if (pRect.containsPoint(locationInNode)) {
        return true;
    }
    
    return false;
}
void ItemLayer::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){
    auto target = static_cast<Sprite* >(pEvent->getCurrentTarget());
    target->setPosition(target->getPosition()+pTouch->getDelta());

}
void ItemLayer::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){
    auto target = static_cast<Sprite*>(pEvent->getCurrentTarget());
    if (m_Rect.containsPoint(pTouch->getLocation())) {
        switch (getcurType()) {
            case ITEM_TYPE_FLOWER:
                
                log("Flower");
                break;
            case ITEM_TYPE_WATCH:
                log("Watch");
                break;
            case ITEM_TYPE_WINDOW:
                
                log("Window");
                break;
            case ITEM_TYPE_CA:
                
                log("Ca");
                break;
        }
    }else {
        
        target->runAction(MoveTo::create(0.1f, startPosition));
    }
    
}
