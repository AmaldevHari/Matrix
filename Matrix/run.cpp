/*
 * run.cpp
 *
 *  Created on: Jun. 1, 2020
 *      Author: amaldev
 */



#include "Matrix.h"
#include <limits>

Matrix main_loop_matrix_init(){



	int row; int col;

	cout<<BOLDGREEN<<"Enter number of rows and coloumns in order: "<<RESET<<"\n\n";


	while(!(cin >> row)){
		cout << BOLDRED<<"error: invalid input!"<<RESET;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	while(!(cin >> col)){
		cout << BOLDRED<<"error: invalid input!"<<RESET;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}


	float* mat;int it= row*col;
	mat = new float[it];

	cout<<BOLDGREEN<<"Enter elements of matrix row by row: "<<RESET<<"\n\n";


	for( int i=0;i <it; i++){
		while(!(cin >> mat[i])){
			cout << BOLDRED<<"error: invalid input!"<<RESET;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}


	}

	Matrix m(mat, row, col);
	return m;
}


int ask(){


	cout<<BOLDGREEN<<" The following operations are available:"<<"\n\n";
	cout<<"1.multiply"<<"\n";
	cout<<"2.adjoint"<<"\n";
	cout<<"3.cofactor"<<"\n";
	cout<<"4.determinant"<<"\n";
	cout<<"5.print matrix"<<"\n";
	cout<<"6.scalar multiply"<<"\n";
	cout<<"7.inverse"<<"\n";
	cout<<"8.reset matrix and other data related to it and start over"<<"\n";
	cout<<"9.save the resultant matrix of previous opeartion to one of the two matrices"<<"\n";
	cout<<"10. transpose"<<"\n";
	cout<<"reply with a number representing the operation"<<RESET"\n\n";

	int result;
	while(!(cin >> result)){
		cout << BOLDRED<<"error: invalid input!"<<RESET;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}


	cout<<"\n";
	return result;
}


Matrix*  operate(Matrix* one_, Matrix* two_ , Matrix* three_, int operation, int previous_operation){

	int dec=0;

	Matrix one =*one_;
	Matrix two =*two_;
	Matrix three =*three_;

	switch(operation){

			case 1: three=one.multiply(two);three.print_matrix(); cout<<"\n\n";break;
			case 2: cout<<BOLDGREEN<<"Which matrix 1 or 2?: \n\n"<<RESET;

			while(!(cin >> dec)){
				cout <<BOLDRED<< "error: invalid input!"<<RESET;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if(dec ==1){
				three=one.adjoint();three.print_matrix();
				cout<<"\n\n";
			}else if( dec ==2){
				three=two.adjoint();three.print_matrix();
				cout<<"\n\n";
			}else{
				cout<<BOLDRED<<"error: unrepresented matrix number\n\n"<<RESET;}
			break;

			case 3:  cout<<BOLDGREEN<<"Which matrix 1 or 2?: \n\n"<<RESET;

			while(!(cin >> dec)){
				cout <<BOLDRED <<"error: invalid input!"<<RESET;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if(dec ==1){
				three=one.cofactor();three.print_matrix();
				cout<<"\n\n";
			}else if( dec ==2){
				three=two.cofactor();three.print_matrix();
				cout<<"\n\n";
			}else{
				cout<<BOLDRED<<"error: unrepresented matrix number\n\n"<<RESET;}
			break;

			case 4:  cout<<BOLDGREEN<<"Which matrix 1 or 2?: \n\n"<<RESET;
			while(!(cin >> dec)){
				cout <<BOLDRED<< "error: invalid input!"<<RESET;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if(dec ==1){
				cout<<"\n"<<BOLDBLUE<<one.determinant();
				cout<<RESET"\n\n";
			}else if( dec ==2){
				cout<<"\n"<<BOLDBLUE<<two.determinant();
				cout<<RESET"\n\n";
			}else{
				cout<<BOLDRED<<"error: unrepresented matrix number\n\n"<<RESET;}
			break;

			case 5: cout<<BOLDGREEN<<"Which matrix 1 or 2?: \n\n"<<RESET;
			while(!(cin >> dec)){
				cout <<BOLDRED<< "error: invalid input!"<<RESET;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if(dec ==1){
				one.print_matrix();
				cout<<"\n\n";
			}else if( dec ==2){
				two.print_matrix();
				cout<<"\n\n";
			}else{
				cout<<BOLDRED<<"error: unrepresented matrix number\n\n"<<RESET;}
			break;

			case 6:{ cout<<BOLDGREEN<<"Which matrix 1 or 2?: \n\n"<<RESET;
			while(!(cin >> dec)){
				cout << BOLDRED<<"error: invalid input!"<<RESET;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			float num;
			if(dec ==1){

				cout<<BOLDGREEN<<"enter a number to multiply(WARNING:The original matrix will be changed!):"<<RESET<<"\n\n";
				while(!(cin >> num)){
					cout << BOLDRED<<"error: invalid input!"<<RESET;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}

				one.scalar_multiply(num);
				one.print_matrix(); cout<<"\n\n";
			}else if( dec ==2){
				cout<<BOLDGREEN<<"enter a number to multiply(WARNING:The original matrix will be changed!):"<<RESET<<"\n\n";
				while(!(cin >> num)){
					cout <<BOLDRED<< "error: invalid input!"<<RESET;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}

				two.scalar_multiply(num);
				two.print_matrix(); cout<<"\n\n";

			}
			else{
				cout<<BOLDRED<<"error: unrepresented matrix number\n\n"<<RESET;}
			break;

			case 7: { cout<<BOLDGREEN<<"Which matrix 1 or 2?: \n\n"<<RESET;
			while(!(cin >> dec)){
				cout << BOLDRED<<"error: invalid input!"<<RESET;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if(dec ==1){

				three=one.inverse();three.print_matrix();
				cout<<"\n\n";
			}else if( dec ==2){
				three=two.inverse();three.print_matrix();
				cout<<"\n\n";
			}else{
				cout<<BOLDRED<<"error: unrepresented matrix number\n\n"<<RESET;}}
			break;
			case 8:  return nullptr;

			case 9: {

				ask_again:cout<<BOLDGREEN<<"Save to which matrix 1 or 2?: \n\n"<<RESET;
				while(!(cin >> dec)){
					cout << BOLDRED<<"error: invalid input!"<<RESET;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				if(!(dec == 1 || dec== 2)){
					cout<<BOLDRED<<"error: unrepresented matrix number\n\n"<<RESET;goto ask_again;
				}

				switch(previous_operation){
				case 1: if(dec ==1){
					one =three;
				}else{
					two =three;
				}
				break;
				case 2:
					if(dec ==1){
						one =three;
					}else{
						two =three;
					}
					break;
				case 3:
					if(dec==1){
						one =three;
					}else{
						two =three;
					}
					break;
				case 7:
					if(dec==1){
						one =three;
					}else{
						two =three;
					}
					break;
				case 10:
					if(dec==1){
						one =three;
					}else{
						two =three;
					}
				}
				break;
			}
			case 10:
				cout<<BOLDGREEN<<"Which matrix 1 or 2?: \n\n"<<RESET;

				while(!(cin >> dec)){
					cout <<BOLDRED <<"error: invalid input!"<<RESET;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				if(dec ==1){
					three=one.transpose();three.print_matrix();
					cout<<"\n\n";
				}else if( dec ==2){
					three=two.transpose();three.print_matrix();
					cout<<"\n\n";
				}else{
					cout<<BOLDRED<<"error: unrepresented matrix number\n\n"<<RESET;}
				break;

			}


			}
	Matrix* result =new Matrix[3];
	result[0] =one;
	result[1] =two;
	result[2] =three;

	return result;


}

int main(int argc, char* argv[]){





	while( true){

		float* phony =new float;
		Matrix one;
		Matrix two(phony, 0, 0);
		Matrix three(phony, 0, 0);

		start:cout<<BOLDGREEN<<"Create main Matrix: "<<RESET<<"\n\n";
		one=main_loop_matrix_init();

		char decision;
		cout<<BOLDGREEN<<"do you want to create a second matrix to perform operations with it? Enter y or n"<<RESET<<"\n \n";

		cin>>decision;
		if(decision == 'y' || decision == 'Y' ){

			two = main_loop_matrix_init();
		}

		cout<<BOLDGREEN<<" What would you like to do:"<<RESET<<"\n\n";

		int operation;
		int previous_operation;

		ask_: previous_operation= operation;
		operation=ask();

		if(operation<1 || operation >10){

			goto ask_;
		}

		Matrix* operation_results=operate(&one,&two,&three, operation, previous_operation);

		if(operation_results == nullptr){

			goto start;

		}else{

			one =operation_results[0];
			two =operation_results[1];
			three =operation_results[2];
		}


		cout<<BOLDMAGENTA<<"to exit this app press Ctrl + C "<<RESET<<"\n\n";
		goto ask_;


	}
	return 0;

}
