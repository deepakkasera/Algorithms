#include <bits/stdc++.h>
using namespace std;
//For 3 steps
int ways(int n){
	if( n == 0){
		return 1;
	}
	if (n < 0) return 0;
	return ways(n-1) + ways(n-2) + ways(n-3);
}
//For general k steps
int countWays(int n,int k){
	if(n==0) return 1;
	if (n<0) return 0;
	int ans=0;
	for(int i=1;i<=k;i++){
		ans += countWays(n-i,k);
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter number of stairs ";
	cin >> n;
	cout << ways(n) << endl ;
	cout << countWays(n,3) << endl;
	return 0;
}