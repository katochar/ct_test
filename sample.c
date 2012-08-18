#include "ct_test.h"

static int add(int a, int b){ return a+b; }

CT_TEST_CASE_BLOCK_BEGIN()

CT_TEST_T(hoge)
{
    CT_TEST_MESSAGE("hoge");
    CT_TEST_CHECK(add(1,2)==3);
}
CT_TEST_T(hage)
{
    CT_TEST_MESSAGE("hage");
    CT_TEST_CHECK_EQ(add(0,0),0);
    CT_TEST_CHECK_EQ(add(1,-1),0);
}
CT_TEST_T(huge)
{
    CT_TEST_MESSAGE("huge");
    CT_TEST_WARN_EQ_PTR("hoge","hoge");
    CT_TEST_WARN_EQ_STR("hoge","hoge");
    CT_TEST_WARN_EQ_STR("hoge","huge");
}
CT_TEST_CASE()
{
    CT_TEST_C(hoge);
    CT_TEST_C(hage);
    CT_TEST_C(huge);
}

CT_TEST_CASE_I(sample)
{
    CT_TEST_MESSAGE("sample test");
}

CT_TEST_CASE_BLOCK_END()

static ct_test_runner_opt*
parse_opt(ct_test_runner_opt* opt, int argc, char* argv[])
{
    opt->lv = CT_TEST_RUNNER_LV_VERBOSE;
}

#include <stdio.h>
int main(int argc, char* argv[])
{
    char bufff[64*1024];
    ct_test_runner_opt tro;
    ct_test_runner tr;
    int result;

    CT_TEST_JOIN();
    CT_TEST_JOIN_I(sample);

    result = CT_TEST_RUN(ct_test_runner_Build(&tr,
        bufff, sizeof(bufff), parse_opt(&tro, argc, argv)));
    puts(bufff);
    return result;
}
