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
	CPPUNIT_TEST(GetScore_OneZero_FifteenLove);
	CPPUNIT_TEST(GetScore_TwoThree_ThirtyFourty);
	CPPUNIT_TEST(GetScore_ThreeThree_Deuce);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp(void);
	void tearDown(void);

protected:
	void TestNewGame(void);
	void GetScore_OneZero_FifteenLove(void);
	void GetScore_TwoThree_ThirtyFourty(void);
	void GetScore_ThreeThree_Deuce(void);

private:
	ScoreBoard *board;
};

/* my tests ------------------------------------- */
void Tests::TestNewGame(void)
{
	CPPUNIT_ASSERT_EQUAL(string("Love:Love"), board->GetScore(0,0));
}
void Tests::GetScore_OneZero_FifteenLove(void)
{
	CPPUNIT_ASSERT_EQUAL(string("Fifteen:Love"), board->GetScore(1,0));
}
void Tests::GetScore_TwoThree_ThirtyFourty(void)
{
	CPPUNIT_ASSERT_EQUAL(string("Thirty:Fourty"), board->GetScore(2,3));
}
void Tests::GetScore_ThreeThree_Deuce(void)
{
	CPPUNIT_ASSERT_EQUAL(string("Deuce"), board->GetScore(3,3));
}
/* -------------------------------- */

void Tests::setUp(void)
{
	board = new ScoreBoard();
}

void Tests::tearDown(void)
{
	delete board;
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
