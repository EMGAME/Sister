//
//  ScorllMainlayer06.h
//  Sister
//
//  Created by 风飞逸 on 14-8-12.
//
//

#ifndef __Sister__ScorllMainlayer06__
#define __Sister__ScorllMainlayer06__

#include "cocos2d.h"

USING_NS_CC;

class ScorllMainlayer06: public Layer
{
public:
    ScorllMainlayer06();
    ~ScorllMainlayer06();
    
    virtual bool init();
    
    CREATE_FUNC(ScorllMainlayer06);
    
    virtual bool onTouchBegan(Touch* pTouch,Event* pEvent);
    virtual void onTouchEnded(Touch* pTouch,Event* pEvent);
};

#endif /* defined(__Sister__ScorllMainlayer06__) */
