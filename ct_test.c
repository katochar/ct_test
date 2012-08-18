#include <stdlib.h>
#include <stdio.h>
#include "ct_test.h"

ct_test_suite ct_test_suiteRoot = {NULL};

/*! initialize dynamic data */
static ct_test_runner*
ct_test_runner_Clear(ct_test_runner* tr)
{
    tr->sts = ct_test_runner_sts_suspend_;
    tr->log.i = 0;
    tr->score.n       = 0;
    tr->score.warn    = 0;
    tr->score.check   = 0;
    tr->score.require = 0;
}

/*! initialize and setup log */
ct_test_runner*
ct_test_runner_Build(ct_test_runner* tr,
    void* const buf, unsigned long const bufn,
    const ct_test_runner_opt* opt)
{
#if defined(NULL)
    static void* const nil = ((void*)(NULL));
#else
    static void* const nil = ((void*)(0));
#endif
    if(tr != nil){
        tr->lv  = (opt != nil) ? opt->lv : ct_test_runner_lv_warn;
        tr->log.a = (buf != nil && bufn != 0) ? ((char*)(buf)) : nil;
        tr->log.n = (buf != nil && bufn != 0) ? bufn : 0;
        ct_test_runner_Clear(tr);
    }
    return tr;
}

/* push front */
ct_test_suite*
ct_test_suite_Join(ct_test_suite* suite, ct_test_case* test)
{
    if(test->list_.next_ == NULL){
        test->list_.next_ = suite->root;
        suite->root = test;
    }
    return suite;
}

/* each(testcase in suite){ run testcase }  */
int
ct_test_Run(ct_test_runner* tr, const ct_test_suite* suite)
{
    const ct_test_case* ii = suite->root;
    int ntc = 0;

    while(ii != NULL){
        const ct_test_case_impl_* const tc = ii->impl_;
        if(tc != NULL && tc->entry != NULL){
            printf("%s(%d):%s\n",
                (tc->fn != NULL) ? tc->fn : "",
                tc->ln,
                (tc->name != NULL) ? tc->name : "");
            tc->entry();
            ++ntc;
        }
        ii = ii->list_.next_;
    }

    printf("%d test.\n", ntc);
    return 0;
}
