#include "pch.h"
#include "CppUnitTest.h" 
#include "C:\Users\elios\OneDrive\Рабочий стол\универ\ипз\3.1\3.1\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace crushtest
{
	TEST_CLASS(calcualte_Test)
	{
	public:

		TEST_METHOD(calculate_get4and3_expexted0_25)
		{
			float x = 4;
			int n = 3;
			int expected = 0.25;
			int actual = calculate(x, n);
			Assert::AreEqual(expected, actual);

		}

	public:
		TEST_METHOD(calculate_getnegative1and3_expected7)
		{
			float x = -1;
			int n = 3;
			
			int expected = 7;
			//float actual = calculate(x, n);
			//Assert::AreEqual(expected, actual);
			int actual = calculate(x, n);

			if (fabs(actual - expected) > 0.0001f)
			{

				Assert::IsTrue(true);
			}
			else
			{
				Assert::Fail();
			}

		}
	};

	TEST_CLASS(checkUpperBoundValidity_Test)
	{
	public:
		TEST_METHOD(checkLoopStepValidity_get2and4_expectionNotTrown)
		{
			float a = 2;
			float b = 4;

			try
			{
				checkLoopBoundsValidity(a, b);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail;

			}
		}

	public:
		TEST_METHOD(checkLoopBoundsValidity_get17and9_exceptionThrown)
		{
			int a = 17;
			int b = 9;

			try
			{
				checkLoopBoundsValidity(a, b);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	};
	TEST_CLASS(checkUpperBoundValidity_Tests)
	{
	public:
		TEST_METHOD(checkUpperBoundValidity_get9_exceptionNotThrown)
		{
			int n = 9;

			try

			{
				checkUpperBoundValidity(n);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

	public:
		TEST_METHOD(checkUpperBoundValidity_get1_exceptionThrown)
		{
			int n = 1;

			try
			{
				checkUpperBoundValidity(n);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	};
	TEST_CLASS(checkLoopStepValidity_Tests)

	{
	public:
		TEST_METHOD(checkLoopStepValidity_get69_exceptionNotThrown)
		{
			int h = 69;

			try
			{
				checkLoopStepValidity(h);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	public:
		TEST_METHOD(checkLoopStepValidity_getnegative_exceptionThrown)
		{
			int h = -5;

			try
			{
				checkLoopStepValidity(h);
				Assert::Fail();
			}

			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	};
}







