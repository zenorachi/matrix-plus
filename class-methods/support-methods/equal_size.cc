#include "../../s21_matrix_oop.h"

bool S21Matrix::EqualSize__(const S21Matrix& other) const noexcept {
  if (rows_ == other.rows_ && cols_ == other.cols_)
    return true;
  else
    return false;
}
