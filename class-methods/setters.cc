#include "../s21_matrix_oop.h"

void S21Matrix::SetRows(int rows) {
  if (rows_ != rows) {
    S21Matrix tmp(rows, cols_);
    int tmp_rows = rows_ > rows ? rows : rows_;
    tmp.CopyValues__(*this, tmp_rows, cols_);
    *this = tmp;
  }
}

void S21Matrix::SetCols(int cols) {
  if (cols_ != cols) {
    S21Matrix tmp(rows_, cols);
    int tmp_cols = cols_ > cols ? cols : cols_;
    tmp.CopyValues__(*this, rows_, tmp_cols);
    *this = tmp;
  }
}
