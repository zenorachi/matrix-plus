#include "../s21_matrix_oop.h"

S21Matrix::~S21Matrix() {
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
      matrix_[i] = nullptr;
    }
    delete[] matrix_;
    rows_ = 0, cols_ = 0;
    matrix_ = nullptr;
  }
}
