#ifndef CT_TEST_I_H
#define CT_TEST_I_H

#define CT_TEST_I_CAT_(A_,B_) A_##B_
#define CT_TEST_I_STZ_(A_) #A_
#define CT_TEST_I_IMPL_NMZ(NAME_) CT_TEST_I_CAT_(ct_test_case_impl_, NAME_)
#define CT_TEST_I_CASE_NMZ(NAME_) CT_TEST_I_CAT_(ct_test_case_, NAME_)
#define CT_TEST_I_TEST_NMZ(NAME_) CT_TEST_I_CAT_(ct_test_, NAME_)

typedef struct ct_test_i_case_impl_
{
    const char*   fn;
    unsigned long ln;
    const char*   name;
    void          (*entry)(void);
} ct_test_i_case_impl_;

typedef struct ct_test_i_case_
{
    const ct_test_i_case_impl_* const impl_;
    struct{
        const struct ct_test_i_case_* next_;
    } list_;
} ct_test_i_case_;

typedef struct ct_test_i_suite_
{
    const ct_test_i_case_* root;
} ct_test_i_suite_;

extern ct_test_i_suite_ ct_test_suite_global;

#define CT_TEST_I_CASE(NAME_)                                       \
    static void CT_TEST_I_TEST_NMZ(NAME_)(void);                    \
    static ct_test_i_case_impl_ const CT_TEST_I_IMPL_NMZ(NAME_) = { \
        __FILE__, __LINE__,                                         \
        CT_TEST_I_STZ_(NAME_),                                      \
        CT_TEST_I_TEST_NMZ(NAME_)};                                 \
    static ct_test_i_case_ CT_TEST_I_CASE_NMZ(NAME_) = {            \
        &(CT_TEST_I_IMPL_NMZ(NAME_)),                               \
        { ((void*)0) } };                                           \
    static void CT_TEST_I_TEST_NMZ(NAME_)(void)

#endif /* CT_TEST_I_H */
/*EOF*/
