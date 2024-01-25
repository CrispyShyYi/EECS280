#include "arrays.hpp"
#include "unit_test_framework.hpp"


// We define a test case with the TEST(<test_name>) macro.
// <test_name> can be any valid C++ function name.
TEST(test_slideRight_func) {
 int arr_1[5] = {1,2,3,4,5};
 slideRight(arr_1,5);
 ASSERT_EQUAL(arr_1[0],5);

 int arr_2[6] = {0, 0, 0, 0, 0 ,0};
 slideRight(arr_2, 6);
 ASSERT_EQUAL(arr_2[0], 0);


}

TEST(test_flip_func) {
  int arr1[5] = {1, 2, 3, 4, 5};
  flip(arr1, 5);
  ASSERT_EQUAL(arr1[0], 5);
  ASSERT_EQUAL(arr1[1], 4);
  ASSERT_EQUAL(arr1[2], 3);
  ASSERT_EQUAL(arr1[3], 2);
  ASSERT_EQUAL(arr1[4], 1);

  int arr2[3] = {0, 0, 0};
  flip(arr2, 3);
  ASSERT_EQUAL(arr2[0], 0);
  ASSERT_EQUAL(arr2[1], 0);
  ASSERT_EQUAL(arr2[2], 0);

  ASSERT_EQUAL(42, 42);
}

TEST_MAIN() // No semicolon!