#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* newNode(int d){
	TreeNode* n = new TreeNode();
	n->data = d;
	n->left = NULL;
	n->right = NULL;
}

void diagonal(TreeNode* root,int d, map<int,std::vector<int> > &m)
{
	//Base case
	if(!root)
		return ;

	m[d].push_back(root->data);

	diagonal(root->left,d+1,m);
	diagonal(root->right,d,m);
}

void diagonalPrint(TreeNode* root){
	map<int,std::vector<int> > m;

	diagonal(root,0,m);
	cout << "Daigonal traversal of binary tree is\n";
	for(auto it=m.begin();it!=m.end();it++){
		for(auto itr = it->second.begin();itr!=it->second.end();itr++){
			cout << *itr << " ";
		}
		cout << "\n";
	}
}

int main(int argc, char const *argv[])
{
    TreeNode* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
    diagonalPrint(root);
	return 0;
}