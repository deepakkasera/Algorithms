#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
	int data;
	int child_count;
	TreeNode** children;

    TreeNode(int d){
    	data = d;
    	child_count = 0;
    	children = NULL;
    }
};
TreeNode* takeInput(){
	int d,c;
	cout << "Enter the data of node ";
	cin >> d;
	TreeNode* n = new TreeNode(d);
	cout << "Enter the number of children ";
	cin >> c;
	n->child_count = c;
	n->children = new TreeNode*[c];
	for(int i=0;i<c;i++){
		n->children[i] = takeInput();
	}
	return n;
}
void print(TreeNode* root){
	if(!root) return ;
	cout << root->data << " " ;
	for(int i=0;i<root->child_count;i++){
		print(root->children[i]);
	}
}
//Level order traversal
void printLevelOrder(TreeNode* root){
	//if(!root) return;
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		TreeNode* x = q.front();
		q.pop();
		cout << x->data <<" ";
		for(int i=0;i<x->child_count;i++)
			q.push(x->children[i]);
	}
}
//Print Level Order traversal with endl after each level
void printLevelOrder2(TreeNode* root){
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		TreeNode* f = q.front();
		q.pop();
		if(f == NULL){
			cout << endl;
			if(!q.empty())
			q.push(NULL);
		}
		else {
			cout << f->data << " ";
			for(int i=0;i<f->child_count;i++)
				q.push(f->children[i]);
		}
	}
}
//height of tree
int heightOfTree(TreeNode* root){
	if(!root) return 0;
	int height = 0;
	for(int i=0;i<root->child_count;i++)
		height = max(height,heightOfTree(root->children[i]));
	return height+1;
}
int countNumberOfNode(TreeNode* root){
	if(!root) return 0;
	int num=1;
	for(int i=0;i<root->child_count;i++){
		num += countNumberOfNode(root->children[i]);
	}
    return num ;
}
int findMax(TreeNode* root){
	if(root == NULL) return 0;
	int maximum_element = root->data;
	for(int i=0;i<root->child_count;i++){
		maximum_element = max(maximum_element,findMax(root->children[i]));
	}
	return maximum_element;
}
TreeNode* levelOrderInput(){
	queue<TreeNode*> q;
	int d;
	cout << "Enter the root data " ;
	cin >> d;
	TreeNode* n = new TreeNode(d);
	q.push(n);
	while(!q.empty()){
		TreeNode* f  =  q.front();
		q.pop();
		int c;
		cout << "Enter the child count for " << f->data << " ";
		cin >> c;
		f->child_count = c;
		f->children = new TreeNode*[c];
		for(int i=0;i<c;i++){
			cout << "Enter the "<< i <<" child data for " << f->data;
			int d;
			cin >> d; 
			f->children[i] = new TreeNode(d);
			q.push(f->children[i]);
		}
	}
	return n;
}
void printLevelK(TreeNode* root,int k){
	if(!root) return;
	if(k == 0) {
		cout << root->data << " ";
		return ;
	}
	for(int i=0;i<root->child_count;i++){
		printLevelK(root->children[i],k-1);
	}
	return ;
}
int maximumNodeSum(TreeNode* root){
	if(root == NULL){
		return 0;
	}
	int currnetSum = root->data;
	for(int i=0;i<root->child_count;i++){
		currnetSum += root->children[i]->data;
	}
	int subTreeSum;
	for(int i=0;i<root->child_count;i++){
		subTreeSum = maximumNodeSum(root->children[i]);
		currnetSum = max(currnetSum,subTreeSum);
	}
	return currnetSum;
}
class Pair{
public:
	int sum;
	TreeNode* node;
};
Pair maximumNodeSum2(TreeNode* root){
	Pair p;
	if(root == NULL){
		p.sum = 0;
		p.node = NULL;
		return p;
	}
	int currnetSum = root->data;
	for(int i=0;i<root->child_count;i++){
		currnetSum += root->children[i]->data;
	}
	p.sum = currnetSum;
	p.node = root;
	for(int i=0;i<root->child_count;i++){
		Pair p1 = maximumNodeSum2(root->children[i]);
		if(p1.sum > p.sum ){
			p.sum = p1.sum;
			p.node = p1.node;
		}
			}
	return p;
}
int main(int argc, char const *argv[])
{
	TreeNode* root = NULL;
	//root = takeInput();
	root =  levelOrderInput();
	print(root);
	cout << endl;
	printLevelOrder(root);
	cout << endl;
	printLevelOrder2(root);
	cout << "Height of tree is " << heightOfTree(root) << endl;
	cout << "Number of nodes in tree " << countNumberOfNode(root) << endl;
	cout << "Maximum element in the tree is " << findMax(root) << endl;
	cout << "Enter the level to print " ;
    int k;
	cin >> k;
	cout << "Level " << k  << " is " ;
	printLevelK(root,k);
	cout << endl;
	cout << "Maximum sum of node is " << maximumNodeSum(root) << endl;
	Pair p = maximumNodeSum2(root);
	cout << "Maximum sum of node is " << p.sum << " and the node data is " << p.node->data <<endl ;
	return 0;
}	