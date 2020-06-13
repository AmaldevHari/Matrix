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
#include <windows.h>


static HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);

static void set_output_green(){
	 SetConsoleTextAttribute(h_console, 2);

}
static void set_output_blue(){
	 SetConsoleTextAttribute(h_console, 1);

}
static void set_output_red(){
	 SetConsoleTextAttribute(h_console, 4);

}
static void set_output_magenta(){
	 SetConsoleTextAttribute(h_console, 5);

}
static void set_output_default(){
	 SetConsoleTextAttribute(h_console, 7);

}
/* 1 for blue, 4 for red, 2 for green , 5 for magenta , 7 for white(default)*/
using namespace std;


class Matrix{
	float** make_2d(float* , int ,int);
public:

	int row;

	int col;

	bool is_valid;

	float** mat;

	Matrix(float* , int ,int );
	Matrix();

	Matrix	multiply(Matrix&);

	Matrix operator*( Matrix&);



	int print_matrix();

	float determinant();

	Matrix transpose();

	Matrix adjoint();

	void scalar_multiply(float);

	Matrix inverse();

	Matrix cofactor();

	bool equal(Matrix& );

	Matrix generate_random_matrix(int , int, float, bool, bool);
	
};
#endif /* MATRIX_H_ */
