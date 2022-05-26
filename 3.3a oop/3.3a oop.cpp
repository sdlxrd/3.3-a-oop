#include <iostream>
#include "Money.h"
#include "prMoney.h"
using namespace std;
int main()
{
	Money a(0, 0), b(0, 0);
	double x;
	cout << "First: " << endl; cin >> a;
	cout << endl << "Second: " << endl; cin >> b;
	cout << endl << "x = "; cin >> x;
	
	cout << endl << "first - second: " << a - b << endl;
	cout << "first * x: " << a * x;
	cout << "second * x: " << b * x << endl;

	if (a == b)
	{
		cout << a.getGrn() << ", " << a.getKop() << " == "  << b.getGrn() << ", " << b.getKop() << endl;
	}
	if (a > b)
	{
		cout << a.getGrn() << ", " << a.getKop() << " > " << b.getGrn() << ", " << b.getKop() << endl;
	}
	if (a < b)
	{
		cout << a.getGrn() << ", " << a.getKop() << " < "  << b.getGrn() << ", " << b.getKop() << endl;
	}
	cout << endl;
	cout << "a++: " << a++;
	cout << "res: " << a << endl;
	cout << "++a: " << ++a << endl;

	cout << "a--: " << a--;
	cout << "res: " << a << endl;
	cout << "--a: " << --a << endl;
	/////////////////////////////////////////
	cin.get();
	cin.get();
	system("cls");
	prMoney a1(0, 0), b1(0, 0);
	double x1;
	cout << "First: " << endl; cin >> a1;
	cout << endl << "Second: " << endl; cin >> b1;
	cout << endl  << "x = "; cin >> x1;
	cout << endl << "first - second: " << a1 - b1;
	cout << "first * x: " << a1 * x1;
	cout << "second * x: " << b1 * x1;
	cout << endl;
	if (a1 == b1)
	{
		cout << a1.getGrn() << ", " << a1.getKop() << " == " << b1.getGrn() << ", " << b1.getKop() << endl;
	}
	if (a1 > b1)
	{
		cout << a1.getGrn() << ", " << a1.getKop() << " > " << b1.getGrn() << ", " << b1.getKop() << endl;
	}
	if (a1 < b1)
	{
		cout << a1.getGrn() << ", " << a1.getKop() << " < " << b1.getGrn() << ", " << b1.getKop() << endl;
	}
	cout << endl;
	cout << "a++: " << a1++;
	cout << "res: " << a1 << endl;
	cout << "++a: " << ++a1 << endl;

	cout << "a--: " << a1--;
	cout << "res: " << a1 << endl;
	cout << "--a: " << --a1 << endl;
	
}