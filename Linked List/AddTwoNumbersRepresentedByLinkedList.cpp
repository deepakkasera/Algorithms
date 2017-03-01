#include <bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* next;
};
Node* head1=NULL;
Node* head2=NULL;
void insertAtPosition(Node* head,int d,int p){
	Node* n = new Node();
	n->data=d;
	n->next=NULL;
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
	n->next=temp->next;
	temp->next=n;
}
void print(Node* head){
	Node* temp=head;
	while(temp){
		cout << temp->data << "-->"; 
		temp=temp->next;
	}
	cout << "NULL\n";
}
int main(int argc, char const *argv[])
{
	int n,m,x;
	cout << "Enter the length of first linked list";
	cin >> n;
	cout << "Enter the elements of first linked list";
	for(int i=0;i<n;i++){
		cin >> x;
		insertAtPosition(head1,x,i);
	}
	print(head1);
	cout << "Enter the length of second linked list";		
	cin >> m;
	cout << "Enter the elements of second linked list";
	for(int i=0;i<m;i++){
		cin >> x;
		insertAtPosition(head2,x,i);
	}
	print(head2);
	return 0;
}