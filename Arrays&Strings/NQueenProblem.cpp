#include <bits/stdc++.h>
using namespace std;
bool isSafe(int board[][10],int i,int j,int n){
	//check for the column
	for(int x=0;x<i;x++){
		if(board[x][j]==1)
			return false;
	}
	
	//Check for top left diagonal
	int x=i,y=j;
	while(x>=0 && y>=0){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y--;
	}

	//Check for top right diagonal
	x=i,y=j;
	while(x>=0 && y<n){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y++;
	}

	//if position is safe to place the queen
	return true;

}
bool solveNQueen(int board[][10],int i,int n){
	//Base Case
	if(i==n){
		//Print the board
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(board[i][j]){
					cout << "Q ";
				}
				else
					cout << ". ";
			}
			cout << endl;
		}
		return true;
	}
	//Recursive Case
	for(int j=0;j<n;j++){
		//Lets try to place the queen at jth column
		if(isSafe(board,i,j,n)){
			board[i][j] = 1;
			bool nextQueen = solveNQueen(board,i+1,n);
			if(nextQueen==true){
				return true;
			}
			board[i][j] = 0;
		}
	}
	return false;
}
int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the value of n\n";
	cin >> n;
	int board[10][10] = {0};
	solveNQueen(board,0,n);
	return 0;
}