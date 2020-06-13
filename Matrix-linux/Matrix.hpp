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
#include <stdlib.h>
#include <time.h>

//the following are colour codes for stdout in UBUNTU/LINUX
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


using namespace std;

class Matrix{
	float** make_2d(float* , int ,int);
public:

	int row;

	int col;

	float** mat;

	bool is_valid;

	Matrix(float* , int ,int );
	Matrix();

	Matrix	multiply(Matrix&);

	Matrix operator*( Matrix&);



	int print_matrix() const;

	float determinant();

	Matrix transpose();

	Matrix adjoint();

	void scalar_multiply(float);

	Matrix inverse();

	Matrix cofactor();

	bool equal(Matrix& ) const;

	Matrix generate_random_matrix(int , int, float, bool, bool);
};
#endif /* MATRIX_H_ */
