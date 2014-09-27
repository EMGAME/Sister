//
//  LevelManager.h
//  Sister
//
//  Created by 风飞逸 on 14-9-18.
//
//

#ifndef __Sister__LevelManager__
#define __Sister__LevelManager__

#include "cocos2d.h"
//#include "game.h"

USING_NS_CC;

enum LevelNum{
    level01 = 1,
    level02 = 2,
    level03 = 3,
    level04 = 4,
    level05 = 5,
    level06 = 6,
    level07 = 7,
    level08 = 8,
    level09 = 9,
    level10 = 10,
    level11 = 11,
    level12 = 12,
    level13 = 13,
    level14 = 14,
    level15 = 15,
    level16 = 16,
    level17 = 17,
    level18 = 18,
    level19 = 19,
    level20 = 20,
    level21 = 21,
    level22 = 22,
    level23 = 23,
    level24 = 24,
    level25 = 25,
    level26 = 26,
    level27 = 27,
    level28 = 28,    
    finalLevel,
};

class LevelManager:public Node{
public:
    virtual bool init();
    CREATE_FUNC(LevelManager);
    
    void replaceScene(LevelNum pLevelNum);
};

#endif /* defined(__Sister__LevelManager__) */
