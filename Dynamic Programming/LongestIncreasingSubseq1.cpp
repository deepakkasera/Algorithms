#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	std::vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	std::vector<int> dp(n,1);
    for(int i=1;i<n;i++){
    	for(int j=0;j<i;j++){
    		if(v[i] > v[j]) dp[i]=max(dp[i],dp[j]+1);
    	}
    }
    for(int i=0;i<n;i++) cout << dp[i] << " ";
    	cout << endl;
    cout << "Length of Longest Increasing Subsequence is " << *max_element(dp.begin(),dp.end()) << "\n";
	return 0;
}