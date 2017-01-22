#include <bits/stdc++.h>
using namespace std;
//O(n)
void insertAtBottom(stack<int> &s,int data){
	if(s.empty()){
		s.push(data);
		return ;
	}
	//cout << s.top() << endl;
	int poppedElement = s.top();
	s.pop();
	insertAtBottom(s,data);
	s.push(poppedElement);
}
//O(n*n)
void reverseStack(stack<int> &s){
	if(s.empty()) return ;
	//Recursive Case
	int topMost = s.top();
	//cout << topMost << endl;
	s.pop();
	reverseStack(s);
	insertAtBottom(s,topMost);
}
void print(stack<int> s){
	while(!s.empty()){ 
	    cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	stack<int> s;
    for(int i=1;i<=5;i++) s.push(i);
    print(s);
    reverseStack(s);
    print(s);
	return 0;
}	