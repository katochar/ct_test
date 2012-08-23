/*---------------------------------------------------------------------------*/
/*! @file ct_test_runner_.h

    @brief
        ct_test runnner.

    @author
        katochar

    @version
        - 2012.08.18 katochar 1st

*//*-------------------------------------------------------------------------*/
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
    ct_test_runner_sts_ready_,
    ct_test_runner_sts_run_,
    ct_test_runner_sts_finish_,

    ct_test_runner_sts_num_
} ct_test_runner_sts_;

//! result
typedef struct ct_test_result
{
    unsigned long warn;
    unsigned long check;
    unsigned long require;
    unsigned long expr;                 /*!< num of checker */
    unsigned long n;                    /*!< num of testcase */
} ct_test_result;

//! runner object
typedef struct ct_test_runner
{
    ct_test_runner_sts_ sts;
    ct_test_runner_lv   lv;
    struct{
        char* beg;                      /*!< begin */
        char* wp;                       /*!< size */
        char* wq;                       /*!< capacity */
    }                   log;
    ct_test_result      score;
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
