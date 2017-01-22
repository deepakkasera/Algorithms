#include <bits/stdc++.h>
using namespace std;
bool isBalanced(string str){
	stack<char> s;
	for(int i=0;str[i]!='\0';i++){
		if(str[i] == '{' || str[i] == '[' || str[i] == '(')
			s.push(str[i]);
		if (str[i] == '}'){
			if(!s.empty() && s.top() == '{'){
                s.pop();
			}
			else return false;
		}
		if (str[i] == ')'){
			if(!s.empty() && s.top() == '('){
                s.pop();
			}
			else return false;
		}
		if (str[i] == ']'){
			if(!s.empty() && s.top() == '['){
                s.pop();
			}
			else return false;
		}
	}
	return s.empty();
}
int main(int argc, char const *argv[])
{
	stack<char> s;
	string str;
	cout << "Enter the String";
	cin >> str;
	if(isBalanced(str)) cout << "Balanced\n";
	else cout << "Not Balanced\n";
	return 0;
}