#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab3_Kuznetsov/WFIAlgorithm.h"
#include "../Lab3_Kuznetsov/WFIAlgorithm.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		WFIAlgorithm* test1 = new WFIAlgorithm("../tests/test1.txt");
		WFIAlgorithm* test2 = new WFIAlgorithm("../tests/test2.txt");
		WFIAlgorithm* test3 = new WFIAlgorithm("../tests/test3.txt");
		TEST_METHOD(Testing1)
		{
			Assert::AreEqual(40, test1->getMinimumPrice("New-York", "Berlin"));
			Assert::AreEqual(30, test1->getMinimumPrice("Berlin", "New-York"));
			Assert::AreEqual(40, test1->getMinimumPrice("New-York", "Berlin"));
			Assert::AreEqual(35, test1->getMinimumPrice("New-York", "Tokyo"));
			Assert::AreEqual(25, test1->getMinimumPrice("London", "Paris"));
			Assert::AreEqual(25, test1->getMinimumPrice("Paris", "Moscow"));
			Assert::AreEqual(15, test1->getMinimumPrice("Berlin", "Moscow"));
			Assert::AreEqual(30, test1->getMinimumPrice("Moscow", "Pekin"));
		}
		TEST_METHOD(Testing2)
		{
			Assert::AreEqual(15, test2->getMinimumPrice("A", "B"));
			Assert::AreEqual(10, test2->getMinimumPrice("A", "D"));
			Assert::AreEqual(29, test2->getMinimumPrice("D", "A"));
			Assert::AreEqual(31, test2->getMinimumPrice("A", "F"));
			Assert::AreEqual(40, test2->getMinimumPrice("A", "H"));
			Assert::AreEqual(29, test2->getMinimumPrice("B", "D"));
			Assert::AreEqual(25, test2->getMinimumPrice("B", "E"));
			Assert::AreEqual(35, test2->getMinimumPrice("C", "B"));
			Assert::AreEqual(10, test2->getMinimumPrice("C", "D"));
			Assert::AreEqual(60, test2->getMinimumPrice("C", "H"));
			Assert::AreEqual(55, test2->getMinimumPrice("D", "H"));
			Assert::AreEqual(32, test2->getMinimumPrice("E", "B"));
		}
		TEST_METHOD(Testing3)
		{
			Assert::AreEqual(29, test3->getMinimumPrice("A", "B"));
			Assert::AreEqual(26, test3->getMinimumPrice("D", "A"));
			Assert::AreEqual(22, test3->getMinimumPrice("A", "F"));
			Assert::AreEqual(26, test3->getMinimumPrice("B", "D"));
			Assert::AreEqual(19, test3->getMinimumPrice("D", "E"));
			Assert::AreEqual(3, test3->getMinimumPrice("E", "F"));
		}
	};
}
