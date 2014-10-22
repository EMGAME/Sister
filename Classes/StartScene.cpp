//
//  StartScene.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-11.
//
//

#include "StartScene.h"
#include "SelectScene/ScrollViewScene.h"
#include "UILayer/SuccessLayer.h"
#include "UILayer/ItemLayer.h"
#include "UILayer/PowerManager.h"
#include "UILayer/PageViewScene.h"
#include "C2DXShareSDK.h"
#include "C2DXiOSShareSDK.h"

USING_NS_CC;
using namespace cn::sharesdk;



void shareResultHandler(C2DXResponseState state, C2DXPlatType platType, Dictionary *shareInfo, Dictionary *error)
{
    switch (state) {
        case C2DXResponseStateSuccess:
            log("分享成功");
            break;
        case C2DXResponseStateFail:
            log("分享失败");
            break;
        default:
            break;
    }
}

void authResultHandler(C2DXResponseState state, C2DXPlatType platType, Dictionary *error)
{
    switch (state) {
        case C2DXResponseStateSuccess:
            log("授权成功");
            break;
        case C2DXResponseStateFail:
            log("授权失败");
            break;
    }
}

void getUserResultHandler(C2DXResponseState state, C2DXPlatType platType, Dictionary *userInfo, Dictionary *error)
{
    if (state == C2DXResponseStateSuccess)
    {
        //输出用户信息
        Array *allKeys = userInfo -> allKeys();
        allKeys->retain();
        for (int i = 0; i < allKeys -> count(); i++)
        {
            String *key = (String *)allKeys -> objectAtIndex(i);
            Object *obj = userInfo -> objectForKey(key -> getCString());
            
            CCLog("key = %s", key -> getCString());
            if (dynamic_cast<String *>(obj))
            {
                CCLog("value = %s", dynamic_cast<String *>(obj) -> getCString());
            }
            else if (dynamic_cast<Integer *>(obj))
            {
                CCLog("value = %d", dynamic_cast<Integer *>(obj) -> getValue());
            }
            else if (dynamic_cast<Double *>(obj))
            {
                CCLog("value = %f", dynamic_cast<Double *>(obj) -> getValue());
            }
        }
        allKeys->release();
    }
}


Scene* StartScene::createScene(){
    auto scene = Scene::create();
    auto layer = StartScene::create();
    scene->addChild(layer);
    return scene;
}

bool StartScene::init(){
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto winSize = Director::getInstance()->getWinSize();
    
    auto bg = Sprite::create("UI/ui_start_bg.png");
    bg->setPosition(Point(winSize.width / 2, winSize.height / 2));
    this->addChild(bg);
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("UI/ui_start.plist");
    
    auto classBtn = Button::create();
    classBtn->loadTextureNormal("ui_start_btn_class.png",UI_TEX_TYPE_PLIST);
    classBtn->addTouchEventListener(this, toucheventselector(StartScene::classBtnCallBack));
    classBtn->setPosition(Point(395, 314));
    this->addChild(classBtn,2);
    
    auto zanBtn = Button::create();
    zanBtn->loadTextureNormal("ui_start_btn_zan.png",UI_TEX_TYPE_PLIST);
    zanBtn->addTouchEventListener(this, toucheventselector(StartScene::zanBtnCallBack));
    zanBtn->setPosition(Point(208, 178));
    this->addChild(zanBtn,2);
    
    auto crazyBtn = Button::create();
    crazyBtn ->loadTextureNormal("ui_start_btn_crazy.png",UI_TEX_TYPE_PLIST);
    crazyBtn->addTouchEventListener(this, toucheventselector(StartScene::crazyBtnCallBack));
    crazyBtn->setPosition(Point(585, 178));
    this->addChild(crazyBtn,2);
    
    ArmatureDataManager::getInstance()->addArmatureFileInfo("UI/start_show.ExportJson");
    
    auto start_show = Armature::create( "start_show");
    start_show->setPosition(Point::ZERO);
    start_show->setAnchorPoint(Point::ZERO);
    start_show->getAnimation()->play("normal");
    this->addChild(start_show,1);
    
    
    PowerManager::getInstance()->initWithNumber(4);


    return true;
}

void StartScene::classBtnCallBack(){
    Director::getInstance()->replaceScene(PageViewScene::createScene());
}

void StartScene::zanBtnCallBack(){

}

void StartScene::crazyBtnCallBack(){
    //shareInit();
    share();
}
void StartScene::shareInit(){
    //C2DXShareSDK::authorize(C2DXPlatTypeFacebook, authResultHandler);
    
    C2DXShareSDK::getUserInfo(C2DXPlatTypeWeixiFav, getUserResultHandler);
    C2DXShareSDK::getUserInfo(C2DXPlatTypeWeixiSession, getUserResultHandler);
    C2DXShareSDK::getUserInfo(C2DXPlatTypeWeixiTimeline, getUserResultHandler);

    
}


void StartScene::share(){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Dictionary *content = CCDictionary::create();
    content -> setObject(CCString::create("这里是content"), "content");
    content -> setObject(CCString::create("Resources/logo.png"), "image");
    content -> setObject(CCString::create("全民5秒钟"), "title");
    content -> setObject(CCString::create("每天5秒钟，天天跟我做，这里是description"), "description");
    content -> setObject(CCString::create("www.yimankeji.com"), "url");
    content -> setObject(CCString::createWithFormat("%d", C2DXContentTypeNews), "type");
    
    C2DXShareSDK::showShareMenu(NULL, content, Point(visibleSize.width/2, visibleSize.height), C2DXMenuArrowDirectionDown, shareResultHandler);
}