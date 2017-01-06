#include <bits/stdc++.h>
using namespace std;
int fib(int n,int dp[]){
	if(n==0 || n==1) 
		return n;
	if(dp[n] != -1){
		return dp[n] ;
	}
	else {
		int f1 = fib(n-1,dp) ;
		int f2 = fib(n-2,dp) ;
		dp[n] = f1 + f2 ;
		return f1 + f2 ;
	}
}
int bottomUp(int n,int dp[]){
	dp[0] = 0;
	dp[1] = 1;
	for(int i=2;i<=n;i++){
		dp[i] = dp[i-1] + dp[i-2] ;
	}
	return dp[n] ;
}
int main(int argc, char const *argv[])
{
	int n ;
	cin >> n ;
	int dp[n] ;
	memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    	cout << fib(i,dp) << " " ;
    cout << endl ;
 	return 0;
}