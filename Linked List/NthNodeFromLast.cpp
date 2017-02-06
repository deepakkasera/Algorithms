#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node* head = NULL;
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
int length(){
	Node* temp = head;
	int count = 0 ;
	while(temp){
		temp = temp->next;
		count++;
	}
	return count;
}
//Complexity is O(n)
Node* nthNodeFromLast(int n){
	if(length() < n) return NULL;
	int x = length()-n+1;
	Node* temp = head;
	int jumps = 0;
	while(jumps < x-1){
		temp = temp->next;
		jumps++;
	}
	return temp;
}
//Recursive method
void nthNodeFromLastRecursive(Node* head,int n){
	int i = 0;
	if(head == NULL)  return ;
	// Node* temp = head->next;
	nthNodeFromLastRecursive(head->next,n);
	if(++i == n) cout << "Data of the node number " << n << " from last is " <<head->data << endl;
}
//using two pointers
Node* nthNodeFromLast2(int n){
	Node* main_ptr = head;
	Node* ref_ptr = head;
	int count=0;
	if(head){
		while(count < n){
			if(ref_ptr != NULL){
				ref_ptr = ref_ptr->next;
				count++;
			}
		}
		while(ref_ptr != NULL){
			main_ptr = main_ptr->next;
			ref_ptr = ref_ptr->next;
		}
	}
	return main_ptr;
}
int main(int argc, char const *argv[])
{
	int n,x;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> x;
		insertAtposition(x,i);
	}
	print();
	int a;
	cout << "Length of linked list is " << length() <<endl;
	cout << "Enter the node from last";
	cin >> a;
	Node* temp = nthNodeFromLast(a);
	if(!temp) cout << "Enter a valid number \n";
	else cout << "Data of the node number " << a << " from last is " <<temp->data << endl;
    //nthNodeFromLastRecursive(head,a);
 	Node* temp2 = nthNodeFromLast2(a);
 	if(!temp2) cout << "Enter a valid number \n";
	else cout << "Data of the node number " << a << " from last is " <<temp2->data << endl;
 	return 0;
}