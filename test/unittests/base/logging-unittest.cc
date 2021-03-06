// Copyright 2015 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "src/base/logging.h"
#include "testing/gtest-support.h"

namespace v8 {
namespace base {

namespace {
template <typename Lhs, typename Rhs>
std::string *CallCheckEQ(Lhs lhs, Rhs rhs, const char *msg) {
  return CheckEQImpl<Lhs, Rhs>(lhs, rhs, msg);
}
}  // namespace

TEST(LoggingTest, CheckEQImpl) {
  EXPECT_EQ(nullptr, CallCheckEQ(0.0, 0.0, ""));
  EXPECT_EQ(nullptr, CallCheckEQ(0.0, -0.0, ""));
  EXPECT_EQ(nullptr, CallCheckEQ(-0.0, 0.0, ""));
  EXPECT_EQ(nullptr, CallCheckEQ(-0.0, -0.0, ""));
}

}  // namespace base
}  // namespace v8
