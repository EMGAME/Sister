//
//  GoldManager.h
//  Sister
//
//  Created by 风飞逸 on 14-8-13.
//
//

#ifndef __Sister__GoldManager__
#define __Sister__GoldManager__

#include "cocos2d.h"
USING_NS_CC;

class GoldManager:public Layer{
public:
    static GoldManager* getInstance();
    void test();
    virtual bool init();
    void purge();

    void restMgr();
    void initWithNumber(int number);
    void addGold(int number);
    void subGold(int number);
    void saveGold();
    int readGold();
    
    //请在ccTouchEnded里面调用这个函数
    //@brief 每次点击减少一个金币
    void clickReduceGold();
    
    CC_SYNTHESIZE(int, m_GoldNum, GoldNum);
    CREATE_FUNC(GoldManager);
    
protected:
    GoldManager();
};
#endif /* defined(__Sister__GoldManager__) */
