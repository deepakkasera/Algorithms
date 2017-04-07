#include <bits/stdc++.h>
using namespace std;
int min(int a,int b,int c){
	return min(min(a,b),c);
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n ;
	int a[n][n];
	int dp[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dp[i][j] = 1;
		}
	}
	int ans=1;
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(a[i][j]==a[i-1][j-1] && a[i][j]==a[i-1][j] && a[i][j]==a[i][j-1])
				dp[i][j] = min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]) + 1;
			ans=max(ans,dp[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}