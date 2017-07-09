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
	levelOrderPrint(root);
	return os;
}

int height(node* root){
	if(!root){
		return 0;
	}
	return max(height(root->left),height(root->right))+1;
}

//O(n^2) approach
bool isBalanced(node* root) {
	if(root == NULL){
		return true;
	}

	int l = height(root->left);
	int r = height(root->right);

	if(abs(l-r)<=1 && isBalanced(root->left) && isBalanced(root->right)){
		return true;
	}
	return false;
}


int isBalancedOptimized(node* root) {
	if(root == NULL){
		return 0;
	}

	int l = isBalancedOptimized(root->left);
	if(l == -1){
		return -1;
	}

	int r = isBalancedOptimized(root->right);
	if(r == -1){
		return -1;
	}

	if(abs(l - r) > 1){
		return -1;
	}

	return 1+max(l,r);
}

int main(int argc, char const *argv[])
{
	node* root = NULL;
	cin>>root;
	cout<<root;
	if(isBalanced(root)){
		cout << "Balanced tree\n";
	}
	else{
		cout << "not a balanced tree\n";
	}
	return 0;
}