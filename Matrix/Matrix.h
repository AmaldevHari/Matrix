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
#include <vector>

using namespace std;

class Matrix{
public:

	int row;
	int col;
	float** mat;
	Matrix(float* a[], int row,int col){

		Matrix::row = row;
		Matrix::col = col;
		Matrix::mat= new float* [row* col];

		for( int i=0 ; i< row*col ;i ++){

						Matrix::mat[i]= a[i];


					}


	};


};


#endif /* MATRIX_H_ */
