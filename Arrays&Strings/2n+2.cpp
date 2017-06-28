#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int resultXor = 0;
	for(int i = 0; i < n; i++){
		resultXor ^= a[i];
	}
	int x = resultXor;
	int num = x & (-1*x);
	int e1=0,e2=0;
	for(int i = 0; i < n; i++){
		if(num & a[i]){
			e1 ^= a[i];
		}
	}
	e2 = resultXor^e1;
	cout << e1 << " " << e2 << "\n";
	return 0;
}