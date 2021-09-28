#include "Matrix.h"



Matrix::Matrix()
{
	Rows = Cols = 0;
	Vs = NULL;
}

Matrix::Matrix(int R, int C)
{
	Rows = R;
	Cols = C;
	Vs = nullptr;
	allocateMatrix(R, C);
}

Matrix::Matrix(ifstream& Rdr)
{
	int R, C;
	Rdr >> R >> C;
	allocateMatrix(R, C);
}

void Matrix::allocateMatrix(int R, int C)
{
	if(Vs)
		deleteMatrix();
	Rows = R;
	Cols = C;
	Vs = new int* [R];
	for (int ri = 0; ri < R; ri++)
	{
		Vs[ri] = new int[C];
	}
}

void Matrix::deleteMatrix()
{
	for (int ri = 0; ri < Rows; ri++)
		delete Vs[ri];
	delete[]Vs;
	Vs = nullptr;
}

Matrix Matrix ::  ReturnNull()
{
	Matrix Null(2,2);
	for (int ri = 0; ri < 2; ri++)
	{
		for (int ci = 0; ci < 2; ci++)
		{
			Null.Vs[ri][ci] = 0;
		}
	}
	return Null;
}

void Matrix::loadMatrix(ifstream& Rdr)
{
	for (int ri = 0; ri < Rows; ri++)
	{
		for (int ci = 0; ci < Cols; ci++)
		{
			Rdr >> Vs[ri][ci];
		}
	}
}

void Matrix::print(const char* Msg)const
{
	cout << Msg << " [" << Rows << "," << Cols << "]\n\n";
	for (int ri = 0; ri < Rows; ri++)
	{
		for (int ci = 0; ci < Cols; ci++)
		{
			cout << Vs[ri][ci] << " ";
			//cout << "}"<<endl;
		}
		cout << endl;
	}
	cout << endl;
}






