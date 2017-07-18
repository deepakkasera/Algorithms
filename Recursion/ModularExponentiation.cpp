#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll modularExp(ll x,ll n,ll m){
	if(n == 0){
		return 1;
	}
	// ll power = modularExp(x,n/2,m);
	if(n&1){
		return x * modularExp((x*x)%m,(n-1)/2,m);
	}else{
		return modularExp((x*x)%m,n/2,m);
	}
}
int main(int argc, char const *argv[])
{
	int x,n,m;
	cin >> x >> n >> m;
	cout << modularExp(x,n,m) << endl;
	return 0;
}