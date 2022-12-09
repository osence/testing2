#pragma once
#include <iostream>
using namespace std;

class Matrix
{
private:
    int** Matr;
    int m;
    int n;

    void Create()
    {
        Matr = new int* [m];
        for (int z = 0; z < m; z++)
            Matr[z] = new int[n];
    }
protected:
    void MultiplyBy(int x)
    {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                Matr[i][j] *= x;
    }
public:
    // constructors and destructor
    Matrix() : m(5), n(5) { Create(); }
    Matrix(int i) : m(i), n(i) { Create(); }
    Matrix(int i, int j) : m(i), n(j) { Create(); }
    /*~Matrix()
    {
        for (int z = 0; z < m; z++)
            delete[] Matr[z];
        delete[] Matr;
    }*/
    int getNSize() { return n; }
    int getMSize() { return m; }
    // methods
    int& Element(int i, int j)
    {
        if (i < m && j < n)
            return Matr[i][j];
        else
            cout << "Error: 1";
    }

    Matrix MultiplyOnMatrix(Matrix B) 
    {
        if (B.getMSize() != n) { throw std::out_of_range("Out of range2"); }
        Matrix C(m, B.getNSize());
        for (int p = 0; p < m; p++){
            for (int v = 0; v < B.getNSize(); v++){
                C.Element(p, v) = 0;
                for (int k = 0; k < n; k++)
                {
                    C.Element(p, v) += Matr[p][k] * B.Element(k, v);
                }
            }
        }
        return C;
    }

    void Display()
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout.width(4);
                cout << Matr[i][j];
            }
            cout << endl;
        }
    }
};
