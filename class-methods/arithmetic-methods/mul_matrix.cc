#include "../../s21_matrix_oop.h"

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ == other.rows_) {
    int n = rows_;
    int m = other.rows_;
    int k = other.cols_;
    S21Matrix tmpMatrix(rows_, k);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < k; j++) {
        for (int l = 0; l < m; l++) {
          tmpMatrix.matrix_[i][j] += matrix_[i][l] * other.matrix_[l][j];
        }
      }
    }
    *this = tmpMatrix;
  } else {
    throw std::out_of_range("Multiply isn't possible: ivalid size of");
  }
}
