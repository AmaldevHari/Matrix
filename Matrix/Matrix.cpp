/*
 * Matrix.cpp
 *
 *  Created on: May 30, 2020
 *      Author: amaldev
 */

#include "Matrix.h"

static float* assign_elements(float ary[], int row, int col){
	float* mat;

		for( int i=0 ; i< row*col ;i ++){

			float* loc = mat +i;
			*loc= ary[i];


		}
	return mat;
}

int main(void){


	int row=2;int col=2;
	float ary[]={2,0,0,1};
	float* mat = assign_elements(ary,row,col);
	int row2=2;
	int col2=1;
	float ary2[] ={1,0};
	float* mat1 =assign_elements(ary2, row2,col2);
	Matrix m(mat, row, col);
	cout<<m.mat[0]<<" "<<m.mat[1]<<"\n";
	Matrix m2(mat1,2,1);
	Matrix z = m.multiply(m2);
	cout<< z.mat[0] <<" " <<z.mat[1]<< z.mat[2]<<"\n";

	/*(float* a;
	float b =5;
	float d =10;
	a= &b;
	float* e=(a+ sizeof(float) );
			e=&d;
	cout<<a[0] <<" " <<a[1]<<endl;
	return 0; */
}


