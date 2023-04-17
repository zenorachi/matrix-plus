#include <cmath>
#include <iostream>

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;
  void __initialize();
  bool __equalSize(const S21Matrix& other);
  void __getOffsetMatrix(int row, int col, S21Matrix* tmp);
  void __getDeterminant(double** matrix, int size, double* result);

 public:
  // CONSTRUCTORS
  S21Matrix() noexcept;
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other) noexcept;
  S21Matrix(S21Matrix&& other) noexcept;

  // DESTRUCTOR
  ~S21Matrix();

  // MATRIX-OPERATIONS
  bool EqMatrix(const S21Matrix& other) noexcept;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() noexcept;
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // GETTERS && SETTERS
  int getRows() noexcept;
  int getCols() noexcept;
  void setRows(int rows_);
  void setCols(int cols_);

  // OPERATORS OVERLOADING
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double num) noexcept;
  bool operator==(const S21Matrix& other) noexcept;
  bool operator!=(const S21Matrix& other) noexcept;
  S21Matrix& operator=(const S21Matrix& other) noexcept;
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num) noexcept;
  double& operator()(int i, int j);
};
