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
bool compare(Node* head1,Node* head2){
	Node* temp1=head1;
	Node* temp2=head2;
	while(temp1 && temp2){
		if(temp1->data == temp2->data){
			temp1=temp1->next;
			temp2=temp2->next;
		}
		else return false;
	}
	if(temp1==NULL && temp2==NULL) return true;
	else return false;
}
bool palindrome(Node* head){
	Node *slow,*fast,*prevSlow;
	slow=head;
	fast=head;
	while(fast && fast->next){
		prevSlow = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	Node* middle;
	if(!fast){
		middle=slow;
		slow = slow->next;
	}
	Node* secondHalf = slow;
	prevSlow->next=NULL;
	reverseList(slow);
	bool res = compare(head,secondHalf);
	reverseList(slow);
	if(middle){
		prevSlow->next = middle;
		middle->next = secondHalf;
	}
	else prevSlow->next = secondHalf;
	return res;
}
int main(int argc, char const *argv[])
{
	int n,x;
	cout << "Enter the number of elements in linked list";
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> x;
		insertAtPosition(x,i);
	}
	if(palindrome(head)) cout << "Linked list is palindrome\n";
	else cout << "Linked list is not palindrome\n";
	return 0;
}