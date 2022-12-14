#pragma once
#include <iostream>
#include "Matrix.h"
using namespace std;

class Vector
{
private:
    int* Vect;
    int n;

    void Create()
    {
        Vect = new int [n];
    }

public:
    // constructors and destructor
    Vector() : n(5) { Create(); }
    Vector(int i) : n(i) { Create(); }
    /*~Matrix()
    {
        for (int z = 0; z < m; z++)
            delete[] Matr[z];
        delete[] Matr;
    }*/
    int getSize() { return n; }
    // methods
    int& Element(int i)
    {
        if (i < n)
            return Vect[i];
        else
            cout << "Error: 1";
    }

    void MultiplyBy(int x)
    {
        for (int i = 0; i < n; i++)
                Vect[i] *= x;
    }

    Matrix MultiplyOnMatrix(Matrix B)
    {
        if (B.getNSize() != n) { throw std::domain_error("matrix can't be multiply"); }
        Matrix C(B.getMSize(), n);
        for (int i = 0; i < B.getMSize(); i++)
        {
            for (int j = 0; j < n; j++)
            {
                C.Element(i, j) = Vect[j] * B.Element(i, j);
            }
        }
        return C;
    }

    void Display()
    {
        for (int i = 0; i < n; i++)
        {
            cout << Vect[i];
        }
        cout << endl;
    }
};
