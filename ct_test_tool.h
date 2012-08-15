#ifndef CT_TEST_TOOL_H
#define CT_TEST_TOOL_H

#include <assert.h>
#include <string.h>
#include "ct_test_cfg.h"

#define CT_TEST_ASSERT(F_) assert(F_)
#define CT_TEST_WARN(F_) CT_TEST_ASSERT(F_)
#define CT_TEST_CHECK(F_) CT_TEST_ASSERT(F_)
#define CT_TEST_REQUIRE(F_) CT_TEST_ASSERT(F_)

#define CT_TEST_GT(LHS_,RHS_)  ((LHS_)>(RHS_))
#define CT_TEST_GE(LHS_,RHS_)  ((LHS_)>=(RHS_))
#define CT_TEST_LT(LHS_,RHS_)  ((LHS_)<(RHS_))
#define CT_TEST_LE(LHS_,RHS_)  ((LHS_)<=(RHS_))
#define CT_TEST_EQ(LHS_,RHS_)  ((LHS_)==(RHS_))
#define CT_TEST_EQ_STR(LHS_,RHS_) (strcmp(LHS_,RHS_)==0)
#define CT_TEST_EQ_PTR(LHS_,RHS_) ((LHS_)==(RHS_))

#define CT_TEST_WARN_EQ(LHS_,RHS_) CT_TEST_WARN(CT_TEST_EQ(LHS_,RHS_))
#define CT_TEST_WARN_EQ_STR(LHS_,RHS_) CT_TEST_WARN(CT_TEST_EQ_STR(LHS_,RHS_))
#define CT_TEST_WARN_EQ_PTR(LHS_,RHS_) CT_TEST_WARN(CT_TEST_EQ_PTR(LHS_,RHS_))
#define CT_TEST_WARN_GT(LHS_,RHS_) CT_TEST_WARN(CT_TEST_GT(LHS_,RHS_))
#define CT_TEST_WARN_GE(LHS_,RHS_) CT_TEST_WARN(CT_TEST_GE(LHS_,RHS_))
#define CT_TEST_WARN_LT(LHS_,RHS_) CT_TEST_WARN(CT_TEST_LT(LHS_,RHS_))
#define CT_TEST_WARN_LE(LHS_,RHS_) CT_TEST_WARN(CT_TEST_LE(LHS_,RHS_))

#endif /* CT_TEST_TOOL_H */
/*EOF*/
