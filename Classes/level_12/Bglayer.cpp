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
	bg1 = Sprite::create("l12_bg.png");
	bg1->setPosition(visibleSize.width * 0.5f , visibleSize.height * 0.5f);
	this->addChild(bg1);

	bg2 = Sprite::create("l12_bg.png");
	bg2->setPosition(visibleSize.width * 0.5f , visibleSize.height * 1.5f);
	this->addChild(bg2);

	return true;
}

void Bglayer::logic(float dt){
	int posY1 = bg1->getPositionY();	// ������ͼ1��Y����
	int posY2 = bg2->getPositionY();	// ������ͼ2��Y����

	int iSpeed = 3;	// ��ͼ�����ٶ�


	/* ���ŵ�ͼ���Ϲ��������ŵ�ͼ�����ڵģ�����Ҫһ��������������ֿ�϶�� */
	posY1 -= iSpeed;
	posY2 -= iSpeed;

	/* ��Ļ�� */
	int iVisibleHeight = Director::getInstance()->getVisibleSize().height;

	/* ����1����ͼ��ȫ�뿪��Ļʱ���õ�2����ͼ��ȫ��������Ļ�ϣ�ͬʱ�õ�1����ͼ�����ڵ�2����ͼ���� */
	if (posY1 < -iVisibleHeight * 0.5f) {
	posY2 = iVisibleHeight * 0.5f;
	posY1 = iVisibleHeight * 1.5f;
	}
	/* ͬ������2����ͼ��ȫ�뿪��Ļʱ���õ�1����ͼ��ȫ��������Ļ�ϣ�ͬʱ�õ�2����ͼ�����ڵ�1����ͼ���� */
	if (posY2 < iVisibleHeight * 0.5f) {
		posY1 = iVisibleHeight * 0.5f;
		posY2 = iVisibleHeight * 1.5f;
	}

	bg1->setPositionY(posY1);
	bg2->setPositionY(posY2);
}