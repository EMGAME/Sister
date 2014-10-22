//
//  LoseScene.h
//  Sister
//
//  Created by 风飞逸 on 14-9-18.
//
//

#ifndef __Sister__LoseScene__
#define __Sister__LoseScene__


#include "cocos2d.h"
#include "SuccessScene.h"
#include "../LevelManager.h"
#include "cocostudio/CocoStudio.h"

using namespace cocostudio;

USING_NS_CC;
class LoseScene : public Layer{
public:
    LoseScene();
    ~LoseScene();
    virtual bool init(LevelNum pNum);
    static Scene* createScene(LevelNum pNum);
    static LoseScene* create(LevelNum pNum);
    void gameOver();
    
    LevelNum mNum;
    Scene* mScene;
    

    
    //CCParticleBatchNode* batch;
    //CCParticleSystem* m_emitter1;
    ParticleSystemQuad* _emitter;
    
    
    Armature* meigui01;
    Armature* meigui02;
    Armature* meigui03;
    Armature* meigui04;
    
    Sprite*  next;
    Sprite*  over;
    Sprite*  ready;
    Sprite*  start;
    Sprite*  boss;
    
    MoveTo* nextAct;
    MoveTo* overAct;
    MoveTo* readyAct;
    MoveTo* startAct;
    MoveTo* bossAct;
    
    EaseBackInOut* nextEase;
    EaseBackInOut* overEase;
    EaseBackInOut* readyEase;
    EaseBackInOut* startEase;
    EaseBackInOut* bossEase;

    
    //初始化过关文字
    void initText(LEVEL_TYPE pLevelType);

};
#endif /* defined(__Sister__LoseScene__) */
