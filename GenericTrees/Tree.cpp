#include <bits/stdc++.h>
using namespace std;
class TreeNode{
public:
	int data;
	TreeNode** children;
	int child_count;

	TreeNode(int d){
		data=d;
		children = NULL;
		child_count = 0;
	}
};
TreeNode* takeInput(){
	int d,c;
	cout << "Enter node data";
	cin >> d;
	TreeNode* n = new TreeNode(d);
	cout << "Enter the number of children of " << d;
	cin >> c;
	//Base case is when we enter c to be zero
	n->child_count = c;
	n->children = new TreeNode*[c]; 
	for(int i=0;i<c;i++){
		n->children[i] = takeInput();
	}
	return n;
}
void print(TreeNode* root){
	if(!root) return;
	cout << root->data <<"->";
	for(int i=0;i<root->child_count;i++){
		cout << root->children[i]->data <<",";
	}
	cout << endl;
	for(int i=0;i<root->child_count;i++){
		print(root->children[i]);
	}
	cout << endl;
}
//Level Order Traversal
void printLevelOrder(TreeNode* root){
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		TreeNode* f = q.front();
		if(f == NULL){
			cout << endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else {
			q.pop();
			cout << f->data <<" ";
			for(int i=0;i<f->child_count;i++){
			q.push(f->children[i]);
			}
		}
	}
}
int heightOfTree(TreeNode* root){
	if(root == NULL) return 0;
	int height = INT_MIN;
	for(int i=0;i<root->child_count;i++){
		height = max(heightOfTree(root->children[i]),height);
	}
	return height+1;
}
int countNumberOfNodes(TreeNode* root){
	if(root == NULL){
		return 0;
	}
	int count=1;
	for(int i=0;i<root->child_count;i++){
		count += countNumberOfNodes(root->children[i]);
	}
	return count;
}
int findMax(TreeNode* root){
	if(root = NULL) return 0;
    int maximum_element=INT_MIN;
	for(int i=0;i<root->child_count;i++){
		maximum_element = max(maximum_element,findMax(root->children[i]));
	}
	return maximum_element;
}
void printAtK(TreeNode* root,int k){
	if(root == NULL) {
		return;
	}
	if(k==0){
		cout << root->data << " ";
		return ;
	}
	for(int i=0;i<root->child_count;i++){
		printAtK(root->children[i],k-1);
	}
	return ;
}
TreeNode* levelOrderInput(){
	queue<TreeNode*> q;
	int data;
	cout << "Enter root data";
	cin >> data ;
	TreeNode* root = new TreeNode(data);
	q.push(root);
	while(!q.empty()){
		TreeNode* f = q.front();
		q.pop();
		cout << "Enter chile count for " << f->data;
		int c;
		cin >> c;
		f->child_count = c;
		f->children = new TreeNode*[c];
		for(int i=0;i<c;i++){
			cout << "Enter " << i << "child data for " << f->data;
			int d;
			cin >> d;
			f->children[i] = new TreeNode(data);
			q.push(f->children[i]);  
		}
	}
	return root;
}
int main(int argc, char const *argv[])
{
	TreeNode* root = NULL;
	root = takeInput();
	printLevelOrder(root);
	// TreeNode* n = new TreeNode(1);
	// n->child_count = 2;
	// n->children = new TreeNode*[2];
	// n->children[0] = new TreeNode(2);
	// n->children[1] = new TreeNode(3);
	return 0;
}