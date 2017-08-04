#include <bits/stdc++.h>
using namespace std;
int func(string s,int n){
	int ans = 0;

	//checking for odd length substrings
	for(int i = 0; i < n; i++){

		for(int j = 0; i+j < n && i - j >= 0; j++){
			if(s[i-j] != s[i+j]){
				break;
			}
			else{
				ans++;
			}
		}
	}

	//checking for even length substrings

	for(int i = 0; i < n; i++){
		for(int j = 0; i - j >= 0 && i + j + 1 < n; j++){
			if(s[i-j] != s[i+j+1]){
				break;
			}
			else{
				ans++;
			}
		}
	}
	return ans;
}
int main(){
	string s;
	cin>>s;
	int n = s.length();
	cout << func(s,n) << endl;
}