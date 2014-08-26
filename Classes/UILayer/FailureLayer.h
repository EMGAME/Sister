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
USING_NS_CC;

//玩家获得的星星数

class FailureLayer:public Layer{
public:
    FailureLayer();
    ~FailureLayer();
    
    virtual bool init(Ref* pSender,std::string loseTip);
    static FailureLayer* create(Ref* pSender,std::string loseTip);
    
    Node* controllNode;
    
    void shareCallBack();
    void restartCallBack();
    void homeCallback();
    void pushLayer(Ref* pSender,std::string loseTip);

    //uilayer的引用
    Layer* uiLayer;
    void setString(std::string m_string);
    CC_SYNTHESIZE(std::string, mTip, Tip);
    
};

#endif /* defined(__Sister__FailureLayer__) */
