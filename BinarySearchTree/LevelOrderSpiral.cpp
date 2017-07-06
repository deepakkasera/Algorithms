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

void levelOrderSpiral(node* root) {
	stack<node*> s1;
	stack<node*> s2;

	s1.push(root);

	while(!s1.empty() || !s2.empty()) {
		while(!s1.empty()){
			node* temp = s1.top();
			s1.pop();
			cout << temp->data << "->";
			if(temp->right){
				s2.push(temp->right);
			}
			if(temp->left){
				s2.push(temp->left);
			}
		}
		while(!s2.empty()){
			node* temp = s2.top();
			s2.pop();
			cout << temp->data << "->";
			if(temp->left){
				s1.push(temp->left);
			}
			if(temp->right){
				s1.push(temp->right);
			}
		}
	}
}

int CountNodes(node* root) {
	if(root == NULL){
		return 0;
	}
	return CountNodes(root->left)+CountNodes(root->right)+1;
}

istream& operator>>(istream& is,node* &root){
	levelOrderInput(root);
	return is;
}

ostream& operator<<(ostream& os,node* &root){
	levelOrderSpiral(root);
	return os;
}

int main(int argc, char const *argv[])
{
	node* root = NULL;
	cin>>root;
	cout<<root<<endl;
	cout<<"number of nodes "<<CountNodes(root);
	return 0;
}