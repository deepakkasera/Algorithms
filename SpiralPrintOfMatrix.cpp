#include <bits/stdc++.h>
using namespace std;
void printSpiral(int a[][12],int m,int n)
{
	int startRow = 0, endRow = m-1;
	int startCol = 0, endCol = n-1;
	while(startRow <= endRow && startCol <= endCol){
		for(int i = startCol; i <= endCol; i++){
			cout << a[startRow][i] << ", ";
		}
		startRow++;
		
		for(int i = startRow; i <= endRow; i++){
			cout << a[i][endCol] << ", ";
		}
		endCol--;

		for(int i = endCol; i >= startCol; i--){
			cout << a[endRow][i] << ", ";
		}
		endRow--;

		for(int i = endRow; i >= startRow; i--){
			cout << a[i][startCol] << ", ";
		}
		startCol++;
	}
}
int main(int argc, char const *argv[])
{
	int a[12][12] = {0};
	int m,n;
	cin >> m >> n;
	int value = 1;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			// a[i][j] = value++;
			// cout << a[i][j] << " ";
			cin >> a[i][j];
		}
		// cout << '\n';
	}
	printSpiral(a,m,n);
	cout << "END\n";
	return 0;
}