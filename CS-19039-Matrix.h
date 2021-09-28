#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class Matrix
{
	int** Vs;
	int Rows;
	int Cols;
public:
	Matrix();
	Matrix(int R, int C);
	Matrix(ifstream& Rdr);
	void allocateMatrix(int, int);
	void loadMatrix(ifstream& Rdr);
	void print(const char*)const;
	void deleteMatrix();
	Matrix ReturnNull();
	Matrix Multiply(const Matrix& other) ;


	void Swap(int& A, int& B)
	{
		int Hold = A;
		A = B;                                                        // Swaping Two Adjecent Elements of an Array.
		B = Hold;
	}

	void Transpose(Matrix &M, int R, int C)
	{
		for (int Ri = 0; Ri < R; Ri++)                                // Transpose of Matrices.
		{
			for (int Ci = 0; Ci < Ri; Ci++)
			{
				Swap(M.Vs[Ci][Ri], M.Vs[Ri][Ci]);
			}
		}
	}

	void operator=(Matrix Mr)
	{
		allocateMatrix(Mr.Rows, Mr.Cols);
		for (int ri = 0; ri < Rows; ri++)
		{
			for (int ci = 0; ci < Cols; ci++)
			{
			Vs[ri][ci] = Mr.Vs[ri][ci];
			}
		}
	}

	int& GetVs(int R, int C)
	{
		return Vs[R][C];
	}

	int GetRow()
	{
		return Rows;
	}
	int GetCol()
	{
		return Cols;
	}
};