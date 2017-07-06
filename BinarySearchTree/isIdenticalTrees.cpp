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

bool isIdentical(node* root1 , node* root2) {
	if(!root1 && !root2){
		return true;
	}

	if(root1 && root2) {
		return (root1->data==root2->data && 
			    isIdentical(root1->left,root2->left) && 
			    isIdentical(root1->right,root2->right)
			    );
	}
} 

istream& operator>>(istream& is,node* &root){
	levelOrderInput(root);
	return is;
}

ostream& operator<<(ostream& os,node* &root){
	levelOrderInput(root);
	return os;
}

int main(int argc, char const *argv[])
{
	node* root1 = NULL;
	node* root2 = NULL;
	cin >> root1;
	cin >> root2;
	if (isIdentical(root1,root2)){
		cout << "Two trees are identical\n";
	}
	else{
		cout << "Two trees are not identical\n";
	}
	return 0;
}