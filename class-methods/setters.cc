#include "../s21_matrix_oop.h"

void S21Matrix::setRows(int rows) {
  if (rows_ != rows) {
    S21Matrix tmp(rows, cols_);
    int tmpRows = rows_ > rows ? rows : rows_;
    tmp.CopyValues__(*this, tmpRows, cols_);
    *this = tmp;
  }
}

void S21Matrix::setCols(int cols) {
  S21Matrix tmp(rows_, cols);
  int tmpCols = cols_ > cols ? cols : cols_;
  tmp.CopyValues__(*this, rows_, tmpCols);
  *this = tmp;
}
