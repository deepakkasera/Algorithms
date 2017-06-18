#include <bits/stdc++.h>
using namespace std;
set<string> st;
void permutations(string s,int i){
	if(i==s.length()){
		st.insert(s);
		// cout << s << endl;
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
	// cout << "permutations\n";
	permutations(s,0);
	set<string>::iterator it;
	for(it=st.begin();it!=st.end();it++){
		cout << *it << endl;
	}
	// cout << "string " << s << endl;
	return 0;
}