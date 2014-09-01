//
//  TipLayer.h
//  Sister
//
//  Created by 风飞逸 on 14-8-28.
//
//

#ifndef __Sister__TipLayer__
#define __Sister__TipLayer__

#include "cocos2d.h"
USING_NS_CC;

class TipLayer:public Layer{
public:
    TipLayer();
    ~TipLayer();
    
    virtual bool init();
    CREATE_FUNC(TipLayer);
};
#endif /* defined(__Sister__TipLayer__) */
