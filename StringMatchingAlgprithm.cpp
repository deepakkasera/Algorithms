#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string s,p;
	cin>>s>>p;
	int n=s.length();
	int m=p.length();
	bool flag=false;
	for(int i=0 ; i <= n-m ; i++){
         int j=0;
         while(j<m && s[i+j]==p[j]) j++;
         	if(j == m)  
         		flag=true,cout<<"pattern found\n";
	}
	if(!flag) cout<<"Pattern not found\n";
	return 0;
}