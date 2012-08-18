#ifndef CT_TEST_RUNNER_H
#define CT_TEST_RUNNER_H

#include "ct_test_cfg.h"

//! output log level
typedef enum ct_test_runner_lv
{
    ct_test_runner_lv_info,
    ct_test_runner_lv_warn,
    ct_test_runner_lv_error,

    ct_test_runner_lv_num
} ct_test_runner_lv;
#define CT_TEST_RUNNER_LV_VERBOSE ct_test_runner_lv_info
#define CT_TEST_RUNNER_LV_QUIET ct_test_runner_lv_num

//! runner status
typedef enum ct_test_runner_sts_
{
    ct_test_runner_sts_suspend_,
    ct_test_runner_sts_run_,
    ct_test_runner_sts_finish_,

    ct_test_runner_sts_num_
} ct_test_runner_sts_;

//! runner object
typedef struct ct_test_runner
{
    ct_test_runner_sts_ sts;
    ct_test_runner_lv   lv;
    struct{
        char*         a;                /*!< begin */
        unsigned long i;                /*!< size */
        unsigned long n;                /*!< capacity */
    }                   log;
    struct{
        unsigned long warn;
        unsigned long check;
        unsigned long require;
        unsigned long n;
    }                   score;
} ct_test_runner;

//! build option
typedef struct ct_test_runner_opt
{
    ct_test_runner_lv lv;
} ct_test_runner_opt;

//! preparing before ct_test_Run
extern ct_test_runner*
ct_test_runner_Build(ct_test_runner* tr,
    void* const buf, unsigned long const bufn,
    const ct_test_runner_opt* opt);

#endif /* CT_TEST_RUNNER_H */
/*EOF*/
