#include <bits/stdc++.h>
using namespace std;
int inversions=0;
int a[1000000];
// Naive approach O(N^2)
int countInversions(int a[],int n){
	int count =0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]) count++;
		}
	}
	return count;
}
int merge(int a[],int *left,int leftCount,int *right,int rightCount){
	int i=0,j=0,k=0;
	int count=0;
	while(i < leftCount && j<rightCount){
		if(left[i] <= right[j]) a[k++] = left[i++];
		else{
			a[k++] = right[j++];
			count += (leftCount-i);
		}
	}
	while(i < leftCount) a[k++] = left[i++];
	while(j < rightCount) a[k++] = right[j++];
	return count;
}
int mergeSort(int a[],int n){
	if(n <= 1) return 0;
	int mid=n/2;
	int *left,*right;
	left = new int[mid];
	right = new int[n-mid];
	for(int i=0;i<mid;i++) left[i] = a[i];
	for(int i=mid;i<n;i++) right[i-mid] = a[i];

	mergeSort(left,mid);
    mergeSort(right,n-mid);
    inversions += merge(a,left,mid,right,n-mid);
    delete left;
    delete right;
    return inversions;
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	//int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
    cout << countInversions(a,n) << endl;
	cout << mergeSort(a,n) << endl ;
	return 0;
}