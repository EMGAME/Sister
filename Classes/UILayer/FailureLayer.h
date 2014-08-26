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

class FailureLayer:public Layer{
public:
    FailureLayer();
    ~FailureLayer();
    
    virtual bool init();
    
    void shareCallBack();
    void restartCallBack();
    void nextCallback();
    
    void setString(std::string m_string);
    CC_SYNTHESIZE(std::string, mTip, Tip);
    CREATE_FUNC(FailureLayer);
};

#endif /* defined(__Sister__FailureLayer__) */
