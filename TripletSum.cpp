#include <bits/stdc++.h>
using namespace std;
bool func(int *a,int n,int sum){
	sort(a,a+n);
	int l,r;
	for(int i = 0; i < n-2; i++){
		l = i+1;
		r = n-1;

		while(l < r){
			if(a[i] + a[l] + a[r] == sum){
				return true;
			}
			else if (a[i] + a[l] + a[r] < sum){
				l++;
			}
			else{
				r--;
			}
		}
	}
	return false;
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int sum;
	cout << "Enter sum ";
	cin >> sum;
	if(func(a,n,sum)){
		cout << "Triplet found\n";
	}
	else cout << "Triplet not found\n";
	return 0;
}