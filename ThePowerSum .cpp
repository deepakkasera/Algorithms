#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll fastPower(ll x,ll n){
	if(n == 0){
		return 1;
	}
	ll halfPow = fastPower(x,n/2);
	if(n & 1){
		return x * halfPow * halfPow;
	}
	else
		return halfPow * halfPow;
}
// ll numWays = 0;
ll numberOfWays(ll x,ll n,ll start) {
	if(x == 0){
		return 1;
	}
	int ans = 0;
	for(int i = start+1; fastPower(i,n) <= x; i++){
		ans += numberOfWays(x - fastPower(i,n) , n , i);
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	ll x,n;
	cin >> x >> n;
	cout << numberOfWays(x,n,0) << '\n';
	// cout << numWays << endl;
	return 0;
}
