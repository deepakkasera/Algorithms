#include <bits/stdc++.h>
using namespace std;
int minJumps(int a[],int n)
{
	if(n == 0 || a[0] == 0)
		return INT_MAX;
	int* jumps,i,j;
	jumps[0] = 0;
	for(int i=1;i<n;i++){
		jumps[i] = INT_MAX;
		for(int j=i+1;j<=i + a[i] && j<=n-1; j++){
			jumps[i] = min(jumps[i],jumps[j] + 1);
		}
	}
	return jumps[n-1]; 
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	cout << minJumps(a,n) << endl;
	return 0;
}