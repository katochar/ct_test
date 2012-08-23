#include <stdio.h>
#include <string.h>
#include "ct_test.h"

static ct_test_runner_opt*
parse_opt(ct_test_runner_opt* opt, int argc, char* argv[])
{
    int i = 0;
    opt->lv = CT_TEST_RUNNER_LV_VERBOSE;
    for( ; i < argc; ++i){
        if(strcmp(argv[i], "--quiet") == 0){
            opt->lv = CT_TEST_RUNNER_LV_QUIET;
        }
    }
    return opt;
}

int main(int argc, char* argv[])
{
    extern ct_test_Startup(int argc, char* argv[]);
    char bufff[64*1024];
    ct_test_runner_opt tro;
    ct_test_runner tr;
    int result;

    ct_test_Startup(argc, argv);

    result = CT_TEST_RUN(ct_test_runner_Build(&tr,
        bufff, sizeof(bufff), parse_opt(&tro, argc, argv)));
    puts(bufff);
    return result;
}
