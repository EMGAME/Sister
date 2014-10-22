//
//  PageViewScene.h
//  Sister
//
//  Created by EMG on 14-10-5.
//
//

#ifndef __Sister__PageViewScene__
#define __Sister__PageViewScene__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "game.h"


USING_NS_CC;
using namespace ui;

class PageViewScene : public Layer
{
public:
    virtual bool init();
    static Scene* createScene();
    CREATE_FUNC(PageViewScene);
    
    void pageViewEvent(Ref* pSender, PageViewEventType type);
    void imageViewCallBack(Ref* pSender, TouchEventType type);
    void imageView1CallBack(Ref* pSender, TouchEventType type);
    void imageView2CallBack(Ref* pSender, TouchEventType type);

public:
    Armature* selectBar01;
};

class MyPageView : public PageView
{
public:
    void handleReleaseLogic(const Point &touchPoint) override
    {
        if (_pages.size() <= 0)
        {
            return;
        }
        Widget* curPage = _pages.at(_curPageIdx);
        if (curPage)
        {
            Point curPagePos = curPage->getPosition();
            ssize_t pageCount = _pages.size();
            float curPageLocation = curPagePos.x;
            float pageWidth = getSize().width;
            float boundary = pageWidth/2.0f;
            if(boundary > 50.0f)boundary = 50.0f;//调整灵敏度
            if (curPageLocation <= -boundary)
            {
                if (_curPageIdx >= pageCount-1)
                {
                    scrollPages(-curPageLocation);
                }
                else
                {
                    scrollToPage(_curPageIdx+1);
                }
            }
            else if (curPageLocation >= boundary)
            {
                if (_curPageIdx <= 0)
                {
                    scrollPages(-curPageLocation);
                }
                else
                {
                    scrollToPage(_curPageIdx-1);
                }
            }
            else
            {
                scrollToPage(_curPageIdx);
            }
        }
    }
    
    CREATE_FUNC(MyPageView);
};

#endif /* defined(__Sister__PageViewScene__) */
