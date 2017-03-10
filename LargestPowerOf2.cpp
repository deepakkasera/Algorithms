#include <bits/stdc++.h>
#define ll long long
using namespace std;
long long largestPowerOf2(long long n){
	n |= (n>>1);
	n |= (n>>2);
	n |= (n>>4);
	n |= (n>>8);

	return (n+1) >> 2;
}
int main(int argc, char const *argv[])
{
	ll n;
	cin >> n;
	cout << largestPowerOf2(n) << endl;
	return 0;
}