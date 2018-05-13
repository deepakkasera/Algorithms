#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int d) : data(d),left(NULL),right(NULL) {}

};

void levelOrderInput (node* &root) {
	int d;
	cout << "Enter root data ";
	cin >> d;
	if (d != -1) {
		root = new node(d);
		queue<node*> q;
		q.push(root);
		while(!q.empty()) {
			node* f = q.front();
			q.pop();
			int c1,c2;
			cout << "Enter children of " << f->data << " ";
			cin >> c1 >> c2;
			if (c1 != -1) {
				f->left = new node(c1);
				q.push(f->left);
			}
			if (c2 != -1) {
				f->right = new node(c2);
				q.push(f->right);
			} 
		}
	}
}
void levelOrderPrint (node* root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		node* temp = q.front();
		q.pop();
		if (temp) {
			cout << temp->data << " ";
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
		if (!temp) {
			cout << endl;
			if (!q.empty()){
				q.push(NULL);
			}
		}
	}
}
istream& operator>>(istream& is,node* &root){
	levelOrderInput(root);
	return is;
}

ostream& operator<<(ostream& os,node* &root){
	levelOrderPrint(root);
	return os;
}

void mirror(node* &root) {
	if (!root) {
		return;
	}

	mirror(root->left);
	mirror(root->right);

	node* temp = root->left;
	root->left = root->right;
	root->right = temp;
	return; 
}
int main(int argc, char const *argv[])
{
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);     
	node* root = NULL;
	cin >> root;
	cout << root;
	mirror(root);
	cout << root;
	return 0;
}
