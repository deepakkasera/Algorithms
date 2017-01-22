#include <bits/stdc++.h>
using namespace std;
int numberOfWays(int rows,int cols){
	std::vector<std::vector<int> > v(rows,std::vector<int>(cols));
	for(int i=0;i<cols;i++){
		v[0][i] = 1;
	}
	for(int i=0;i<rows;i++){
		v[i][0] = 1;
	}
	for(int i=1;i<rows;i++){
		for(int j=1;j<cols;j++){
			v[i][j] += (v[i-1][j] + v[i][j-1]);
		}
	}
	return v[rows-1][cols-1];
}
int main(int argc, char const *argv[])
{
	int rows,cols;
	cout << "Enter rows and columns ";
	cin >> rows >> cols ;
	std::vector<std::vector<int> > v(rows,std::vector<int>(cols) );
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++) cin >> v[i][j];
	}
    cout << "Number of ways " << numberOfWays(rows,cols) << endl; 
	return 0;
}