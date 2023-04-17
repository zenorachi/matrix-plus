#include "s21_matrix_oop.h"

int main() {
    S21Matrix matrix(3, 3);
    S21Matrix test;
    test = matrix;
    test.debug();

    S21Matrix kek(10, 10);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            kek(i, j) = 3;
        }
    }
    kek.debug();
    // kek.InverseMatrix();
    std::cout << kek.Determinant();
    // lol.debug();
    return 0;
}
