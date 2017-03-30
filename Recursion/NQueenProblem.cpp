#include <bits/stdc++.h>
#define N 4
using namespace std;
int board[N][N];

void printSolution(int board[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << board[i][j] << " ";
		}
		cout << endl ;
	}
}

bool isSafe(int board[N][N],int row,int col){
	for(int i=0;i<N;i++){
		if(board[row][i])
			return false;
	}
	for(int i=row,j=col;i>=0 && j>=0;i--,j--){
		if(board[i][j])
			return false;
	}
	for(int i=row,j=col;i<N && j>=0;i++,j--){
		if(board[i][j])
			return false;
	}
	return true;
}

bool solveNQueen(int board[N][N],int col){
	if(col >= N){
		return true;
	}
	for(int i=0;i<N;i++){
		if(isSafe(board,i,col)){
			board[i][col] = 1;
			if(solveNQueen(board,col+1))
				return true;
			board[i][col] = 0;
		}
	}
	return false;
}

bool solveNQ(){
	int board[N][N] = { {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    if(solveNQueen(board,0) == false){
    	cout << "Solution does not exist\n";
    	return false;
    }
    printSolution(board);
    return true;
}

int main(int argc, char const *argv[])
{
	solveNQ();
	return 0;
}