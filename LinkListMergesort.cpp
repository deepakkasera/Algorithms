#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node* next;
};
node* insertAtN(node* head,int data,int n){
   node* new_node = new node();
   new_node->data=data;
   new_node->next=NULL;
   if(n==1){
     new_node->next=head;
     head=new_node;
     return head;
   }
   node* temp=head;
   for(int i=0;i<n-2;i++) temp=temp->next;
   new_node->next = temp->next;
   temp->next = new_node;
   return head;
}
void print(node* head){
	node* temp=head;
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"\n";
}
int getLength(node* head){
	node* temp=head;
	int count=0;
	while(temp)  {
		count++;
		temp=temp->next;
	}
	return count;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int n,x;
	node* head=NULL;
	cout<<"Enter the number of elements in Linked list";
	cin>>n;
	cout<<"Enter elements ";
	for(int i=0;i<n;i++) {
		cin>>x;
		head=insertAtN(head,x,i+1);
	}
	print(head);
	return 0;
}