#include<bits/stdc++.h>
using namespace std;
int inversions=0;
int a[10000000];
int merge(int a[],int left[],int leftCount,int *right,int rightCount){
    int i=0,j=0,k=0;
    int count=0;
    while(i<leftCount && j<rightCount){
        if(left[i] < right[j]) a[k++]=left[i++];
        else{
            a[k++]=right[j++];
            count += (leftCount-i);
        }
    }
    while(i<leftCount) a[k++]=left[i++];
    while(j<rightCount) a[k++]=right[j++];
    return count;
}
int mergeSort(int a[],int n){
    if( n < 2) return 0;
    int middle=n/2;
    int *left,*right;
    left = new int[middle];
    right = new int[n-middle];
    for(int i=0;i<middle;i++) left[i]=a[i];
    for(int i=middle;i<n;i++) right[i-middle] = a[i];
    
    mergeSort(left,middle);
    mergeSort(right,n-middle);
    inversions += merge(a,left,middle,right,n-middle);
    delete left;
    delete right;
    
    return inversions;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++) cin >> a[i];
        int inv = mergeSort(a,n);
        for(int i=0;i<n;i++) cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}