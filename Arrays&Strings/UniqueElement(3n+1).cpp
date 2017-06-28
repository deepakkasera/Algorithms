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
	int cntBits[64] = {0};
	for(int i = 0; i < n; i++){
		int num = a[i];
		for(int j = 0; j < 64; j++){
			if(num&1){
				cntBits[j]++;
			}
			num = num >> 1;
		}
	}
	cout << "cntBits array \n";
	for(int i=0;i<64;i++){
		cout << cntBits[i] << " ";
	}
	cout << endl;
	int ans=0;
	int power=1;
	for(int i = 0; i < 64; i++){
		cntBits[i] %= 3;
		ans += cntBits[i]*power;
		power*=2;
	}
	cout << ans << endl;
	return 0;
}