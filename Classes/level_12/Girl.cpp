#include "Girl.h"

USING_NS_CC;

Girl::Girl(){}
Girl::~Girl(){}

bool Girl::init(){

	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto girl = Sprite::create("girl_nor.png");
	girl->setPosition(Point(visibleSize.width * 0.5f , visibleSize.height * 0.5f));
	this->addChild(girl,1,2);

	auto boy = Sprite::create("boy.png");
	boy->setPosition(Point(visibleSize.width * 0.5f , visibleSize.height * 0.5f));
	this->addChild(boy,2,3);

	auto girl_d = Sprite::create("girl_down.png");
	girl_d->setPosition(Point(visibleSize.width * 0.5f , visibleSize.height * 0.5f));
	girl_d->setVisible(false);
	this->addChild(girl_d,3,4);

	auto girl_r = Sprite::create("girl_right.png");
	girl_r->setPosition(Point(visibleSize.width * 0.5f , visibleSize.height * 0.5f));
	girl_r->setVisible(false);
	this->addChild(girl_r,3,5);

	auto girl_l = Sprite::create("girl_left.png");
	girl_l->setPosition(Point(visibleSize.width * 0.5f , visibleSize.height * 0.5f));
	girl_l->setVisible(false);
	this->addChild(girl_l,3,6);

	return true;
}

void Girl::backNormal(){
	this->getChildByTag(2)->setVisible(true);
	this->getChildByTag(6)->setVisible(false);
	this->getChildByTag(4)->setVisible(false);
	this->getChildByTag(5)->setVisible(false);

}
void Girl::moveDown(){
	this->getChildByTag(2)->setVisible(false);
	this->getChildByTag(4)->setVisible(true);
	
}

void Girl::moveRight(){
	this->getChildByTag(4)->setVisible(false);
	this->getChildByTag(2)->setVisible(false);
	this->getChildByTag(5)->setVisible(true);

}

void Girl::moveLeft(){
	this->getChildByTag(2)->setVisible(false);
	this->getChildByTag(4)->setVisible(false);
	this->getChildByTag(6)->setVisible(true);

}