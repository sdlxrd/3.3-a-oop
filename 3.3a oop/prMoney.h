#pragma once
#include "Pair.h"
class prMoney :private Pair
{
public:
	prMoney(const long x = 0, const unsigned long y = 0);
	prMoney(const prMoney&);
	prMoney(double x);
	~prMoney(void);

	using Pair::getGrn;
	using Pair::getKop;
	using Pair::setGrn;
	using Pair::setKop;

	friend prMoney operator -(const prMoney&, const prMoney&);
	friend prMoney operator *(const prMoney&, const double);
	

	bool operator ==(const prMoney&);
	bool operator >(const prMoney&);
	bool operator <(const prMoney&);


	operator string() const;
	friend ostream& operator <<(ostream&, const prMoney&);
	friend istream& operator >>(istream&, prMoney&);

	prMoney& operator ++();
	prMoney operator ++(int);
	prMoney& operator --();
	prMoney operator --(int);
};

