#include <stdlib.h>
#include <stdio.h>
#include "ct_test.h"

ct_test_i_suite_ ct_test_suite = {NULL};

/* push front */
ct_test_i_case_* ct_test_suite_register(ct_test_i_case_* tc)
{
    tc->list_.next_ = ct_test_suite.root;
    ct_test_suite.root = tc;
    return tc;
}

/* each(testcase in each(unite in suite)){ run testcase }  */
int ct_test_suite_run(int argc, char* argv[])
{
    const ct_test_i_case_* tc = ct_test_suite.root;
    int ntc = 0;

    while(tc != NULL){
        printf("%s:\n", tc->name);
        if(tc->entry != NULL){
            tc->entry();
            ++ntc;
        }
        tc = tc->list_.next_;
    }

    printf("%d test.\n", ntc);
    return 0;
}
