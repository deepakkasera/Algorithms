#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string s;
	int n,x;
	cin >> s >> n >> x;
	int len = s.length();
	int l = 2*len+1;
	char ans[l];
	int k = 0;
	for(int i = 0; i < n; i++) {
		if(i==0) {
			if(s[i] == '0'){
				ans[k] = '0';
				ans[k+1] = '1';
			    k+=2;
			}
			else {
				ans[k] = '1';
				ans[k+1] = '0';
				k+=2;
			}
		}
		else {
			if(ans[i] == '0'){
				ans[k] = '0';
				ans[k+1] = '1';
			    k+=2;
			}
			else {
				ans[k] = '1';
				ans[k+1] = '0';
				k+=2;
			}
		}
	}
	ans[k]='\0';
	cout << ans <<endl ;
	cout << "Answer " << ans[x] << " ";
	return 0;
}