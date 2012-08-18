#ifndef CT_TEST_CASE_H
#define CT_TEST_CASE_H

#include "ct_test_cfg.h"

//! testcase entity
typedef struct ct_test_case_impl_
{
    const char*   fn;
    unsigned long ln;
    const char*   name;
    void          (*entry)(void);
} ct_test_case_impl_;

//! testcase I/F
typedef struct ct_test_case
{
    const ct_test_case_impl_* const impl_;
    struct{
        const struct ct_test_case* next_;
    } list_;
} ct_test_case;

//! create testcase
#define CT_TEST_CASE_GENERATOR(NAME_)                                \
    static void CT_TEST_I_TEST_NMZ(NAME_)(void);                    \
    static ct_test_case_impl_ const CT_TEST_I_IMPL_NMZ(NAME_) = {   \
        __FILE__, __LINE__,                                         \
        CT_TEST_I_STZ_(NAME_),                                      \
        CT_TEST_I_TEST_NMZ(NAME_)};                                 \
    static ct_test_case CT_TEST_I_CASE_NMZ(NAME_) = {               \
        &(CT_TEST_I_IMPL_NMZ(NAME_)),                               \
        { ((void*)0) } };                                           \
    static void CT_TEST_I_TEST_NMZ(NAME_)(void)

#endif /* CT_TEST_CASE_H */
/*EOF*/
