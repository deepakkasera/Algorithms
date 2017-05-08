#include <bits/stdc++.h>
using namespace std;
struct BSTNode
{
	int data;
	BSTNode* left;
	BSTNode* right;
};

// BSTNode* root = NULL;

BSTNode* newNode(int d){
	BSTNode* n = new BSTNode();
	n->data = d;
	n->left = n->right = NULL;
	return n;
}

BSTNode* balancedBST(int *a,int start,int end)
{
	if(start > end) return NULL;
	int middle = (start + end)/2;
	
	BSTNode* root = newNode(a[middle]);

	root->left = balancedBST(a,start,middle - 1);
	root->right = balancedBST(a,middle + 1,end);
	return root;
}

void printBST(BSTNode* root)
{
	if(!root) return ;
	cout << root->data << " ";
	printBST(root->left);
	printBST(root->right);
}

void printLevelOrder(BSTNode* root)
{
	queue<BSTNode*> q;
	q.push(root);
	while(!q.empty())
	{
		BSTNode* n = q.front();
		q.pop();
		if(n->left) 
			q.push(n->left);
		if(n->right) 
			q.push(n->right);
		if(n)
			cout << n->data << " ";
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the number elements in array\n";
	cin >> n;
	int a[n];
	cout << "Enter a sorted array\n";
	for(int i=0;i<n;i++) cin >> a[i];
	BSTNode* root =  balancedBST(a,0,n-1);
    cout << "BST\n";
    printBST(root);
    cout << endl;
    cout << "Level order traversal of BST\n";
    printLevelOrder(root);
	return 0;
}