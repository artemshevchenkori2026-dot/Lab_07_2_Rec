#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07_2_Rec/Lab_07_2_Rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab0722
{
    TEST_CLASS(UnitTestLab0722)
    {
    public:
        TEST_METHOD(TestMethodMinSecondaryDiagonalRec)
        {
            const int n = 3;
            int** a = new int* [n];
            for (int i = 0; i < n; i++)
                a[i] = new int[n];

            // Матриця 3x3:
            //  1   2   [8]  -> елемент побічної діагоналі (i=0, j=2): 8
            //  4  [-2]  6   -> елемент побічної діагоналі (i=1, j=1): -2
            // [12] 5    7   -> елемент побічної діагоналі (i=2, j=0): 12
            a[0][0] = 1;  a[0][1] = 2;  a[0][2] = 8;
            a[1][0] = 4;  a[1][1] = -2; a[1][2] = 6;
            a[2][0] = 12; a[2][1] = 5;  a[2][2] = 7;

            int minDiag = MinSecondaryDiagonal(a, n, 0);

            Assert::AreEqual(-2, minDiag); // Мінімальний серед {8, -2, 12} є -2

            for (int i = 0; i < n; i++)
                delete[] a[i];
            delete[] a;
        }
    };
}