#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Misha\source\repos\3.3a oop\3.3a oop\Pair.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Pair a(20, 50);
			double f = a.getKop();
			Assert::AreEqual(f, 50.);
		}
	};
}
