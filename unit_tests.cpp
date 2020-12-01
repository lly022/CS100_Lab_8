#include "gtest/gtest.h"

#include "iterator_test.hpp"
#include "iterator.hpp"
#include "base.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

