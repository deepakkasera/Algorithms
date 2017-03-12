#include <bits/stdc++.h>
using namespace std;
void prefixTable(string p,int m,int a[]){
	int i=1,j=0;
	a[0]=0;
	while(i < m){
		if(p[i] == p[j]){
			a[i]=j+1;
			j++;
			i++;
		}
		else{
			if(j!=0){
				j=a[j-1];
			}
			else if (j==0){
				a[i]=0;
				i++;
			}
		}
	}
}
bool KMP(string s,int n,string p,int m){
	int pre[m];
	prefixTable(p,m,pre);
	for(int i=0;i<m;i++)cout<<pre[i]<<" ";
	int i=0,j=0;
	while(i < n){
		if(s[i] == p[j]){
			if(j==m-1) return true;
			j++;
			i++;
		}
		else if (j>0) j=pre[j-1];
		else i++;
	}
	return false;
}
int main(int argc, char const *argv[])
{
	string s,p;
	cin>>s>>p;
	if(KMP(s,s.length(),p,p.length()))
		cout<<"Pattern found\n";
	else cout<<"Pattern not found\n";
	return 0;
}