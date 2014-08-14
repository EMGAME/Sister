//
//  ScrollVIew.h
//  Sister
//
//  Created by 风飞逸 on 14-8-12.
//
//

#ifndef __Sister__ScrollVIew__
#define __Sister__ScrollVIew__

#include "cocos2d.h"
#include "../GoldManager.h"

USING_NS_CC;

// 屏幕尺寸
const float WINDOW_WIDTH = 1136.0f;
const float WINDOW_HEIGHT = 640.0f;

// 触摸误差
const int TOUCH_DELTA = 20;

class ScrollView: public Layer
{
private:
    // 按下点
    Point m_TouchDownPoint;
    // 抬起点 配合使用判断是否为点击事件
    Point m_TouchUpPoint;
    // 当前触摸点
    Point m_TouchCurPoint;
    
private:
    // 总页数
    int m_Page;
    // 当前显示页
    int m_CurPage;
    
private:
    // 存储所有页层
    Array *m_PageLayer;
    
private:
    // 跳转页
    void goToPage();
    
public:
    ScrollView();
    ~ScrollView();
    
    virtual bool init();
    
    CREATE_FUNC(ScrollView);
    
public:
    // 初始化相关
    //virtual void onEnter();
    //virtual void onExit();
    
    //gold检测
 //   GoldManager* GoldMgr;
    // 触摸事件相关
    bool onTouchBegan(Touch *pTouch, Event  *pEvent);
    void onTouchMoved(Touch *pTouch, Event  *pEvent);
    void onTouchEnded(Touch *pTouch, Event  *pEvent);
    void onTouchCancelled(Touch *pTouch, Event  *pEvent);
    
public:
    // 添加页
    void addPage(Layer *pPageLayer);
    //公开方法跳转页面
    void gotoUserChoosePage(int _isToOrBack);
    
};

#endif /* defined(__Sister__ScrollVIew__) */
