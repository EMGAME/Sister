//
//  SuccessScene.h
//  Sister
//
//  Created by 风飞逸 on 14-9-18.
//
//

#ifndef __Sister__SuccessScene__
#define __Sister__SuccessScene__

#include "cocos2d.h"
#include "LevelManager.h"


USING_NS_CC;
enum LEVEL_TYPE{
    LEVEL_TYPE_NEXT,//下一关
    LEVEL_TYPE_BOSS,//下一关是boss关卡
    LEVEL_TYPE_OVER,//关卡结束
};

class SuccessScene : public Layer{
public:
    SuccessScene();
    ~SuccessScene();
    virtual bool init(LevelNum pNum);
    static Scene* createScene(LevelNum pNum);
    static SuccessScene* create(LevelNum pNum);
    
    LevelNum mNum;
    Scene* mScene;
    
    //初始化过关文字
    void initText(LEVEL_TYPE pLevelType);
    
    
    Sprite*  next;
    
    Sprite*  boss;
    
    Sprite*  ready;
    
    Sprite*  start;
    
    MoveTo* nextAct;
    MoveTo* bossAct;
    MoveTo* readyAct;
    MoveTo* startAct ;
    
    EaseBackInOut* nextEase;
    EaseBackInOut* bossEase;
    EaseBackInOut* readyEase;
    EaseBackInOut* startEase;
};

#endif /* defined(__Sister__SuccessScene__) */
