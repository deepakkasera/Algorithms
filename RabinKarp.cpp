#include <bits/stdc++.h>
using namespace std;
int prime =11;
int reCalculateHash(string text,int start,int end,int textHash,int m){
     long newhash = 0;
     newhash=textHash-text[start];
     newhash/=prime;
     newhash += text[start+m]*pow(prime,m-1);
     return newhash; 
}
int createHash(string text,int n){
	long hash=0;
    for(int i=0;i<n;i++)
      hash+=text[i]*pow(prime,i);
   return hash;
}
void patternSearch(string text,string pattern){
    int n=text.length();
    int m=pattern.length();
    int patternHash = createHash(pattern,m);
    int textHash = createHash(text,n);
    bool flag;
    for(int i=0;i <= n-m ;i++){
    	int j=0;
    	if(textHash == patternHash ){
    		while(j<m && text[i+j] == pattern[j])   j++;
    		if(j==m) flag=true,cout<<"Pattern found at index "<<i<<"\n";
    	}
    	if(i <= n-m){
    		textHash = reCalculateHash(text,i,i+m,textHash,m);
    	}
    }
    if(!flag)  cout<<"pattern not found\n";
}
int main(int argc, char const *argv[])
{
	string s,p;
	cin>>s>>p;
	patternSearch(s,p,prime);
	return 0;
}