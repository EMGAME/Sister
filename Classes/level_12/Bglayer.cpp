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

	//����ͼƬ
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
//	//int posY1 = bg1->getPositionY();	// ������ͼ1��Y����
//	//int posY2 = bg2->getPositionY();	// ������ͼ2��Y����
//
//	int iSpeed = 3;	// ��ͼ�����ٶ�
//
//
//	/* ���ŵ�ͼ���Ϲ��������ŵ�ͼ�����ڵģ�����Ҫһ��������������ֿ�϶�� */
//	/*posY1 -= iSpeed;
//	posY2 -= iSpeed;*/
//
//	/* ��Ļ�� */
//	int iVisibleHeight = Director::getInstance()->getVisibleSize().height;
//
//	/* ����1����ͼ��ȫ�뿪��Ļʱ���õ�2����ͼ��ȫ��������Ļ�ϣ�ͬʱ�õ�1����ͼ�����ڵ�2����ͼ���� */
//	if (posY1 < -iVisibleHeight * 0.5f) {
//	posY2 = iVisibleHeight * 0.5f;
//	posY1 = iVisibleHeight * 1.5f;
//	}
//	/* ͬ������2����ͼ��ȫ�뿪��Ļʱ���õ�1����ͼ��ȫ��������Ļ�ϣ�ͬʱ�õ�2����ͼ�����ڵ�1����ͼ���� */
//	if (posY2 < iVisibleHeight * 0.5f) {
//		posY1 = iVisibleHeight * 0.5f;
//		posY2 = iVisibleHeight * 1.5f;
//	}
//
//	//bg1->setPositionY(posY1);
//	//bg2->setPositionY(posY2);
//}