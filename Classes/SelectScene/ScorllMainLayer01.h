//
//  ScorllMainLayer01.h
//  Sister
//
//  Created by 风飞逸 on 14-8-12.
//
//

#ifndef __Sister__ScorllMainLayer01__
#define __Sister__ScorllMainLayer01__

#include "cocos2d.h"

USING_NS_CC;

class ScorllMainLayer01: public Layer
{
public:
    ScorllMainLayer01();
    ~ScorllMainLayer01();
    
    virtual bool init();
    
    CREATE_FUNC(ScorllMainLayer01);
    
    void menuCloseCallback01(cocos2d::Ref* pSender);
    void menuCloseCallback02(cocos2d::Ref* pSender);
    void menuCloseCallback03(cocos2d::Ref* pSender);
    void menuCloseCallback04(cocos2d::Ref* pSender);
    void menuCloseCallback05(cocos2d::Ref* pSender);
    void menuCloseCallback06(cocos2d::Ref* pSender);
    
};

#endif /* defined(__Sister__ScorllMainLayer01__) */
