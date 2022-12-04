#ifndef VECTOR_H
#define VECTOR_H

#include <gtest/gtest.h>
#include "Vector.h"
#include "Matrix.h"


#define MAXLINE 1024

//Тест на присвоение значения элементу Вектора и его получения
TEST(TestCaseVector, TestFindVectorElement) {
	Vector M(5);
	M.Element(2) = 3;
	M.Element(4) = 4;
	M.Element(2) = 9;
	EXPECT_EQ(M.Element(2), 9);
	EXPECT_EQ(M.Element(4), 4);
}
//Тест на операцию умножения матрицы на число
TEST(TestCaseVector, TestMultiplyVectorByNumber) {
	Vector V(3);
	V.Element(0) = 3;
	V.Element(1) = 4;
	V.Element(2) = 9;
	V.MultiplyBy(9);
	EXPECT_EQ(V.Element(0), 27);
	EXPECT_EQ(V.Element(1), 36);
	EXPECT_EQ(V.Element(2), 81);
}

//Тест на операцию умножения матрицы на матрицу
TEST(TestCaseVector, TestMultiplyVectorByMatrix) {
	Vector V(2);
	V.Element(0) = 2;
	V.Element(1) = 6;

	Matrix B(3, 2);
	B.Element(0, 0) = 3;
	B.Element(0, 1) = 1;
	B.Element(1, 0) = 0;
	B.Element(1, 1) = 2;
	B.Element(2, 0) = -1;
	B.Element(2, 1) = 5;

	Matrix C = V.MultiplyOnMatrix(B);
	EXPECT_EQ(C.Element(0, 0), 6);
	EXPECT_EQ(C.Element(0, 1), 6);
	EXPECT_EQ(C.Element(1, 0), 0);
	EXPECT_EQ(C.Element(1, 1), 12);
	EXPECT_EQ(C.Element(2, 0), -2);
	EXPECT_EQ(C.Element(2, 1), 30);
}

#endif // VECTOR_H