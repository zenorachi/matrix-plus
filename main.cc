#include "s21_matrix_oop.h"

int main() {
    S21Matrix matrix(3, 3);
    S21Matrix test;
    test = matrix;
    test.debug();
    return 0;
}
