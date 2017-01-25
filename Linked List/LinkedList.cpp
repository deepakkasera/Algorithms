#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
public:
	Node(d){
		data = d;
		next = NULL;
	}
};
class LinkedList{
	Node* head,tail;
public :
     LinkedList(){
     	head = NULL;
     	tail = NULL;
     }
     void insertAtFront(int d){
     	if(head!){
     		head = tail = new Node(d);
     		return ;
     	}
     	Node* n = new Node(d);
     	n->next = head;
     	head = n;
     }
     int length() const{
     	Node* temp = head;
     	int length = 0;
     	while(temp){
     		length++;
     		temp = temp->next;
     	}
     	return length();
     }
     void insertAtEnd(int d){
     	if(head == NULL ){
     		head = tail = new Node(d);
     		return ;
     	}
     	else {
     		Node* n = new Node(d);
     		tail->next = n;
     		tail = n;
     	}
     }
     void insertAtPosition(int d,int n){
     	if(p==0){
     		insertAtFront(d);
     		return ;
     	}
     	else if(p > length()){
     		insertAtEnd(d);
     		return ;
     	}
     	Node* n = new Node(d);
     	Node* temp = head;
     	int i=0;
     	while(i < p-1){
     		temp = temp->next;
     		i++;
     	}
     	n->next = temp->next;
     	temp->next = n;
     }
     void removeAtFront(){
     	if(head == NULL) return ;
     	Node* temp = head;
     	head = head->next;
     	delete temp;
     }
     void removeAtEnd(){
     	if(head == NULL) return;
     	Node* prev = head;
     	while(prev->next != tail){
     		prev = prev->next;
     	}
     	delete tail;
     	prev->next = NULL;
     	tail = prev;
     }
     void removeAtPosition(int p){
     	if(p==0) removeAtFront();
     	if(p>length()) removeAtEnd();
     	Node* prev = head;
     	int i=0;
     	while(i<p-2){
     		prev = prev->next;
     		i++;
     	} 
     	Node* n = prev->next;
     	prev->next = n->next;
     	delete n;
     }
     void print(){
     	Node* temp=head;
     	while(temp){
     		cout << temp->data << "-->";
     		temp=temp->next;
     	}
     	cout << "NULL" << endl;
     }
}
int main(int argc, char const *argv[])
{
	LinkedList l;
	l.insertAtFront(4);
	l.insertAtFront(2);
	l.insertAtFront(1);
	l.insertAtFront(0);
	l.insertAtEnd(5);
	l.insertAtEnd(6);
	l.print();
	return 0;
}