/*
 * Matrix.cpp
 *
 *  Created on: May 30, 2020
 *      Author: amaldev
 */

#include "Matrix.h"


int main(void){


	int row=3;int col=3;
	float ary[]={2,2,2,2,2,2,2,2,2,2};
	float* mat = &ary[0];
	float ary2[] ={1,1,1,1,1,1,1,1,1};
	float* mat1 =&ary2[0];
	Matrix m(mat, row, col);
	Matrix m2(mat1,3,3);
	Matrix z =m*m2;
	for(int i =0; i<9;i++){
		char e ='\n';
		char append=' ';
		if((i+1)%3 ==0){
			append=e;
		}
	cout<<*(z.mat+ i)<<append;
	append=' ';
	}

	return 0;
}


