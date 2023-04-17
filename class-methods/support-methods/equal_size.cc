#include "../../s21_matrix_oop.h"

bool S21Matrix::__equalSize(const S21Matrix& other) {
  if (rows_ == other.rows_ && cols_ == other.cols_)
    return true;
  else
    return false;
}
