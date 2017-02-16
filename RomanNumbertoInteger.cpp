#include <bits/stdc++.h>
using namespace std;
int value(char c){
	if(c == 'I') return 1;
	if(c == 'V') return 5;
	if(c == 'X') return 10;
	if(c == 'L') return 50;
	if(c == 'C') return 100;
	if(c == 'D') return 500;
	if(c == 'M') return 1000;

    return -1;
}
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	string s;
	while(t--){
		string s;
		cin >> s;
		int n=s.length();
		int ans=0;
		for(int i=0;i<n;i++){
			int s1 = value(s[i]);
			if(i+1 < n){
				int s2 = value(s[i+1]);
				if(value(s[i+1]) > value(s[i])){
					ans += (s2-s1);
					i++;
				}
				else {
					ans += s1;
				}
			}
			else {
				ans += s1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}