#include "Bglayer.h"

Bglayer::Bglayer(){

}

Bglayer::~Bglayer(){

}

bool Bglayer::init(){

	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//背景图片
	/*bg1 = Sprite::create("level12/l12_bg.png");
	bg1->setAnchorPoint(Point(0,0));
	bg1->setPosition(Point::ZERO);
	this->addChild(bg1,2);*/

	auto bg2 = Sprite::create("level12/tree.png");
	bg2->setAnchorPoint(Point(0,0));
	bg2->setPosition(Point::ZERO);
	this->addChild(bg2,1);

	
	// 帧动画测试
	//auto spriteFrameCache = SpriteFrameCache::sharedSpriteFrameCache();    
	//spriteFrameCache->addSpriteFramesWithFile("level12/bgscroll0.plist");  //将动画图片的plist放入缓存中  
	// 

 //    SpriteFrame* frame = NULL;  
	// Vector<SpriteFrame*> frameArray;
	//  
	// for(int i=0;i<6;i++)  
	//	{  
	//		    frame = spriteFrameCache->spriteFrameByName(CCString::createWithFormat("level12/bg%d.png",i)
	//				->getCString());  
	//		    frameArray.pushBack(frame);  
	//		}  
	//  
	//auto animation = Animation::createWithSpriteFrames(frameArray,0.2f);  
	//auto animate = Animate::create(animation);//创建一个动画  aa
	//  
	//auto heard_sp = Sprite::create("level12/bg1.png");  
	//heard_sp->setPosition(Point(visibleSize.width/2,visibleSize.height/2));  
	//heard_sp->runAction(animate);//播放动画  
	//this->addChild(heard_sp,1);  

	//测试2 失败
	//auto sprite =  (Sprite*)(this->getChildByTag(1000));      
	// 
	//	  //sprite->stopAllActions();  
	//sprite->cleanup();  
	//sprite->runAction(Place::create(Point(100.0f, g_ClientMidY)));


	//auto animation = Animation::create();

	//for (int i = 1;i<7;i++)
	//{
	//	char szName[100] = {0};
	//	sprintf(szName,"bg%d.png",i);
	//	animation->addSpriteFrameWithFile(szName);
	//}

	//animation->setDelayPerUnit(1.2f / 6.0f);
	//animation->setRestoreOriginalFrame(true); 

	//测试3
    Animation* animation = Animation::create();
	for (int i=1;i<7;i++)
	{
		char szName[100] = {0};
		sprintf(szName,"level12/bg%d.png",i);
		animation->addSpriteFrameWithFileName(szName);
	}

	animation->setDelayPerUnit(0.8f / 6.0f);
	animation->setRestoreOriginalFrame(true);

	Animate* action = CCAnimate::create(animation);
    
	bg2->runAction(RepeatForever::create(action));

	return true;

}

