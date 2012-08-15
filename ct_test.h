#ifndef CT_TEST_H
#define CT_TEST_H

#include "ct_test_i.h"

#define CT_TEST_CFG_NONAME noname

#define CT_TEST_UNITE_BEGIN() \
    CT_TEST_I_UNITE_BEGIN(CT_TEST_CFG_NONAME)
#define CT_TEST_UNITE_END() \
    CT_TEST_I_UNITE_END(CT_TEST_CFG_NONAME, CT_TEST_CASE_C)
#define CT_TEST_SUITE_REGISTER() \
    ct_test_suite_register(&(CT_TEST_I_UNITE_NMZ(CT_TEST_CFG_NONAME)))

#define CT_TEST_CASE(NAME_)                                     \
    static void CT_TEST_I_TEST_NMZ(NAME_)(void);                \
    static ct_test_i_case_ const CT_TEST_I_CASE_NMZ(NAME_) = {  \
        CT_TEST_I_STZ_(NAME_),                                  \
        CT_TEST_I_TEST_NMZ(NAME_),                              \
        { CT_TEST_CASE_C } };                                   \
    static void CT_TEST_I_TEST_NMZ(NAME_)(void)

#define CT_TEST_CASE_NEXT(NAME_) &(CT_TEST_I_CASE_NMZ(NAME_))
#define CT_TEST_CASE_C ((void*)0)

#define CT_TEST_T(NAME_) static void CT_TEST_I_TEST_NMZ(NAME_)
#define CT_TEST_C(NAME_) CT_TEST_I_TEST_NMZ(NAME_)()

static ct_test_i_unite_ CT_TEST_I_CAT_(ct_test_unite_, CT_TEST_CFG_NONAME);

extern ct_test_i_unite_* ct_test_suite_register(ct_test_i_unite_* unite);
extern int ct_test_suite_run(int argc, char* argv[]);

#endif /* CT_TEST_H */
/*EOF*/
