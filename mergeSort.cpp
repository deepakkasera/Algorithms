#include <bits/stdc++.h>
using namespace std;
void merge(int a[],int left[],int leftcount,int right[],int rightcount){
	int i=0,j=0,k=0;
	// i points to left subarray
	// j points to right subarray
    // k points to merged subarray
	while(i<leftcount && j<rightcount ){
		if ( left[i] < right[j] ) a[k++]=left[i++];
		else a[k++]=right[j++];
    }
    while(i < leftcount)  a[k++] = left[i++];
    while(j < rightcount)  a[k++] = right[j++];
}
void mergesort(int a[],int n){
	if(n<2) return;   //base condition:if array has only one element then it is already sorted 
	int middle;   // middle index of array
	int *left=NULL;
	int *right=NULL;
	middle=n/2;
	left = new int[middle];
	right = new int[n-middle];
	for(int i=0;i<middle;i++) 
		left[i]=a[i];
	for(int i=middle;i<n;i++)
		right[i-middle]=a[i];
	mergesort(left,middle);
	mergesort(right,n-middle);
	merge(a,left,middle,right,n-middle);
	delete left;
	delete right;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cout<<"Enter the number";
		cin>>a[i];
	}
	clock_t startTime = 0;
	mergesort(a,n);
	clock_t endTime = clock();
	cout << endTime - startTime <<endl;
	cout<<"Sorted array is ";
	for(int i=0;i<n;i++ )  cout<<a[i]<<" ";
	return 0;
}
