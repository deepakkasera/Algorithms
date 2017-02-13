#include <bits/stdc++.h>
using namespace std;
int min(int a,int b,int c){
	return min(min(a,b),c);
}
int minEditDistance(string str1,string str2,int m,int n){
	std::vector < std::vector<int> > dp(n+1, std::vector<int>(m+1) );
	for(int i=0;i<n+1;i++){
		for(int j=0;j<m+1;j++){
			if(i == 0){
				dp[i][j] = j;
			}
			else if ( j == 0){
				dp[i][j] = i;
			}
			else if (str1[i-1] == str2[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}
			else if (str1[i-1] != str2[j-1]){
				dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]) + 1;
			}
		}
	}
	for(int i=0;i<n+1;i++){
		for(int j=0;j<m+1;j++){
			cout << dp[i][j] << " " ;
		}
		cout << endl;
	}
	return dp[n][main];
}
int main(int argc, char const *argv[])
{
	string str1,str2;
	cin >> str1 >> str2;
	int m = str1.length();
	int n = str2.length();
	cout << "Number of operations are " << minEditDistance(str1,str2,m,n) << endl;
	return 0;
}