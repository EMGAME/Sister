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
USING_NS_CC;

//玩家获得的星星数

class SuccessLayer:public Layer{
public:
    SuccessLayer();
    ~SuccessLayer();
    
    virtual bool init(Ref* pSender,std::string passTip);
    static SuccessLayer* create(Ref* pSender,std::string passTip);
    
    Node* controllNode;
    
    void shareCallBack();
    void restartCallBack();
    void nextCallback();
    void pushLayer(Ref* pSender,int starNum,std::string passTip);
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
