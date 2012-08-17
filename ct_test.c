#include <stdlib.h>
#include <stdio.h>
#include "ct_test.h"

ct_test_i_suite_ ct_test_suite_global = {NULL};

/* push front */
ct_test_i_case_*
ct_test_suite_Join(ct_test_i_suite_* suite, ct_test_i_case_* ii)
{
    ii->list_.next_ = suite->root;
    suite->root = ii;
    return ii;
}

/* each(testcase in suite){ run testcase }  */
int
ct_test_suite_Run(const ct_test_i_suite_* suite, int argc, char* argv[])
{
    const ct_test_i_case_* ii = suite->root;
    int ntc = 0;

    while(ii != NULL){
        const ct_test_i_case_impl_* const tc = ii->impl_;
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
