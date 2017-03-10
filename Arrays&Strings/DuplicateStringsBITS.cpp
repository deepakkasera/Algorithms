#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	int n=s.length();
	int flag=0;
	for(int i=0;i<n;i++){
		if( flag & (1<<(s[i]-'a')) ){
			cout << "String has duplicate\n";
			return 0;
		}
		flag |= 1<<(s[i]-'a');
	}
	cout << "String does not contain duplicate\n";
	return 0;
}