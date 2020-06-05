/*
 * run.cpp
 *
 *  Created on: Jun. 1, 2020
 *      Author: amaldev
 */



#include "Matrix.h"


int main(int argc, char* argv[]){


	float array1[12]= {1,1,3,1,1,7,1,5,6,3,2,8};


	int row1,col1;


	row1=3;col1=4;


	Matrix m(&array1[0], row1, col1);

	m.print_matrix();
	cout<<"\n";


	cout<<m.determinant()<<"\n";





	cout<<"inverse of this matrix is:"<<"\n";
	Matrix x= m.inverse();
	x.print_matrix();
	cout<<"\n";
	(m* x).print_matrix();
	cout<<"\n";
	if(m.equal(x)){cout<<"yes";}
	else{cout<<"no";}

	return 0;
}
