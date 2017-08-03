#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* next;
};

node* head = NULL;

node* getnewNode(int data){
	node* n = new node();
	n->data = data;
	n->next = NULL;
	return n;
}

void insertAtPos(int d,int pos){
	node* n = getnewNode(d);
	if(pos == 0){
		n->next = head;
		head = n;
		return ;
	}
	int jumps = 0;
	node* temp = head;
	while(jumps < pos - 1){
		temp = temp->next;
		jumps++;
	}
	n->next = temp->next;
	temp->next = n;
	return;
}

void print(){
	node* temp = head;
	while(temp != NULL){
		cout << temp->data << "-->";
		temp = temp->next;
	}
	cout<<"NULL";
	return;
}

void printRev(node* p){
	if(p == NULL){
		return;
	}
	printRev(p->next);
	cout<<p->data<<"-->";
}

node* getMiddle(node* head){
	// if(head == NULL || head->next == NULL){
	// 	return head;
	// }

	node* slow = head;
	node* fast = head->next;

	while(fast!=NULL && fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	
	return slow;

}

node* mergeSorted(node* a , node* b){
	if(a == NULL){
		return b;
	}
	if(b == NULL){
		return a;
	}
	node* newHead;
	if(a->data <= b->data){
		newHead = a;
		newHead->next = mergeSorted(a->next,b);
	}

	else{
		newHead = b;
		newHead->next = mergeSorted(a,b->next);
	}
	return newHead;
}

node* mergeSort(node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	node* middle = getMiddle(head);
	node* a = head;
	node* b = middle->next;
	middle->next = NULL;
	a = mergeSort(a);
	b = mergeSort(b);

	node* newHead = mergeSorted(a,b);
	return newHead;
}

int main(int argc, char const *argv[])
{
	int n,x;
	cout << "Enter the number of elements on LL\n";
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x;
		insertAtPos(x,i);
	}
	print();
	cout<<endl;
	node* p = head;
	printRev(p);cout<<"NULL"<<endl;
	// cout<<"data of middle node is \n";
	// cout<<getMiddle()->data <<endl;
	head = mergeSort(head);
	print();
	return 0;
}