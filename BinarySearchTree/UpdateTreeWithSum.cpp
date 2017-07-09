#include <bits/stdc++.h>
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
	levelOrderPrint	(root);
	return os;
}

int sum(node* root) {
	if(!root) {
		return 0;
	}
	return sum(root->left)+sum(root->right)+root->data;
}

int updateTree(node* root) {
	if(root == NULL){
		return 0;
	}
	if(root->left==NULL && root->right==NULL){
		return root->data;
	}
	int temp = root->data;
	int leftSum = updateTree(root->left);
	int rightSum = updateTree(root->right);

	root->data = leftSum+rightSum;

	return temp + root->data;
} 
int main(int argc, char const *argv[])
{
	node* root = NULL;
	cin>>root;
	cout<<root;
	updateTree(root);
	cout<<root;
	return 0;
}