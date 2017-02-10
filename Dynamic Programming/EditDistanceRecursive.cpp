#include <bits/stdc++.h>
using namespace std;
int min(int a,int b,int c){
	return min(min(a,b),c);
}

int editDistance(string str1,string str2,int m,int n){
	if(m == 0) return n;
	if(n == 0) return m;

	if(str1[m-1] == str2[n-1]){
		return editDistance(str1,str2,m-1,n-1);
	}

	return 1 + min(editDistance(str1,str2,m-1,n-1),editDistance(str1,str2,m-1,n),editDistance(str1,str2,m,n-1));
}

int main(int argc, char const *argv[])
{
	string str1,str2;
	cin >> str1 >> str2;
	int m = str1.length();
	int n = str2.length();
	cout << editDistance(str1,str2,m,n) << endl;
	return 0;
}