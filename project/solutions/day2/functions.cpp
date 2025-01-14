#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

int sum_n(int n) {
  if (n < 0) {
    return -1;
  }
  return n * (n + 1) * 0.5;
}

int lcm(int a, int b) {
  if (a == 0 || b == 0) {
    return 0;
  }
  a = std::abs(a);
  b = std::abs(b);
  const int step{a > b ? a : b};
  int result{step};
  while (!(result % a == 0 && result % b == 0)) {
    result += step;
  }
  return result;
}

TEST_CASE("Testing the sum_n function") {
  CHECK(sum_n(0) == 0);
  CHECK(sum_n(3) == 6);
  CHECK(sum_n(10) == 55);
  CHECK(sum_n(-5) == -1);
}

TEST_CASE("testing the lcm function") {
  CHECK(lcm(12, 16) == 48);
  CHECK(lcm(20, 25) == 100);
  CHECK(lcm(0, 1) == 0);
  CHECK(lcm(1, 0) == 0);
  CHECK(lcm(0, 0) == 0);
  CHECK(lcm(12, -16) == 48);
  CHECK(lcm(-12, 16) == 48);
  CHECK(lcm(-12, -16) == 48);
}
