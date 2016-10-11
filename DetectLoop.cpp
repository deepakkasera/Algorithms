#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node* next;
};
node* head;
void insertAtN(int data,int n){
	node* new_node=new node();
	new_node->data=data;
	new_node->next=NULL;
	if(n==1){
		new_node->next=head;
		head=new_node;
		return ;
	}
	node* temp=head;
	for (int i = 0; i < n-2; ++i)  temp=temp->next;
    new_node->next=temp->next;
    temp->next=new_node;
}
void print(){
	node* temp=head;
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"\n";
}
void printReverse(node * p){
	node* temp=p;
	if(!temp) return ;
	printReverse(temp->next);
	cout<<temp->data<<" ";
}
bool loopDetect(){
	node* first = head , *second = 	head;
	while(first && second && second->next){
		first = first->next;
		second = second->next->next;
        if(first == second) return true;
	}
	return false;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int n;
	cout<<"How many numbers you want to enter ";
	cin>>n;
	int x;
    for (int i = 0; i < n; ++i)
    {
    	cout<<"Enter the number ";
    	cin>>x;
    	insertAtN(x,i+1); 
    }
    node * temp=head;
    while(temp->next != NULL) temp=temp->next;
    temp->next=head;
    if(loopDetect())  cout<<"\nLoop exists in list";
    else cout<<"\nNo loop";
	return 0;
}
