/*
 * Matrix.h
 *
 *  Created on: May 30, 2020
 *      Author: amaldev
 */

#ifndef MATRIX_H_
#define MATRIX_H_
#include <iostream>
#include <stddef.h>
#include <cmath>

using namespace std;

class Matrix{
	float** make_2d(float* , int ,int);
public:

	int row;

	int col;

	float** mat;

	Matrix(float* , int ,int );


	Matrix	multiply(Matrix);

	Matrix operator*( Matrix );



	int print_matrix();

	float determinant();

	Matrix transpose();

	Matrix adjoint();

	void scalar_multiply(float);

	Matrix inverse();

	Matrix cofactor();

	bool equal(Matrix );
};
#endif /* MATRIX_H_ */
