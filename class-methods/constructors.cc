#include "../s21_matrix_oop.h"

S21Matrix::S21Matrix() noexcept : rows_(0), cols_(0) { matrix_ = nullptr; }

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows > 0 && cols > 0) {
    matrix_ = new double*[rows]();
    for (int i = 0; i < rows; i++) {
      matrix_[i] = new double[cols]();
    }
  } else {
    throw std::invalid_argument("Invalid size of matrix");
  }
}

S21Matrix::S21Matrix(const S21Matrix& other) noexcept
    : rows_(other.rows_), cols_(other.cols_) {
  if (rows_ > 0 && cols_ > 0) {
    matrix_ = new double*[rows_];
    for (int i = 0; i < rows_; i++) {
      matrix_[i] = new double[cols_];
    }
    for (int j = 0; j < rows_; j++) {
      for (int k = 0; k < cols_; k++) {
        matrix_[j][k] = other.matrix_[j][k];
      }
    }
  } else {
    matrix_ = nullptr;
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
      other.rows_ = 0, other.cols_ = 0;
      other.matrix_ = nullptr;
}
