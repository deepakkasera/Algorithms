#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	map<int,bool> m;
	bool flag = false;
	int sum = 0;
	for(int i=0;i<n;i++){
		sum += a[i];
		if(sum == 0 || m[sum])
			flag = true;
		m[sum] = true;
	}
	// int sum;
	// bool flag = false;
	// for(int i=0;i<n;i++){
	// 	sum = a[i];
	// 	if(sum == 0) {flag = true;break;}
	// 	for(int j=i+1;j<n;j++){
	// 		sum += a[j];
	// 		if(sum == 0) {flag = true;break;}
	// 	}
	// 	if(flag) break;
	// }
	if(flag) cout << "Subarray with sum zero found\n";
	else cout << "Subarray with sum zero not found\n";
	return 0;
}