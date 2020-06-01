/*
 * Matrix.cpp
 *
 *  Created on: May 30, 2020
 *      Author: amaldev
 */

#include "Matrix.h"


int main(void){


	int row=2;int col=2;
	float ary[]={2.0,0.0,0.0,1.0};
	float* mat = &ary[0];
	float ary2[] ={1,0};
	float* mat1 =&ary2[0];
	Matrix m(mat, row, col);
	cout<<m.mat[0]<<" "<<m.mat[1]<<"\n";
	Matrix m2(mat1,2,1);
	Matrix z = m.multiply(m2);
	cout<< z.mat[0] <<" " <<z.mat[1]<<"\n";
	cout<<*mat<<","<<*(mat +1)<<","<<*(mat+2)<<","<<*(mat+3)<<"\n";


	return 0;
}


