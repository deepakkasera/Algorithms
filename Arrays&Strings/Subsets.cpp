#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,k;
	cin >> n >> k;
	std::vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	int res=0;
	for(int i=0;i<(1<<n);i++){
		int sum=0;
		for(int j=0;j<n;j++){
			if(i & (1<<j)) sum+=v[j];
		}
		if(sum >= k) res++;
	}
	cout << res << endl;
	return 0;
}