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
	float* mat;
	Matrix(float* a, int row,int col){

		Matrix::row = row;
		Matrix::col = col;
		Matrix::mat= a;

	/*	for( int i=0 ; i< row*col ;i ++){

						Matrix::mat[i]= a[i];


					}
*/

	};
	Matrix	multiply(Matrix b){
		int col= this->col;
		float* mat;
		int matrix1_row= this->row;
		int matrix2_col = b.col;
		int matrix1_col =this->col;
		Matrix result(mat, matrix1_row, matrix2_col);
		int current_result_index=0;
		for(int i=0 ;i<matrix1_row; i++){
			for( int j=0; j<matrix2_col ;j++){
				float entry=0;
				for(int k=0; k< matrix1_col; k++){
					entry+= *(this->mat + matrix1_col*i+ k)* *(b.mat + k* matrix2_col +j);
				}
				float* r;
				r=mat+ current_result_index;
				*r= entry;
				current_result_index ++;
			}
		}


		return result;

		};


};

#endif /* MATRIX_H_ */
