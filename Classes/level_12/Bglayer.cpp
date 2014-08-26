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
	bg1 = Sprite::create("level12/l12_bg.png");
	bg1->setAnchorPoint(Point(0,0));
	bg1->setPosition(Point::ZERO);
	this->addChild(bg1,2);

	auto bg2 = Sprite::create("level12/l12_bg2.png");
	bg2->setAnchorPoint(Point(0,0));
	bg2->setPosition(Point::ZERO);
	this->addChild(bg2,1);

	tree1 = Sprite::create("level12/tree.png");
	tree1->setPosition(Point(visibleSize.width * 0.3f , visibleSize.height * 0.75f));
	tree1->setScale(0.5f,0.5f);
	tree1->runAction(Spawn::create(MoveBy::create(2.0f,Point(-120,-70)),ScaleBy::create(2.0f,2.5f),NULL));
	this->addChild(tree1,1);
	return true;

}

//void Bglayer::logic(float dt){
//	//int posY1 = bg1->getPositionY();	// 背景地图1的Y坐标
//	//int posY2 = bg2->getPositionY();	// 背景地图2的Y坐标
//
//	int iSpeed = 3;	// 地图滚动速度
//
//
//	/* 两张地图向上滚动（两张地图是相邻的，所以要一起滚动，否则会出现空隙） */
//	/*posY1 -= iSpeed;
//	posY2 -= iSpeed;*/
//
//	/* 屏幕高 */
//	int iVisibleHeight = Director::getInstance()->getVisibleSize().height;
//
//	/* 当第1个地图完全离开屏幕时，让第2个地图完全出现在屏幕上，同时让第1个地图紧贴在第2个地图后面 */
//	if (posY1 < -iVisibleHeight * 0.5f) {
//	posY2 = iVisibleHeight * 0.5f;
//	posY1 = iVisibleHeight * 1.5f;
//	}
//	/* 同理，当第2个地图完全离开屏幕时，让第1个地图完全出现在屏幕上，同时让第2个地图紧贴在第1个地图后面 */
//	if (posY2 < iVisibleHeight * 0.5f) {
//		posY1 = iVisibleHeight * 0.5f;
//		posY2 = iVisibleHeight * 1.5f;
//	}
//
//	//bg1->setPositionY(posY1);
//	//bg2->setPositionY(posY2);
//}