#include "BaseLayer.h"

void BaseLayer::setTips(std::string tips[3])
{
	for(unsigned int i = 0; i < this->tips->length(); i++)
	{
		this->tips[i] = tips[i];
	}
}

std::string BaseLayer::getTips(int index)
{
	return tips[index];
}


BaseLayer::BaseLayer(void)
{
	for (unsigned int i = 0; i < tips->length(); i++)
	{
		tips[i] = "";
	}
}

BaseLayer::~BaseLayer(void)
{
}

