#include <bits/stdc++.h>
#define for(i,n)  for(int i=0;i<n;i++)
using namespace std;
struct node
{
	int data;
	node* next;
};
struct node* head;
// insert a node at nth position
void insertAtN(int x,int n){
   node* temp1 = new node();
   temp1->data=x;
   temp1->next=NULL;
   node* temp2=head;
   if(n==1){
   	temp1->next=head;
   	head=temp1;
   	return;
   }
   for(i,n-2)  temp2=temp2->next;
   temp1->next=temp2->next;
   temp2->next=temp1;
}
// Reversal of a linked list using iterative method
void reverse(){
	node *prev,*current,*next;
	prev=NULL;
	current=head;
	while(current!=NULL){
     next=current->next;
     current->next=prev;
     prev=current;
     current=next;
	}
    head=prev;
}
// Reversal of a linked list using recursive method
void reverseRecursive(node *p){
   node* temp=p;
   if(temp->next == NULL){
     head=temp;
     return;
   }
   reverseRecursive(temp->next);
   node* temp1 = temp->next;
   temp1->next = temp;
   temp->next = NULL;
}
//print linked list using iterative method
void print(){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"\n";
}
//print linked list using recursive approach
void printRecursive(node* p){
	 node* temp=p;
   if(temp == NULL)  {
    cout<<"\n";
    return;
   }
     cout<<temp->data<<" ";
     printRecursive(temp->next);
} 
//print linked list in reverse order using recursive approach
void reversePrintRecursive(node *p){
  node* temp=p;
   if(temp == NULL)  return ;
     reversePrintRecursive(temp->next); 
     cout<<temp->data<<" ";
}
//Delete a node at nth position
void deleteAtN(int n){
  node* temp1=head;
  if(n==1){
    head=temp1->next;
    delete temp1;
    return ;
  }
  for(i,n-2)  temp1=temp1->next;
  node* temp2 = temp1->next;
  temp1->next = temp2->next;
  delete temp2;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
    head = NULL;
    int n,x;
    cout<<"How many numbers you want to insert";
    cin>>n;
    for(i,n){
    	cout<<"Insert the number";
    	cin>>x;
    	insertAtN(x,i+1);
    }
    cout<<"List is ";
    print();
    cout<<"Reverse of linked list is ";
    reverse();
    print();
    reverse();
    cout<<"List is ";
    printRecursive(head);
    cout<<"Reversal print of linked list is ";
    reversePrintRecursive(head);   
    cout<<"\n";  
    cout<<"Reverse of linked list is ";
    reverseRecursive(head);
    print();
    reverse();
    deleteAtN(2);
    cout<<"List after deleting element at position 2 is ";
    print();
    cout<<"\n";
	return 0;
}
