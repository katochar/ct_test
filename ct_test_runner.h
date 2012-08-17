#ifndef CT_TEST_RUNNER_H
#define CT_TEST_RUNNER_H

/*! output log level */
typedef enum ct_test_runner_lv_
{
    ct_test_runner_lv_info,
    ct_test_runner_lv_warn,
    ct_test_runner_lv_error,

    ct_test_runner_lv_num
} ct_test_runner_lv_;
#define CT_TEST_I_RUNNER_LV_VERBOSE ct_test_runner_lv_info
#define CT_TEST_I_RUNNER_LV_QUIET ct_test_runner_lv_num

/*! running status */
typedef enum
{
    ct_test_runner_sts_suspend,
    ct_test_runner_sts_run,
    ct_test_runner_sts_finish,

    ct_test_runner_sts_num
} ct_test_runner_sts_;

/*! runner object */
typedef struct ct_test_runner_
{
    ct_test_runner_lv_  lv;
    ct_test_runner_sts_ sts;
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
} ct_test_runner_;

/*! setup log @todo parse_opt */
static ct_test_runner_*
ct_test_runner_Build(ct_test_runner_* tr,
    void* const buf, unsigned long const bufn,
    const int argc, const char* argv[])
{
    if(tr != NULL){
        tr->lv  = ct_test_runner_lv_warn;
        tr->sts = ct_test_runner_sts_suspend;
        tr->log.a = (buf != NULL && bufn != 0) ? ((char*)(buf)) : NULL;
        tr->log.i = 0;
        tr->log.n = (buf != NULL && bufn != 0) ? bufn : 0;
        tr->score.n       = 0;
        tr->score.warn    = 0;
        tr->score.check   = 0;
        tr->score.require = 0;
    }
    return tr;
}

#endif /* CT_TEST_RUNNER_H */
/*EOF*/
