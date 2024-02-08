#include "Matrix.hpp"
#include "Matrix_test_helpers.hpp"
#include "unit_test_framework.hpp"

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);
  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.hpp as needed.

// Test Matrix_column and Matrix_row functions
TEST(test_width_height){
  Matrix *mat = new Matrix;

  const int width = 6;
  const int height = 8;
  Matrix_init(mat, 6, 8);
  ASSERT_EQUAL(Matrix_width(mat), width);
  ASSERT_EQUAL(Matrix_height(mat), height);

  delete mat;
}


// Test Matrix_fill_border function
TEST(test_fill_border){
  Matrix *mat = new Matrix;

  const int width = 3;
  const int height = 4;
  const int value = 2;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, 0);
  Matrix_fill_border(mat, value);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 2);
  ASSERT_EQUAL(*Matrix_at(mat, 0 ,2), 2);
  ASSERT_EQUAL(*Matrix_at(mat, 2, 2), 2);
  ASSERT_EQUAL(*Matrix_at(mat, 1, 1), 0);
  ASSERT_EQUAL(*Matrix_at(mat, 1, 0), 2);
  ASSERT_EQUAL(*Matrix_at(mat, 3, 2), 2);
  
  delete mat;
}

TEST(test_row_column){
  Matrix *mat = new Matrix;

  const int width = 3;
  const int height = 4;

  Matrix_init(mat, width, height);
  int *ptr = Matrix_at(mat, 2, 1);
  ASSERT_EQUAL(Matrix_row(mat, ptr), 2);
  ASSERT_EQUAL(Matrix_column(mat, ptr), 1);

  ptr = Matrix_at(mat, 3, 2);
  ASSERT_EQUAL(Matrix_row(mat, ptr), 3);
  ASSERT_EQUAL(Matrix_column(mat, ptr), 2);

  Matrix_init(mat, 1, 1);
  ptr = Matrix_at(mat, 0, 0);
  ASSERT_EQUAL(Matrix_row(mat, ptr), 0);
  ASSERT_EQUAL(Matrix_column(mat, ptr), 0);

  delete mat;
}

TEST(test_max){
  Matrix *mat = new Matrix;

  const int width = 3;
  const int height = 4;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, 3);
  Matrix_fill_border(mat, 5);
  ASSERT_EQUAL(Matrix_max(mat), 5);

  Matrix_fill(mat, 6);
  Matrix_fill_border(mat, 2);
  ASSERT_EQUAL(Matrix_max(mat), 6);

  delete mat;

}

TEST(test_column_of_min_value_in_row){
  Matrix *mat = new Matrix;

  const int width = 5;
  const int height = 4;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, 3);
  Matrix_fill_border(mat, 5);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 2,
                                                 0, 3), 1); 
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0,
                                                 1, 4), 1);
  delete mat;
}

TEST(test_Matrix_min_value_in_row){
  Matrix *mat = new Matrix;

  const int width = 5;
  const int height = 4;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, 5);
  Matrix_fill_border(mat, 3);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 1, 3), 3);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 2, 1, 4), 5);
  delete mat;
}
// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
