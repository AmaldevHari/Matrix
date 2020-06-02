/*
 * Matrix.cpp
 *
 *  Created on: May 30, 2020
 *      Author: amaldev
 */

#include "Matrix.h"

	Matrix::Matrix(float* a, int row,int col){


		Matrix::row = row;

		Matrix::col = col;

		Matrix::mat= make_2d(a, row ,col);


	};


Matrix	Matrix::multiply(Matrix b){






		int matrix1_row = this->row;

		int matrix2_col = b.col;

		int matrix1_col =this->col;

		float* mat;

		mat= new float[matrix1_row* matrix2_col];



		int current_result_index=0;

		for(int i=0 ;i<matrix1_row; i++){

			for( int j=0; j<matrix2_col ;j++){

				float entry=0;

				for(int k=0; k< matrix1_col; k++){

					entry+= this->mat[i][k] * b.mat[k][j];

				}

				mat[current_result_index]= entry;

				current_result_index ++;
			}
		}

		Matrix result(mat, matrix1_row, matrix2_col);


		return result;

		};
	Matrix Matrix::operator*( Matrix b) {

		return this->multiply(b);

	};

 float** Matrix::make_2d(float* mat, int rows, int cols){



		float** temp_mat = new float*[rows];

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


int Matrix::print_matrix(){
		string append = " ";
		string e ="\n";
		int col=this->col;
		int row=this->row;
			for(int i =0; i<row;i++){
				for( int j=0; j<col ;j++){


					if(j == col-1){
						append=e;
					}
				cout<< this->mat[i][j]<<append;
				append=' ';
				}
			}
			return 0;
	};



