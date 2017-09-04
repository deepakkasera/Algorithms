#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node (int d) : data(d),left(NULL),right(NULL){}
};

void levelOrderInput (node* &root) {
	int d;
	cout << "Enter root data "; 
	cin >> d;
	if (d != -1) {
		root = new node(d);
		queue <node*> q;
		q.push(root);
		while(!q.empty()) {
			node* temp = q.front();
			q.pop();
			int c1,c2;
			cout << "Enter children for " << temp->data << " ";
			cin >> c1 >> c2;
			if (c1 != -1) {
				temp->left = new node(c1);
				q.push(temp->left);
			}
			if (c2 != -1) {
				temp->right = new node(c2);
				q.push(temp->right);
			}
		}
	}
}

void SpiralLevelOrderPrint (node* root) {
	stack<node*> s1;
	stack<node*> s2;
	s1.push(root);
	while(!s1.empty() || !s2.empty()){
		while(!s1.empty()){
			node* n = s1.top();
			s1.pop();
			cout << n->data <<" ";
			if(n->right)
				s2.push(n->right);
			if(n->left)
				s2.push(n->left);
		}
		while(!s2.empty()){
			node* n = s2.top();
			s2.pop();
			cout << n->data << " ";
			if(n->left)
				s1.push(n->left);
			if(n->right)
				s1.push(n->right);
		}
	}
	return;
}

istream& operator>>(istream& is,node* &root) {
	levelOrderInput(root);
	return is;
}

ostream& operator<< (ostream& os,node* &root) {
	SpiralLevelOrderPrint(root);
	return os;
}

int main(int argc, char const *argv[])
{
	node* root = NULL;
	cin>>root;
	cout<<root;
	return 0;
}