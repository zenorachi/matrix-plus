#include "../../s21_matrix_oop.h"

void S21Matrix::GetDeterminant__(double** matrix, int size, double* result) const {
  if (rows_ != cols_)
    throw std::logic_error(
        "Determinant calculation impossible: matrix must be square");
  if (rows_ == 1)
    *result = matrix[0][0];
  else if (rows_ == 2)
    *result = (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
  else {
    *result = 0;
    int degree = 1;
    double resultTmp = 0;
    S21Matrix tmp;
    for (int j = 0; j < size; j++) {
      GetOffsetMatrix__(0, j, tmp);
      tmp.GetDeterminant__(tmp.matrix_, size, &resultTmp);
      resultTmp *= degree * matrix[0][j];
      degree = -degree;
      *result += resultTmp;
    }
  }
}
