#include <bits/stdc++.h>
using namespace std;
std::vector<int>  computeTemporaryArray(string pattern){
	int m=pattern.length();
	int j=0;
	std::vector<int> v(m);
	for(int i=1;i < m; ){
		if(pattern[i] == pattern[j]) {
			v[i]=j+1;
			i++;
			j++;
		}
		else {
			if(j == 0)  v[i]=0,i++;
			else j=v[j-1];
		}
	}
	return v;
}
bool knuthMorrisPratt(string text,string pattern){
	int m=pattern.length();
	int n=text.length();
	std::vector<int> v;
	v = computeTemporaryArray(pattern);
	int i=0,j=0;
	while(i<n && j<m){
		if(pattern[j] == text[i]) i++,j++;
		else if(j!=0)   j = v[j-1];
		else i++;
	}
	if(j == m)  return true;
	else return false;
}
int main(int argc, char const *argv[])
{
	string text,pattern;
	cin>>text>>pattern;
    bool flag = knuthMorrisPratt(text,pattern);
    if(flag)   cout<<"pattern found";
    else cout<<"pattern not found";
	return 0;
}