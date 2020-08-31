#include "./cxxtest-4.4/cxxtest/TestSuite.h"
#include "calc.h"
#include <cstdlib>

class MyTest : public CxxTest::TestSuite
{
public:
    void testAdd(void) {
        Calc obj;
        for (int i = 0; i < 90; ++i) {
            int first = rand();
            int second = rand();
            TS_ASSERT_EQUALS(obj.add(first, second), first + second);
        }
    }

    void testMult(void) {
        Calc obj;
        for (int i = 0; i < 90; ++i) {
            int first = rand();
            int second = rand();
            TS_ASSERT_EQUALS(obj.mult(first, second), first * second);
        }
    }

    void testSub(void) {
        Calc obj;
        for (int i = 0; i < 90; ++i) {
            int first = rand();
            int second = rand();
            TS_ASSERT_EQUALS(obj.sub(first, second), first - second);
        }
    }

    void testDiv(void) {
        Calc obj;
        for (int i = 0; i < 90; ++i) {
            int first = rand();
            int second = rand();
            TS_ASSERT_EQUALS(obj.div(first, second), first / second);
        }
    }
};