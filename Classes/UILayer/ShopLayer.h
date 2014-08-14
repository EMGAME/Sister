//
//  ShopLayer.h
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#ifndef __Sister__ShopLayer__
#define __Sister__ShopLayer__

#include "cocos2d.h"
using namespace cocos2d;

class ShopLayer:public cocos2d::Layer{
public:
    ShopLayer();
    ~ShopLayer();
    virtual bool init();
    
    CREATE_FUNC(ShopLayer);
};

#endif /* defined(__Sister__ShopLayer__) */
