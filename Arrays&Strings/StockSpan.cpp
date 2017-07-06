#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int a[n];
	int max[n] = {0};
	for(int i =0 ;i < n; i++){
		cin >> a[i];
		max[i] = max()
	}
	for(int i = 1; i < n; i++){
		if (a[i] >= a[i-1]){
			ans[i] = ans[i-1] + 1;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << ans[i] << " ";
	}
	return 0;
}