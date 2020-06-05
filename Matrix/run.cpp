/*
 * run.cpp
 *
 *  Created on: Jun. 1, 2020
 *      Author: amaldev
 */



#include "Matrix.h"

Matrix main_loop_matrix_init(){



		row_col_init:	int row; int col;

			cout<<"Enter number of rows and coloumns in order: "<<"\n";

			
	while(!(cin >> row)){
    cout << "error: invalid input!";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}		
		while(!(cin >> col)){
    cout << "error: invalid input!";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}	

			array_inputs:
			float* mat;int it= row*col;
			mat = new float[it];

			cout<<"Enter elements of matrix in order: "<<"\n";


			for( int i=0;i <it; i++){
					while(!(cin >> mat[i])){
    cout << "error: invalid input!";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}	

					
			}

			Matrix m(mat, row, col);
			return m;
}


int ask(){

	ask_:cout<<" What would you like to do:"<<"\n";
	cout<<" The following operations are available:"<<"\n";
	cout<<"1.multiply"<<"\n";
	cout<<"2.adjoint"<<"\n";
	cout<<"3.cofactor"<<"\n";
	cout<<"4.determinant"<<"\n";
	cout<<"5.print matrix"<<"\n";
	cout<<"6.scalar multiply"<<"\n";
	cout<<"7.inverse"<<"\n";
	cout<<"reply with a number representing the operation"<<"\n";

	int result;
		while(!(cin >> result)){
    cout << "error: invalid input!";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}	

		
	
	return result;
}


int main(int argc, char* argv[]){





	while( true){

		cout<<"Create main Matrix: "<<"\n";
		Matrix one=main_loop_matrix_init();
		char decision;
		cout<<"do you want to create a second matrix to perform operations with it? Enter y or n"<<"\n";

		Matrix two;
		cin>>decision;
		if(decision == 'y'){

			two = main_loop_matrix_init();
		}

		ask_:int operation=ask();

		if(operation<1 || operation >7){

			delete(&operation);
			goto ask_;
		}
		switch(operation){

		case 1: one.multiply(two).print_matrix();break;
		case 2: one.adjoint().print_matrix();break;
		case 3: one.cofactor().print_matrix(); break;
		case 4: cout<<one.determinant()<<"\n"; break;
		case 5: one.print_matrix(); break;
		case 6: {
			get_num:float num;
			cout<<"enter a number to multiply:"<<"\n";
				while(!(cin >> num)){
    cout << "error: invalid input!";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}	

			one.scalar_multiply(num);
			one.print_matrix();
			break;}
		case 7: one.inverse().print_matrix();break;


		}
		cout<<"would you like to continue doing operations on same matrix? Enter y or n \n";
		cin>>decision;
		if(decision == 'y' ||decision == 'Y'){
			goto ask_;
		}
		cout<<"would you like to exit? Enter y or n"<<"\n";

		cin>>decision;
		if(decision == 'y'||decision == 'Y'){
			return 0;
		}

	}
	return 0;
}
