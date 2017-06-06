#include <bits/stdc++.h>
using namespace std;
//this function will be called once to build the tree
void buildTree(int *tree,int *a,int index,int start,int end) //start and end is the range
{	
	//Base Case
	if(start > end){
		return ;
	}

	//Base Case --> Leaf node
	if(start == end){
		tree[index] = a[start];
		return ;  
	}

	//Recursive Case
	int mid = (start + end)/2;
	
	//leftSubtree 
	buildTree(tree,a,2*index,start,mid);

	//rightSubtree
	buildTree(tree,a,2*index+1,mid+1,end);
	int left = tree[2*index];
	int right = tree[2*index + 1];
	tree[index] = min(left,right);
}

//Query function
int query(int *tree,int index,int start,int end,int qs,int qe) // qs and qe is the query range 
{
	//3 cases
	//1. No overlap
	if(qs > end || qe < start){
		return INT_MAX;
	}

	//2. Complete Overlap
	if(start >= qs && end <= qe){
		return tree[index];
	}

	//3. Partial overlap --> call both sides
	int mid = (start+end)/2;
	int leftAns = query(tree,2*index,start,mid,qs,qe);
	int rightAns = query(tree,2*index+1,mid+1,end,qs,qe);
	return min(leftAns,rightAns);
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the number of elements\n";
	cin >> n;
	int a[n];
	cout << "Enter array elements\n";
	for(int i=0;i<n;i++)
		cin >> a[i];
	
	//Build the tree array 
	int *tree = new int[4*n+1]; // or int tree[4*n+1]	
	int index = 1;
	buildTree(tree,a,index,0,n-1);
	for(int i=0;i<4*n+1;i++){
		cout << tree[i] << " ";
	}
	cout << endl;
	int q,qs,qe;
	cout << "enter number of queries\n";
	cin >> q;
	while(q--){
		cin >> qs >> qe;
		cout << "Minimum element in range " << qs << " and " << qe << " is " ;
		cout << query(tree,1,0,n-1,qs,qe) << endl;
	}
	return 0;
}