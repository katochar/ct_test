#include <stdlib.h>
#include "ct_test.h"

CT_TEST_CASE_BLOCK_BEGIN()

CT_TEST_T(hoge)
{
    puts("hoge");
}
CT_TEST_T(hage)
{
    puts("hage");
}
CT_TEST_T(huge)
{
    puts("huge");
}
CT_TEST_CASE()
{
    CT_TEST_C(hoge);
    CT_TEST_C(hage);
    CT_TEST_C(huge);
}

CT_TEST_CASE_I(sample)
{
    puts("sample test");
}

CT_TEST_CASE_BLOCK_END()

static ct_test_runner_opt* parse_opt(ct_test_runner_opt* opt,
    const int argc, const char* const argv[])
{
    opt->lv = ct_test_runner_lv_warn;
}

int main(int argc, char* argv[])
{
    CT_TEST_JOIN();
    CT_TEST_JOIN_I(sample);
    return CT_TEST_RUN(NULL);
}
