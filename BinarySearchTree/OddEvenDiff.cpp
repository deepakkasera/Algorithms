#include <bits/stdc++.h>
using namespace std;
int odd=0,even=0;
class node{
public:
	int data;
	node* left;
	node* right;

	node(int d) : data(d),left(NULL),right(NULL) {}

};

void levelOrderInput (node* &root) {
	int d;
	cout << "Enter root data ";
	cin >> d;
	if (d != -1) {
		root = new node(d);
		queue<node*> q;
		q.push(root);
		while(!q.empty()) {
			node* f = q.front();
			q.pop();
			int c1,c2;
			cout << "Enter children of " << f->data << " ";
			cin >> c1 >> c2;
			if (c1 != -1) {
				f->left = new node(c1);
				q.push(f->left);
			}
			if (c2 != -1) {
				f->right = new node(c2);
				q.push(f->right);
			} 
		}
	}
}
void levelOrderPrint (node* root) {
	queue<node*> q;
	int k=0;
	q.push(root);
	q.push(NULL);
	// odd += root->data;
	while (!q.empty()) {
		node* temp = q.front();
		q.pop();
		if (temp) {
			cout << temp->data << " ";
			if(k&1) odd+=temp->data;
			else even+=temp->data;
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
			k++;
		}
		if (!temp) {
			cout << endl;
			if (!q.empty()){
				q.push(NULL);
			}
		}
	}
	// return odd-even;
}
istream& operator>>(istream& is,node* &root){
	levelOrderInput(root);
	return is;
}

ostream& operator<<(ostream& os,node* &root){
	levelOrderPrint(root);
	return os;
}
int main(int argc, char const *argv[])
{
	node* root = NULL;
	cin>>root;
	cout<<root;
	cout<<odd<<" "<<even<<endl;
	cout<<odd-even<<endl;
	return 0;
}