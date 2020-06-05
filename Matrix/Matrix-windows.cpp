/*
 * Matrix.cpp
 *
 *  Created on: May 30, 2020
 *      Author: amaldev
 * Description: A high level description of the ALgorithms I used can be found in the algorithm.txt file included in the
 * 				project.
 *
 */
static HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);

static void set_output_green(){
	 SetConsoleTextAttribute(h_console, 2);

}
static void set_output_blue(){
	 SetConsoleTextAttribute(h_console, 1);

}
static void set_output_red(){
	 SetConsoleTextAttribute(h_console, 4);

}
static void set_output_magenta(){
	 SetConsoleTextAttribute(h_console, 5);

}
static void set_output_default(){
	 SetConsoleTextAttribute(h_console, 7);

}
/* 1 for blue, 4 for red, 2 for green , 5 for magenta , 7 for white(default)*/


#include "Matrix-windows.hpp"
/***************************************************************************************************************************
 * Matrix constructor that takes the address of the first element of a 1D array. The first input is given is part of
 *  1D array and the number of rows and columns are specified. The constructor then constructs a 2d matrix based on
 *  the specified values.
 *
 *  The convention of reading this 1D array is row by row, the first [col] number of elements constitute 1st row, the next
 *  [col] number of elements constitute row 2 and so on...
 *
 *  WARNING : Enough memory must be allocated to the 1D array to have row * col number of elements. Failure to do so
 *  may result in segfault and might produce unpredictable results;
 ***************************************************************************************************************************/
Matrix::Matrix(float* a, int row,int col){

	if(row<=0 || col <=0){

		Matrix::mat = new float*[1];
		Matrix::row = 0;
		Matrix::col = 0;

	}else{
		Matrix::row = row;

		Matrix::col = col;

		Matrix::mat= make_2d(a, row ,col);
	}

};

/***************************************************************************************************************************
 * multiplication of two matrices. This function returns a void Matrix ( uninitialized) if the dimensions are not compatible
 *
 * two matrices can only be multiplied if the columns of left hand side matrix is equal to rows of right hand side matrix.
 * The resultant matrix will have dimensions of row_1 x col_2, where row_1 is rows of left matrix and col2 is the columns of
 * right matrix.
 *
 ***************************************************************************************************************************/
Matrix	Matrix::multiply(Matrix b){



	if(b.row != this->col ){
		set_output_red();
		cout<<" "<<"error: matrix dimensions are not compatible for multiplication"<<" "<<"\n";
		set_output_default();
		float* phony= new float;
		float p=0;
		phony=&p;
		return Matrix(phony,0,0);
	}


	int matrix1_row = this->row;
	int matrix2_col = b.col;
	int matrix1_col =this->col;

	float* mat= new float[matrix1_row* matrix2_col];


	int current_result_index=0;

	for(int i=0 ;i<matrix1_row; i++){
		for( int j=0; j<matrix2_col ;j++){

			float entry=0;

			for(int k=0; k< matrix1_col; k++){

				entry+= this->mat[i][k] * b.mat[k][j];

			}
			if(entry > 1.0e-3 || entry< -1.0e-3){
				mat[current_result_index]= entry;

			}else{
				mat[current_result_index]= 0;
			}
			current_result_index ++;
		}
	}

	Matrix result(mat, matrix1_row, matrix2_col);


	return result;

};

/***************************************************************************************************************************
 * Overloaded * operator for multiplication of two matrices
 ***************************************************************************************************************************/
Matrix Matrix::operator*( Matrix b) {

	return this->multiply(b);

};

/***************************************************************************************************************************
 * This function is called inside the constructor to change the 1D input to 2D matrix. 2D matrix structure is necessary
 * for implementation of other matrix operations.
 ***************************************************************************************************************************/
float** Matrix::make_2d(float* mat, int rows, int cols){



	float** temp_mat = new float*[rows];

	if(rows ==1 && cols==1){

		float* row_element= new float[cols];
		row_element[0] = mat[0];

		temp_mat[0] =row_element;
		return temp_mat;
	}


	int current_index=0;

	for ( int i =0 ;i < rows ; i++ ){

		float* row_elements= new float[cols];

		for( int j =0 ; j< cols ;j++){

			row_elements[j]= mat[current_index];
			current_index++;
		}
		temp_mat[i]= row_elements;
	}

	return temp_mat;
};

/***************************************************************************************************************************
 * Prints out the matrix in standard matrix form into stdout. The columns and rows are interpreted from the object members.
 ***************************************************************************************************************************/
int Matrix::print_matrix(){

	cout<<"\n";
	string append = " ";
	string e ="\n";
	if(this->row==0 || this->col==0){
		set_output_red();
		cout<<" "<<"error: invalid dimenstions for matrix"<<" "<<"\n";
		set_output_default();
		return 0;
	}
	int col=this->col;
	int row=this->row;

	set_output_blue();
	for(int i =0; i<row;i++){
		for( int j=0; j<col ;j++){


			if(j == col-1){
				append=e;
			}
			cout<<" "<<this->mat[i][j]<<append;
			append=' ';
		}
	}
	set_output_default();
	cout<<" "<<"\n";
	return 0;
};


/***************************************************************************************************************************
 *finds the determinant of the matrix this function is called with. First checks if the matrix is square or not.
 *In the former case this function is recursively called with a base case for 2 x 2 matrix. The method used is
 *is cofactor expansion along the first row.
 ***************************************************************************************************************************/
float Matrix::determinant(){

	int col=this->col;
	int row=this->row;

	if(row ==0 || col==0 ){
		return NAN;
	}
	if(row != col){
		set_output_red();
		cout<<" "<<"error: only square matrices can have determinants"<<" "<<"\n";
		set_output_default();
		return NAN;
	}

	if(row==1){
		set_output_red();
		cout<<" "<<"error: invalid dimenstions for determinant"<<" "<<"\n";
		set_output_default();
		return this->mat[0][0];
	}

	float result=0;

	if( row ==2){
		return this->mat[0][0] *this->mat[1][1] -this->mat[0][1]*this->mat[1][0];
	}





	for(int i=0; i< col ;i++){

		float* arr = new float[(row-1)*(col-1)];
		int array_index=0;

		for(int j=0;j< row ;j++){
			for(int k=0; k<col; k++){

				if (!(k==i || j==0)){
					arr[array_index]= this->mat[j][k];
					array_index++;
				}
			}
		}
		Matrix m(arr, row-1,col-1);

		if((i+1)%2 ==0){
			result+= -1*this->mat[0][i]*m.determinant();
		}else{
			result+= this->mat[0][i]*m.determinant();
		}

	}


	return result;

};

/***************************************************************************************************************************
 * Transposes the matrix this function is called. Rows are switched to columns and vice versa
 ***************************************************************************************************************************/
Matrix Matrix::transpose(){

	if(this->row ==0 || this->col ==0 ){
		set_output_red();
		cout<<" "<<"error: invalid dimensions"<<" "<<"\n";
		set_output_default();
				float* phony= new float;;
				float p=0;
				phony=&p;
				return Matrix(phony,0,0);
		}
	float* ary= new float[this->row *this->col];

	int ary_index=0;
	for( int i = 0; i<this->col;i++){



		for(int j=0;j<this->row;j++){

			ary[ary_index] =this->mat[j][i];
			ary_index++;
		}

	}
	Matrix m(ary,this->row, this->col);
	return m;
};

/***************************************************************************************************************************
 * adjoint is the transpose of a cofactor matrix. Cofactor matrix is the matrix that is replaced with the determinant of
 * the (n-1) x(n-1) matrix formed by eliminating the row and column of an element, at the place of that element.
 ***************************************************************************************************************************/
Matrix Matrix::adjoint(){

	int col=this->col;
	int row=this->row;

	if(col !=row){
		set_output_red();
		cout<<" "<<"error: only square matrices can have adjoint"<<" "<<"\n";
		set_output_default();
		float* phony= new float;;
		float p=0;
		phony=&p;
		return Matrix(phony,0,0);
	}if(row==0){
		set_output_red();
		cout<<" "<<"error: invalid dimenstions for adjoint"<<" "<<"\n";
		set_output_default();
		float* phony= new float;;
		float p=0;
		phony=&p;
		return Matrix(phony,0,0);
	}

	float* ary =new float[this->col*this->row];
	int ary_index=0;

	if(col ==2){

		ary[0] =this->mat[1][1];
		ary[1] = -1*this->mat[0][1] ;
		ary[2]=  -1*this->mat[1][0];
		ary[3] =this->mat[0][0];

		return Matrix(ary,row,col);
	}

	for(int i=0; i< col ;i++){
		for(int h=0 ;h <row ;h++){

			float* arr = new float[(row-1)*(col-1)];
			int array_index=0;

			for(int j=0;j< row ;j++){
				for(int k=0; k<col; k++){

					if (!(k==i || j==h)){
						arr[array_index]= this->mat[j][k];
						array_index++;
					}
				}
			}
			Matrix m(arr, row-1,col-1);
			ary[ary_index] =pow(-1.0,(double)(i+h))*m.determinant();

			ary_index++;
		}

	}

	Matrix cofac(ary,row,col);
	return cofac;
};
/***************************************************************************************************************************
 * multiplies each element of the matrix this function is called with the input parameter a.
 ***************************************************************************************************************************/

void Matrix::scalar_multiply(float a){

	int row=this->row;
	int col=this->col;

	for( int i=0 ;i< row ;i++){
		for(int j=0; j<col ;j++){

			this->mat[i][j]= a* this->mat[i][j];
		}

	}
};

/***************************************************************************************************************************
 * returns an inverse matrix. This algorithm uses the adjoint() function followed by determinant(). The inverse of a matrix A
 * is defined as 1/det(A) x adj(A)
 ***************************************************************************************************************************/
Matrix Matrix::inverse(){

	if(this->col != this->row){

		set_output_red();
		cout<<" "<<"error: only square matrices can have inverse"<<" "<<"\n";
		set_output_default();
		float* phony= new float;;
		float p=0;
		phony=&p;

		return Matrix(phony,0,0);
	}
	if(this->col <=1){
		
		set_output_red();
		cout<<" "<<"error: singular value"<<" "<<"\n";
		set_output_default();
		float* phony= new float;;
		float p=0;
		phony=&p;

		return Matrix(phony,0,0);
	}


	float det = this->determinant();
	float input =1.0/det;

	Matrix x=this->adjoint();
	x.scalar_multiply(input);

	return x;
};

/***************************************************************************************************************************
 * checks if two matrices are equal. first checks if the dimensions are equal. If yes then each entry is checked row by row
 * in a linear manner until one of them is not equal or the checking completes. In the case of completion true vale is
 * returned by default
 ***************************************************************************************************************************/
bool Matrix::equal(Matrix b){

	if(this->row != b.row || this->col != b.col){

		return false;
	}

	bool result =true;

	for( int i =0; i< b.row ;i++){
		for(int j=0; j<b.col ;j++){

			if(this->mat[i][j] != b.mat[i][j]){

				return false;
			}
		}
	}
	return result;

};
/***************************************************************************************************************************
 * cofactor function that transposes the adjoint of a matrix.
 ***************************************************************************************************************************/
Matrix Matrix::cofactor(){

	return this->adjoint().transpose();

};

Matrix Matrix::generate_random_matrix(int row, int col, float max , bool negative, bool decimal){

	srand(time(NULL));
	int it = row*col;

	float* mat= new float[it];
	float bias =0;

	if(negative){
		bias-= max -1;
		max = max*2;
	}
	if(decimal){
		for( int i =0; i<it ;i++){
			mat[i] = rand() % ((int)max) + bias + (rand()%100 )/100.0 ;
		}
	}else{
		for( int i =0; i<it ;i++){
			mat[i] = rand() % ((int)max) + bias ;
		}
	}
	Matrix result(mat,row, col);
	return result;
};

Matrix::Matrix(){

	this->col =0;
	this->row =0;
	this->mat = nullptr;
};


