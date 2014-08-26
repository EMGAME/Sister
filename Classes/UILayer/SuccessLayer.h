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
class SuccessLayer:public Layer{
public:
    SuccessLayer();
    ~SuccessLayer();
    
    virtual bool init();
    
    void shareCallBack();
    void restartCallBack();
    void nextCallback();
    
    void setString(std::string m_string);
    CC_SYNTHESIZE(std::string, mTip, Tip);
    CREATE_FUNC(SuccessLayer);
    
};

#endif /* defined(__Sister__SuccessLayer__) */
