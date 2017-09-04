#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		int l = 0;
		int r = n-1;
		while(l < r){
			while(a[l]==0 && l < r){
				l++;
			}
			while(a[r] == 1 &&  l < r){
				r--;
			}
			if(l < r){
				a[l] = 0;
				a[r] = 1;
				l++;
				r--;
			}
		}
		for(int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout<<endl;
	}
	return 0;
}