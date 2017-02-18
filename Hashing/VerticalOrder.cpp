#include <bits/stdc++.h>
using namespace std;
class TreeNode{
public:
	int data;
	TreeNode* left;
	TreeNode* right;


	TreeNode(int d){
		data =d;
		left=NULL;
		right=NULL;
	}
};
//O(N)
void traverseTree(TreeNode* root,map<int, std::vector<int> &m> ,int d){
	if(root == NULL){
		return ;
	}
	int key = d;
	m[key].push_back(root->data);
	traverseTree(root->left,m,d-1);
	traverseTree(root->right,m,d+1);
}
int main(int argc, char const *argv[])
{
	TreeNode* n = new TreeNode(1);
	n->left = new TreeNode(2);
	n->right = new TreeNode(3);
	n->left->left = new TreeNode(4);
	n->left->right = new TreeNode(5);
	n->right->left = new TreeNode(6);
	n->right->right = new TreeNode(7);
	n->left->right->right = new TreeNode(8);
	n->right->right->right = new TreeNode(9);
	std::map<int, vector<int> > m;
	std::map<int , vector<int> >::iterator it;
	traverseTree(n,m,0);
	int min_key=INT_MIN,max_key = INT_MAX;;
	for(it=m.begin();it!=m.end();it++){
		min_key = min(min_key,it->first);
		max_key = max(max_key,it->first);
	} 
	for(int i=min_key;i<=	max_key;i++){
		for(int j=0;j<m[i].size();j++){
			cout << m[i][j] << " " ;
		}
		cout << endl;
	}
	return 0;
}