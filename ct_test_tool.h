#ifndef CT_TEST_TOOL_H
#define CT_TEST_TOOL_H

#include "ct_test_cfg.h"

extern void ct_test_tool_Warn(
    const char* flags, const char* fn, const unsigned long ln);
extern void ct_test_tool_Check(
    const char* flags, const char* fn, const unsigned long ln);
extern void ct_test_tool_Require(
    const char* flags, const char* fn, const unsigned long ln);
extern void ct_test_tool_Message(
    const char* msg, const char* fn, const unsigned long ln);

#define CT_TEST_WARN(F_) ((F_)                                  \
    ? ((void)(0))                                               \
    : ct_test_tool_Warn(CT_TEST_I_STZ_(F_), __FILE__, __LINE__))
#define CT_TEST_CHECK(F_) ((F_)                                  \
    ? ((void)(0))                                                \
    : ct_test_tool_Check(CT_TEST_I_STZ_(F_), __FILE__, __LINE__))
#define CT_TEST_REQUIRE(F_) ((F_)                                  \
    ? ((void)(0))                                                  \
    : ct_test_tool_Require(CT_TEST_I_STZ_(F_), __FILE__, __LINE__))
#define CT_TEST_ASSERT(F_) CT_TEST_CHECK(F_)
#define CT_TEST_MESSAGE(STR_) ct_test_tool_Message(STR_, __FILE__, __LINE__)

#define CT_TEST_GT(LHS_,RHS_)  ((LHS_)>(RHS_))
#define CT_TEST_GE(LHS_,RHS_)  ((LHS_)>=(RHS_))
#define CT_TEST_LT(LHS_,RHS_)  ((LHS_)<(RHS_))
#define CT_TEST_LE(LHS_,RHS_)  ((LHS_)<=(RHS_))
#define CT_TEST_EQ(LHS_,RHS_)  ((LHS_)==(RHS_))
#define CT_TEST_EQ_STR(LHS_,RHS_) (strcmp(LHS_,RHS_)==0)
#define CT_TEST_EQ_PTR(LHS_,RHS_) (((void*)(LHS_))==((void*)(RHS_)))

#define CT_TEST_WARN_EQ(LHS_,RHS_) CT_TEST_WARN(CT_TEST_EQ(LHS_,RHS_))
#define CT_TEST_WARN_EQ_STR(LHS_,RHS_) CT_TEST_WARN(CT_TEST_EQ_STR(LHS_,RHS_))
#define CT_TEST_WARN_EQ_PTR(LHS_,RHS_) CT_TEST_WARN(CT_TEST_EQ_PTR(LHS_,RHS_))
#define CT_TEST_WARN_GT(LHS_,RHS_) CT_TEST_WARN(CT_TEST_GT(LHS_,RHS_))
#define CT_TEST_WARN_GE(LHS_,RHS_) CT_TEST_WARN(CT_TEST_GE(LHS_,RHS_))
#define CT_TEST_WARN_LT(LHS_,RHS_) CT_TEST_WARN(CT_TEST_LT(LHS_,RHS_))
#define CT_TEST_WARN_LE(LHS_,RHS_) CT_TEST_WARN(CT_TEST_LE(LHS_,RHS_))
#define CT_TEST_CHECK_EQ(LHS_,RHS_) CT_TEST_CHECK(CT_TEST_EQ(LHS_,RHS_))
#define CT_TEST_CHECK_EQ_STR(LHS_,RHS_) CT_TEST_CHECK(CT_TEST_EQ_STR(LHS_,RHS_))
#define CT_TEST_CHECK_EQ_PTR(LHS_,RHS_) CT_TEST_CHECK(CT_TEST_EQ_PTR(LHS_,RHS_))
#define CT_TEST_CHECK_GT(LHS_,RHS_) CT_TEST_CHECK(CT_TEST_GT(LHS_,RHS_))
#define CT_TEST_CHECK_GE(LHS_,RHS_) CT_TEST_CHECK(CT_TEST_GE(LHS_,RHS_))
#define CT_TEST_CHECK_LT(LHS_,RHS_) CT_TEST_CHECK(CT_TEST_LT(LHS_,RHS_))
#define CT_TEST_CHECK_LE(LHS_,RHS_) CT_TEST_CHECK(CT_TEST_LE(LHS_,RHS_))
#define CT_TEST_REQUIRE_EQ(LHS_,RHS_) CT_TEST_REQUIRE(CT_TEST_EQ(LHS_,RHS_))
#define CT_TEST_REQUIRE_EQ_STR(LHS_,RHS_) CT_TEST_REQUIRE(CT_TEST_EQ_STR(LHS_,RHS_))
#define CT_TEST_REQUIRE_EQ_PTR(LHS_,RHS_) CT_TEST_REQUIRE(CT_TEST_EQ_PTR(LHS_,RHS_))
#define CT_TEST_REQUIRE_GT(LHS_,RHS_) CT_TEST_REQUIRE(CT_TEST_GT(LHS_,RHS_))
#define CT_TEST_REQUIRE_GE(LHS_,RHS_) CT_TEST_REQUIRE(CT_TEST_GE(LHS_,RHS_))
#define CT_TEST_REQUIRE_LT(LHS_,RHS_) CT_TEST_REQUIRE(CT_TEST_LT(LHS_,RHS_))
#define CT_TEST_REQUIRE_LE(LHS_,RHS_) CT_TEST_REQUIRE(CT_TEST_LE(LHS_,RHS_))

#endif /* CT_TEST_TOOL_H */
/*EOF*/
