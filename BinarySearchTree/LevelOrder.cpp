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
	if(!root){
		root=getNewNode(data);
	}
	else if (data > root->data){
		root->right = insert(root->right,data);
	}
	else if (data < root->data) {
		root->left = insert(root->left,data);
	}
	return root;
}
void preOrder(bstNode* root){
	if(!root) return;
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}
void levelOrder(bstNode* root){
	if(!root) return ;
	queue<bstNode*> q;
	q.push(root);
	while(!q.empty()){
		bstNode* n = q.front();
		q.pop();
		if(n!=NULL){
			cout<<n->data<<" ";
			q.push(n->left);
		    q.push(n->right);
		}
	}
}
void levelOrder2(bstNode* root){
	queue<bstNode*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		bstNode* n=q.front();
		q.pop();
		if(n==NULL){
			cout<<endl;
			if(!q.empty()) q.push(NULL);
		}
		else{
			cout<<n->data<<" ";
			if(n->left!=NULL) q.push(n->left);
			if(n->right!=NULL) q.push(n->right);
		}
	}
}
int main(int argc, char const *argv[])
{
	bstNode* root = NULL;
	int n,x;
	cout<<"Enter number of nodes\n";
	cin>>n;
	cout<<"Enter data\n";
	for(int i=0;i<n;i++){
		cin>>x;
		root=insert(root,x);
	}
	cout<<"Preorder traversal\n";
	preOrder(root);cout<<endl;
	cout<<"levelOrder traversal\n";
	levelOrder(root);cout<<endl;
	levelOrder2(root);cout<<endl;
	return 0;
}