/*
 * run.cpp
 *
 *  Created on: Jun. 1, 2020
 *      Author: amaldev
 */



#include "Matrix.h"


int main(void){


	float array1[4]= {1,1,3,1};


	int row1,col1;


	row1=2;col1=2;


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
