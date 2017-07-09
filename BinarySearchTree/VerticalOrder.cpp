#include <iostream>
#include <climits>
#include <queue>
#include <unordered_map>
#define um unordered_map<int, vector<int> >
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

void verticalOrderPrint(node*root,um &m,int d=0){

    if(root==NULL){
        return ; 
    }
    m[d].push_back(root->data);
    verticalOrderPrint(root->left,m,d-1);
    verticalOrderPrint(root->right,m,d+1);
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


int main(int argc, char const *argv[])
{
	node* root = NULL;
	cin >> root;
	cout << root;
	um m;
	verticalOrderPrint(root,m);
	int min_key = INT_MAX;
    int max_key = INT_MIN;

    for(auto it=m.begin();it!=m.end();it++){

        min_key = min(min_key,it->first);
        max_key = max(max_key,it->first);
    }

    for(int key=min_key;key<=max_key;key++){

        for(int i=0;i<m[key].size();i++){
            cout<<m[key][i]<<" ";
        }
        cout<<endl;

    }
	return 0;
}