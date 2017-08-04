#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;


	node(int d) : data(d) , left(NULL) , right(NULL) {}
};

void levelOrderInput(node* &root){
	cout << "Enter root data\n";
	int d;
	cin >> d;
	if(d != -1){
		root = new node(d);
		queue<node*> q;
		q.push(root);

		while(!q.empty()){
			node* f = q.front();
			q.pop();
			int c1,c2;
			cout << "Enter children for "  << f->data << " ";
			cin >> c1 >> c2;
			if(c1 != -1){
				f->left = new node(c1);
				q.push(f->left);
			}
			if(c2!=-1){
				f->right = new node(c2);
				q.push(f->right);
			}
		}
 	}
}

void levelOrderPrint(node* root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* f = q.front();
		q.pop();
		if(f!=NULL){
			cout << f->data << " ";
			if(f->left)
				q.push(f->left);
			if(f->right)
				q.push(f->right);
		}
		if(f==NULL){
			cout << endl;
			if(!q.empty())
				q.push(NULL);
		}
	}
}

istream& operator>>(istream& is , node* &root){
	levelOrderInput(root);
	return is;
}

ostream& operator<<(ostream& os,node* root){
	levelOrderPrint(root);
	return os;
}

node* lca(node* root,int  a,int b){
	if(!root){
		return NULL;
	}
	
	if(root->data == a || root->data == b){
		return root;
	}

	node* l = lca(root->left,a,b);
	node* r = lca(root->right,a,b);

	if(l!=NULL && r!=NULL)
		return root;
	if(!l)
		return r;
	else return l;
}

int main(int argc, char const *argv[])
{
	node* root = NULL;
	cin>>root;
	cout<<"Level Order Traversal of Binary Tree is \n";
	cout<<root;
	int a,b;
	cout<<"Enter nodes to find LCA\n";
	cin>>a>>b;
	cout<<"LCA is " << lca(root,a,b)->data << endl;
	return 0;
}