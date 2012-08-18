#include "ct_test.h"

#define a_sizeof(A_) (sizeof(A_) / sizeof((A_)[0]))

ct_test_suite ct_test_suiteRoot = {NULL};
static ct_test_runner* ct_test_trCurrent = NULL;

//! output log
static ct_test_runner*
ct_test_runner_Log(ct_test_runner* tr, ct_test_runner_lv lv,
    const char* msg, const char* fn, unsigned long ln)
{
    if(tr == NULL || tr->log.wp == NULL) return tr;
    if(lv >= tr->lv){
        static const char* const subject[ct_test_runner_lv_num] = {
            "[info] ",                  // ct_test_runner_lv_info
            "[warning] ",               // ct_test_runner_lv_warn
            "[error] ",                 // ct_test_runner_lv_error
        };
        char*             wp  = tr->log.wp;
        const char* const wq  = tr->log.wq;
        const char* const beg = wp;
        if(lv < a_sizeof(subject)){
            wp = ct_test_i_StrLCpy(wp, wq, subject[lv]);
        }
        if(fn != NULL){
            wp = ct_test_i_StrLCpy(wp, wq, fn);
            wp = ct_test_i_StrLCpy(wp, wq, "(");
            wp = ct_test_i_FormatDec(wp, wq, ln);
            wp = ct_test_i_StrLCpy(wp, wq, ") ");
        }
        if(msg != NULL && *msg != '\0'){
            wp = ct_test_i_StrLCpy(wp, wq, msg);
        }
        if(wp != beg){
            wp = ct_test_i_StrLCpy(wp, wq, CT_TEST_CFG_EOL);
        }
        tr->log.wp = wp;
    }
    return tr;
}
//! output score
static ct_test_runner*
ct_test_runner_Report(ct_test_runner* tr,
    const char* msg, const ct_test_result* sc)
{
    if(tr != NULL && sc != NULL){
        char*             wp  = tr->log.wp;
        const char* const wq  = tr->log.wq;
        if(msg != NULL){
            wp = ct_test_i_StrLCpy(wp, wq, "'");
            wp = ct_test_i_StrLCpy(wp, wq, msg);
            wp = ct_test_i_StrLCpy(wp, wq, "' ");
        }
        wp = ct_test_i_StrLCpy(wp, wq, (sc->require != 0)
            ? "aborted. "
            : "completed. ");
        wp = ct_test_i_FormatDec(wp, wq, sc->n);
        wp = ct_test_i_StrLCpy(wp, wq, " tests, ");
        wp = ct_test_i_FormatDec(wp, wq, sc->expr);
        wp = ct_test_i_StrLCpy(wp, wq, " clear, ");
        wp = ct_test_i_FormatDec(wp, wq, sc->warn);
        wp = ct_test_i_StrLCpy(wp, wq, " warning, ");
        wp = ct_test_i_FormatDec(wp, wq, sc->check + sc->require);
        wp = ct_test_i_StrLCpy(wp, wq, " error.");
        wp = ct_test_i_StrLCpy(wp, wq, CT_TEST_CFG_EOL);
    }
    return tr;
}

/*! initialize dynamic data */
static ct_test_runner*
ct_test_runner_Clear(ct_test_runner* tr)
{
    tr->sts = ct_test_runner_sts_suspend_;
    tr->log.wp = tr->log.beg;
    if(tr->log.wp != NULL && tr->log.wp != tr->log.wq){
        *(tr->log.wp) = '\0';
    }
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
    static void* const NIL = ((void*)(NULL));
#else
    static void* const NIL = ((void*)(0));
#endif
    if(tr != NIL){
        tr->lv  = (opt != NIL) ? opt->lv : ct_test_runner_lv_warn;
        tr->log.wp  = (buf!=NIL && bufn!=0) ? ((char*)(buf)) : NIL;
        tr->log.wq  = (buf!=NIL && bufn!=0) ? tr->log.wp + bufn : tr->log.wp;
        tr->log.beg = tr->log.wp;
        ct_test_runner_Clear(tr);
    }
    return tr;
}

void ct_test_tool_Warn(int f,
    const char* flags, const char* fn, const unsigned long ln)
{
    ct_test_runner* tr = ct_test_trCurrent;
    if(tr != NULL){
        ++(tr->score.expr);
        if(!f){
            ct_test_runner_Log(tr, ct_test_runner_lv_warn, flags, fn, ln);
            ++(tr->score.warn);
        }
    }
}
void ct_test_tool_Check(int f,
    const char* flags, const char* fn, const unsigned long ln)
{
    ct_test_runner* tr = ct_test_trCurrent;
    if(tr != NULL){
        ++(tr->score.expr);
        if(!f){
            ct_test_runner_Log(tr, ct_test_runner_lv_error, flags, fn, ln);
            ++(tr->score.check);
        }
    }
}
void ct_test_tool_Require(int f,
    const char* flags, const char* fn, const unsigned long ln)
{
    ct_test_runner* tr = ct_test_trCurrent;
    if(tr != NULL){
        ++(tr->score.expr);
        if(!f){
            ct_test_runner_Log(tr, ct_test_runner_lv_error, flags, fn, ln);
            ++(tr->score.require);
        }
    }
}
void ct_test_tool_Message(
    const char* msg, const char* fn, const unsigned long ln)
{
    ct_test_runner* tr = ct_test_trCurrent;
    ct_test_runner_Log(tr, ct_test_runner_lv_info, msg, fn, ln);
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
    const ct_test_case* ii;

    if(tr == NULL || suite == NULL) return 0;

    ct_test_trCurrent = tr;
    for(ii = suite->root; ii != NULL; ii = ii->list_.next_){
        const ct_test_case_impl_* const tc = ii->impl_;
        if(tc != NULL && tc->entry != NULL){
            ct_test_runner_Log(tr, ct_test_runner_lv_info,
                (tc->name != NULL) ? tc->name : "",
                tc->fn, tc->ln);
            tc->entry();
            ++(tr->score.n);
        }
    }
    ct_test_trCurrent = NULL;

    ct_test_runner_Report(tr, NULL, &(tr->score));
    return (tr->score.check != 0 && tr->score.require != 0)
        ? (int)(tr->score.check + tr->score.require)
        : (tr->score.warn != 0) ? (int)-((int)(tr->score.warn)) : 0;
}
