#include "prMoney.h"
#include <string>
#include <sstream>
using namespace std;

prMoney::prMoney(const long x, const unsigned long y)
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
prMoney::prMoney(double x)
{
	long a = (long)x;
	x *= 100;
	unsigned long b = (unsigned long)x;
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
prMoney::prMoney(const prMoney& x)
{
	int a = x.getGrn();
	int b = x.getKop();

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

prMoney::~prMoney()
{}
prMoney operator -(const prMoney& x, const prMoney& y)
{
	prMoney t;
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
prMoney operator *(const prMoney& x, const double y)
{
	prMoney t;
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
string format(unsigned long b)
{
	stringstream ss;

	if (b < 10)
	{
		ss << "0";
	}

	ss << b;

	return ss.str();
}
prMoney::operator string() const
{
	stringstream ss;
	ss << getGrn() << ", " << format(getKop()) << endl;
	return ss.str();
}
ostream& operator << (ostream& out, const prMoney& x)
{
	out << string(x);
	return out;
}
istream& operator >> (istream& in, prMoney& x)
{
	long a;
	unsigned long b;
	cout << "Grn = "; in >> a;
	cout << "Kop = "; in >> b;
	x.setGrn(a);
	x.setKop(b);
	return in;
 }
bool prMoney::operator ==(const prMoney& x)
{
	if ((this->getGrn() == x.getGrn()) && (this->getKop() == x.getKop()))
		return 1;
	else return 0;
}
bool prMoney::operator >(const prMoney& x)
{
	if ((this->getGrn() > x.getGrn()) or ((this->getGrn() == x.getGrn()) && (this->getKop() > x.getKop())))
		return 1;
	else return 0;
}
bool prMoney::operator < (const prMoney& x)
{
	if ((this->getGrn() < x.getGrn()) or ((this->getGrn() == x.getGrn()) && this->getKop() < x.getKop()))
		return 1;
	else return 0;
}

prMoney& prMoney::operator ++()
{
	int x = this->getGrn();
	int y = this->getKop();
	x++;
	y++;
	this->setGrn(x);
	this->setKop(y);

	return *this;
}
prMoney& prMoney::operator --()
{
	int x = this->getGrn();
	int y = this->getKop();
	x--;
	y--;
	this->setGrn(x);
	this->setKop(y);

	return *this;
}
prMoney prMoney::operator ++(int)
{
	prMoney t(*this);

	int x = this->getGrn();
	int y = this->getKop();

	x++;
	y++;

	this->setGrn(x);
	this->setKop(y);

	return t;
}
prMoney prMoney::operator --(int)
{
	prMoney t(*this);

	int x = this->getGrn();
	int y = this->getKop();

	x--;
	y--;

	this->setGrn(x);
	this->setKop(y);

	return t;
}