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

Money operator -(const Money& x, const Money& y)
{
	Money t;
	if ((x.getGrn() < y.getGrn()) && (x.getKop() < y.getKop()))
	{
		t.setGrn(0);
		t.setKop(0);
		return t;
	}
	if (x.getKop() < y.getKop())
	{
		t.setGrn((x.getGrn() - 1) - y.getGrn());
		t.setKop(100 - (y.getKop() - x.getKop()));
	}
	else
	{
		t.setGrn(x.getGrn() - y.getGrn());
		t.setKop(x.getKop() - y.getKop());
	}
	return t;
}
Money operator *(const Money& x, const double y)
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
bool Money::operator ==(const Money& x)
{
	if ((this->getGrn() == x.getGrn()) && (this->getKop() == x.getKop()))
		return 1;
	else return 0;
}
bool Money::operator >(const Money& x)
{
	if ((this->getGrn() > x.getGrn()) or ((this->getGrn() == x.getGrn()) && (this->getKop() > x.getKop())))
		return 1;
	else return 0;
}
bool Money::operator < (const Money& x)
{
	if ((this->getGrn() < x.getGrn()) or ((this->getGrn() == x.getGrn()) && this->getKop() < x.getKop()))
		return 1;
	else return 0;
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