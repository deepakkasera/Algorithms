#include <bits/stdc++.h>
#define d 10
using namespace std;
void patternMatching(string text,string pattern,int q){
	int n = text.length();
	int m = pattern.length();
	int p=0; //hash value for the pattern
	int temp=0,t=0; //hash value for the text
	int h=1;
	bool flag=false;
	for(int i=0;i<m;i++)  h=(h*d)%m;
	for(int i=0;i<m;i++){
			p = (d*p + (int)pattern[i])%q;
			temp = (d*t + (int)text[i]);
			t = (temp)%q;
	}
	for(int s=0;s <= n-m;s++){
		if(p==t){
			int j=0;
			while(j<m && pattern[j]==text[s+j])  j++;
			if(j==m)    flag=true,cout<<"pattern found at position "<<s+1<<"\n";
			if(s < n-m)   temp = ((d*(t-text[s]*h)) + ((int)text[s+m])), t=temp%q;	
		}
	}
	if(!flag)   cout<<"Pattern not found";
}
int main(int argc, char const *argv[])
{
	string s,p;
	cin>>s>>p;
	int q=17;
	patternMatching(s,p,q); 
	return 0;
}