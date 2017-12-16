#include <iostream>
#include "Matrix.h"

int main() {
    Matrix m1(2, 3);
    Matrix m2(2, 3);

    m1.setValue(0, 0, 1);
    m1.setValue(0, 1, 2);
    m1.setValue(0, 2, 3);
    m1.setValue(1, 0, 5);
    m1.setValue(1, 1, 7);
    m1.setValue(1, 2, 11);

    m2.setValue(0, 0, 13);
    m2.setValue(0, 1, 17);
    m2.setValue(0, 2, 23);
    m2.setValue(1, 0, 29);
    m2.setValue(1, 1, 31);
    m2.setValue(1, 2, 37);

    Matrix m3 = m1 + m2;

    std::cout << m1 << std::endl;
    std::cout << m2 << std::endl;
    std::cout << m3 << std::endl;
    m3 = m3;
    m3 = m2;

    m3 += m3;
    std::cout << m3 << std::endl;
    Matrix m4 = std::move(m1);
    std::cout << m1 << std::endl;
    std::cout << m4 << std::endl;

    m4.setValue(0,1,9000);
    std::cout << m4.getValue(0,1) << std::endl;
    std::cout << "m4: " << m4.getColumns() << " x " << m4.getRows() << std::endl;

    std::cout << std::endl;
    std::cout << m4 << std::endl;
    Matrix m5 = m4 * 3;
    std::cout << m5 << std::endl;
    m5 *= 3;
    std::cout << m5 << std::endl;
    std::cout << std::endl;

    //Example from https://pl.wikipedia.org/wiki/Mnożenie_macierzy
    Matrix m6(2,3);
    Matrix m7(3,2);

    m6.setValue(0,0,1);
    m6.setValue(0,1,0);
    m6.setValue(0,2,2);
    m6.setValue(1,0,-1);
    m6.setValue(1,1,3);
    m6.setValue(1,2,1);

    m7.setValue(0,0,3);
    m7.setValue(0,1,1);
    m7.setValue(1,0,2);
    m7.setValue(1,1,1);
    m7.setValue(2,0,1);
    m7.setValue(2,1,0);

    Matrix m8 = m6 * m7;

    std::cout << m6;
    std::cout << "X" << std::endl;
    std::cout << m7;
    std::cout << "=" << std::endl;
    std::cout << m8;
    std::cout << std::endl;
    std::cout << (m8 *= m8);
    std::cout << std::endl;

    try {
        m8.getValue(3,0);
    } catch (std::out_of_range& e){
        std::cout << e.what() << std::endl;
        std::cout << "Row validation works\n" << std::endl;
    }

    try {
        m8.getValue(0,3);
    } catch (std::out_of_range& e){
        std::cout << e.what() << std::endl;
        std::cout << "Column validation works\n" << std::endl;
    }

    try {
        m6 * m6;
    } catch (std::invalid_argument& e){
        std::cout << e.what() << std::endl;
        std::cout << "Matrix multiplication validation works\n" << std::endl;
    }

    try {
        m6 + m7;
    } catch (std::invalid_argument& e){
        std::cout << e.what() << std::endl;
        std::cout << "Matrix addition validation works\n" << std::endl;
    }

    return 0;
}