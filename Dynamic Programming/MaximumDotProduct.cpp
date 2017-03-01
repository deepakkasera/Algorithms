#include <bits/stdc++.h>
using namespace std;
int maxDotProduct(std::vector<int> &a , int m , std::vector<int> &b, int n){
	std::vector< std::vector<int> > dp(n+1,std::vector<int>(m+1) );
	for(int i=0;i<n+1;i++) dp[i][0]=0;
	for(int i=0;i<m+1;i++) dp[0][i]=0;
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			dp[i][j] = max(dp[i-1][j-1]+a[j-1]*b[i-1],dp[i][j-1]);
		}
	}
	for(int i=0;i<n+1;i++){
		for(int j=0;j<m+1;j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return dp[n][m];
}
int main(int argc, char const *argv[])
{
	int m,n;
	cin >> m >> n;
	std::vector<int> a(m);
	std::vector<int> b(n);
	for(int i=0;i<m;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> b[i];
	cout << "Maximum dot product is " << maxDotProduct(a,m,b,n) << endl;
	return 0;
}