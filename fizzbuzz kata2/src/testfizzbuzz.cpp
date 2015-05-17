#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include "fizzbuzz.h"

using namespace std;
using namespace CppUnit;

/* inicialization -------------------------------- */
class TestFizzBuzz : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TestFizzBuzz);
	CPPUNIT_TEST(testOne);
	CPPUNIT_TEST(testTwo);
	CPPUNIT_TEST(testThree);
	CPPUNIT_TEST(testFive);
	CPPUNIT_TEST(testSix);
	CPPUNIT_TEST(testSeven);
	CPPUNIT_TEST(testFifteen);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp(void);
	void tearDown(void);

protected:
	void testOne(void);
	void testTwo(void);
	void testThree(void);
	void testFive(void);
	void testSix(void);
	void testSeven(void);
	void testFifteen(void);

private:
	FizzBuzz *mTestObj;
};

/* my tests ------------------------------------- */
void TestFizzBuzz::testOne(void)
{
	CPPUNIT_ASSERT((mTestObj->Convert(1).compare("1")) == 0);
}

void TestFizzBuzz::testTwo(void)
{
	CPPUNIT_ASSERT((mTestObj->Convert(2).compare("Fizz")) == 0);
}
void TestFizzBuzz::testThree(void)
{
	CPPUNIT_ASSERT((mTestObj->Convert(3).compare("Fizz")) == 0);
}
void TestFizzBuzz::testFive(void)
{
	CPPUNIT_ASSERT((mTestObj->Convert(5).compare("Buzz")) == 0);
}
void TestFizzBuzz::testSix(void)
{
	CPPUNIT_ASSERT((mTestObj->Convert(6).compare("Fizz")) == 0);
}
void TestFizzBuzz::testSeven(void)
{
	CPPUNIT_ASSERT((mTestObj->Convert(7).compare("Whiz")) == 0);
}
void TestFizzBuzz::testFifteen(void)
{
	CPPUNIT_ASSERT((mTestObj->Convert(15).compare("FizzBuzz")) == 0);
}
/* -------------------------------- */

void TestFizzBuzz::setUp(void)
{
	mTestObj = new FizzBuzz();
}

void TestFizzBuzz::tearDown(void)
{
	delete mTestObj;
}

CPPUNIT_TEST_SUITE_REGISTRATION( TestFizzBuzz );

int main(int argc, char* argv[])
{
	// informs test-listener about testresults
	CPPUNIT_NS::TestResult testresult;

	// register listener for collecting the test-results
	CPPUNIT_NS::TestResultCollector collectedresults;
	testresult.addListener (&collectedresults);

	// register listener for per-test progress output
	CPPUNIT_NS::BriefTestProgressListener progress;
	testresult.addListener (&progress);

	// insert test-suite at test-runner by registry
	CPPUNIT_NS::TestRunner testrunner;
	testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
	testrunner.run(testresult);

	// output results in compiler-format
	CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
	compileroutputter.write ();

	// return 0 if tests were successful
	return collectedresults.wasSuccessful() ? 0 : 1;
}
