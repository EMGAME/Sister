//
//  ScrollVIew.cpp
//  Sister
//
//  Created by 风飞逸 on 14-8-12.
//
//

#include "../UILayer/GoldManager.h"
#include "ScrollView.h"
#include "ScrollViewScene.h"

ScrollView::ScrollView()
{
    m_Page = 0;
    m_CurPage = 0;
    m_PageLayer = CCArray::createWithCapacity(5);
    m_PageLayer->retain();
    
    init();
}
ScrollView::~ScrollView()
{
    m_PageLayer->removeAllObjects();
    m_PageLayer->release();
}

bool ScrollView::init()
{
    bool bRet = false;
    
    do {
        CC_BREAK_IF(!CCLayer::init());
        
        bRet = true;
    } while (0);
//    GoldMgr = GoldManager::getInstance();
//    log("刚刚加载的时候金币为：%d",GoldMgr->readGold());

    
    setTouchEnabled(true);
	//设置为单点响应
	setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
    
    auto myListener = EventListenerTouchOneByOne::create();
    myListener->onTouchBegan = CC_CALLBACK_2(ScrollView::onTouchBegan, this);
    myListener->onTouchMoved = CC_CALLBACK_2(ScrollView::onTouchMoved, this);
    myListener->onTouchEnded = CC_CALLBACK_2(ScrollView::onTouchEnded, this);
    myListener->onTouchCancelled = CC_CALLBACK_2(ScrollView::onTouchCancelled, this);
    
    
    return bRet;
}

//void ScrollView::onEnter()
//{
//    CCLayer::onEnter();
//    //CCDirector::sharedDirector()->getInstance()->addTargetedDelegate(this, 0, true);
//}
//
//void ScrollView::onExit()
//{
//    //CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
//    CCLayer::onExit();
//}

void ScrollView::goToPage()
{
    MoveTo *moveTo = MoveTo::create(0.2f, Point::Point(-m_CurPage * WINDOW_WIDTH, 0));
    
    this->runAction(moveTo);
}

void ScrollView::addPage(cocos2d::Layer *pPageLayer)
{
    if (pPageLayer) {
        // 设置成一页大小
        pPageLayer->setContentSize(Size::Size(WINDOW_WIDTH, WINDOW_HEIGHT));
        pPageLayer->setPosition(Point(WINDOW_WIDTH * m_Page, 0));
        this->addChild(pPageLayer);
        // 添加到页
        m_PageLayer->addObject(pPageLayer);
        m_Page = m_PageLayer->count();
    }
}

//公开方法进行页面跳转
void ScrollView::gotoUserChoosePage(int _isToOrBack){
    if (0 == _isToOrBack) {
        //上一页
        if (m_CurPage > 0) {
            --m_CurPage;
        }
    }else if(1 == _isToOrBack){
        //下一页
        if (m_CurPage < (m_Page - 1)) {
            ++m_CurPage;
        }
    }
    
    // 执行跳转动画
    goToPage();
}

bool ScrollView::onTouchBegan(Touch *pTouch, Event  *pEvent){
    m_TouchDownPoint = CCDirector::getInstance()->convertToGL(pTouch->getLocationInView());
    m_TouchCurPoint = m_TouchDownPoint;
    
    return true;
}
void ScrollView::onTouchMoved(Touch *pTouch, Event  *pEvent){
    // 移动
    Point touchPoint = CCDirector::getInstance()->convertToGL(pTouch->getLocationInView());
    Point posPoint = Point::Point(getPositionX() + touchPoint.x - m_TouchCurPoint.x, getPositionY());
    setPosition(posPoint);
    m_TouchCurPoint = touchPoint;
}
void ScrollView::onTouchEnded(Touch *pTouch, Event  *pEvent){
    m_TouchUpPoint = CCDirector::getInstance()->convertToGL(pTouch->getLocationInView());

//    GoldMgr->clickReduceGold();
//    log("当前剩余金币量%d",GoldMgr->readGold());
    // 计算按下和抬起的偏移量
    float offset = (m_TouchUpPoint.x - m_TouchDownPoint.x) * (m_TouchUpPoint.x - m_TouchDownPoint.x) + (m_TouchUpPoint.y - m_TouchDownPoint.y) * (m_TouchUpPoint.y - m_TouchDownPoint.y);
    
    if (offset < (TOUCH_DELTA * TOUCH_DELTA)) {
        // 点击
        // 向子Layer发送Click消息
        //((CCLayer*) m_PageLayer->objectAtIndex(m_CurPage))->ccTouchBegan(pTouch, pEvent);
    }
    else {
        // 滑动结束
        int offset = getPositionX() - m_CurPage * (-WINDOW_WIDTH);
        //if (offset > WINDOW_WIDTH / 2) {
        if (offset > 50) {
//            GoldMgr->subGold(30);
//            log("上一页金币为：%d",GoldMgr->readGold());
            // 上一页
            if (m_CurPage > 0) {
                --m_CurPage;
                Sprite *sprite =  (Sprite *)ScrollViewScene::sharedSC()->getChildByTag(888);
                sprite->setPosition(Point(sprite->getPositionX()-50,sprite->getPositionY()));
            }
        }
        //else if (offset < -WINDOW_WIDTH / 2) {
        else if (offset < -50) {
//            GoldMgr->addGold(20);
//            log("下一页金币为：%d",GoldMgr->readGold());
            // 下一页
            if (m_CurPage < (m_Page - 1)) {
                ++m_CurPage;
                Sprite *sprite =  (Sprite *)ScrollViewScene::sharedSC()->getChildByTag(888);
                sprite->setPosition(Point(sprite->getPositionX()+50,sprite->getPositionY()));
            }
        }
        
        // 执行跳转动画
        goToPage();
    }
}
void ScrollView::onTouchCancelled(Touch *pTouch, Event  *pEvent){
    
}
