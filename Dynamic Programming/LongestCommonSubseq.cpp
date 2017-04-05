#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string s1,s2;
	cin>>s1>>s2;
	int n=s1.length();
	int m=s2.length();
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(!i || !j)
				dp[i][j] = 0 ;
			else if (s2[i-1] == s1[j-1])
				dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	cout << dp[n][m] << '\n';
	return 0;
}