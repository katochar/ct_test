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

#endif /* CT_TEST_CFG_H */
/*EOF*/
