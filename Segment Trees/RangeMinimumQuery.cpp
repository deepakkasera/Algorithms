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
	return 0;
}