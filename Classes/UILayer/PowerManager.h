//
//  PowerManager.h
//  Sister
//
//  Created by 风飞逸 on 14-8-14.
//
//

#ifndef __Sister__PowerManager__
#define __Sister__PowerManager__

#include "cocos2d.h"
USING_NS_CC;


class PowerManager:public Node{
public:
    
    static PowerManager* getInstance();
    void test();
    virtual bool init();
    void purge();
    
    void restMgr();
    void initWithNumber(int number);
    void addPower(int number);
    void subPower(int number);
    void savePower();
    int readPower();
    
    //请在ccTouchEnded里面调用这个函数
    //@brief 每次点击减少一个体力
    void clickReducePower();
    
    CC_SYNTHESIZE(int, m_PowerNum, PowerNum);
    CREATE_FUNC(PowerManager);

protected:
    PowerManager();    
};
#endif /* defined(__Sister__PowerManager__) */
