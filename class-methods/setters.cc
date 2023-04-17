#include "../s21_matrix_oop.h"

void S21Matrix::setRows(int rows) {
  if (rows_ != rows) {
    S21Matrix tmp(rows, cols_);
    int tmpRows = rows_ > rows ? rows : rows_;
    tmp.CopyValues__(*this, tmpRows, cols_);
    this->~S21Matrix();
    // for (int i = 0; i < tmpRows; i++) {
    //   for (int j = 0; j < cols_; j++) {
    //     tmp.matrix_[i][j] = matrix_[i][j];
    //   }
    // }
    // double** tmpMatrix = matrix_;
    // matrix_ = tmp.matrix_;
    // tmp.matrix_ = tmpMatrix;
    // tmp.rows_ = rows_;
    // rows_ = rows;
    *this = tmp;
    // S21Matrix tmpRes(std::move(tmp));
    // *this = tmpRes;
  }
}

void S21Matrix::setCols(int cols) {
  S21Matrix tmp(rows_, cols);
  int tmpCols = cols_ > cols ? cols : cols_;
  tmp.CopyValues__(*this, rows_, tmpCols);
  this->~S21Matrix();
  // for (int i = 0; i < rows_; i++) {
  //   for (int j = 0; j < tmpCols; j++) {
  //     tmp.matrix_[i][j] = matrix_[i][j];
  //   }
  // }
  // double** tmpMatrix = matrix_;
  // matrix_ = tmp.matrix_;
  // tmp.matrix_ = tmpMatrix;
  // tmp.cols_ = cols_;
  // cols_ = cols;
  *this = tmp;
  // S21Matrix tmpRes(std::move(tmp));
  // *this = tmpRes;
}
