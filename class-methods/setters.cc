#include "../s21_matrix_oop.h"

void S21Matrix::setRows(int rows_) {
  for (int i = 0; i < this->rows_; i++) delete[] matrix_[i];
  delete[] matrix_;

  this->rows_ = rows_;
  matrix_ = new double*[rows_];
  for (int j = 0; j < rows_; j++) matrix_[j] = new double[cols_];
  __initialize();
}

void S21Matrix::setCols(int cols_) {
  for (int i = 0; i < rows_; i++) delete[] matrix_[i];
  delete[] matrix_;

  this->cols_ = cols_;
  matrix_ = new double*[rows_];
  for (int j = 0; j < rows_; j++) matrix_[j] = new double[cols_];
  __initialize();
}
