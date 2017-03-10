#include <bits/stdc++.h>
using namespace std;
struct bstNode{
	int data;
	bstNode* left;
	bstNode* right;
};
bstNode* getNewNode(int data){
	bstNode* n = new bstNode();
	n->data=data;
	n->left=n->right=NULL;
	return n;
}
bstNode* insert(bstNode* root,int data){
	if(root==NULL){
		root=getNewNode(data);
	}
	else if(data < root->data)
		root->left = insert(root->left,data);
	else if (data > root->data)
		root->right = insert(root->right,data);
	return root;
}
bool search(bstNode* root,int data){
	if(!root) return false;
	if(root->data==data) return true;
	if(data < root->data)
		search(root->left,data);
	else if (data > root->data)
		search(root->right,data);
}
void preOrder(bstNode* root){
	if(root==NULL) return ;
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}
void postOrder(bstNode* root){
	if(root==NULL) return ;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}
void inOrder(bstNode* root){
	if(root==NULL) return ;
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}
int height(bstNode* root){
	if(!root) return -1;
	return max(height(root->left),height(root->right))+1;
}
int maxElement(bstNode* root){
	bstNode* temp=root;
	while(temp->right){
		temp=temp->right;
	}
	return temp->data;
}
int minElement(bstNode* root){
	bstNode* temp=root;
	while(temp->left)
		temp=temp->left;
	return temp->data;
}
int main(int argc, char const *argv[])
{
	bstNode* root=NULL;
	int n,x;
	cout << "Enter the number of nodes\n";
	cin >> n;
	cout<<"Enter n elements\n";
	for(int i=0;i<n;i++){
		cin >> x;
		root=insert(root,x);
	}
	cout << "preOrder traversal\n";
	preOrder(root);cout<<endl;
	cout << "Inoder traversal\n";
	inOrder(root);cout<<endl;
	cout << "postOrder traversal\n";
	postOrder(root);cout<<endl;
	int a;
	cout << "Enter the number to be searched\n";
	cin >> a;
	if(search(root,a))cout<<"Found\n";
	else cout<<"Not found\n";
	cout << "height of BST is " << height(root)<<endl;
	cout << "maxElement is " << maxElement(root)<<endl;
	cout << "minElement is " << minElement(root)<<endl;
 	return 0;
}