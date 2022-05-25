#include "Money.h"
#include <string>
#include <sstream>
using namespace std;

Money::Money(const long x, const unsigned long y)
{
	long a = x;
	unsigned long b = y;
	while (b > 99)
	{ 
		b -= 100;
		a++;
	}
	while (b < -99)
	{
		b += 100;
		a--;
	}
	setGrn(a);
	setKop(b);
}
Money::Money(double x)
{
	long a = (long)x;
	x -= a;
	x *= 100;
	unsigned long b = (unsigned long)x;

	while (b > 99)
	{
		b -= 100;
		a++;
	}
	while (b < 99)
	{
		b += 100;
		a--;
	}
	setGrn(a);
	setKop(b);
}
Money::Money(const Money& r)
{
	int a = r.getGrn();
	int b = r.getKop();

	while (b > 99)
	{
		b -= 100;
		a++;
	}
	while (b < -99)
	{
		b += 100;
		a--;
	}
	setGrn(a);
	setKop(b);
}
Money::~Money() 
{}

Money operator -(const Money& l, const Money& r)
{
	Money t;

	long a = l.getGrn() - r.getGrn();
	unsigned long b = l.getKop() - r.getKop();

	t.setGrn(a);
	t.setKop(b);

	return t;
}
Money operator *(const Money& x, const  double y)
{
	Money t;
	long a = (x.getGrn() * y);
	unsigned long b = (x.getKop() * y);

	while (b > 99)
	{
		b -= 100;
		a++;
	}
	t.setGrn(a);
	t.setKop(b);
	return t;
}

Money& Money::operator ++()
{
	int x = this->getGrn();
	int y = this->getKop();
	x++;
	y++;
	this->setGrn(x);
	this->setKop(y);

	return *this;
}
Money& Money::operator --()
{
	int x = this->getGrn();
	int y = this->getKop();
	x--;
	y--;
	this->setGrn(x);
	this->setKop(y);

	return *this;
}
Money Money::operator ++(int)
{
	Money t(*this);

	int x = this->getGrn();
	int y = this->getKop();

	x++;
	y++;

	this->setGrn(x);
	this->setKop(y);

	return t;
}
Money Money::operator --(int)
{
	Money t(*this);

	int x = this->getGrn();
	int y = this->getKop();

	x--;
	y--;

	this->setGrn(x);
	this->setKop(y);

	return t;
}