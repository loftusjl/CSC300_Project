#ifndef RANDRANGE_H
#define RANDRANGE_H
#include <stdio.h>  /* printf, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
using namespace std;

class RandRange
{
private:
	int lowNum;
	int highNum;

public:
	RandRange();
	RandRange(int, int);
	~RandRange();
	int getLowNum() const;
	int getHighNum() const;
	void setLowNum(int);
	void setHighNum(int);
	int RandResult();
};
#endif