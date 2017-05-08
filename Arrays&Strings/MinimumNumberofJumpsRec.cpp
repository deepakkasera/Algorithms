#include <bits/stdc++.h>
using namespace std;
int minJumps(int a[],int l,int r)
{
	if(l == r) return 0;
	if(a[l] == 0) return INT_MAX;
	int ans = INT_MAX;
	for(int i=l+1; i <= l + a[l] && i<= r; i++){
		// int jumps = minJumps(a,i,r);
		// if(jumps != INT_MAX && jumps + 1 < ans)
		// 	ans = jumps + 1;
		ans = min(ans , minJumps(a,i,r) + 1) ;
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	cout << minJumps(a,0,n-1) << endl;
	return 0;
}