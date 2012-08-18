#ifndef CT_TEST_SUITE_H
#define CT_TEST_SUITE_H

#include "ct_test_cfg.h"
#include "ct_test_case_.h"

//! set of testcase
typedef struct ct_test_suite
{
    const ct_test_case* root;
} ct_test_suite;

//! append testcase
extern ct_test_suite*
ct_test_suite_Join(ct_test_suite* suite, ct_test_case* test);

#endif /* CT_TEST_SUITE_H */
/*EOF*/
