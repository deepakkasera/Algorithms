#include<iostream>
#include<queue>

#define max(a,b) ( ((a)>(b)) ? (a) : (b) )

using std::cout;

struct BSTNode{
	int data;
	BSTNode* left;
	BSTNode* right;
	//BSTNode* parent;
};

//To initialize a binary search tree.
void BSTInit(BSTNode* root, int data){
	root->data = data;
	root->left = root->right = NULL;
}

//To insert nodes to tree.
void insertNode(BSTNode* root, int data){
	BSTNode* newNode = new BSTNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	while(1){
		if(data < root->data){
			if(!root->left){
				root->left = newNode;
				break;
			}
			else root = root->left;
			
		}
		else{
			if(!root->right){
				root->right = newNode;
				break;
			}
			else root = root->right;
		}
	}
}

//Searching if a element is present or not, if exist return the node.
BSTNode* searchTree(BSTNode* root, int data){
	while(root){
		if(data == root->data) return root;
		else if(data > root->data) root = root->right;
		else root = root->left;
	}
	return NULL;
}

//Finding minimum element in tree
int findMin(BSTNode* root){
	while(root->left) root = root->left;
	return root->data;
}

//Finding maximum element in tree
int findMax(BSTNode* root){
	while(root->right) root = root->right;
	return root->data;
}

//Pre order traversal.
void preOrder(BSTNode* root){
	if(root){
		cout << root->data << " " ;
		preOrder(root->left);
		preOrder(root->right);
	}
}

//Post order traversal.
void postOrder(BSTNode* root){
	if(root){
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << " " ;
	}

}
//In order traversal.
void inOrder(BSTNode* root){
	if(root){
		inOrder(root->left);
		cout << root->data << " " ;
		inOrder(root->right);
	}
}

//Find height of tree.
int getHeight(BSTNode* root){
	if(!root) return -1;
	return max(getHeight(root->left),getHeight(root->right))+1;
}

//Level order traversal .
void levelOrder(BSTNode* root){
	BSTNode* curr;
	std::queue<BSTNode*>q;
	q.push(root);
	while(!q.empty()){
		curr = q.front();
		cout << curr->data << " ";
		q.pop();
		if(curr->left) q.push(curr->left);
		if(curr->right) q.push(curr->right);
	}
}

int main(){
	BSTNode* root = new BSTNode();
	BSTInit(root, 5);
	insertNode(root, 3);
	insertNode(root, 2);
	insertNode(root, 4);
	insertNode(root, 8);
	insertNode(root, 7);
	insertNode(root, 9);

}