#include <bits/stdc++.h>
#define N1 9
#define N2 6
using namespace std;
// int n;
bool isSafe(int matrix[][N1],int i,int j,int num){
	//Row Check
	for(int x=0;x<N1;x++){
		if(matrix[i][x] == num){
			return false;
		} 
	}
	for(int y=0;y<N1;y++){
		if(matrix[y][j] == num){
			return false;
		}
	}
	
	int sq = sqrt(N1); 
	int x = (i/sq)*sq;
	int y = (j/sq)*sq;
	for(int i=x;i<x+sq;i++){
		for(int j=y;j<y+sq;j++){
			if(matrix[i][j] == num){
				return false;
			}
		}
	}
	return true;
}
bool solveSudoku(int matrix[][N1],int i,int j)
{
	//Base Case
	if(i==N1){
		//Print Sudoku
		for(int i=0;i<N1;i++){
			for(int j=0;j<N1;j++){
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		return true;
	}
	if(j==N1){
		return solveSudoku(matrix,i+1,0);
	}
	if(matrix[i][j] != 0){
		return solveSudoku(matrix,i,j+1);
	}
	for(int num=1;num<=N1;num++){
		if(isSafe(matrix,i,j,num)){
			matrix[i][j] = num;
			bool solve = solveSudoku(matrix,i,j+1);
			if(solve){
				return true;
			}
			matrix[i][j] = 0;
		}
	}
	return false;
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
		int matrix[N1][N1];
		for(int i=0;i<N1;i++){
			for(int j=0;j<N1;j++){
				cin >> matrix[i][j];
			}
		}
		solveSudoku(matrix,0,0);
	return 0;
}