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

int main(int argc, char* argv[])
{
    CT_TEST_SUITE_JOIN();
    CT_TEST_SUITE_JOIN_I(sample);
    return CT_TEST_SUITE_RUN(argc, argv);
}
