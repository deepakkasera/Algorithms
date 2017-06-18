#include <bits/stdc++.h>
using namespace std;
void permutations(string s,int i){
	if(i==s.length()){
		cout << s << endl;
		return ;
	}
	for(int j=i;j<s.length();j++){
		swap(s[i],s[j]);
		permutations(s,i+1);
		swap(s[i],s[j]);
	}
	return;
}
int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	cout << "permutations\n";
	permutations(s,0);
	// cout << "string " << s << endl;
	return 0;
}