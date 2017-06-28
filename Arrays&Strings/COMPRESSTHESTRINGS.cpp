#include <bits/stdc++.h>
using namespace std;
string runLengthEncoding(string s){
	string res = "";
	int i = 0,j = 0;
	for(int i = 0; i < s.length(); i++){
		res += s[i];
		int runLength = 1;
		while(i + 1 < s.length() && s[i+1] == s[i]){
			runLength++;
			i++;
		}
 		if(runLength != 1){
			// res = res + std::to_string(runLength);
			// res += string(itoa(runLength));
			stringstream ss;
			ss << runLength;
			res += ss.str();
		}
	}
	return res;
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	string s;
	while(n--){
		cin >> s;
		cout << runLengthEncoding(s) << endl;
	}
	return 0;
}