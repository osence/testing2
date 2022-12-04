/*
	Сергеевский Максим
	Программа для тестирования
	Содержит в себе 2 класса по 3 метода
	Матрицы и вектора
	в качестве методов будут реализованы операции 
	1) Произведение матрицы на число
	2) Произведение матрицы на матрицу
	3) Получение элемента матрицы по индексам

	1) Сумма векторов
	2) Произведение вектора на число
	3) Умножение вектора на матрицу
*/
#include <iostream>
#include "Matrix.h"
#include "Vector.h"
using namespace std;
int main() {
	//Matrix M(5, 5);

	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//		M.Element(i, j) = i + j;
	//}

	//M.Display();

	//cout << "\n After multiply by 5\n" << endl;
	//M.MultiplyBy(5);
	//M.Display();

	//Matrix A(2, 2);
	//A.Element(0, 0) = 2;
	//A.Element(0, 1) = -1;
	//A.Element(1, 0) = 5;
	//A.Element(1, 1) = 3;

	//Matrix B(2, 3);
	//B.Element(0, 0) = 3;
	//B.Element(0, 1) = 1;
	//B.Element(0, 2) = 0;
	//B.Element(1, 0) = 2;
	//B.Element(1, 1) = -1;
	//B.Element(1, 2) = 5;
	//cout << endl;
	//A.Display();
	//cout << "Matrix Multiply" << endl;
	//B.Display();
	//cout << "Equals" << endl;
	//A.MultiplyOnMatrix(B).Display();
	//cout << "Vectors" << endl << endl;
	//Vector V(2);
	//V.Element(0) = 2;
	//V.Element(1) = 6;

	//Matrix T(3, 2);
	//T.Element(0, 0) = 3;
	//T.Element(0, 1) = 1;
	//T.Element(1, 0) = 0;
	//T.Element(1, 1) = 2;
	//T.Element(2, 0) = -1;
	//T.Element(2, 1) = 5;
	//V.Display();
	//cout << endl;
	//T.Display();
	//cout << endl;
	//cout << "Multiply on Matrix" << endl;
	//V.MultiplyOnMatrix(T).Display();
	Matrix M(2, 2);
	M.Element(0, 0) = 2;
	M.Element(0, 1) = -1;
	M.Element(1, 0) = 5;
	M.Element(1, 1) = 3;
	M.MultiplyBy(8);
	M.MultiplyOnMatrix(M);

	//L equals M
	Matrix L(2, 2);
	L.Element(0, 0) = 2;
	L.Element(0, 1) = -1;
	L.Element(1, 0) = 5;
	L.Element(1, 1) = 3;
	L.MultiplyOnMatrix(L);
	L.MultiplyBy(8);
	M.Display();
	cout << endl;
	L.Display();

	return 0;

}