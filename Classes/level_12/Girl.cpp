#include "Girl.h"

USING_NS_CC;

Girl::Girl(){}
Girl::~Girl(){}

bool Girl::init(){

	Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

	auto girl = Sprite::create("level12/girl_nor.png");
	girl->setPosition(origin+Point(visibleSize.width * 0.5f , visibleSize.height * 0.5f));
	this->addChild(girl,1,2);

	auto boy = Sprite::create("level12/boy.png");
	boy->setPosition(origin+Point(visibleSize.width * 0.5f , visibleSize.height * 0.5f));
	this->addChild(boy,4,3);

	auto girl_d = Sprite::create("level12/girl_down.png");
	girl_d->setPosition(origin+Point(visibleSize.width * 0.5f , visibleSize.height * 0.5f));
	girl_d->setVisible(false);
	this->addChild(girl_d,3,4);

	auto girl_r = Sprite::create("level12/girl_right.png");
	girl_r->setPosition(origin+Point(visibleSize.width * 0.5f , visibleSize.height * 0.5f));
	girl_r->setVisible(false);
	this->addChild(girl_r,3,5);

	auto girl_l = Sprite::create("level12/girl_left.png");
	girl_l->setPosition(origin+Point(visibleSize.width * 0.5f , visibleSize.height * 0.5f));
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
	
	this->runAction(Sequence::create(DelayTime::create(0.5f),CallFunc::create(CC_CALLBACK_0(Girl::backNormal, this)),NULL));
}

void Girl::moveRight(){
	this->getChildByTag(4)->setVisible(false);
	this->getChildByTag(2)->setVisible(false);
	this->getChildByTag(5)->setVisible(true);

	this->runAction(Sequence::create(DelayTime::create(0.5f),CallFunc::create(CC_CALLBACK_0(Girl::backNormal, this)),NULL));
}

void Girl::moveLeft(){
	this->getChildByTag(2)->setVisible(false);
	this->getChildByTag(4)->setVisible(false);
	this->getChildByTag(6)->setVisible(true);

	this->runAction(Sequence::create(DelayTime::create(0.5f),CallFunc::create(CC_CALLBACK_0(Girl::backNormal, this)),NULL));
}