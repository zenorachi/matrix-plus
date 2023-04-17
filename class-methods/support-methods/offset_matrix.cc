#include "../../s21_matrix_oop.h"

void S21Matrix::GetOffsetMatrix__(int row, int col, S21Matrix& other) const {
  int rowShift = 0, colShift = 0;
  int size = rows_;
  S21Matrix tmp(size - 1, size - 1);
  other = tmp;
  for (int i = 0; i < size - 1; i++) {
    if (i == row) rowShift = 1;
    colShift = 0;
    for (int j = 0; j < size - 1; j++) {
      if (j == col) colShift = 1;
      other.matrix_[i][j] = matrix_[i + rowShift][j + colShift];
    }
  }
}
