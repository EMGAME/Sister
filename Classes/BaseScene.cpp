#include "BaseScene.h"

void BaseScene::setTips(std::string tips[3])
{
	for(unsigned int i = 0; i < this->tips->length(); i++)
	{
		this->tips[i] = tips[i];
	}
}

std::string BaseScene::getTips(int index)
{
	return tips[index];
}

void BaseScene::restart()
{

}

BaseScene::BaseScene(void)
{
	for (unsigned int i = 0; i < tips->length(); i++)
	{
		tips[i] = "";
	}
}


BaseScene::~BaseScene(void)
{
}
