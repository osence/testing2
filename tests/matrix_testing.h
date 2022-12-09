#ifndef MATRIX_H
#define MATRIX_H

#include <gtest/gtest.h>
#include "Vector.h"
#include "Matrix.h"


#define MAXLINE 1024

class MatrixTest : public Matrix {
public:
	using Matrix::Matrix;
	void WrapMultiplyBy(int a) { return MultiplyBy(a); }
};
//Ňĺńň íŕ ďđčńâîĺíčĺ çíŕ÷ĺíč˙ ýëĺěĺíňó ěŕňđčöű č ĺăî ďîëó÷ĺíč˙
TEST(TestCaseMatrix, TestFindMatrixElement) {
	Matrix M(5, 5);
	M.Element(1, 2) = 3;
	M.Element(1, 4) = 4;
	M.Element(1, 2) = 9;
	EXPECT_EQ(M.Element(1, 2), 9);
	EXPECT_EQ(M.Element(1, 4), 4);
}

//Ňĺńň íŕ ďđčńâîĺíčĺ çíŕ÷ĺíč˙ ýëĺěĺíňó ěŕňđčöű č ĺăî ďîëó÷ĺíč˙
TEST(TestCaseMatrix, TestCombineMatrixOperations) {
	MatrixTest M(2, 2);
	M.Element(0, 0) = 2;
	M.Element(0, 1) = -1;
	M.Element(1, 0) = 5;
	M.Element(1, 1) = 3;
	M.WrapMultiplyBy(8);
	M.MultiplyOnMatrix(M);

	//L equals M
	MatrixTest L(2, 2);
	L.Element(0, 0) = 2;
	L.Element(0, 1) = -1;
	L.Element(1, 0) = 5;
	L.Element(1, 1) = 3;
	L.MultiplyOnMatrix(L);
	L.WrapMultiplyBy(8);

	EXPECT_TRUE(M.Element(0, 0) == L.Element(0, 0));
	EXPECT_TRUE(M.Element(0, 1) == L.Element(0, 1));
	EXPECT_TRUE(M.Element(1, 0) == L.Element(1, 0));
	EXPECT_TRUE(M.Element(1, 1) == L.Element(1, 1));

}

//Ňĺńň íŕ îďĺđŕöčţ óěíîćĺíč˙ ěŕňđčöű íŕ ÷čńëî
TEST(TestCaseMatrix, TestMultiplyMatrixByNumber) {
	MatrixTest M(2, 2);
	M.Element(0, 0) = 2;
	M.Element(0, 1) = -1;
	M.Element(1, 0) = 5;
	M.Element(1, 1) = 3;
	M.WrapMultiplyBy(-3);
	EXPECT_EQ(M.Element(0, 0), -6);
	EXPECT_EQ(M.Element(0, 1), 3);
	EXPECT_EQ(M.Element(1, 0), -15);
	EXPECT_EQ(M.Element(1, 1), -9);
}



//Ňĺńň íŕ îďĺđŕöčţ óěíîćĺíč˙ ěŕňđčöű íŕ ěŕňđčöó
TEST(TestCaseMatrix, TestMultiplyMatrixByMatrix) {
	Matrix A(2, 2);
	A.Element(0, 0) = 2;
	A.Element(0, 1) = -1;
	A.Element(1, 0) = 5;
	A.Element(1, 1) = 3;

	Matrix B(2, 3);
	B.Element(0, 0) = 3;
	B.Element(0, 1) = 1;
	B.Element(0, 2) = 0;
	B.Element(1, 0) = 2;
	B.Element(1, 1) = -1;
	B.Element(1, 2) = 5;

	Matrix C = A.MultiplyOnMatrix(B);
	EXPECT_EQ(C.Element(0, 0), 4);
	EXPECT_EQ(C.Element(0, 1), 3);
	EXPECT_EQ(C.Element(0, 2), -5);
	EXPECT_EQ(C.Element(1, 0), 21);
	EXPECT_EQ(C.Element(1, 1), 2);
	EXPECT_EQ(C.Element(1, 2), 15);
}

//Ňĺńň íŕ îďĺđŕöčţ óěíîćĺíč˙ ěŕňđčöű íŕ ěŕňđčöó
TEST(TestCaseMatrix, TestMultiplyMatrixByMatrixError) {
	Matrix A(2, 3);
	A.Element(0, 0) = 2;
	A.Element(0, 1) = -1;
	A.Element(0, 2) = 0;
	A.Element(1, 0) = 5;
	A.Element(1, 1) = 3;
	A.Element(1, 2) = 5;

	Matrix B(2, 3);
	B.Element(0, 0) = 3;
	B.Element(0, 1) = 1;
	B.Element(0, 2) = 0;
	B.Element(1, 0) = 2;
	B.Element(1, 1) = -1;
	B.Element(1, 2) = 5;
	    try {
		Matrix C = A.MultiplyOnMatrix(B);
		FAIL() << "Expected std::out_of_range";
	    }
	    catch(std::out_of_range const & err) {
		EXPECT_EQ(err.what(),std::string("Out of range"));
	    }
	    catch(...) {
		FAIL() << "Expected std::out_of_range";
	    }

}
#endif // MATRIX_H
