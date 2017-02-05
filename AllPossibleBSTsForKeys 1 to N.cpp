#include <bits/stdc++.h> 5
using namespace std;
struct node
{
	int data;
	node *right,*left;
};
node* newNode(int data){
	node* n = new node;
	n->data = data;
	n->left = n->right = NULL;
	return n;
}
std::vector<node*> ConstructBSTs(int start,int end){
	std::vector<node*> list;
	if(start > end){
		list.push_back(NULL);
		return list;
	}
	for(int i=start;i<=end;i++){
		std::vector<node*> leftSubTree = ConstructBSTs(start,i-1);
		std::vector<node*> rightSubTree = ConstructBSTs(i+1,end);
		for(int j=0;j<leftSubTree.size();j++){
			node* left = leftSubTree[j];
			for(int k=0;k<rightSubTree.size();k++){
				node* right = rightSubTree[k];
				node* n = newNode(i);
				n->right = right;
				n->left = left;
				list.push_back(n);
			}
		}
	}
	return list;
}
void preOrder(node* root){
	if(!root) return ;
	cout << root->data <<" ";
	preOrder(root->left);
	preOrder(root->right);
}
int main(int argc, char const *argv[])
{
	std::vector<node*> v = ConstructBSTs(1,5);
	cout << "Number of BSTs is " << v.size() << endl;
	for(int i=0;i<v.size();i++){
		preOrder(v[i]);
		cout << endl;
	}
	return 0;
}