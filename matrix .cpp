#include "matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix(int row_size, int column_size)
{
	try
	{
		if( row_size > 5 || row_size <= 0 || column_size > 5 || column_size <= 0) throw(row_size*column_size);
		rows = row_size;
		columns = column_size;
			//Dynamically allocate memory for 1D array 
		data = new MatrixItem[rows * columns];
		if (data == NULL) throw (row_size);
		//initialize matrix elements to contain the value of
		//that element's row - element's column
		for (int i = 0; i <rows; i++)	
		{
			for( int j = 0; j < columns; j++)
			{
				data[i*columns + j] = MatrixItem (i - j); //initializes element at row i and column j to (i-j)
			}
		}
	}
	catch (int i)
	{
		cout<< "ERROR: Cannot make matrix larger than 5x5 or with row and column size less than 1, rows x  columns was:" << i << endl;
	}
}

Matrix::~Matrix()
{
	delete []data;
}

MatrixItem Matrix::getElement(int row, int column) const
{
	try
	{
		if (row <0 || row >= rows || column <0 || column >= columns) throw (row);

		MatrixItem result = data[row*columns + column];
		return data[row*columns + column];
	}
	catch(int i)
	{
		cout<<"ERROR: trying to access index outside of matrix" << i << endl;
	}
}

void Matrix::setElement(int row, int column, MatrixItem value)
{
	try
	{
		if (row <0 || row >= rows || column <0 || column >= columns) throw (row);

		data[row*columns + column] = value;
	}
	catch(int i)
	{
		cout<<"ERROR: trying to access index outside of matrix" << i << endl;
	}

}

//copy constructor
Matrix::Matrix(const Matrix& orig)
{
	rows = orig.rows;
	columns = orig.columns;
	data = new MatrixItem[rows * columns];
	for( int i = 0; i < rows*columns; i++)
	{
			data[i] = orig.data[i];
	}
}

//overloaded assignment: deep copy
Matrix& Matrix:: operator=(const Matrix& orig)
{

	if(this != &orig)
	{
		delete []data;
		rows = orig.rows;
		columns = orig.columns;
		data = new MatrixItem[ rows * columns];
		for( int i = 0; i < rows*columns; i++)
		{
			data[i] = orig.data[i];
		}
		return *this;
	}
	
}

ostream& operator<<(ostream& out,const Matrix& m)
{
	//fixes the precision so matrix is displayed uniformly
	out << std::fixed << std::setprecision(1) << endl;
	for (int i = 0; i < m.rows; i++)
	{
		out << "	";
		for (int j = 0; j < m.columns; j++)
		{
			out << m.getElement(i,j) ;
			
			if(j != m.columns-1)//adds a space between elements
			{
				out << "	";
			}else
				out << endl;
		}

		
	}
	return out;
}

Matrix Matrix::operator+(const Matrix& orig) const
{
	Matrix temp(orig.rows, orig.columns);
	try
	{
		if( rows != orig.rows || columns != orig.columns) throw(rows*orig.columns);
	for( int i = 0; i < temp.rows*temp.columns; i++)
	{
		temp.data[i] = orig.data[i] + data[i];
	}
	return temp;
	}
	catch (int i)
	{
		cout << "ERROR: cannot add matrices whose sizes dont match rows x  columns was:" << i << endl;
	}
}

void Matrix:: operator+=(const Matrix& orig)
{
	Matrix result(orig.rows, orig.columns);
	result = *this + orig;
	*this = result;
}

Matrix Matrix:: operator*(const Matrix& orig)
{
	try
	{
		if( columns != orig.rows ) throw(columns*orig.rows);
		Matrix temp(rows, orig.columns);
		for (int i = 0; i <rows; i++)	
		{
			for (int j = 0; j < columns; j++)
			{
				MatrixItem mult = 0;
				for(int k = 0 ; k < columns; k++)
				{
						mult = mult + data[i*columns + k] * orig.data[k*orig.columns + j];
				}
				temp.data[i*columns + j] = mult;
			}
		}
		return temp;
	}
	catch(int i)
	{
		cout <<"ERROR: cannot add matrices whose sizes dont matchrows x  columns was:" << i << endl;
	}
}

void Matrix:: operator*=(const Matrix& orig)
{
	Matrix result(rows, orig.columns);
	result = *this * orig;
	*this = result;
}

bool Matrix:: operator==(const Matrix& orig)
{
	try
	{
		if( rows != orig.rows || columns != orig.columns) throw(rows*orig.columns);
	bool result = true;
	for( int i = 0; i <rows*columns; i++)
	{
		if( data[i] != orig.data[i])
		{
			result = false;
		}
	}
	return result;
	}
	catch (int i)
	{
		cout << "ERROR: cannot compare matrices whose sizes dont matchrows x  columns was:" << i << endl;
	}
}

bool Matrix:: operator!=(const Matrix& orig)
{
	try
	{
		if( rows != orig.rows || columns != orig.columns) throw(rows*orig.columns);
	bool result = false;
	for( int i = 0; i <rows*columns; i++)
	{
		if( data[i] != orig.data[i])
		{
			result = true;
		}
	}
	return result;
	}
	catch (int i)
	{
		cout << "ERROR: cannot compare matrices whose sizes dont matchrows x  columns was:" << i << endl;
	}
}