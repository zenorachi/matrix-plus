#include "../../s21_matrix_oop.h"

void S21Matrix::CopyValues__(const S21Matrix& other, int rows, int cols) const noexcept {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix_[i][j] = other.matrix_[i][j];
        }
    }
}
