//
//  GameScene36.h
//  Sister
//
//  Created by EMG on 14-10-15.
//
//

#ifndef __Sister__GameScene36__
#define __Sister__GameScene36__

#include "cocos2d.h"
#include "BaseLayer.h"
#include "ui/CocosGUI.h"
#include <random>
#include "UISimple.h"

#define LABELTAG 10

using namespace std;
using namespace ui;
USING_NS_CC;

class GameScene36 : public BaseLayer
{
public:
    virtual bool init();
    static Scene* createScene();
    CREATE_FUNC(GameScene36);
    GameScene36();
    
    void keyCallBack0(Ref* pSender, TouchEventType type);
    void keyCallBack1(Ref* pSender, TouchEventType type);
    void keyCallBack2(Ref* pSender, TouchEventType type);
    void keyCallBack3(Ref* pSender, TouchEventType type);
    void keyCallBack4(Ref* pSender, TouchEventType type);
    void keyCallBack5(Ref* pSender, TouchEventType type);
    void keyCallBack6(Ref* pSender, TouchEventType type);
    void keyCallBack7(Ref* pSender, TouchEventType type);
    void keyCallBack8(Ref* pSender, TouchEventType type);
    void keyCallBack9(Ref* pSender, TouchEventType type);
    void keyCallBack10(Ref* pSender, TouchEventType type);
    void keyCallBack11(Ref* pSender, TouchEventType type);
    
    //uniform_int_distribution<unsigned> u(0,12);//生成0到11（包含）均匀分布的随机数
    default_random_engine e;//生成随机无符号数
    
public:
    virtual void success();
    virtual void lose();
    virtual void restart();
    
    UISimple* m_ui;
    
private:
    void initPaper();
    void initKey();
    int passwordNumber;
    Label* label;
};

#endif /* defined(__Sister__GameScene36__) */
