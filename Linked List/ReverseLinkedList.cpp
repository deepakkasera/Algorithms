#include <bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	Node* next;
public:
	Node(int d) : data(d),next(NULL) {}
};
class LinkedList{
public:
	Node* head;
public:
	LinkedList(){
		head = NULL;
	}
	void insertAtFront(int d){
		if(!head){
			head = new Node(d);
			return ;
		}
		Node* n = new Node(d);
		n->next = head;
		head = n;
	}
	void insertAtPosition(int d,int p){
		if(p == 0){
			insertAtFront(d);
			return ;
		}
		Node* n = new Node(d);
		Node* temp = head;
		int jumps = 0;
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
		cout << "NULL" << endl;
	}
	void reverse(){
		Node* prev = NULL;
		Node* current = head;
		Node* next ;
		while(current != NULL){
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}
};
int main(int argc, char const *argv[])
{
	LinkedList l;
	l.insertAtFront(5);
	l.insertAtFront(4);
	l.insertAtFront(3);
	l.insertAtFront(2);
	l.insertAtFront(1);
	l.print();
	l.insertAtPosition(6,5);
	l.reverse();
	l.print();
	l.print();
	return 0;
}