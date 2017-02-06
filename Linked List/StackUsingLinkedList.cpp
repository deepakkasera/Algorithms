#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node* head = NULL;
void push(int d){
	Node* n = new Node();
	n->data = d;
	n->next = head;
	head = n;
}
int top(){
	if(head != NULL)
		return head->data;
}
void pop(){
	if(!head) return ;
	Node* temp = head;
	head = head->next;
	delete temp;
}
int length(){
	int count = 0;
	Node* temp = head;
	while(temp){
		temp = temp->next;
		count++;
	} 
	return count;
} 
bool isEmpty(){
	if(length() == 0) return true;
	return false;
}
int main(int argc, char const *argv[])
{
	push(5);
	push(4);
	push(3);
	push(2);
	push(1);
	cout << top() << endl;
	pop();
	cout << top() << endl;
	pop();
	cout << top() << endl;
	pop();
	cout << top() << endl;
	pop();
	cout << top() << endl;
	return 0;
}