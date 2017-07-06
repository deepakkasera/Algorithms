#include <bits/stdc++.h>
#define nMax 1005
using namespace std;
char maze[nMax][nMax];
int v[nMax][nMax];
int solutionMaze[nMax][nMax];
int n,m;
bool solveMaze(int i , int j){
	//Base Case
	if(i == m && j == n){
		solutionMaze[i][j] = 1;
		//Print the solution
		for(int x = 0; x <= m; x++){
			for(int y = 0; y <= n; y++){
				cout << solutionMaze[x][y] << " ";
			}
			cout << endl;
		}
		return true;
	}

	if(v[i][j]){
		return false;
	}

	v[i][j] = 1;

	//Assuming path exists from i,j
	solutionMaze[i][j] = 1;
	if(j+1 <= n && !v[i][j+1]){
		bool nextPath = solveMaze(i , j+1);
		if (nextPath){
			return true;
		}
	}

	if(i+1 <= m && !v[i+1][j]){
		bool nextPath = solveMaze(i+1,j);
		if(nextPath){
			return true;
		}
	}

	///yahan aane se path nhi mila 
	/// then backtrack
	solutionMaze[i][j] = 0;
	return false;
}
int main(int argc, char const *argv[])
{
	cin >> m >> n;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> maze[i][j];
			if (maze[i][i] == 'X'){
				v[i][j] = 1;
			}
		}
	}
	m--;
	n--;
	bool ans = solveMaze(0 , 0);
	if(!ans){
		cout << "-1\n";
	}
	return 0;
}