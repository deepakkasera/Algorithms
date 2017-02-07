#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node* head = NULL;
void insertAtFront(int d,int p){
	Node* n = new Node();
	n->next = NULL;
	n->data = d;
	if(p==0){
		n->next = head;
		head = n;
		return ;
	}
	int jumps =0 ;
	Node* temp = head;
	while(jumps < p-1){
		jumps++;
		temp = temp->next;
	}
	n->next = temp->next;
    temp->next = n;
}
void print(){
	Node* temp = head;
	while(temp){
		cout << temp->data <<"-->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}
void printReverse(Node* p){
	Node* temp = p;
	if(p == NULL) return ;
	printReverse(p->next);
	cout << p->data <<"-->";
}
void reverseListRecursive(Node* p){
	if(p->next == NULL){
		head = p;
		return;
	}
	reverseListRecursive(p->next);
	Node* q = p->next;
	q->next = p;
	p->next = NULL;
}
int main(int argc, char const *argv[])
{
	int n,x;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> x;
		insertAtFront(x,i);
	}
	print();
	printReverse(head);
	cout << "NULL\n";
	reverseListRecursive(head);
	print();
	return 0;
}