#include "Pair.h"
using namespace std;
Pair::Pair(const long x, const unsigned long y) : grn(x), kop(y)
{}
Pair::Pair(const Pair& x)
{
	this->grn = x.grn;
	this->kop = x.kop;
}
Pair::~Pair(void)
{}
Pair::operator std::string() const
{
	stringstream ss;
	ss << this->grn << ", " << this->kop << endl;
	return ss.str();
}
ostream& operator << (ostream& out, const Pair& x)
{
	return out << string(x);
}
istream& operator >> (istream& in, Pair& x)
{
	int a, b;
	cout << "Grn = "; in >> a;
	cout << "Kop = "; in >>b;
	x.setGrn(a);
	x.setKop(b);
	return in;
}