#include "AppDelegate.h"
#include "StartScene.h"
#include "game.h"
//#include "SuccessScene.h"
//#include "LoseScene.h"
#include "PowerManager.h"
#include "C2DXShareSDK.h"

USING_NS_CC;
using namespace cn::sharesdk;

AppDelegate::AppDelegate() {

}
//中文注释测试，大家好好哈哈哈哈哈哈哈哈哈哈哈哈哈，努力工作

AppDelegate::~AppDelegate() 
{
}

 bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }
    
    auto screenSize = glview->getFrameSize();
    auto designSize = Size(768,1136);
    auto resourceSize = Size(768,1136);
     
     //shareSdk配置
     C2DXShareSDK::open(CCString::create("3e985bbdcc89"), false);
     
     Dictionary *wcConfigDict = Dictionary::create();
     wcConfigDict -> setObject(CCString::create("wxc147c3906667a3d1"), "app_id");
     C2DXShareSDK::setPlatformConfig(C2DXPlatTypeWeixiSession, wcConfigDict);
     C2DXShareSDK::setPlatformConfig(C2DXPlatTypeWeixiTimeline, wcConfigDict);
     C2DXShareSDK::setPlatformConfig(C2DXPlatTypeWeixiFav, wcConfigDict);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	glview->setFrameSize(designSize.width, designSize.height);

	glview->setFrameZoomFactor(0.6f);

#endif

    glview->setDesignResolutionSize(designSize.width, designSize.height, ResolutionPolicy::NO_BORDER);
    
    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
     auto scene =StartScene::createScene();

    // run
    director->runWithScene(scene);
    //PowerManager::getInstance()->initWithNumber(4);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
