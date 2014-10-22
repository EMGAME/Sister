//
//  FailureLayer.h
//  Sister
//
//  Created by 风飞逸 on 14-8-25.
//
//

#ifndef __Sister__FailureLayer__
#define __Sister__FailureLayer__

#include "cocos2d.h"
#include "../SelectScene/ScrollViewScene.h"
#include "../ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;
//玩家获得的星星数

class FailureLayer:public Layer{
public:
    FailureLayer();
    ~FailureLayer();
    
    virtual bool init(Ref* pSender);
    static FailureLayer* create(Ref* pSender);
    
    Node* controllNode;
    
    void shareCallBack(Ref* pSender,TouchEventType type);
    void restartCallBack(Ref* pSender,TouchEventType type);
    void homeCallback(Ref* pSender,TouchEventType type);
    void pushLayer(Ref* pSender);

    //uilayer的引用
    Layer* uiLayer;
    void setString(std::string m_string);
    CC_SYNTHESIZE(std::string, mTip, Tip);
    
};

#endif /* defined(__Sister__FailureLayer__) */
