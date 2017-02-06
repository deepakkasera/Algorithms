#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node* head;
void insertAtposition(int d,int p){
	Node* n = new Node();
	n->data = d;
	n->next = NULL;
	if(p == 0){
		n->next = head;
		head = n;
		return ;
	}
	int jumps = 0;
	Node* temp = head;
	while(jumps < p-1){
		temp = temp->next;
		jumps++;
	}
	n->next = temp->next;
	temp->next = n;
}
void print(){
	Node* temp = head;
	while(temp){
		cout << temp->data << "-->";
		temp = temp->next;
	}
	cout << "NULL\n";
}
Node* getMiddle(Node* head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	Node* slow = head;
	Node* fast = head->next;
	while(fast!=NULL && fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
Node* mergeSorted(Node* a,Node* b){
	if(a == NULL) return b;
	if(b == NULL) return a;
	Node* newHead;
	if(a->data < b->data){
		newHead = a;
		newHead->next = mergeSorted(a->next,b);
	}
	else{
		newHead = b;
		newHead->next = mergeSorted(a,b->next);
	}
	return newHead;
}
Node* mergeSort(Node* head){
	if(head==NULL || head->next==NULL){
		return head;
	}  
	Node* middle = getMiddle(head);
	Node* a = head;
	Node* b = middle->next;
	middle->next = NULL;
	a = mergeSort(a);
	b = mergeSort(b);

	Node* newHead = mergeSorted(a,b);
	return newHead;
}
int main(int argc, char const *argv[])
{
	int n,x;
	cout << "Enter the number of elements";
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> x;
		insertAtposition(x,i);
	}
	print();
	cout << "Data of middle node is " << getMiddle(head)->data << endl;
	head = mergeSort(head);
	print();
	return 0;
}