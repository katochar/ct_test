/*---------------------------------------------------------------------------*/
/*! @file ct_test.h

    @brief
        ct_test I/F header.

    @author
        katochar

    @version
        - 2012.08.18 katochar 1st

*//*-------------------------------------------------------------------------*/
#ifndef CT_TEST_H
#define CT_TEST_H

#include "ct_test_cfg.h"
#include "ct_test_case_.h"
#include "ct_test_suite_.h"
#include "ct_test_runner_.h"

#define CT_TEST_CASE_BLOCK_BEGIN()
#define CT_TEST_CASE_BLOCK_END()
#define CT_TEST_CASE_I(NAME_) CT_TEST_CASE_GENERATOR(NAME_)
#define CT_TEST_JOIN_I(NAME_) \
    ct_test_suite_Join(&ct_test_suiteRoot, &(CT_TEST_I_CASE_NMZ(NAME_)))
#define CT_TEST_RUN_I(RUNNER_, SUITE_) \
    ct_test_Run(RUNNER_, SUITE_)

//! smallest test unit
#define CT_TEST_T(NAME_) static void CT_TEST_I_TEST_NMZ(NAME_)(void)
//! call test function its generated CT_TEST_T
#define CT_TEST_C(NAME_) CT_TEST_I_TEST_NMZ(NAME_)()

//! basic test case
#define CT_TEST_CASE()   CT_TEST_CASE_I(CT_TEST_CFG_NONAME)
//! register test case
#define CT_TEST_JOIN() CT_TEST_JOIN_I(CT_TEST_CFG_NONAME)
//! run all tests
#define CT_TEST_RUN(RUNNER_) \
    CT_TEST_RUN_I(RUNNER_, &ct_test_suiteRoot)

//! default suite instance for noname
extern ct_test_suite ct_test_suiteRoot;

//! run the suite
extern int
ct_test_Run(ct_test_runner* tr, const ct_test_suite* suite);

#include "ct_test_tool.h"

#endif /* CT_TEST_H */
/*EOF*/
