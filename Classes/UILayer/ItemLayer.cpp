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
    menuItemSprite->setPosition(origin + Point(visibleSize.width - 60, 50));
    auto menu = Menu::create(menuItemSprite, NULL);
    menu->setPosition(Point::ZERO);
    
    this->addChild(menu);
    
    return true;
}

void ItemLayer::initItemXML()
{
    
    //要储存XML文件的路径
    std::string filePath = FileUtils::getInstance()->getWritablePath() + "sisterItem.xml";
    //log("filePath:%s", filePath.c_str());
    //xml文档
    XMLDocument *pDoc = new XMLDocument();
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
    XMLDocument *pDoc = new XMLDocument();
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
    showItems();
    //保存xml
    pDoc->SaveFile(filePath.c_str());
}

void ItemLayer::showItems()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    int x = 50, y = 50;
    for(auto itemSprite : m_AllEnableItems)
    {
        itemSprite->setPosition(origin + Point(x, y));
        x += 100;
        this->addChild(itemSprite);
    }
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
    XMLDocument *pDoc = new XMLDocument();
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