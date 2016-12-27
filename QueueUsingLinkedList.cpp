#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node* front =NULL;
Node* rear =NULL;
void enQueue(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if(front == NULL && rear == NULL){
		front = rear = temp;
		return ;
	}
    rear->next = temp;
    rear = temp;
}
void deQueue()
{
	Node* temp = front;
	if(front == NULL){
		return ;
	}
    if(front == rear)  front = rear = NULL;
    else front = front->next;
    delete temp;
}
int frontElement()
{
   if(front == NULL && rear == NULL)  return -1;
   return front->data;
}
bool isEmpty()
{
	if(!front && !rear)  return true;
	return false;
}
int main(int argc, char const *argv[])
{
	enQueue(2);
	enQueue(7);
	enQueue(5);
	cout << frontElement() << endl;
	// cout << frontElement() << endl;
	// cout << frontElement() << endl;
	deQueue();
	cout << frontElement() << endl ;
	if(isEmpty()) cout << "Queue is empty " << endl ;
	else cout << "Queue is not empty " << endl ;
	enQueue(8); 
	deQueue();
	deQueue();
	cout << frontElement() << endl ;
	deQueue();
	if(isEmpty()) cout << "Queue is empty " << endl ;
	else cout << "Queue is not empty " << endl ;
	return 0;
}