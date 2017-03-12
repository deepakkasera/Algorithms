#include <bits/stdc++.h>
using namespace std;
void updateBITree(int* BITree,int n,int index,int val){
	index=index+1;

	while(index<=n){
		BITree[index]+=val;

		index += (index&(-index));
	}

}
int getSum(int BITree[],int index){
	int sum=0;
	
	index=index+1;

	while(index>0){
		sum+=BITree[index];
		index = index - (index & (-index));
	}
	return sum;
}
int *constructBITree(int a[],int n){
	//creating and initializing BIT
	int *BITree = new int[n+1];
	for(int i=1;i<=n;i++)
		BITree[i]=0;

	//store the actual value by calling update function
	for(int i=0;i<n+1;i++){
		updateBITree(BITree,n,i,a[i]);
	}
	return BITree;
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	int *BITree = constructBITree(a,n);
    for(int i=1;i<=n;i++)cout<<BITree[i]<<" ";
	cout<<endl;
	cout << getSum(BITree,5) << endl;
	return 0;
}