#include <bits/stdc++.h>
#define ll long long
using namespace std;
int dp[110][110][2]; 
int total_strings[110][110];
ll f(int n,int k){
	dp[1][0][1] = 1;
	dp[1][0][0] = 1;
	dp[1][1][1] = 0;
	dp[1][1][0] = 0;

	for(int i = 2; i <= 100; i++){
		dp[i][0][0] = dp[i-1][0][0] + dp[i-1][0][1];
		dp[i][0][1] = dp[i-1][0][0];
		for(int bits = 1; bits < i; bits++){
			dp[i][bits][0] = dp[i-1][bits][0] + dp[i-1][bits][1];
			dp[i][bits][1] = dp[i-1][bits][0] + dp[i-1][bits-1][1];
		}
	}
	return dp[n][k][0] + dp[n][k][1];
}
int main(){
	int p,n,k,x;
	cin >> p;
	while(p--){
		cin >> x >> n >> k;
		cout << x << " " << f(n,k) << endl;
	}
	return 0;
}