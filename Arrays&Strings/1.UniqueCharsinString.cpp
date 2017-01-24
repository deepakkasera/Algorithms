#include <bits/stdc++.h>
using namespace std;
//Time Complexity is O(min(c,n)),c is the character set and n is the length of the string,space O(c) 
bool isUnque(string str){
	int n = str.length();
	if( n > 128 )  return false;
	std::vector<bool> v(128);
	for(int i=0;i<n;i++){
		int a = str[i];
		if(v[a]) return false;
		v[a] = true; 
	}
	return true;
}
int main(int argc, char const *argv[])
{
	string str;
	cin >> str;
	if(isUnque(str)) cout << "String has all unique characters \n";
	else cout << "String does not have all unique characters \n";
	return 0;
}