#include <gtest.h>
#include "arithmetic.cpp"

TEST(arithmetic, can_convert_in_a_postfix_notation) {
  string str = "a+(b-c)*d-f/(g+h)";
  string str1 = "abc-d*+fgh+/-";
  string str2 = arithmetic::arithmetic_notation(str);
  EXPECT_EQ(str1, str2);
}

TEST(arithmetic, can_calculate_expresion_in_a_postfix_notation) {
  string str1 = "a+b*c";
  double d2 = 7;
  string str2 = arithmetic::arithmetic_notation(str1);
  cout << "Type: 1, 2, 3" << endl;
  double d1 = arithmetic::arithmetic_calculation(str2);
  EXPECT_EQ(d1, d2);
}

TEST(arithmetic, throws_when_input_invalid) {
  string str1 = "a+(b-c";
  EXPECT_ANY_THROW(arithmetic::arithmetic_notation(str1));
}

TEST(arithmetic, throws_when_try_convert_empty_wtring) {
  string str1 = "";
  EXPECT_ANY_THROW(arithmetic::arithmetic_notation(str1));
}
