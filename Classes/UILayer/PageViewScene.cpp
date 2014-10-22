//
//  PageViewScene.cpp
//  Sister
//
//  Created by EMG on 14-10-5.
//
//

#include "PageViewScene.h"

bool PageViewScene::init()
{
    if (Layer::init())
    {
        auto cache = SpriteFrameCache::getInstance();
        cache->addSpriteFramesWithFile("ui_select.plist");
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Size winSize = Director::getInstance()->getWinSize();
        
        //背景
        auto bg = Sprite::createWithSpriteFrame(cache->getSpriteFrameByName("sel_bg.png"));
        bg->setPosition(Point(winSize.width / 2, winSize.height / 2));
        this->addChild(bg);
        
        auto pageView = MyPageView::create();
        pageView->setTouchEnabled(true);
        pageView->setSize(winSize);
        pageView->setPosition(Point::ZERO);

        //加载骨骼动画
        ArmatureDataManager::getInstance()->addArmatureFileInfo("UI/ui_select_bar.ExportJson");
       
        
        Layout* layout0 = Layout::create();
        layout0->setSize(Size(60, 40));
        ImageView* imageView = ImageView::create();
        imageView->setTouchEnabled(true);
        imageView->loadTexture("UI/NoColor.png", UI_TEX_TYPE_LOCAL);
        imageView->setScale9Enabled(true);
        imageView->setSize(Size(500, 500));
        imageView->setPosition(Point(winSize.width / 2.0f, winSize.height / 2.0f));
        imageView->addTouchEventListener(this, toucheventselector(PageViewScene::imageViewCallBack));
        
        selectBar01 = Armature::create( "ui_select_bar");
        selectBar01->setPosition(visibleSize.width/2,visibleSize.height/2);
        selectBar01->getAnimation()->play("normal");
        
        layout0->CCNode::addChild(selectBar01,0,0);
        layout0->addChild(imageView);
        
        Layout* layout1 = Layout::create();
        layout1->setSize(winSize);
        ImageView* imageView1 = ImageView::create();
        imageView1->setTouchEnabled(true);
        imageView1->loadTexture("UI/ui_select_shop.png");
        //imageView1->setSize(winSize);
        imageView1->setPosition(Point(layout1->getSize().width / 2.0f, layout1->getSize().height / 2.0f));
        imageView1->addTouchEventListener(this, toucheventselector(PageViewScene::imageView1CallBack));
        layout1->addChild(imageView1);
        
        Layout* layout2 = Layout::create();
        layout2->setSize(winSize);
        ImageView* imageView2 = ImageView::create();
        imageView2->setTouchEnabled(true);
        imageView2->loadTexture("sel_continue.png", UI_TEX_TYPE_PLIST);
        //imageView2->setSize(winSize);
        imageView2->setPosition(Point(layout2->getSize().width / 2.0f, layout2->getSize().height / 2.0f));
        imageView2->addTouchEventListener(this, toucheventselector(PageViewScene::imageView2CallBack));
        layout2->addChild(imageView2);
        
        Layout* layout3 = Layout::create();
        layout3->setSize(Size(60, 40));
        ImageView* imageView3 = ImageView::create();
        imageView3->setTouchEnabled(true);
        imageView3->loadTexture("sel_continue.png", UI_TEX_TYPE_PLIST);
        //imageView->setSize(Size(60, 40));
        imageView3->setPosition(Point(winSize.width / 2.0f, winSize.height / 2.0f));
        layout3->addChild(imageView3);
        
        pageView->addPage(layout0);
        pageView->addPage(layout1);
        pageView->addPage(layout2);
        pageView->addPage(layout3);
        
        pageView->addEventListenerPageView(this, pagevieweventselector(PageViewScene::pageViewEvent));
        
        //page_indicator
        Sprite* sprite0 =Sprite::createWithSpriteFrameName("sel_page_indicator_off.png");
        sprite0->setPosition(Point(winSize.width*0.5-75,100));
        addChild(sprite0,2);
        Sprite* sprite1 =Sprite::createWithSpriteFrameName("sel_page_indicator_off.png");
        sprite1->setPosition(Point(winSize.width*0.5-25,100));
        addChild(sprite1,2);
        Sprite* sprite2 =Sprite::createWithSpriteFrameName("sel_page_indicator_off.png");
        sprite2->setPosition(Point(winSize.width*0.5+25,100));
        addChild(sprite2,2);
        Sprite* sprite3 =Sprite::createWithSpriteFrameName("sel_page_indicator_off.png");
        sprite3->setPosition(Point(winSize.width*0.5+75,100));
        addChild(sprite3,2);
        
        Sprite* sprite =Sprite::createWithSpriteFrameName("sel_page_indicator_on.png");
        sprite->setPosition(Point(winSize.width*0.5 - 75,100));
        sprite->setTag(888);
        addChild(sprite,4);
        
        this->addChild(pageView);
    }
    return true;
}

void PageViewScene::pageViewEvent(Ref* pSender, PageViewEventType type)
{
    switch (type) {
        case PAGEVIEW_EVENT_TURNING:
        {
            PageView* pageView = dynamic_cast<PageView*>(pSender);
            long index = pageView->getCurPageIndex();
            auto sprite = (Sprite*)this->getChildByTag(888);
            Size winSize = Director::getInstance()->getWinSize();
            switch (index) {
                case 0:
                {
                    sprite->setPositionX(winSize.width*0.5-75);
                    
                }
                    break;
                case 1:
                {
                    sprite->setPositionX(winSize.width*0.5-25);
                    break;
                }
                case 2:
                {
                    sprite->setPositionX(winSize.width*0.5+25);
                    break;
                }
                case 3:
                {
                    sprite->setPositionX(winSize.width*0.5+75);
                    break;
                }
                default:
                    break;
            }
        }
            break;
            
        default:
            break;
    }
}

void PageViewScene::imageViewCallBack(cocos2d::Ref *pSender, TouchEventType type)
{
    switch (type) {
        case TOUCH_EVENT_ENDED:
        {
            Director::getInstance()->replaceScene(GameScene21::createScene());
        }
            break;
        default:
            break;
    }
    
}

void PageViewScene::imageView1CallBack(cocos2d::Ref *pSender, TouchEventType type)
{
    switch (type) {
        case TOUCH_EVENT_ENDED:
        {
            log("点击");
        }
            break;
        default:
            break;
    }
}

void PageViewScene::imageView2CallBack(cocos2d::Ref *pSender, TouchEventType type)
{
    switch (type) {
        case TOUCH_EVENT_ENDED:
        {
            log("点击");
        }
            break;
        default:
            break;
    }
}

Scene* PageViewScene::createScene()
{
    Scene* scene = Scene::create();
    Layer* layer = PageViewScene::create();
    scene->addChild(layer);
    return scene;
}