#include "../../s21_matrix_oop.h"

S21Matrix S21Matrix::InverseMatrix() const {
  if (Determinant() == 0 || rows_ != cols_)
    throw std::logic_error("Inverse matrix calculation impossible");
  S21Matrix complements = CalcComplements();
  S21Matrix transposeComplements = complements.Transpose();
  transposeComplements.MulNumber(1 / Determinant());
  return transposeComplements;
}
