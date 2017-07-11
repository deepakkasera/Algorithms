#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* input(node* root,int d) {
	if(root == NULL) {
		root = new node(d);
	}
	if(d < root->data){
		root->left = input(root->left , d);
	}
	else if (d > root->data) {
		root->right = input(root->right,d);
	}
	return root;
}

void inorderTraversal(node* root) {
	if(root) {
		inorderTraversal(root->left);
		cout << root->data << " ";
		inorderTraversal(root->right);
	}
}

node* minElement(node* root) {
	if(!root){
		return NULL;
	}
	while(root->left != NULL){
		root = root->left;
	}
	return root;
}

class LinkedListNode{
public:
	node* head;
	node* tail;
};

LinkedListNode bstToLinkedList(node* root) {
	LinkedListNode l;
	if(root == NULL){
		l.head = NULL;
		l.tail = NULL;
		return l;
	}
	//1. Leaf node
	if(!root->left && !root->right) {
		l.head = root;
		l.tail = root;
		return l;
	}

	//2. left is null and right is not null
	else if (root->left == NULL && root->right!=NULL){
		LinkedListNode rightLL = bstToLinkedList(root->right);
		root->right = rightLL.head;
		l.head = root;
		l.tail = rightLL.tail;
	}

	//3. right is null and left is not null
	else if (root->left != NULL && root->right == NULL){
		LinkedListNode leftLL = bstToLinkedList(root->left);
		leftLL.tail->right = root;
		l.head = leftLL.head;
		l.tail = root;
	}

	else{
		LinkedListNode ll = bstToLinkedList(root->left);
		LinkedListNode lr = bstToLinkedList(root->right);
		ll.tail->right = root;
		root->right = lr.head;
		l.head = ll.head;
		l.tail = lr.tail;
	}
	return l;
}
int main(int argc, char const *argv[])
{
	node* root = NULL;
	int n,x;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x;
		root = input(root,x);
	}
	inorderTraversal(root);
	node* temp = minElement(root);
	cout << endl;
	if(temp == NULL){
		cout << "Tree is empty\n";
	}
	else{
		cout << "Minimum element in tree is " << temp->data << endl;
	}
	cout << "linked list of tree is \n";
	LinkedListNode list = bstToLinkedList(root);
	temp = list.head;
	while(temp) {
		cout << temp->data << "-->";
		temp = temp->right;
	}
	cout << "NULL\n";
	return 0;
}