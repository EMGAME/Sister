//
//  ScorllMainlayer02.h
//  Sister
//
//  Created by 风飞逸 on 14-8-12.
//
//

#ifndef __Sister__ScorllMainlayer02__
#define __Sister__ScorllMainlayer02__

#include "cocos2d.h"

USING_NS_CC;

class ScorllMainlayer02: public Layer
{
public:
    ScorllMainlayer02();
    ~ScorllMainlayer02();
    
    virtual bool init();
    
    CREATE_FUNC(ScorllMainlayer02);
    
    void menuCloseCallback01(cocos2d::Ref* pSender);
    void menuCloseCallback02(cocos2d::Ref* pSender);
    void menuCloseCallback03(cocos2d::Ref* pSender);
    void menuCloseCallback04(cocos2d::Ref* pSender);
    void menuCloseCallback05(cocos2d::Ref* pSender);
    void menuCloseCallback06(cocos2d::Ref* pSender);
    
};

#endif /* defined(__Sister__ScorllMainlayer02__) */
