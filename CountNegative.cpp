#include <bits/stdc++.h>
using namespace std;
//Time Complexity is O(n*m)
int countNegativeNonOptimal(std::vector<std::vector<int> > &v,int rows,int cols){
	int count=0;
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(v[i][j] < 0) count++;
		}
	}
	return count;
}
//Time Complexity is O(n+m)
int countNegativeOptimal(std::vector<std::vector<int> > &v,int rows,int cols){
	int count = 0 ;
	int i=0,j=cols-1;
	while(i < rows && j >= 0){
		if(v[i][j] < 0){
			count += (j+1);
			i++;
		}
		else j--;
	}
	return count ;
}
int main(int argc, char const *argv[])
{
	int rows,cols;
	cout << "Enter the number of rows and columns " ;
	cin >> rows >> cols;
	std::vector<std::vector<int> > v(rows,std::vector<int>(cols) );
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cin >> v[i][j];
		}
	}
	cout << "Number of negative number is " << countNegativeNonOptimal(v,rows,cols) << endl;
	cout << "Number of negative number is " << countNegativeOptimal(v,rows,cols) << endl;
	return 0;
}