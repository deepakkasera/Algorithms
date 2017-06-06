#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll fastPow(int a,int n){
	if(n == 0)
		return 1;
	if(n&1) return a*fastPow(a,(n-1)/2)*fastPow(a,(n-1)/2);
	else return fastPow(a,n/2)*fastPow(a,n/2);
}
void printAllSubsets(std::vector<int> &v,int n)
{
	ll cnt = fastPow(2,n);
	// cout << "cnt value " << cnt << endl;
	for(ll i=0;i<cnt;i++)
	{
		for(ll j=0;j<n;j++){
			if(i&(1<<j))
				cout << v[j] << " ";
		}
		cout << endl;
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	std::vector<int> v(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	printAllSubsets(v,n);
	return 0;
}