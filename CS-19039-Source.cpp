#include<iostream>
#include<fstream>
#include<conio.h>
#include<time.h>
#include"Matrix.h"
using namespace std;



Matrix operator+( Matrix& M1, Matrix& M2)
{
	Matrix M3;

	if (M1.GetRow() == M2.GetRow() && M1.GetCol() == M2.GetCol())
	{
		M3.allocateMatrix(M1.GetRow(), M1.GetCol());

		for (int ri = 0; ri < M1.GetRow(); ri++)
		{
			for (int ci = 0; ci < M1.GetCol(); ci++)
			{
				M3.GetVs(ri,ci) = M1.GetVs(ri, ci) + M2.GetVs(ri, ci);
			}
		}
		return M3;
	}
	return M3.ReturnNull();
}


Matrix operator-(Matrix& M1, Matrix& M2)
{
	Matrix M3;

	if (M1.GetRow() == M2.GetRow() && M1.GetCol() == M2.GetCol())
	{
		M3.allocateMatrix(M1.GetRow(), M1.GetCol());

		for (int ri = 0; ri < M1.GetRow(); ri++)
		{
			for (int ci = 0; ci < M1.GetCol(); ci++)
			{
				M3.GetVs(ri, ci) = M1.GetVs(ri, ci) - M2.GetVs(ri, ci);
			}
		}
		return M3;
	}
	return M3.ReturnNull();
}

Matrix operator*(Matrix M1, Matrix M2)
{
	Matrix M3(M1.GetRow(), M2.GetCol());
	int j;

	if (M1.GetCol() == M2.GetCol())
	{
		M3.allocateMatrix(M1.GetRow(), M2.GetCol());
		for (int ri = 0; ri < M1.GetRow(); ++ri)
		{
			for (int ci = 0; ci < M2.GetCol(); ++ci)
			{
				j = 0;
				for (int i = 0; i < M1.GetRow(); ++i)
				{
					j += M2.GetVs(ri, ci + i) * M2.GetVs(ri + i, ci);
					M3.GetVs(ri, ci) += M1.GetVs(ri, ci + i) * M2.GetVs(ri + 1, ci);
					//M3.Vs[i][j] = 0;
				}
				M3.GetVs(ri, ci) = j;
			}
		}
		M3.allocateMatrix(M1.GetRow(), M1.GetRow());
		M2 = M3;
		return M2;
	}
	return M3.ReturnNull();

}


Matrix operator!(Matrix &M1)
{
	Matrix M2;
	M2.allocateMatrix(M1.GetCol(), M1.GetRow());
	M1.Transpose(M1,M1.GetRow(),M1.GetCol());
	M2 = M1;
	M1.Transpose(M1, M1.GetRow(), M1.GetCol());
	return M2;
}


Matrix operator+=(Matrix& M1, Matrix& M2)
{

	if (M1.GetRow() == M2.GetRow() && M1.GetCol() == M2.GetCol())
	{

		for (int ri = 0; ri < M1.GetRow(); ri++)
		{
			for (int ci = 0; ci < M1.GetCol(); ci++)
			{
				M1.GetVs(ri, ci) = M1.GetVs(ri, ci) + M2.GetVs(ri, ci);
			}
		}
		return M1;
	}
	return M1.ReturnNull();
}



Matrix operator-=(Matrix& M1, Matrix& M2)
{

	if (M1.GetRow() == M2.GetRow() && M1.GetCol() == M2.GetCol())
	{

		for (int ri = 0; ri < M1.GetRow(); ri++)
		{
			for (int ci = 0; ci < M1.GetCol(); ci++)
			{
				M1.GetVs(ri, ci) = M1.GetVs(ri, ci) - M2.GetVs(ri, ci);
			}
		}
		return M1;
	}
	return M1.ReturnNull();
}

Matrix operator*=(Matrix M1, Matrix M2)
{
	int j;

	if (M1.GetCol() == M2.GetCol())
	{
		M1.allocateMatrix(M1.GetRow(), M2.GetCol());
		for (int ri = 0; ri < M1.GetRow(); ++ri)
		{
			for (int ci = 0; ci < M2.GetCol(); ++ci)
			{
				j = 0;
				for (int i = 0; i < M1.GetRow(); ++i)
				{
					j += M2.GetVs(ri, ci + i) * M2.GetVs(ri + i, ci);
					M1.GetVs(ri, ci) += M1.GetVs(ri, ci + i) * M2.GetVs(ri + 1, ci);
					//M3.Vs[i][j] = 0;
				}
				M1.GetVs(ri, ci) = j;
			}
		}
		return M2;
	}
	return M2.ReturnNull();

}


Matrix operator+(Matrix& M1,int V)
{
	Matrix M3;

		M3.allocateMatrix(M1.GetRow(), M1.GetCol());

		for (int ri = 0; ri < M1.GetRow(); ri++)
		{
			for (int ci = 0; ci < M1.GetCol(); ci++)
			{
				M3.GetVs(ri, ci) = M1.GetVs(ri, ci) + V;
			}
		}
		return M3;
}

Matrix operator-(Matrix& M1, int V)
{
	Matrix M3;

	M3.allocateMatrix(M1.GetRow(), M1.GetCol());

	for (int ri = 0; ri < M1.GetRow(); ri++)
	{
		for (int ci = 0; ci < M1.GetCol(); ci++)
		{
			M3.GetVs(ri, ci) = M1.GetVs(ri, ci) - V;
		}
	}
	return M3;
}

Matrix operator*(Matrix& M1, int V)
{
	Matrix M3;
	V++;

	M3.allocateMatrix(M1.GetRow(), M1.GetCol());

	for (int ri = 0; ri < M1.GetRow(); ri++)
	{
		for (int ci = 0; ci < M1.GetCol(); ci++)
		{
			M3.GetVs(ri, ci) = M1.GetVs(ri, ci) * V;
		}
	}
	return M3;
}

bool operator==(Matrix& M1,Matrix& M2)
{
	if (M1.GetRow() != M2.GetRow() || M1.GetCol() != M2.GetCol())
		return 0;

	for (int ri = 0; ri < M1.GetRow(); ri++)
	{
		for (int ci = 0; ci < M1.GetCol(); ci++)
		{
			if (M1.GetVs(ri, ci) != M2.GetVs(ri, ci))
				return 0;
		}
	}
	return 1;
}


Matrix operator--(Matrix& M1)
{
	Matrix M3;

	M3.allocateMatrix(M1.GetRow(), M1.GetCol());

	for (int ri = 0; ri < M1.GetRow(); ri++)
	{
		for (int ci = 0; ci < M1.GetCol(); ci++)
		{
			M3.GetVs(ri, ci) = M1.GetVs(ri, ci) - 1;
		}
	}
	return M3;
}


Matrix operator++(Matrix& M1)
{
	Matrix M3;

	M3.allocateMatrix(M1.GetRow(), M1.GetCol());

	for (int ri = 0; ri < M1.GetRow(); ri++)
	{
		for (int ci = 0; ci < M1.GetCol(); ci++)
		{
			M3.GetVs(ri, ci) = M1.GetVs(ri, ci) + 1;
		}
	}
	return M3;
}



void Sleep(int x)
{
	int l = 0;
	for ( int i = 0;  i < x*x*x; i++)
	{
		for (int j = 0;  j < x * x  ; j++)
		{
			l++;
		}
	}
}

int main()
{
	srand(time(0));
	int NOM = 0;
	ifstream Rdr("Data.txt");
	Rdr >> NOM;
	Matrix* Ms = new Matrix[NOM];
	for (int mi = 0; mi < NOM; mi++)
	{
		int R, C;
		Rdr >> R >> C;
		Ms[mi].allocateMatrix(R, C);
		Ms[mi].loadMatrix(Rdr);
		Ms[mi].print("M");
	}
	Matrix M3;

	char D, Opr;

	int One, Two, Three;
	do
	{
		//do
		//{
			system("cls");

			for (int mi = 0; mi < NOM; mi++)
			{
				Ms[mi].print("M");
			}

			cin >> D >> One >> D >> D >> Two >> Opr >> D >> Three;
			cout << endl;
			Two--, Three--;
			switch (Opr)
			{
			case '+':
				M3 = Ms[Two] + Ms[Three];                    //        Metrice1+Metrice2
				M3.print("Affan");
				break;
			case '-':
				M3 = Ms[Two] - Ms[Three];                    //        Metrice1-Metrice2
				M3.print("Affan");
				break;
			case 'P':
			   Ms[Two] += Ms[Three];                         //        Metrice1 = Metrice1+Metrice2
			   Ms[Two].print("Affan");
				break;
			case 'S':
				Ms[Two] -= Ms[Three];                         //        Metrice1 = Metrice1-Metrice2
				Ms[Two].print("Affan");
				break;
			case '*':
				Ms[Two] * Ms[Three];                         //        Metrice1 = Metrice1*Metrice2
				Ms[Two].print("Affan");
				break;
			case 'M':
				Ms[Two] *= Ms[Three];                         //        Metrice1 = Metrice1*Metrice2
				Ms[Two].print("Affan");
				break;
			case 's':
				M3 = Ms[Two] + Three;                         //      Subtract constant from metrice
				M3.print("Affan");
				break;
			case 'a':
				M3 = Ms[Two] + Three;                         //      Add constant to metrice
				M3.print("Affan");
				break;
			case 'm':
				M3 = Ms[Two] * Three;                         //     Multiply metrice by constant
				M3.print("Affan");
				break;
			case 'E':
				if (Ms[Two] == Ms[Three])
					cout << "Matrices are Equal";              //     ==   is Equal to 
				else
					cout << "Matrices are not Equal";
				break;
			case 'D':
				M3 = --Ms[Two];                               //     Deccrement
				M3.print("Affan");
				break;
			case 'I':
				M3 = ++Ms[Two];                               //     Increment
				M3.print("Affan");
				break;
			case 'T':
				M3 = !Ms[Two];                               //     Transpose
				M3.print("Affan");
				break;



			
			}
			Sleep(50);
	//	} while (kbhit());
		
	} while (69);

		return _getch();
}
