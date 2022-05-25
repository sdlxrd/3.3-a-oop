#pragma once
#include <iostream>
#include <string>
#include<sstream>
using namespace std;

class Pair
{
	long grn;
	unsigned long kop;
public:
	Pair(const long f = 0, const unsigned long s = 0);
	Pair(const Pair&);
	~Pair();

	long getGrn() const { return grn; }
	unsigned long getKop() const { return kop; }

	void setGrn(const long grn) { this->grn = grn; }
	void setKop(const unsigned long kop) { this->kop = kop; }

	operator string() const;
	friend ostream& operator<<(ostream&, const Pair&);
	friend istream& operator>>(istream&, Pair&);
};