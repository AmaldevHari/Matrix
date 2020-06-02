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
#include <chrono>
#include <ctime>
#include <cmath>

using namespace std;

class Matrix{
public:

	int row;

	int col;

	float** mat;

	Matrix(float* , int ,int );
	Matrix();
	Matrix	multiply(Matrix);

	Matrix operator*( Matrix );

	float** make_2d(float* , int ,int);

	int print_matrix();

	float determinant();

	Matrix transpose();

	Matrix cofactor();

	void scalar_multiply(float);

	Matrix inverse();
};
#endif /* MATRIX_H_ */
