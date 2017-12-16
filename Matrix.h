#ifndef ZMPO4_MATRIX_H
#define ZMPO4_MATRIX_H

class Matrix {
private:
    unsigned int m;
    unsigned int n;
    int **structure;
    void makeEmpty();
    void validate(unsigned int row, unsigned int column);
public:
    Matrix();
    Matrix(unsigned int rows, unsigned int columns);
    Matrix(Matrix &matrixToCopy);
    Matrix(Matrix &&matrixToMove);
    ~Matrix();
    Matrix& operator =(const Matrix& matrixToCopy);
    Matrix& operator =(Matrix&& matrixToMove);
    Matrix add(Matrix& matrixToAdd);
    Matrix operator +(Matrix& matrixToAdd);
    Matrix& operator +=(Matrix& matrixToAdd);
    Matrix multiply(const int scalar);
    Matrix operator *(const int & scalar);
    Matrix & operator *=(const int & scalar);
    Matrix multiply(Matrix& matrix);
    Matrix operator *(Matrix& matrixToMultiply);
    Matrix operator *=(Matrix& matrixToMultiply);
    void setValue(unsigned int row, unsigned int column, int value);
    int getValue(unsigned int row, unsigned int column);
    inline unsigned int getRows() { return m;}
    inline unsigned int getColumns() { return n;}
    friend std::ostream& operator<<(std::ostream& o, const Matrix& matrix);
};

#endif //ZMPO4_MATRIX_H