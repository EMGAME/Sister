#pragma once
#include "cocos2d.h"
USING_NS_CC;
class PauseLayer : public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(PauseLayer);

	//��ͣ��Ϸ
	void pauseGame(Ref* pSender);
	//������Ϸ
	void returnToGame(Ref* pSender);
	//���ùؿ�
	void resetGame(Ref* pSender);
	//������ҳ��
	void returnToHome(Ref* pSender);
	//���þ���
	void muteSound(Ref* pSender);

	PauseLayer(void);
	~PauseLayer(void);
private:
	Layer* uiLayer;
};

