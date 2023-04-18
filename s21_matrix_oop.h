#ifndef MATRIX_PLUS_S21_MATRIX_OOP_H_
#define MATRIX_PLUS_S21_MATRIX_OOP_H_

#include <cmath>
#include <iostream>

class S21Matrix {
 public:
  // CONSTRUCTORS
  S21Matrix() noexcept;
  explicit S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other) noexcept;
  S21Matrix(S21Matrix&& other) noexcept;

  // DESTRUCTOR
  ~S21Matrix();

  // MATRIX-OPERATIONS
  bool EqMatrix(const S21Matrix& other) const noexcept;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() const;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;

  // GETTERS && SETTERS
  int GetRows() const noexcept;
  int GetCols() const noexcept;
  void SetRows(int rows);
  void SetCols(int cols);

  // OPERATORS OVERLOADING
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator*(const double num) const;
  bool operator==(const S21Matrix& other) const noexcept;
  bool operator!=(const S21Matrix& other) const noexcept;
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  double& operator()(int i, int j);

 private:
  int rows_, cols_;
  double** matrix_;
  void CopyValues__(const S21Matrix& other, int rows, int cols) const noexcept;
  bool EqualSize__(const S21Matrix& other) const noexcept;
  void GetOffsetMatrix__(int row, int col, S21Matrix& other) const;
  void GetDeterminant__(double** matrix, int size, double* result) const;
};

#endif  // MATRIX_PLUS_S21_MATRIX_OOP_H_
