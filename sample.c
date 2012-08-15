#include "ct_test.h"

#include "ct_test_unite_begin.h"

CT_TEST_CASE(t1)
{
    puts("testcase1");
}
#undef CT_TEST_CASE_C
#define CT_TEST_CASE_C CT_TEST_CASE_NEXT(t1)

CT_TEST_CASE(t2)
{
    puts("testcase2");
}
#undef CT_TEST_CASE_C
#define CT_TEST_CASE_C CT_TEST_CASE_NEXT(t2)

#include "ct_test_unite_end.h"


int main(int argc, char* argv[])
{
    CT_TEST_SUITE_REGISTER();
    return ct_test_suite_run(argc, argv);
}
