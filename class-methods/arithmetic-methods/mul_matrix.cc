#include "../../s21_matrix_oop.h"

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ == other.rows_) {
    S21Matrix tmp_matrix(rows_, other.cols_);
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < other.cols_; j++) {
        for (int k = 0; k < other.rows_; k++) {
          tmp_matrix.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
        }
      }
    }
    *this = tmp_matrix;
  } else {
    throw std::out_of_range("Multiply isn't possible: ivalid size of");
  }
}
