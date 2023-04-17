#include "../../s21_matrix_oop.h"

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_)
    throw std::logic_error(
        "Complements calculation impossible: matrix should be square");
  S21Matrix result(rows_, cols_);
  double determinant = 0;
  int size = rows_;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      S21Matrix tmp(size - 1, size - 1);
      __getOffsetMatrix(i, j, &tmp);
      determinant = tmp.Determinant();
      result.matrix_[i][j] = determinant * pow(-1, (i + j));
      determinant++;
    }
  }
  return result;
}
