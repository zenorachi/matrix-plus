#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

// ------- EQ_MATRIX -------

TEST(EQ_MATRIX, EqMatrix_1) {
  S21Matrix matrix_1(1, 1);
  S21Matrix matrix_2(1, 1);
  bool result = matrix_1.EqMatrix(matrix_2);
  EXPECT_TRUE(result);
}

TEST(EQ_MATRIX, EqMatrix_2) {
  S21Matrix matrix_1;
  S21Matrix matrix_2;
  bool result = matrix_1.EqMatrix(matrix_2);
  EXPECT_TRUE(result);
}

TEST(EQ_MATRIX, EqMatrix_3) {
  S21Matrix matrix_1(104, 43);
  S21Matrix matrix_2(104, 43);
  bool result = matrix_1.EqMatrix(matrix_2);
  EXPECT_TRUE(result);
}

TEST(EQ_MATRIX, EqMatrix_4) {
  S21Matrix matrix_1(104, 43);
  S21Matrix matrix_2(104, 43);
  matrix_2.setCols(100341);
  bool state = (matrix_1 == matrix_2);
  EXPECT_FALSE(state);
}

// ------- SUM_MATRIX -------

TEST(SUM_MATRIX, SumMatrix_1) {
  int rows = 10, cols = 134;
  S21Matrix matrix_1(rows, cols);
  S21Matrix matrix_2(rows, cols);
  double num1 = 314984.431;
  double num2 = 431.14114;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix_1(i, j) = num1;
      matrix_2(i, j) = num2;
    }
  }
  matrix_1.SumMatrix(matrix_2);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      EXPECT_DOUBLE_EQ(matrix_1(i, j), (num1 + num2));
    }
  }
}

TEST(SUM_MATRIX, SumMatrix_2) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(5, 5);
  EXPECT_ANY_THROW(matrix_1.SumMatrix(matrix_2));
}

// ------- SUB_MATRIX -------

TEST(SUB_MATRIX, SubMatrix_1) {
  int rows = 10, cols = 134;
  S21Matrix matrix_1(rows, cols);
  S21Matrix matrix_2(rows, cols);
  double num1 = 314984.431;
  double num2 = 431.14114;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix_1(i, j) = num1;
      matrix_2(i, j) = num2;
    }
  }
  matrix_1.SubMatrix(matrix_2);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      EXPECT_DOUBLE_EQ(matrix_1(i, j), (num1 - num2));
    }
  }
}

TEST(SUB_MATRIX, SubMatrix_2) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(5, 5);
  EXPECT_ANY_THROW(matrix_1.SubMatrix(matrix_2));
}

// ------- MUL_NUMBER -------

TEST(MUL_NUMBER, MulNumber_1) {
  int rows = 10, cols = 134;
  S21Matrix matrix_1(rows, cols);
  double num1 = 314984.431;
  double num2 = 431.14114;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix_1(i, j) = num1;
    }
  }
  matrix_1.MulNumber(num2);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      EXPECT_DOUBLE_EQ(matrix_1(i, j), (num1 * num2));
    }
  }
}

// ------- MUL_MATRIX -------

TEST(MUL_MATRIX, MulMatrix_1) {
  int rows = 3, cols = 3;
  S21Matrix matrix_1(rows, cols);
  double num1 = 10;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix_1(i, j) = num1;
    }
  }
  S21Matrix matrix_2(rows, cols);
  double num2 = 10;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix_2(i, j) = num2;
    }
  }
  matrix_1.MulMatrix(matrix_2);
  double result = 300.0;
  for (int i = 0; i < matrix_1.getRows(); i++) {
    for (int j = 0; j < matrix_1.getCols(); j++) {
      EXPECT_DOUBLE_EQ(result, matrix_1(i, j));
    }
  }
}

TEST(MUL_MATRIX, MulMatrix_2) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(4, 3);
  EXPECT_ANY_THROW(matrix_1.MulMatrix(matrix_2));
}

// ------- TRANSPOSE -------

TEST(TRANSPOSE, Transpose_1) {
  S21Matrix matrix_1(2, 3);
  int increment = 1;
  for (int i = 0; i < matrix_1.getRows(); i++) {
    for (int j = 0; j < matrix_1.getCols(); j++) {
      matrix_1(i, j) = increment++;
    }
  }
  S21Matrix matrix_2(3, 2);
  matrix_2(0, 0) = 1;
  matrix_2(0, 1) = 4;
  matrix_2(1, 0) = 2;
  matrix_2(1, 1) = 5;
  matrix_2(2, 0) = 3;
  matrix_2(2, 1) = 6;
  S21Matrix transposeMatrix = matrix_1.Transpose();
  EXPECT_TRUE(matrix_2.EqMatrix(transposeMatrix));
}

// ------- DETERMINANT -------

TEST(DETERMINANT, Determinant_1) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 2;
  matrix(0, 1) = 4;
  matrix(0, 2) = 3;
  matrix(1, 0) = 5;
  matrix(1, 1) = 7;
  matrix(1, 2) = 8;
  matrix(2, 0) = 6;
  matrix(2, 1) = 9;
  matrix(2, 2) = 1;
  double result = matrix.Determinant();
  double detRes = 51.0;
  EXPECT_DOUBLE_EQ(detRes, result);
}

TEST(DETERMINANT, Determinant_2) {
  S21Matrix matrix(1, 1);
  matrix(0, 0) = 34.24414;
  double result = matrix.Determinant();
  double detRes = 34.24414;
  EXPECT_DOUBLE_EQ(detRes, result);
}

TEST(DETERMINANT, Determinant_3) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 34.24414;
  matrix(0, 1) = 4;
  matrix(1, 0) = 43.5;
  matrix(1, 1) = 7.000987;
  double result = matrix.Determinant();
  double detRes = 34.24414 * 7.000987 - 4 * 43.5;
  EXPECT_DOUBLE_EQ(detRes, result);
}

TEST(DETERMINANT, Determinant_4) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 34.24414;
  matrix(0, 1) = 4;
  matrix(1, 0) = 43.5;
  matrix(1, 1) = 7.000987;
  double result = matrix.Determinant();
  double detRes = 34.24414 * 7.000987 - 4 * 43.5;
  EXPECT_DOUBLE_EQ(detRes, result);
  S21Matrix testMatrix;
  testMatrix = matrix;
  testMatrix.setRows(5);
  testMatrix.setCols(100034);
  int rows = testMatrix.getRows();
  int cols = testMatrix.getCols();
  EXPECT_TRUE(rows == 5);
  EXPECT_TRUE(cols == 100034);
  EXPECT_ANY_THROW(testMatrix.Determinant());
}

// ------- CALC_COMPLEMENTS -------

TEST(CALC_COMPLEMENTS, CalcComplements_1) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 0;
  matrix(1, 1) = 4;
  matrix(1, 2) = 2;
  matrix(2, 0) = 5;
  matrix(2, 1) = 2;
  matrix(2, 2) = 1;
  S21Matrix matrixComplements = matrix.CalcComplements();
  EXPECT_DOUBLE_EQ(matrixComplements(0, 0), 0);
  EXPECT_DOUBLE_EQ(matrixComplements(0, 1), 10);
  EXPECT_DOUBLE_EQ(matrixComplements(0, 2), -20);
  EXPECT_DOUBLE_EQ(matrixComplements(1, 0), 4);
  EXPECT_DOUBLE_EQ(matrixComplements(1, 1), -14);
  EXPECT_DOUBLE_EQ(matrixComplements(1, 2), 8);
  EXPECT_DOUBLE_EQ(matrixComplements(2, 0), -8);
  EXPECT_DOUBLE_EQ(matrixComplements(2, 1), -2);
  EXPECT_DOUBLE_EQ(matrixComplements(2, 2), 4);
}

TEST(CALC_COMPLEMENTS, CalcComplements_2) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 2;
  matrix(0, 1) = 5;
  matrix(0, 2) = 7;
  matrix(1, 0) = 6;
  matrix(1, 1) = 3;
  matrix(1, 2) = 4;
  matrix(2, 0) = 5;
  matrix(2, 1) = -2;
  matrix(2, 2) = -3;
  S21Matrix matrixComplements = matrix.CalcComplements();
  EXPECT_DOUBLE_EQ(matrixComplements(0, 0), -1);
  EXPECT_DOUBLE_EQ(matrixComplements(0, 1), 38);
  EXPECT_DOUBLE_EQ(matrixComplements(0, 2), -27);
  EXPECT_DOUBLE_EQ(matrixComplements(1, 0), 1);
  EXPECT_DOUBLE_EQ(matrixComplements(1, 1), -41);
  EXPECT_DOUBLE_EQ(matrixComplements(1, 2), 29);
  EXPECT_DOUBLE_EQ(matrixComplements(2, 0), -1);
  EXPECT_DOUBLE_EQ(matrixComplements(2, 1), 34);
  EXPECT_DOUBLE_EQ(matrixComplements(2, 2), -24);
}

TEST(CALC_COMPLEMENTS, CalcComplements_3) {
  S21Matrix matrix(3, 4);
  matrix(0, 0) = 2;
  matrix(0, 1) = 5;
  matrix(0, 2) = 7;
  matrix(1, 0) = 6;
  matrix(1, 1) = 3;
  matrix(1, 2) = 4;
  matrix(2, 0) = 5;
  matrix(2, 1) = -2;
  matrix(2, 2) = -3;
  EXPECT_ANY_THROW(matrix.CalcComplements());
}

// ------- INVERSE_MATRIX -------

TEST(INVERSE_MATRIX, InverseMatrix_1) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 2;
  matrix(0, 1) = 5;
  matrix(0, 2) = 7;
  matrix(1, 0) = 6;
  matrix(1, 1) = 3;
  matrix(1, 2) = 4;
  matrix(2, 0) = 5;
  matrix(2, 1) = -2;
  matrix(2, 2) = -3;
  S21Matrix matrixComplements = matrix.InverseMatrix();
  EXPECT_DOUBLE_EQ(matrixComplements(0, 0), 1);
  EXPECT_DOUBLE_EQ(matrixComplements(0, 1), -1);
  EXPECT_DOUBLE_EQ(matrixComplements(0, 2), 1);
  EXPECT_DOUBLE_EQ(matrixComplements(1, 0), -38);
  EXPECT_DOUBLE_EQ(matrixComplements(1, 1), 41);
  EXPECT_DOUBLE_EQ(matrixComplements(1, 2), -34);
  EXPECT_DOUBLE_EQ(matrixComplements(2, 0), 27);
  EXPECT_DOUBLE_EQ(matrixComplements(2, 1), -29);
  EXPECT_DOUBLE_EQ(matrixComplements(2, 2), 24);
}

TEST(INVERSE_MATRIX, InverseMatrix_2) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 0;
  matrix(0, 1) = 0;
  matrix(1, 0) = 0;
  matrix(1, 1) = 0;
  S21Matrix test(matrix);
  EXPECT_TRUE(matrix == test);
  matrix(0, 0) = 1;
  matrix(0, 1) = 1;
  matrix(1, 0) = 1;
  matrix(1, 1) = 1;
  matrix += test;
  matrix *= 2;
  EXPECT_DOUBLE_EQ(matrix(0, 0), 2);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 2);
  EXPECT_DOUBLE_EQ(matrix(1, 0), 2);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 2);
  EXPECT_TRUE(matrix != test);
  double determinant = matrix.Determinant();
  EXPECT_DOUBLE_EQ(determinant, 0.0);
  EXPECT_ANY_THROW(matrix.InverseMatrix());
}

// ------- OTHER_TESTS -------

TEST(OTHER_TESTS, TestCase_1) { EXPECT_ANY_THROW(S21Matrix test(-1, 1)); }

TEST(OTHER_TESTS, TestCase_2) {
  S21Matrix matrix;
  S21Matrix test(matrix);
  EXPECT_TRUE(test.getRows() == test.getCols());
}

TEST(OTHER_TESTS, TestCase_3) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.5;
  matrix(0, 1) = 1.5;
  matrix(1, 0) = 1.5;
  matrix(1, 1) = 1.5;
  S21Matrix test(matrix);
  test = test + matrix;
  for (int i = 0; i < test.getCols(); i++) {
    for (int j = 0; j < test.getCols(); j++) {
      EXPECT_DOUBLE_EQ(test(i, j), 3.0);
    }
  }
}

TEST(OTHER_TESTS, TestCase_4) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.5;
  matrix(0, 1) = 1.5;
  matrix(1, 0) = 1.5;
  matrix(1, 1) = 1.5;
  S21Matrix test(matrix);
  test = test * 2;
  matrix = matrix * 3;
  test = test - matrix;
  for (int i = 0; i < test.getCols(); i++) {
    for (int j = 0; j < test.getCols(); j++) {
      EXPECT_DOUBLE_EQ(test(i, j), -1.5);
    }
  }
}

TEST(OTHER_TESTS, TestCase_5) {
  S21Matrix matrix(3, 3);
  EXPECT_ANY_THROW(matrix(0, -1));
}

TEST(OTHER_TESTS, TestCase_6) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.5;
  matrix(0, 1) = 1.5;
  matrix(1, 0) = 1.5;
  matrix(1, 1) = 1.5;
  S21Matrix tmp2(matrix);
  S21Matrix tmp(2, 2);
  tmp(0, 0) = 1.5;
  tmp(0, 1) = 1.5;
  tmp(1, 0) = 1.5;
  tmp(1, 1) = 1.5;
  matrix.MulMatrix(tmp);
  S21Matrix test;
  test = tmp2 * tmp;
  EXPECT_TRUE(matrix == test);
}

TEST(OTHER_TESTS, TestCase_7) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.5;
  matrix(0, 1) = 1.5;
  matrix(1, 0) = 1.5;
  matrix(1, 1) = 1.5;
  S21Matrix tmp2(matrix);
  S21Matrix tmp(2, 2);
  tmp(0, 0) = 1.5;
  tmp(0, 1) = 1.5;
  tmp(1, 0) = 1.5;
  tmp(1, 1) = 1.5;
  matrix.SubMatrix(tmp);
  tmp2 -= tmp;
  EXPECT_TRUE(matrix == tmp2);
}

TEST(OTHER_TESTS, TestCase_8) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.5;
  matrix(0, 1) = 1.5;
  matrix(1, 0) = 1.5;
  matrix(1, 1) = 1.5;
  S21Matrix tmp2(matrix);
  S21Matrix tmp(2, 2);
  tmp(0, 0) = 1.5;
  tmp(0, 1) = 1.5;
  tmp(1, 0) = 1.5;
  tmp(1, 1) = 1.5;
  matrix.MulMatrix(tmp);
  tmp2 *= tmp;
  EXPECT_TRUE(matrix == tmp2);
}

TEST(OTHER_TESTS, TestCase_9) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.5;
  matrix(0, 1) = 1.5;
  matrix(1, 0) = 1.5;
  matrix(1, 1) = 1.5;
  S21Matrix test(std::move(matrix));
  EXPECT_TRUE(matrix.getRows() == 0);
  EXPECT_TRUE(matrix.getCols() == 0);
  EXPECT_TRUE(test.getRows() == 2);
  EXPECT_TRUE(test.getCols() == 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      EXPECT_DOUBLE_EQ(test(i, j), 1.5);
    }
  }
}

TEST(OTHER_TESTS, TestCase_10) {
  S21Matrix matrix;
  S21Matrix test(std::move(matrix));
  EXPECT_TRUE(matrix.getRows() == 0);
  EXPECT_TRUE(matrix.getCols() == 0);
  EXPECT_TRUE(test.getRows() == 0);
  EXPECT_TRUE(test.getCols() == 0);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
