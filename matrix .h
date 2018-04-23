// File name: matrix.h
// Description: Header file for the ADT Matrix
// Date: 09/11/2015
//Author: Timothy Mureithi
//pid: tim96
#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
// Here the user can specify a different type;
// your implementation should work for double, float, and int
typedef double MatrixItem;
class Matrix
{
// overload operator<< to print a matrix
 friend ostream& operator<<(ostream& out,const Matrix& m);
public:
// Constructor: create a matrix of size (row_size x column_size)
Matrix(int row_size, int column_size);
// Copy constructor: create a deep copy of matrix orig
Matrix(const Matrix& orig);

 // Destructor: deallocate memory that was allocated dynamically
 ~Matrix();
// Set/Get the value of an element at (row, column), where
// ‘row’ ranges from 0 to (row_size-1), and ‘column’ ranges
// from 0 to (column_size-1)
void setElement(int row, int column, MatrixItem value);
MatrixItem getElement(int row, int column) const;
 
// Overloaded assignment operator
Matrix& operator=(const Matrix& orig);

 // Overloaded matrix math operators

//compute the sum of two matrices
Matrix operator+(const Matrix&) const; 

//add the right-hand-side matrix to the matrix on the left
void Matrix:: operator+=(const Matrix&);

//multiply two matrices
Matrix operator*(const Matrix&);

//multiply two matrices and replace the left-hand matrix with the result
void Matrix:: operator*=(const Matrix&);

//Tests two Matrices for equality(having identical values for each position)
bool Matrix:: operator==(const Matrix&);

//Tests two Matrices for inequality(nhaving identical values for each position)
bool Matrix:: operator!=(const Matrix&);


private:
int rows; // the number of rows in the matrix
int columns; // the number of columns in the matrix
MatrixItem *data; // dynamically allocated array storage
}; // End Matrix class
// End header file