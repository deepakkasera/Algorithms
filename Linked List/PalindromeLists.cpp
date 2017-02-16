#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node* head= NULL;
void insertAtPosition(int d,int p){
	Node* n =  new Node();
	n->data = d;
	n->next = NULL;
	if(p==0){
		n->next = head;
		head = n;
		return ;
	}
	int jumps=0;
	Node* temp=head;
	while(jumps < p-1){
		temp = temp->next;
		jumps++;
	}
	n->next = temp->next;
	temp->next = n;
}
void print(){
	Node* temp=head;
	while(temp){
		cout << temp->data <<"-->";
		temp=temp->next;
	}
	cout << "NULL\n";
}
Node* reverseList(Node* head){
	Node* prev = NULL;
	Node* curr = head;
	Node* next ;
	while(curr){
		next = curr->next;
		curr->next = prev;
		prev=curr;
		curr=next;
	}
	head = prev;
	return head;
}
int main(int argc, char const *argv[])
{
	int n,x;
	cout << "Enter the number of elements in linked list";
	cin >> n;
	stack<int> s1;
	//stack<int> s2;
	for(int i=0;i<n;i++){
		cin >> x;
		insertAtPosition(x,i);
	}
	//print();
	Node* temp=head;
	while(temp){
		s1.push(temp->data);
		temp=temp->next;
	}
	//cout << s1.top() << " ";
	//head = reverseList(head);
	//print();
	bool flag=false;
	temp=head;
	while(!s1.empty()){
		if(temp->data != s1.top()){
			flag=true;
			break;
		}
		else{
			s1.pop();
			temp=temp->next;
		}
	}
	if(!flag) cout << "Linked list is palindrome\n";
	else cout << "Linked list is not palindrome\n";
	return 0;
}