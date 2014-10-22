//
//  SuccessLayer.h
//  Sister
//
//  Created by 风飞逸 on 14-8-25.
//
//

#ifndef __Sister__SuccessLayer__
#define __Sister__SuccessLayer__

#include "cocos2d.h"
#include "../SelectScene/ScrollViewScene.h"
#include "../ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

//玩家获得的星星数

class SuccessLayer:public Layer{
public:
    SuccessLayer();
    ~SuccessLayer();
    
    virtual bool init(Ref* pSender);
    static SuccessLayer* create(Ref* pSender);
    
    Node* controllNode;
    
    void shareCallBack(Ref* pSender,TouchEventType type);
    void homeCallBack(Ref* pSender,TouchEventType type);
    void nextCallback(Ref* pSender,TouchEventType type);
    void pushLayer(Ref* pSender,int starNum);
    
    void showStar(int starNum);
    
    //3颗星星
    Sprite* star1;
    Sprite* star2;
    Sprite* star3;
    
    //uilayer的引用
    Layer* uiLayer;
    void setString(std::string m_string);
    CC_SYNTHESIZE(std::string, mTip, Tip);
    
};

#endif /* defined(__Sister__SuccessLayer__) */
