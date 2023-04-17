#include "../../s21_matrix_oop.h"

double S21Matrix::Determinant() const {
  double result = 0;
  GetDeterminant__(matrix_, rows_, &result);
  return result;
}
