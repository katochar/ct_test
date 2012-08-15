#ifndef CT_TEST_I_H
#define CT_TEST_I_H

#include <stdlib.h>

#define CT_TEST_I_CAT_(A_,B_) A_##B_
#define CT_TEST_I_STZ_(A_) #A_
#define CT_TEST_I_UNITE_NMZ(NAME_) CT_TEST_I_CAT_(ct_test_unite_, NAME_)
#define CT_TEST_I_CASE_NMZ(NAME_) CT_TEST_I_CAT_(ct_test_case_, NAME_)
#define CT_TEST_I_TEST_NMZ(NAME_) CT_TEST_I_CAT_(ct_test_, NAME_)

typedef struct ct_test_i_case_
{
    const char* name;
    void        (*entry)(void);
    struct{
        const struct ct_test_i_case_* next_;
    } list_;
} ct_test_i_case_;

typedef struct ct_test_i_unite_
{
    const ct_test_i_case_* root;
    struct{
        const struct ct_test_i_unite_* next_;
    } list_;
} ct_test_i_unite_;

typedef struct ct_test_i_suite_
{
    const ct_test_i_unite_* root;
} ct_test_i_suite_;

#define CT_TEST_I_UNITE_BEGIN(NAME_) \
    static ct_test_i_unite_ CT_TEST_I_UNITE_NMZ(NAME_);
//    static void (*__ct_test_case_prev)(void) = NULL;
#define CT_TEST_I_UNITE_END(NAME_, ROOT_)                \
    static ct_test_i_unite_ CT_TEST_I_UNITE_NMZ(NAME_)  \
        = { ROOT_, {NULL} };
#define CT_TEST_I_SUITE_REGISTER(NAME_) \
    ct_test_suite_register(&(CT_TEST_I_UNITE_NMZ(NAME_)))

#endif /* CT_TEST_I_H */
/*EOF*/
