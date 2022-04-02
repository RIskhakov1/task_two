//Copyright 2022 RIskhakov1
#include <gtest/gtest.h>

extern "C" {
#include "sum.h"
}

TEST(Simple, Test) {
    EXPECT_TRUE(1 == 1);
}