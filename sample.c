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

CT_TEST_I_CASE(sample)
{
    puts("sample test");
}

CT_TEST_CASE_BLOCK_END()

int main(int argc, char* argv[])
{
    CT_TEST_SUITE_REGISTER();
    CT_TEST_SUITE_REGISTER_I(sample);
    return ct_test_suite_run(argc, argv);
}
