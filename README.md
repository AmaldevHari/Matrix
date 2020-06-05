# Matrix
Matrix:

Create Matrix objects by passing in 1D array of matrix elements and 
specifying the rows and coloumns for it. Every $coloumn number of 
 elements are interpreted as a row.

You can perform the following operations with Matrix objects: 

The functions that can be called to perform the operations are also 
specified along

1. Multiply two matrices- can be done with m1.multiply(m2) or m1 * m2
2. Find determinants of n x n matrice-  can be done with m.determinant()
3. Find inverse of n x n matrices - can be done with m.inverse()
4. Find adjoints of n x n matrices - can be done with m.adjoint()
5. Transpose a m x n matrix - can be done with m.transpose()
6. Multiply a Matrix with a scalar number- can be done with m.scalar_multiply()
7. Print out the matrix to stdout in standard form- can be done with m.print_matrix()
8. Check if two matrices are equal - can be done with m.equal()

A brief documentation is provided inside source file Matrix.cpp

A more detailed explanantion on the algorithms can be found on algorithm.txt file



For Linux users:

Requirements CMake, g++/gcc

(1) execute the file linux-install-matrix

(2) run linux-run-matrix
 

Gor Windows users:

Requirements g++/gcc
(1)  simply type "win-install-matrix"

(2) type "win-run-matrix"
