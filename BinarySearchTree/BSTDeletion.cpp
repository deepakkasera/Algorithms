#include <iostream>
#include <queue>

using namespace std;
class node{
public:
	int data;
	node* left;
	node* right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

void levelOrderInput(node* &root) {
	int d;
	cout << "Enter root data\n";
	cin >> d;
	root = new node(d);
	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		node* temp = q.front();
		q.pop();

		int c1,c2;
		cout << "Enter the children for " << temp->data << " ";
		cin >> c1 >> c2;
		if(c1 != -1) {
			temp->left = new node(c1);
			q.push(temp->left);
		}

		if(c2 != -1) {
			temp->right = new node(c2);
			q.push(temp->right);
		}
	}
}

void levelOrderPrint(node* root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		node* temp = q.front();
		q.pop();

		if(temp){
			cout << temp->data << " ";
			if(temp->left){
				q.push(temp->left);
			} 
			if(temp->right){
				q.push(temp->right);
			}
		}
		else{
			cout << endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
	}
}

istream& operator>>(istream& is,node* &root) {
	levelOrderInput(root);
	return is;
}

ostream& operator<<(ostream& os,node* root) {
	levelOrderPrint(root);
	return os;
}

node* findMin(node* root){
	if(!root){
		return NULL;
	}
	node* temp = NULL;
	while(temp->left){
		temp = temp->left;
	}
	return temp;
}

node* deleteNode(node* &root,int d) {
	//Base Case
	if(root == NULL){
		return root;
	}

	if(root->data == d){
		//leaf node

		if(!root->left && !root->right){
			delete root;
			return NULL;
		}

		
		//one child
		if(root->left==NULL && root->right!=NULL){
			node* temp = root->right;
			delete root;
			return temp;

		}
		if(root->left!= NULL && root->right==NULL){
			node* temp = root->left;
			delete root;
			return temp;
		}

		// two children
		node* temp = findMin(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right,temp->data);
	}
	else if(root->data< d){
        root->right = deleteNode(root->right,d);
    }
    else{
        root->left = deleteNode(root->left,d);
    }
    return root;
}
int main(int argc, char const *argv[])
{
	node* root = NULL;
	cin >> root;
	cout << root;
	int d;
	cout << "Enter node to delete\n";
	cin >> d;
	root = deleteNode(root,d);
	cout << root;
	return 0;
}