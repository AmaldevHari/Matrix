/*
 * run.cpp
 *
 *  Created on: Jun. 1, 2020
 *      Author: amaldev
 */



#include "Matrix-windows.hpp"
#include <limits>




Matrix main_loop_matrix_init(){



	int row; int col;
	set_output_green();
	cout<<" "<<"Enter number of rows and coloumns in order: "<<" "<<"\n\n";

	set_output_default();

	while(!(cin >> row)){
	set_output_red();
		cout << " "<<"error: invalid input!"<<" ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	set_output_default();

	}
	while(!(cin >> col)){
		set_output_red();
		cout << " "<<"error: invalid input!"<<" ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		set_output_default();

	}


	float* mat;int it= row*col;
	mat = new float[it];

	set_output_green();
	cout<<" "<<"Enter elements of matrix row by row: "<<" "<<"\n\n";
	set_output_default();


	for( int i=0;i <it; i++){
		while(!(cin >> mat[i])){
			set_output_red();
			cout << " "<<"error: invalid input!"<<" ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			set_output_default();

		}


	}

	Matrix m(mat, row, col);
	return m;
}


int ask(){

	set_output_green();

	cout<<" "<<" The following operations are available:"<<"\n\n";
	cout<<"1.multiply"<<"\n";
	cout<<"2.adjoint"<<"\n";
	cout<<"3.cofactor"<<"\n";
	cout<<"4.determinant"<<"\n";
	cout<<"5.print matrix"<<"\n";
	cout<<"6.scalar multiply"<<"\n";
	cout<<"7.inverse"<<"\n";
	cout<<"8." " matrix and other data related to it and start over"<<"\n";
	cout<<"9.save the resultant matrix of previous opeartion to one of the two matrices"<<"\n";
	cout<<"10. transpose"<<"\n";
	cout<<"reply with a number representing the operation"<<" ""\n\n";
	
	set_output_default();
	int result;
	while(!(cin >> result)){
		set_output_red();
		cout << " "<<"error: invalid input!"<<" ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		set_output_default();
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
			case 2:
			set_output_green(); 
			cout<<" "<<"Which matrix 1 or 2?: \n\n"<<" ";
			set_output_default();
			while(!(cin >> dec)){
				set_output_red();
				cout <<" "<< "error: invalid input!"<<" ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				set_output_default();
			}
			if(dec ==1){
				three=one.adjoint();three.print_matrix();
				cout<<"\n\n";
			}else if( dec ==2){
				three=two.adjoint();three.print_matrix();
				cout<<"\n\n";
			}else{
				set_output_red();
				cout<<" "<<"error: unrepresented matrix number\n\n"<<" ";
				set_output_default();}
			break;

			case 3: 
				set_output_green();
				 cout<<" "<<"Which matrix 1 or 2?: \n\n"<<" ";
				set_output_default();
			while(!(cin >> dec)){
				set_output_red();
				cout <<" " <<"error: invalid input!"<<" ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				set_output_default();
			}
			if(dec ==1){
				three=one.cofactor();three.print_matrix();
				cout<<"\n\n";
			}else if( dec ==2){
				three=two.cofactor();three.print_matrix();
				cout<<"\n\n";
			}else{
				set_output_red();
				cout<<" "<<"error: unrepresented matrix number\n\n"<<" ";
				set_output_default();}
			break;

			case 4: set_output_green(); 
				cout<<" "<<"Which matrix 1 or 2?: \n\n"<<" ";
				set_output_default();
			while(!(cin >> dec)){
				set_output_red();
				cout <<" "<< "error: invalid input!"<<" ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				set_output_default();
			}
			if(dec ==1){
				set_output_blue();
				cout<<"\n"<<" "<<one.determinant();
				cout<<" ""\n\n";
				set_output_default();
			}else if( dec ==2){
				set_output_blue();
				cout<<"\n"<<" "<<two.determinant();
				cout<<" ""\n\n";
				set_output_default();
			}else{
				set_output_red();
				cout<<" "<<"error: unrepresented matrix number\n\n"<<" ";
				set_output_default();}
			break;

			case 5:set_output_green(); 
			cout<<" "<<"Which matrix 1 or 2?: \n\n"<<" ";
			set_output_default();
			while(!(cin >> dec)){
				set_output_red();
				cout <<" "<< "error: invalid input!"<<" ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				set_output_default();
			}
			if(dec ==1){
				one.print_matrix();
				cout<<"\n\n";
			}else if( dec ==2){
				two.print_matrix();
				cout<<"\n\n";
			}else{
				set_output_red();
				cout<<" "<<"error: unrepresented matrix number\n\n"<<" ";
				set_output_default();}
			break;

			case 6:{set_output_green();
				 cout<<" "<<"Which matrix 1 or 2?: \n\n"<<" ";
				set_output_default();
			while(!(cin >> dec)){
				set_output_red();
				cout << " "<<"error: invalid input!"<<" ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				set_output_default();
			}
			float num;
			if(dec ==1){
				set_output_green();

				cout<<" "<<"enter a number to multiply(WARNING:The original matrix will be changed!):"<<" "<<"\n\n";
				set_output_default();
				while(!(cin >> num)){
					set_output_red();
					cout << " "<<"error: invalid input!"<<" ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					set_output_default();
				}

				one.scalar_multiply(num);
				one.print_matrix(); cout<<"\n\n";
			}else if( dec ==2){
				set_output_green();
				cout<<" "<<"enter a number to multiply(WARNING:The original matrix will be changed!):"<<" "<<"\n\n";
				set_output_default();
				while(!(cin >> num)){
					set_output_red();
					cout <<" "<< "error: invalid input!"<<" ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					set_output_default();
				}

				two.scalar_multiply(num);
				two.print_matrix(); cout<<"\n\n";

			}
			else{
				set_output_red();
				cout<<" "<<"error: unrepresented matrix number\n\n"<<" ";
				set_output_default();}
			break;

			case 7: {set_output_green();
				 cout<<" "<<"Which matrix 1 or 2?: \n\n"<<" ";
				set_output_default();
			while(!(cin >> dec)){
				set_output_red();
				cout << " "<<"error: invalid input!"<<" ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				set_output_default();
			}
			if(dec ==1){

				three=one.inverse();three.print_matrix();
				cout<<"\n\n";
			}else if( dec ==2){
				three=two.inverse();three.print_matrix();
				cout<<"\n\n";
			}else{
				set_output_red();
				cout<<" "<<"error: unrepresented matrix number\n\n"<<" ";
				set_output_default();}}
			break;
			case 8:  return nullptr;

			case 9: {set_output_green();

				ask_again:cout<<" "<<"Save to which matrix 1 or 2?: \n\n"<<" ";
				set_output_default();
				while(!(cin >> dec)){
					set_output_green();
					cout << " "<<"error: invalid input!"<<" ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					set_output_default();
				}
				if(!(dec == 1 || dec== 2)){
					set_output_red();
					cout<<" "<<"error: unrepresented matrix number\n\n"<<" ";goto ask_again;
					set_output_default();
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
				set_output_green();
				cout<<" "<<"Which matrix 1 or 2?: \n\n"<<" ";
				set_output_default();
				while(!(cin >> dec)){
					set_output_red();
					cout <<" " <<"error: invalid input!"<<" ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				set_output_default();
				if(dec ==1){
					three=one.transpose();three.print_matrix();
					cout<<"\n\n";
				}else if( dec ==2){
					three=two.transpose();three.print_matrix();
					cout<<"\n\n";
				}else{
					set_output_red();
					cout<<" "<<"error: unrepresented matrix number\n\n"<<" ";
					set_output_default();}
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
		
		set_output_green();
		start:cout<<" "<<"Create main Matrix: "<<" "<<"\n\n";
		set_output_default();
		one=main_loop_matrix_init();

		char decision;
		set_output_green();
		cout<<" "<<"do you want to create a second matrix to perform operations with it? Enter y or n"<<" "<<"\n \n";
		set_output_default();

		cin>>decision;
		if(decision == 'y' || decision == 'Y' ){

			two = main_loop_matrix_init();
		}
		
		set_output_green();
		cout<<" "<<" What would you like to do:"<<" "<<"\n\n";
		set_output_default();

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

		set_output_magenta();
		cout<<" "<<"to exit this app press Ctrl + C "<<" "<<"\n\n";
		set_output_default();
		goto ask_;
		

	}
	return 0;

}
