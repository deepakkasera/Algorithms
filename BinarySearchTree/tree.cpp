#include <iostream>
#include <queue>
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

bool fun(node* root){
	if(root==NULL || (!root->left && !root->right)){
		return true;
	}
	int x=0;
	if(root->left!=NULL){
		x += root->left->data;
	}
	if(root->right!=NULL){
		x += root->right->data;
	}
	return x == root->data && fun(root->left) && fun(root->right);
}

istream& operator>>(istream& is,node* &root) {
	levelOrderInput(root);
	return is;
}

ostream& operator<< (ostream& os,node* &root) {
	levelOrderPrint(root);
	return os;
}

int main(int argc, char const *argv[])
{
	node* root = NULL;
	cin>>root;
	cout<<root;
	if(fun(root)){
		cout << "yes\n";
	}else{
		cout << "No\n";
	}
	return 0;
}