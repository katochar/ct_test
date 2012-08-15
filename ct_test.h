#ifndef CT_TEST_H
#define CT_TEST_H

#include "ct_test_cfg.h"
#include "ct_test_i.h"

#define CT_TEST_CASE_BLOCK_BEGIN()
#define CT_TEST_CASE_BLOCK_END()
#define CT_TEST_CASE_I(NAME_) CT_TEST_I_CASE(NAME_)
#define CT_TEST_SUITE_REGISTER_I(NAME_) \
    ct_test_suite_register(&ct_test_suite_global, &(CT_TEST_I_CASE_NMZ(NAME_)))
#define CT_TEST_SUITE_RUN_I(SUITE_, ARGC_, ARGV_) \
    ct_test_suite_run(SUITE_, ARGC_, ARGV_)

#define CT_TEST_T(NAME_) static void CT_TEST_I_TEST_NMZ(NAME_)(void)
#define CT_TEST_C(NAME_) CT_TEST_I_TEST_NMZ(NAME_)()

#define CT_TEST_CASE()   CT_TEST_CASE_I(CT_TEST_CFG_NONAME)
#define CT_TEST_SUITE_REGISTER() CT_TEST_SUITE_REGISTER_I(CT_TEST_CFG_NONAME)
#define CT_TEST_SUITE_RUN(ARGC_, ARGV_) \
    CT_TEST_SUITE_RUN_I(&ct_test_suite_global, ARGC_, ARGV_)

extern ct_test_i_case_*
ct_test_suite_register(ct_test_i_suite_* suite, ct_test_i_case_* ii);
extern int
ct_test_suite_run(const ct_test_i_suite_* suite, int argc, char* argv[]);

#endif /* CT_TEST_H */
/*EOF*/
