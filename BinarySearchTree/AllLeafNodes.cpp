#include <iostream>
#include <climits>
#include <queue>

using namespace std;
int level;
int levelLeaf;
bool var = false;
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

bool levelOrderPrint(node* root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	level = 1;
	while(!q.empty()) {
		node* temp = q.front();
		q.pop();
		if(temp){
			if(!temp->left && !temp->right && !var){
				var = true;
				levelLeaf = level;
			}
			if(!temp->left && !temp->right && var && levelLeaf!=level){
				return false;
			}
			cout << temp->data << " ";
			if(temp->left){
				q.push(temp->left);
			} 
			if(temp->right){
				q.push(temp->right);
			}
		}
		else{
			level++;
			cout << endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
	}
	return true;
}



istream& operator>>(istream& is,node* &root) {
	levelOrderInput(root);
	return is;
}

ostream& operator<<(ostream& os,node* root) {
	levelOrderPrint(root);
	return os;
}

int main(int argc, char const *argv[])
{
	node* root = NULL;
	cin >> root;
	// cout << root;
	if(levelOrderPrint(root)){
		cout << "All leaf nodes are at same level\n";
	}else{
		cout << "All leaf nodes are not at same level\n";
	}
	return 0;
}