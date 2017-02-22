#include <bits/stdc++.h>
using namespace std;
//Time Complexity is O(n^2)
//Space Complexity is O(n^2)
int longest(string s,int n){
	int dp[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dp[i][j]=0;
		}
	}
	for(int i=0;i<n;i++) dp[i][i] = 1;
	for(int l=2;l<=n;l++){
		for(int i=0;i<n;i++){
			int j = i+l-1;
			if(s[i] == s[j] && l == 2) dp[i][j]=2;
			else if (s[i] == s[j]) dp[i][j] = 2+dp[i+1][j-1];
			else if dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
		}
	}
	return dp[0][n-1];
}
int main(int argc, char const *argv[])
{
	string s;
	cout << "Enter a string \n";
	cin >> s;
	int n = s.length();
	cout << "Length of longest palindromic subsequence is " << longest(s,n) << endl;
	return 0;
}