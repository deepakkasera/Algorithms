#include <bits/stdc++.h>
using namespace std;
struct BSTNode
{
	int data;
	BSTNode* left;
	BSTNode* right;
};
BSTNode* getNewNode(int data){
	BSTNode* n = new BSTNode();
	n->data=data;
	n->left=n->right=NULL;
	return n;
}
std::vector<BSTNode*> allPossibleBST(int start,int end){
	std::vector<BSTNode*> list;
	if(start > end){
		list.push_back(NULL);
		return list;
	}
	for(int i=start;i<=end;i++){
		std::vector<BSTNode*> leftList=allPossibleBST(start,i-1);
		std::vector<BSTNode*> rightList=allPossibleBST(i+1,end);
		for(int j=0;j<leftList.size();j++){
			BSTNode* left=leftList[j];
			for(int k=0;k<rightList.size();k++){
				BSTNode* right=rightList[k];
				BSTNode* node=getNewNode(i);
				node->left=left;
				node->right=right;
				list.push_back(node);
			}
		}
	}
	return list;
}
void preOrder(BSTNode* root){
	if(!root) return ;
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}
int main(int argc, char const *argv[])
{
	std::vector<BSTNode*> v=allPossibleBST(1,12);
	cout<<"Number of possible BST's is " << v.size()<<endl;
	// for(int i=0;i<v.size();i++){
	// 	preOrder(v[i]);
	// 	cout<<endl;
	// }
	return 0;
}