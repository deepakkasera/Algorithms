#include <bits/stdc++.h>
using namespace std;
int func(string s,int l,int h){
	if(l > h){
		return INT_MAX;
	}
	if(l==h-1){
		return s[l]==s[h] ? 0 : 1;
	}
	if(l == h){
		return 0;
	}

	if(s[l]==s[h]){
		return func(s,l+1,h-1);
	}
	return 1+min(func(s,l+1,h) , func(s,l,h-1));
}
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	int n = s.length();
	cout << func(s,0,n-1) << endl;
	return 0;
}