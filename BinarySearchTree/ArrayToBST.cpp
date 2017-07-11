#include <iostream>
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

node* insert(node* root,int d){
	if(!root){
		root = new node(d);
		return root;
	}
	if(d < root->data){
		root->left = insert(root->left,d);
	}
	else if (d>root->data){
		root->right = insert(root->right,d);
	}
	return root;
}

void inorder(node* root){
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

node* arrayToBST(int a[],int start,int end){
	if(start > end) {
		return NULL;
	}
	int middle = (start + end) / 2;
	node* root = new node(a[middle]);
	root->left = arrayToBST(a,start,middle-1);
	root->right = arrayToBST(a,middle+1,end);
	return root;
}

int main(int argc, char const *argv[])
{
	node* root=NULL;
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		root=insert(root,x);
	}
	inorder(root);
	int e;
	cout << "Enter number of elements in array\n";
	cin >> e;
	int a[e];
	for(int i=0;i<e;i++){
		cin >> a[i];
	}
	node* root2 = arrayToBST(a,0,e-1);
	inorder(root2);
	cout<<endl;
	return 0;
}