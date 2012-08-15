#include <stdlib.h>
#include <stdio.h>
#include "ct_test.h"

ct_test_i_suite_ ct_test_suite;

/* push front */
ct_test_i_unite_* ct_test_suite_register(ct_test_i_unite_* unite)
{
    unite->list_.next_ = ct_test_suite.root;
    ct_test_suite.root = unite;
    return unite;
}

/* each(testcase in each(unite in suite)){ run testcase }  */
int ct_test_suite_run(int argc, char* argv[])
{
    const ct_test_i_unite_* unite = ct_test_suite.root;
    int ntc = 0;

    while(unite != NULL){
        const ct_test_i_case_* tc = unite->root;
        while(tc != NULL){
            if(tc->entry != NULL){
                printf("%s:", tc->name);
                tc->entry();
                ++ntc;
            }
            tc = tc->list_.next_;
        }
        unite = unite->list_.next_;
    }

    printf("%d test.\n", ntc);
    return 0;
}
