#include <bits/stdc++.h>
using namespace std;
int min(int a,int b,int c){
	return min(min(a,b),c);
}
int maximumSquareSubMatrix(std::vector<std::vector<int> > &v,int rows,int cols){
	std::vector<std::vector<int> > dp(rows,std::vector<int>(cols));
	//Entry dp[i][j] denotes the size of the maximum square submatrix ending at i,j
	for(int i=0;i<cols;i++){
		dp[0][i] = v[0][i];
	}
	for(int i=1;i<rows;i++){
		dp[i][0] = v[i][0];
	}
	for(int i=1;i<rows;i++){
		for(int j=1;j<cols;j++){
            if(v[i][j] == 0) dp[i][j] = 0;
            else if(v[i][j] == 1){
            	dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]) + 1;
            }
		}
	}
	//Finding the maximum entry un dp[i][j]
	int maximum_entry = dp[0][0],max_i=0,max_j=0;
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(dp[i][j] > maximum_entry){
				maximum_entry = dp[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}
	//Printing dp matrix
	// for(int i=0;i<rows;i++){
	// 	for(int j=0;j<cols;j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	for(int i=max_i - maximum_entry + 1 ; i<= max_i;i++){
		for(int j=max_j - maximum_entry + 1;j<=max_j;j++){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	return maximum_entry;
}
int main(int argc, char const *argv[])
{
	int rows,cols;
	cout << "Enter the number of rows and columns \n" ;
	cin >> rows >> cols ;
	std::vector<std::vector<int> > v(rows , std::vector<int>(cols));
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cin >> v[i][j];
		}
	}
    cout << "Size of the maximum square submatrix is " << maximumSquareSubMatrix(v,rows,cols) << endl;
 	return 0;
}