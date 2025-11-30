/*Develop a program to identify and efficiently store a sparse matrix using compact 
representation and perform basic operations like display and simple transpose. */

#include<iostream>
using namespace std;

void convertSparse(int matrix[10][10] , int rows , int columns, int sparse[100][3], int &countNonZero){
    countNonZero = 0;
    for(int i=0 ; i< rows ; i++){
        for(int j=0 ; j<columns ; j++ ){
            if(matrix[i][j]!=0){
                sparse[countNonZero+1][0] = matrix[i][0];
                sparse[countNonZero+1][1] = matrix[i][1];
                sparse[countNonZero+1][2] = matrix[i][j];
                countNonZero++;

            }
        }
    }

    sparse[0][0] = rows;
    sparse[0][1] = columns;
    sparse[0][2] = countNonZero;
}

void display(int sparse[][3]){
    cout << "\nRow\tCol\tValue\n";
    int total = sparse[0][2];
    for(int i=0 ; i<= total ; i++){
        cout<<sparse[i][0]<<"\t"<<sparse[i][1]<<"\t"<<sparse[i][2]<<"\n";

    }
}

void computeTranspose(int sparse[][3] , int transpose[][3]){
    int rows = sparse[0][0];
    int col = sparse[0][1];
    int total = sparse[0][2]; 

    transpose[0][0] = rows;
    transpose[0][1] = col;
    transpose[0][2] = total;
    
    int k=1;
    for(int i =0 ; i<col ; i++){
        for(int j=1 ; j<=total ; j++){
            if(sparse[j][1]==i){
                transpose[k][0] = sparse[i][1];
                transpose[k][1] = sparse[i][0];
                transpose[k][2] = sparse[i][2];
                k++;
            }
            
        }
    }

}


int main() {
    int rows, cols;
    int matrix[10][10];
    int sparse[100][3], transpose[100][3];
    int nonZeroCount;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter matrix elements:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    convertSparse(matrix, rows, cols, sparse, nonZeroCount);

    cout << "\nSparse Matrix (3-Tuple Representation):";
    display(sparse);

    // Transpose
    computeTranspose(sparse, transpose);

    cout << "\nSimple Transpose of Sparse Matrix:";
    display(transpose);

    return 0;
}