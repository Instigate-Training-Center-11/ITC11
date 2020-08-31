/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_MyTest_init = false;
#include "Mytest.h"

static MyTest suite_MyTest;

static CxxTest::List Tests_MyTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTest( "Mytest.h", 5, "MyTest", suite_MyTest, Tests_MyTest );

static class TestDescription_suite_MyTest_testAdd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTest_testAdd() : CxxTest::RealTestDescription( Tests_MyTest, suiteDescription_MyTest, 8, "testAdd" ) {}
 void runTest() { suite_MyTest.testAdd(); }
} testDescription_suite_MyTest_testAdd;

static class TestDescription_suite_MyTest_testMult : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTest_testMult() : CxxTest::RealTestDescription( Tests_MyTest, suiteDescription_MyTest, 17, "testMult" ) {}
 void runTest() { suite_MyTest.testMult(); }
} testDescription_suite_MyTest_testMult;

static class TestDescription_suite_MyTest_testSub : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTest_testSub() : CxxTest::RealTestDescription( Tests_MyTest, suiteDescription_MyTest, 26, "testSub" ) {}
 void runTest() { suite_MyTest.testSub(); }
} testDescription_suite_MyTest_testSub;

static class TestDescription_suite_MyTest_testDiv : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTest_testDiv() : CxxTest::RealTestDescription( Tests_MyTest, suiteDescription_MyTest, 35, "testDiv" ) {}
 void runTest() { suite_MyTest.testDiv(); }
} testDescription_suite_MyTest_testDiv;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
