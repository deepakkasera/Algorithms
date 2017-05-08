#include <bits/stdc++.h>
#define R 3
#define C 6
using namespace std;
// const int rows=4,cols=4;
void spiralPrint(int a[R][C],int m,int n){
	int k=0,l=0;
	while(k < m && l < n)
	{
		for(int i=l;i<n;i++)
			cout << a[k][i] << " " ;
		k++;
		for(int i=k;i<m;i++)
			cout << a[i][n-1] << " ";
		n--;
		if(k < m){
			for(int i=n-1;i>=l;i--){
				cout << a[m-1][i] << " " ;
			}
			m--;
		}
		if(l < n){
			for(int i=m-1;i>=k;i--){
				cout << a[i][l] << " " ;
			}
			l++;
		}
	}
	return ;
}
int main(int argc, char const *argv[])
{
	int a[R][C] = { {1,  2,  3,  4,  5,  6},
        {7,  8,  9,  10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };
	spiralPrint(a,R,C);
	return 0;
}