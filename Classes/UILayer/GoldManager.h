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

class GoldManager:public Node{
public:
    static GoldManager* getInstance();
    virtual bool init();
    void purge();

    void restMgr();
    void initWithNumber(int number);
    void addGold(int number);
    void subGold(int number);
    void saveGold();
    int readGold();
    
    CC_SYNTHESIZE(int, m_GoldNum, GoldNum);
    CREATE_FUNC(GoldManager);
    
protected:
    GoldManager();
};
#endif /* defined(__Sister__GoldManager__) */
