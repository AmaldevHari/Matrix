/*
 * Matrix.cpp
 *
 *  Created on: May 30, 2020
 *      Author: amaldev
 */

#include "Matrix.h"

int main(void){


	int row=2;int col=2;
	float ary[row][col]={{1,0},{0,1}};
	float* mat[row * col];
	int r=0; int c=0;
	for( int i=0 ; i< row*col ;i ++){

		if(c == col){
			r++;
			c=0;
		}
		mat[i]= &ary[r][c];
		c++;

	}
	Matrix m(mat, row, col);
   std::cout<<m.mat<<"\n" ;
}


