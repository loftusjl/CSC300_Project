#include"RandRange.h"

RandRange::RandRange()
{
	lowNum = 1;
	highNum = 100;
}

RandRange::RandRange(int low, int high)
{
	setLowNum(low);
	setHighNum(high);
}

RandRange::~RandRange()
{
}
int RandRange::getLowNum() const
{
	return lowNum;
}
int RandRange::getHighNum() const
{
	return highNum;
}
void RandRange::setLowNum(int low)
{
	lowNum = low;
}
void RandRange::setHighNum(int high)
{
	highNum = high;
}

int RandRange::RandResult()
{
	int result = rand() % (getHighNum() - getLowNum() + 1) + getLowNum();

	return result;
};