/*
 * run.cpp
 *
 *  Created on: Jun. 1, 2020
 *      Author: amaldev
 */



#include "Matrix.h"

int main(void){


	int row=3;int col=3;
	float ary[]={1,2,3,4,5,6,7,8,9};
	float* mat = &ary[0];
	float ary2[] ={1,2,3,4,5,6,7,8,9};
	float* mat1 =&ary2[0];
	Matrix m(mat, row, col);
	Matrix m2(mat1,3,3);
	Matrix z =m*m2;
	z.print_matrix();


	return 0;
}
