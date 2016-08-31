#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* next;
};
// insert new node at nth position
node* insert(node* head,int data,int n){
	node* temp=new node();
	temp->data=data;
	temp->next=NULL;
	node* temp1=head;
	if(n==1)
	 {
	 	temp->next=head;
	 	head=temp;
	 	return head ;
	 }
    for(int i=0;i<n-2;i++)
	   	temp1=temp1->next;
	temp->next=temp1->next;
	temp1->next=temp;
	return head; 
}
//reverse the linked list
node* reverse(node* head){
	node *prev,*current,*next;
	prev=NULL;
	current=head;
	while(current){
		next=current->next;
		current->next=prev;
		prev=current;
		curr=next;
	}
	head=prev;
	return head;
}
//print linked list
void print(node* head){
	node* temp=head;
	while(temp){
	  cout<<temp->data<<" ";
	  temp=temp->next;	
	}
}
int main(){
    node* head=NULL;
    int n;
    cout<<"enter the number of elements in linked list";
    cin>>n;
	for(int i=0;i<n;i++){
		head=insert(head,i+1,i+1);
	}
	print(head);
	head=reverse(head);
	cout<<"\n";
	print(head);
	return 0;
}
