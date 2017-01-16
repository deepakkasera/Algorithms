#include <bits/stdc++.h>
using namespace std;
int maximumRectangleSubmatrix(std::vector<std::vector<int> > &v,int rows,int cols){

}
int main(int argc, char const *argv[])
{
	int rows,cols;
	cout << "Enter the number of rows and columns \n";
	cin >> rows >> cols ;
	std::vector<std::vector<int> > v(rows,std::vector<int>(cols));
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout << v[i][j] ;
		}
		cout << endl;
	}

	return 0;
}