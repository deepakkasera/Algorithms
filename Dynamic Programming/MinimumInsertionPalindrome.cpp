#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	string str;
	str = s;
	int n = s.length();
 	reverse(str.begin(),str.end());
 	cout << str << endl ;
	int dp[n+1][n+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(!i || !j)
				dp[i][j] = 0;
			else if (str[i-1] == s[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else 
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			cout << dp[i][j] << " ";
		}
		cout << endl ;
	}
	cout << (n - dp[n][n]) << endl;
	return 0;
}