//
//  ScrollViewScene.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-12.
//
//
#include "ScrollViewScene.h"
#include "ScrollView.h"
#include "ScorllMainLayer01.h"
#include "ScorllMainLayer02.h"
#include "ScorllMainLayer03.h"
#include "ScorllMainLayer04.h"
#include "ScorllMainLayer05.h"
#include "ScorllMainLayer06.h"
#include "../StartScene.h"

//using namespace CocosDenshion;
//声明静态变量

static ScrollView *scrollView;

static ScrollViewScene *sc;

ScrollViewScene *ScrollViewScene::sharedSC(){
    if(sc != NULL){
        return sc;
    }
    return  NULL;
}

ScrollViewScene::ScrollViewScene()
{
}

bool ScrollViewScene::init()
{
    sc = this;
    
    bool bRet = false;
    
    do {
        CC_BREAK_IF(!CCScene::init());
        auto winSize = Director::getInstance()->getWinSize();
        scrollView = ScrollView::create();
        
        for (int i=0; i<6; ++i) {
            if (0==i) {
                ScorllMainLayer01 *layer = ScorllMainLayer01::create();
                layer->setTag(i);
                scrollView->addPage(layer);
            }else if(1==i){
                auto layer = ScorllMainlayer02::create();
                layer->setTag(i);
                scrollView->addPage(layer);
            }else if(2==i){
                auto layer = ScorllMainlayer03::create();
                layer->setTag(i);
                scrollView->addPage(layer);
                
            }else if(3==i){
                auto layer = ScorllMainLayer04::create();
                layer->setTag(i);
                scrollView->addPage(layer);
            }else if(4==i){
                auto layer = ScorllMainlayer05::create();
                layer->setTag(i);
                scrollView->addPage(layer);
                
            }else if(5==i){
                auto layer = ScorllMainlayer06::create();
                layer->setTag(i);
                scrollView->addPage(layer);
            }
            
        }
        
        Size size = CCDirector::getInstance()->getWinSize();
        Size visibleSize = Director::getInstance()->getVisibleSize();
       
        //初始化信息
        SpriteFrameCache *cache = SpriteFrameCache::getInstance();
        cache->addSpriteFramesWithFile("ui_select.plist");
        
        auto spritebg =Sprite::createWithSpriteFrameName("sel_bg.png");
        spritebg->setAnchorPoint(Point::ZERO);
        spritebg->setPosition(Point::ZERO);
        addChild(spritebg,0);
        
        auto lighter = Sprite::createWithSpriteFrameName("sel_lighter.png");
        lighter->setPosition(Point(size.width/2,size.height/2));
        addChild(lighter,1);
        
        //page_indicator
        Sprite* sprite1 =Sprite::createWithSpriteFrameName("sel_page_indicator_off.png");
        sprite1->setPosition(Point(size.width*0.5-125,100));
        addChild(sprite1,2);
        Sprite* sprite2 =Sprite::createWithSpriteFrameName("sel_page_indicator_off.png");
        sprite2->setPosition(Point(size.width*0.5-75,100));
        addChild(sprite2,2);
        Sprite* sprite3 =Sprite::createWithSpriteFrameName("sel_page_indicator_off.png");
        sprite3->setPosition(Point(size.width*0.5-25,100));
        addChild(sprite3,2);
        Sprite* sprite4 =Sprite::createWithSpriteFrameName("sel_page_indicator_off.png");
        sprite4->setPosition(Point(size.width*0.5+25,100));
        addChild(sprite4,2);
        Sprite* sprite5 =Sprite::createWithSpriteFrameName("sel_page_indicator_off.png");
        sprite5->setPosition(Point(size.width*0.5+75,100));
        addChild(sprite5,2);
        Sprite* sprite6 =Sprite::createWithSpriteFrameName("sel_page_indicator_off.png");
        sprite6->setPosition(Point(size.width*0.5+125,100));
        addChild(sprite6,2);
        
        Sprite* sprite =Sprite::createWithSpriteFrameName("sel_page_indicator_on.png");
        sprite->setPosition(Point(size.width*0.5 - 125,100));
        sprite->setTag(888);
        addChild(sprite,4);
       
        cache->addSpriteFramesWithFile("ui_common.plist","ui_common.png");
        
        auto backBtn = MenuItemSprite::create(Sprite::createWithSpriteFrameName("common_btn_back.png"),
                                                Sprite::createWithSpriteFrameName("common_btn_back.png"),
                                                CC_CALLBACK_1(ScrollViewScene::backBtnCallback, this));
        
        backBtn->setAnchorPoint(Point::ANCHOR_TOP_LEFT);
        backBtn->setPosition(Point(60,visibleSize.height-20));
        
        auto menu = Menu::create(backBtn, NULL);
        menu->setPosition(Point::ZERO);
        this->addChild(menu, 1);
        
        this->addChild(scrollView);
        bRet = true;
    } while (0);
    
    return bRet;
}

void ScrollViewScene::backBtnCallback(cocos2d::Ref* pSender){
    CCDirector::getInstance()->replaceScene(CCTransitionFade::create(0.5, StartScene::createScene()));
}