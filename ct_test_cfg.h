#ifndef CT_TEST_CFG_H
#define CT_TEST_CFG_H

/******************************************************************************
    configure
******************************************************************************/
#if defined(NDEBUG)
#define CT_TEST_CFG_NDEBUG
#endif

#define CT_TEST_CFG_PREFIX_TEST ct_test_
#define CT_TEST_CFG_PREFIX_CASE ct_test_case_
#define CT_TEST_CFG_PREFIX_IMPL ct_test_impl_
#define CT_TEST_CFG_NONAME /*ct_test_*/noname

#define CT_TEST_CFG_EOL "\n"

/******************************************************************************
    implementation utility
******************************************************************************/
#define CT_TEST_I_CAT_(A_,B_) A_##B_
#define CT_TEST_I_STZ_(A_) #A_
#define CT_TEST_I_IMPL_NMZ(NAME_) CT_TEST_I_CAT_( \
    CT_TEST_CFG_PREFIX_IMPL, NAME_)
#define CT_TEST_I_CASE_NMZ(NAME_) CT_TEST_I_CAT_( \
    CT_TEST_CFG_PREFIX_CASE, NAME_)
#define CT_TEST_I_TEST_NMZ(NAME_) CT_TEST_I_CAT_( \
    CT_TEST_CFG_PREFIX_TEST, NAME_)

#include <stdlib.h>
#include <stdio.h>
//! strlcpy
static char*
ct_test_i_StrLCpy(char* wp, const char* wq, const char* rp)
{
    if(wp == wq) return wp;
    if(rp == NULL) return wp;

    --wq;
    while(wp != wq && *rp != '\0'){
        *wp++ = *rp++;
    }
    *wp = '\0';
    return wp;
}
//! itoa
static char*
ct_test_i_FormatDec(char* wp, const char* const wq, unsigned long v)
{
    char bufff[16+1];                   /* keta of MAX_UINT32 in dec. */
    sprintf(bufff, "%d", v);
    return ct_test_i_StrLCpy(wp, wq, bufff);
}

#endif /* CT_TEST_CFG_H */
/*EOF*/
