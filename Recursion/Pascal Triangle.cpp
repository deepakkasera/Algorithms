#include <bits/stdc++.h>
using namespace std;
int  pascalTriangle(int rows,int cols){
	if(rows == 0) return 1;
	else if (rows == cols ) return 1;
	else if (cols == 0 ) return 1;
	else return pascalTriangle(rows-1,cols) + pascalTriangle(rows-1,cols-1);
}
int main(int argc, char const *argv[])
{
	int rows,cols;
	cin >> rows >> cols ;
	cout << pascalTriangle(rows,cols) <<endl ;
	return 0;
}