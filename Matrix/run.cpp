/*
 * run.cpp
 *
 *  Created on: Jun. 1, 2020
 *      Author: amaldev
 */



#include "Matrix.h"


int main(void){


	float array1[25]= {1,2,3,1,2,3,5,6,1,2,7,3,2,1,2,1,1,1,1,2,2,2,2,2,2};


	int row1,col1;


	row1=5;col1=5;


	Matrix m(&array1[0], row1, col1);

	m.print_matrix();
	cout<<"\n";


	cout<<m.determinant()<<"\n";





	cout<<"inverse of this matrix is:"<<"\n";

	m.inverse().print_matrix();
	cout<<"\n";
	(m* m.inverse()).print_matrix();
	return 0;
}
