#include "../../s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) const noexcept {
  bool result = true;
  if (EqualSize__(other)) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-07)
          result = false;
      }
    }
  } else {
    result = false;
  }
  return result;
}
