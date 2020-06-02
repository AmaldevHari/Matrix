/*
 * run.cpp
 *
 *  Created on: Jun. 1, 2020
 *      Author: amaldev
 */



#include "Matrix.h"


int main(void){


	float array1[25]= {1,2,3,1,2,3,5,6,1,2,7,3,2,1,2,1,1,1,1,2,2,2,2,2,2};
	//float array2;

	int row1,col1;//row2,col2;
/*
	cout<<"Enter number of rows for left hand matrix:";
	cin>>row1;
	cout<<"\n";
	cout<<"Enter number of columns for left hand matrix:";
	cin>>col1;

	cout<<"Enter number of rows for right hand matrix:";
	cin>>row2;
	cout<<"\n";
	cout<<"Enter number of columns for right hand matrix:";
	cin>>col2;

	int num_elements1 = row1*col1 ;int num_elements2= row2*col2;

	array1= new float[num_elements1];
	array2 = new float[num_elements2];

	cout<<"Enter the elements of the left hand matrix row by row with each element followed by Enter key:";
	for(int i =0 ;i <num_elements1 ;i++){
		cin>>array1[i];
	}

	cout<<"Enter the elements of the right hand matrix row by row with each element followed by Enter key:";
		for(int i =0 ;i <num_elements2 ;i++){
			cin>>array2[i];
		}*/

row1=5;col1=5;


	Matrix m(&array1[0], row1, col1);
	//Matrix m2(array2,row2,col2);
//	Matrix z =m*m2;
	//z.print_matrix();
	m.print_matrix();
	cout<<"\n";
	auto start = std::chrono::system_clock::now();

	cout<<m.determinant()<<"\n";


	auto end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	std::cout << "finished computation at " << std::ctime(&end_time)
	              << "elapsed time: " << elapsed_seconds.count() << "\n";


	//m.cofactor().print_matrix();
	cout<<"inverse of this matrix is:"<<"\n";
	/*float det = m.determinant();
	float input =1.0/det;
	Matrix n;n=(m.cofactor()).transpose();
	n.scalar_multiply(input);
	n.print_matrix();

	Matrix x = m*n;
	x.print_matrix();*/
	m.inverse().print_matrix();
	cout<<"\n";
	(m* m.inverse()).print_matrix();
	return 0;
}
