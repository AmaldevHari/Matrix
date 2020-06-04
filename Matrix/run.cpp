/*
 * run.cpp
 *
 *  Created on: Jun. 1, 2020
 *      Author: amaldev
 */



#include "Matrix.h"


int main(int argc, char* argv[]){



	Matrix x ;
	x=x.generate_random_matrix(4,4,51.0,true);
	x.print_matrix();
	Matrix m= x.inverse();

	cout<<"\n";
	m.print_matrix();
	cout<<"\n";
	(m* x).print_matrix();
	cout<<"\n";
	if(m.equal(x)){cout<<"yes";}
	else{cout<<"no";}

	return 0;
}
