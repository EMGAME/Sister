//
//  ScorllMainLayer04.h
//  Sister
//
//  Created by 风飞逸 on 14-8-12.
//
//

#ifndef __Sister__ScorllMainLayer04__
#define __Sister__ScorllMainLayer04__

#include "cocos2d.h"

USING_NS_CC;

class ScorllMainLayer04: public Layer
{
public:
    ScorllMainLayer04();
    ~ScorllMainLayer04();
    
    virtual bool init();
    
    CREATE_FUNC(ScorllMainLayer04);
    
    void menuCloseCallback01(cocos2d::Ref* pSender);
    void menuCloseCallback02(cocos2d::Ref* pSender);
    void menuCloseCallback03(cocos2d::Ref* pSender);
    void menuCloseCallback04(cocos2d::Ref* pSender);
    void menuCloseCallback05(cocos2d::Ref* pSender);
    void menuCloseCallback06(cocos2d::Ref* pSender);
    
};

#endif /* defined(__Sister__ScorllMainLayer04__) */
