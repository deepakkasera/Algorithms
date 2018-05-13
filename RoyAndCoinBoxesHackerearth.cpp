#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m,q,l,r;
ll start[1000005];
ll ending[1000005];
ll a[1000005];
ll num_of_coins[1000005];
int main(){
	cin >> n >> m;
	while(m--){
		cin >> l >> r;
		l--;
		r--;
		start[l]++;
		ending[r]++;
	}
	num_of_coins[0] = start[0];
	for(ll i = 1; i < n; ++i){
		num_of_coins[i] = num_of_coins[i-1] + (start[i] - ending[i-1]);
	}
	// ll a[n];
	for(ll i = 0; i < n; i++){
		// a[i] = 0;
		a[num_of_coins[i]]++;
	}
	for(ll i = n-2; i >= 0; --i){
		a[i] += a[i+1];
	}
	cin >> q;
	ll x;
	while(q--){
		cin >> x;
		cout << a[x] << endl;
	}
	return 0;
}