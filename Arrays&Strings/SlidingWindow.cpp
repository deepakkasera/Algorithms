#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
int main(int argc, char const *argv[])
{
	int n,k;
	cin >> n >> k;
	int v[n+1],left[n+1],right[n+1];
	for(int i=1;i<=n;i++){
		cin >> v[i];
	}
	for(int i=1;i<=n;i++){
		if(i % k == 1) left[i] = v[i];
		else left[i] = max(left[i-1],v[i]);
	}
	for(int i=n;i>=1;i--){
		if(i == n || i % k == 0) right[i] = v[i];
		else right[i] = max(right[i+1],v[i]);
	}
	for(int i=1;i<=n-k+1;i++){
		cout << max(right[i],left[i+k-1]) << " ";
	}
	return 0;
}