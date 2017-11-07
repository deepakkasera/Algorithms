#include <bits/stdc++.h>
using namespace std;
void transpose(int a[][10],int m,int n){
	for(int i = 0; i < m; i++){
		for(int j = i; j < n; j++){
			swap(a[i][j] ,a[j][i]);
		}
	}
}
void reverse(int a[][10],int m,int n){
	for(int i = 0; i < n; i++){
		for(int j = 0,k=m-1; j < k; j++,k--){
			swap(a[j][i] , a[k][i]);
		}
	}
	return;
}
void rotateACW(int a[][10],int m,int n){
	transpose(a,m,n);
	reverse(a,m,n);
	return;
}
void printMatrix(int a[][10],int m,int n){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cout << a[i][j] << " ";
		}
		cout<<endl;
	}
}
int main(int argc, char const *argv[])
{
	int a[10][10];
	int m,n;
	cin >> m >> n;
	int value = 1;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			a[i][j] = value++;
		}
	}
	printMatrix(a,m,n);
	rotateACW(a,m,n);
	// transpose(a,m,n);
	printMatrix(a,m,n);
	return 0;
}