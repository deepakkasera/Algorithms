#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	stack<char> s;
	string str;
	cin >> str;
	int i=0;
	while(str[i]) s.push(str[i]),i++;
    while(!s.empty()) cout << s.top(),s.pop();
    cout << endl;
    reverseString(str);	
	return 0;
}