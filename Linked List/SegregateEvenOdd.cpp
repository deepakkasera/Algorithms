#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* head = NULL;

node* getNewNode(int d){
	node* n = new node();
	n->data = d;
	n->next = NULL;
	return n;
}

void insertAtPosition(int d,int p){
	node* n = getNewNode(d);
	if(p==0){
		n->next = head;
		head = n;
		return;
	}
	int jumps = 0;
	node* temp = head;
	while(jumps < p-1){
		temp = temp->next;
		jumps++;
	}
	n->next = temp->next;
	temp->next = n;
	return;
}

void print(){
	node* temp = head;
	while(temp!=NULL){
		cout << temp->data <<"-->";
		temp = temp->next;
	}
	cout << "NULL\n";
}

void reversePrint(node* p){
	if(p == NULL){
		return ;
	}
	reversePrint(p->next);
	cout<<p->data<<"-->";
}

void segregateEvenOdd(){
	node* evenhead = NULL;
	node* evenEnd = NULL;
	node* oddHead = NULL;
	node* oddEnd = NULL;
	node* curr = head;

	while(curr != NULL){
		if(curr->data%2 != 0){
			if(oddHead == NULL){
				oddHead = curr;
				oddEnd = oddHead;
			}
			else{
				oddEnd->next = curr;
				oddEnd = oddEnd->next;
			}
		}
		else{
			if(evenhead == NULL){
				evenhead = curr;
				evenEnd = curr;
			}
			else{
				evenEnd->next = curr;
				evenEnd = evenEnd->next; 
			}
		}
		curr = curr->next;
	}


	if(oddHead == NULL || evenhead == NULL){
		return ;
	}

	evenEnd->next = oddHead;
	oddEnd->next = NULL;
	head = evenhead;
}

int main(int argc, char const *argv[])
{
	int n,x;
	cout<<"Enter number of elements \n";
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>x;
		insertAtPosition(x,i);
	}
	print();
	reversePrint(head);cout<<"NULL\n";
	print();
	segregateEvenOdd();
	print();
	return 0;
}