#include <gtest.h>

#include "stack.h"
#include "stack.cpp"

TEST(Stack, can_create_stack) {
  stack<double> *st;
  ASSERT_NO_THROW(st = new stack<double>());
}

TEST(Stack, can_create_copied_stack) {
  stack<char> st_1;
  st_1.push(2);
  st_1.push(4);
  ASSERT_NO_THROW(stack<char> st_2(st_1));
}

TEST(Stack, copied_stack_is_equal_to_sourse_one) {
  stack<char> st_1;
  st_1.push(7);
  stack<char> st_2(st_1);
  EXPECT_EQ(true, st_1 == st_2);
}

TEST(Stack, copied_stack_has_its_own_memory) {
  stack<char> st_1;
  st_1.push(4);
  st_1.push(5);
  stack<char> st_2(st_1);
  st_2.pop();
  st_2.push(3);
  EXPECT_EQ(false,st_1 == st_2);
}

TEST(Stack, IsEmpty_returns_1_when_stack_is_empty) {
  stack<char> st;
  EXPECT_EQ(1, st.isEmpty());
}

TEST(Stack, IsEmpty_returns_0_when_stack_isnt_empty) {
  stack<char> st;
  st.push(5);
  EXPECT_EQ(0, st.isEmpty());
}

TEST(Stack, IsFull_returns_0_when_stack_isnt_full) {
  stack<char> st;
  st.push(5);
  EXPECT_EQ(0, st.isFull());
}

TEST(Stack, can_push_new_element) {
  stack<char> st;
  ASSERT_NO_THROW(st.push(5));
}

TEST(Stack, cant_pop_element_when_stack_is_empty) {
  stack<char> st;
  ASSERT_ANY_THROW(st.pop());
}

TEST(Stack, can_pop_element_from_no_empty_stack) {
  stack<char> st;
  st.push(5);
  ASSERT_NO_THROW(st.pop());
}

TEST(Stack, poped_element_is_equal_to_pushed_one) {
  stack<char> st;
  st.push(5);
  EXPECT_EQ(5, st.pop());
}
