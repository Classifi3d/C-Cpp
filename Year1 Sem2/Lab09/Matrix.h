#include <iostream>
using namespace std;

const int linii = 20;
const int coloane = 30;
class Matrix
{
    int rows;
    int cols;
    int *elems;

public:
    Matrix();
    Matrix(int rows, int cols);
    Matrix(const Matrix &);
    ~Matrix(void) { delete elems; }
    int &operator()(int row, int col);
    Matrix &operator=(const Matrix &);
    friend Matrix operator+(Matrix &, Matrix &);
    friend Matrix operator-(Matrix &, Matrix &);
    friend Matrix operator*(Matrix &, Matrix &);
    int getRows(void) { return rows; }
    int getCols(void) { return cols; }
    void init(int r, int c);
    void citire();
    void afisare();
}; //Matrix
Matrix::Matrix() : rows(linii), cols(coloane)
{
    elems = new int[rows * cols];
}
Matrix::Matrix(int r, int c) : rows(r), cols(c)
{
    elems = new int[rows * cols];
}
Matrix::Matrix(const Matrix &m) : rows(m.rows), cols(m.cols)
{
    int n = m.rows * m.cols;
    elems = new int[n];
    for (int i = 0; i < n; i++)
        elems[i] = m.elems[i];
}
void Matrix::init(int r, int c)
{
    rows = r;
    cols = c;
    elems = new int[rows * cols];
}
int &Matrix::operator()(int row, int col)
{
    return elems[row * cols + col];
}
Matrix &Matrix::operator=(const Matrix &m)
{
    if (this != &m)
    {
        int n = m.rows * m.cols;
        for (int i = 0; i < n; i++)
            elems[i] = m.elems[i];
    }
    return *this;
}
Matrix operator+(Matrix &p, Matrix &q)
{
    Matrix m(p.rows, p.cols);
    for (int r = 0; r < p.rows; ++r)
        for (int c = 0; c < p.cols; ++c)
            m(r, c) = p(r, c) + q(r, c);
    return m;
}
Matrix operator-(Matrix &p, Matrix &q)
{
    Matrix m(p.rows, p.cols);
    for (int r = 0; r < p.rows; ++r)
        for (int c = 0; c < p.cols; ++c)
            m(r, c) = p(r, c) - q(r, c);
    return m;
} //op-
Matrix operator*(Matrix& p, Matrix& q) {
    Matrix m(p.rows, q.cols);
    for (int r = 0; r < p.rows; ++r)
        for (int c = 0; c < q.cols; ++c)
        {
            m(r, c) = 0;
            for (int i = 0; i < p.cols; ++i)
                m(r, c) += p(r, i) * q(i, c);
        }
    return m;
} //op*
void Matrix::citire()
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            cout << "Dati elem. [" << i << "][" << j << "] ";
            cin >> elems[cols * i + j];
        }
} //citire
void Matrix::afisare()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << elems[cols * i + j] << "\t";
        cout << endl;
    }
} //afisare
