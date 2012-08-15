#ifndef CT_TEST_H
#define CT_TEST_H

#include "ct_test_i.h"

#define CT_TEST_CFG_NONAME noname

#define CT_TEST_CASE_BLOCK_BEGIN()
#define CT_TEST_CASE_BLOCK_END()
#define CT_TEST_SUITE_REGISTER_I(NAME_) \
    ct_test_suite_register(&(CT_TEST_I_CASE_NMZ(NAME_)))

#define CT_TEST_T(NAME_) static void CT_TEST_I_TEST_NMZ(NAME_)(void)
#define CT_TEST_C(NAME_) CT_TEST_I_TEST_NMZ(NAME_)()

#define CT_TEST_CASE()   CT_TEST_I_CASE(CT_TEST_CFG_NONAME)
#define CT_TEST_SUITE_REGISTER() \
    CT_TEST_SUITE_REGISTER_I(CT_TEST_CFG_NONAME)

extern ct_test_i_case_* ct_test_suite_register(ct_test_i_case_* tc);
extern int ct_test_suite_run(int argc, char* argv[]);

#endif /* CT_TEST_H */
/*EOF*/
