#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given a matrix if an element in the matrix is 0 
    then you will have to set its entire column and row to 0 and then return the matrix.
*/

vector<vector<int>> brute_force_approach(vector<vector<int>> &matrix, int n, int m) {
	vector<vector<int>> mt(matrix);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(matrix[i][j]==0){
				for(int k=0; k<n; k++) mt[k][j]=0;
				for(int k=0; k<m; k++) mt[i][k]=0;
			}
		}
	}
	return mt;
}

/*
    TC: O(N*M*(N+M)) worst case
    SC: O(N*M)
*/

vector<vector<int>> brute_force_approach_2(vector<vector<int>> &matrix, int n, int m) {
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(matrix[i][j]==0){
				for(int k=0; k<n; k++){
					if(matrix[k][j]!=0) matrix[k][j]=-1;
				}
				for(int k=0; k<m; k++){
					if(matrix[i][k]!=0) matrix[i][k]=-1;
				}
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(matrix[i][j]==-1) matrix[i][j] = 0;
		}
	}
		
	return matrix;
}

/*
	works only if matrix is assumed to be having only positive elements
    TC: O(N*M*(N+M)) worst case
    SC: O(1)
*/

vector<vector<int>> better_approach(vector<vector<int>> &matrix, int n, int m) {
	int arr[n]={0},a[m]={0};
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(matrix[i][j]==0){
				arr[i]=1;
				a[j]=1;
			}
		}
	}
	for(int i=0; i<n; i++){
		if(arr[i]){
			for(int j=0; j<m; j++) matrix[i][j]=0;
		}
	}
	for(int i=0; i<m; i++){
		if(a[i]){
			for(int j=0; j<n; j++) matrix[j][i]=0;
		}
	}
	return matrix;
}

/*
	TC: O(N*M + N*M + N*M)
	SC: O(N + M)
*/

vector<vector<int>> optimal_approach(vector<vector<int>> &matrix, int n, int m) {
	int col=1;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(matrix[i][j]==0){
				if(j==0) col=0;
				else matrix[0][j]=0;
				matrix[i][0] = 0;

			}
		}
	}
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			if(matrix[0][j]==0 || matrix[i][0]==0){
				matrix[i][j]=0;
			}
		}
	}
	if(matrix[0][0]==0){
		for(int i=0; i<m; i++){
			matrix[0][i]=0;
		}		
	}
	if(col==0){
		for(int i=0; i<n; i++){
			matrix[i][0]=0;
		}
	}

	return matrix;
}

/*
	TC: O(N*M + N*M)
	SC: O(1)

	First, we will traverse the matrix and mark the proper cells of 1st row and 1st column with 0 accordingly. 
	The marking will be like this: if cell(i, j) contains 0, we will mark the i-th row i.e. matrix[i][0] with 0 
	and we will mark j-th column i.e. matrix[0][j] with 0.
	If i is 0, we will mark matrix[0][0] with 0 but if j is 0, 
	we will mark the col0 variable with 0 instead of marking matrix[0][0] again.
	
	After step 1 is completed, we will modify the cells from (1,1) to (n-1, m-1) 
	using the values from the 1st row, 1st column, and col0 variable.
	
	We will not modify the 1st row and 1st column of the matrix here as the modification 
	of the rest of the matrix(i.e. From (1,1) to (n-1, m-1)) is dependent on that row and column.
	
	Finally, we will change the 1st row and column using the values from matrix[0][0] and col0 variable. 
	
	Here also we will change the row first and then the column.
	If matrix[0][0] = 0, we will change all the elements from the cell (0,1) to (0, m-1), to 0.
	If col0 = 0, we will change all the elements from the cell (0,0) to (n-1, 0), to 0.
*/