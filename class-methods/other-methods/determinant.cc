#include "../../s21_matrix_oop.h"

double S21Matrix::Determinant() {
  double result = 0;
  __getDeterminant(matrix_, rows_, &result);
  return result;
}
