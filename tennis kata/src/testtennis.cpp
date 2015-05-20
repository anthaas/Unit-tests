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

#include "tennis.h"

using namespace std;
using namespace CppUnit;

/* inicialization -------------------------------- */
class Tests : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(Tests);

	CPPUNIT_TEST(TestNewGame);
	CPPUNIT_TEST(Test1pointPlayer1_0pointPlayer2);
	CPPUNIT_TEST(TestDeuce);

	CPPUNIT_TEST_SUITE_END();

public:
	void setUp(void);
	void tearDown(void);

protected:
	void TestNewGame(void);
	void Test1pointPlayer1_0pointPlayer2(void);
	void TestDeuce(void);

private:
	Game *mygame;
};

/* my tests ------------------------------------- */
void Tests::TestNewGame(void)
{
	CPPUNIT_ASSERT((mygame->GetScore().compare("Love-Love")) == 0);
}

void Tests::Test1pointPlayer1_0pointPlayer2(void)
{
	mygame->InitializeScore(1,0);
	CPPUNIT_ASSERT((mygame->GetScore().compare("Fifteen-Love")) == 0);
}

void Tests::TestDeuce(void)
{
	mygame->InitializeScore(3,3);
	CPPUNIT_ASSERT((mygame->GetScore().compare("Deuce")) == 0);
}
/* -------------------------------- */

void Tests::setUp(void)
{
	mygame = new Game();
}

void Tests::tearDown(void)
{
	delete mygame;
}

CPPUNIT_TEST_SUITE_REGISTRATION( Tests );

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
