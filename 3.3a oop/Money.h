#pragma once
#include "Pair.h"
class Money :public Pair
{
	Money(const long x = 0, const unsigned long y = 0);
	Money(const Money&);
	Money(double x);
	~Money(void);

	friend Money& operator -(const Money&, const Money&);
	friend Money& operator *(const Money&, const int);


	bool operator ==(const Money&);
	bool operator >(const Money&);
	bool operator <(const Money&);

	operator string() const;

	Money& operator ++();
	Money& operator --();
	Money operator ++(int);
	Money operator --(int);
};

